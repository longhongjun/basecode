/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include <runtime/base/hphp_system.h>
#include <runtime/base/compiler_id.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Globals::StaticInits *Globals::s_next_inits = 0;

void Globals::initialize() {
  StaticInits *s = s_next_inits;
  while (s) {
    const ClassPropTable *cpt = s->table;
    const int *e = s->entries;
    int n = *e++;
    while (n--) {
      const ClassPropTableEntry *p = cpt->m_entries + *e++;
      char *addr = (char*)this + p->offset;
      if (LIKELY(p->isFastInit())) {
        CVarRef v = cpt->getInitV(p->init_offset);
        switch (p->type) {
          case KindOfBoolean:
            *(bool*)addr = v.asBooleanVal();
            break;
          case KindOfInt64:
            *(int64*)addr = v.asInt64Val();
            break;
          case KindOfDouble:
            *(double*)addr = v.asDoubleVal();
            break;
          case KindOfString:
            *(String*)addr = v.asCStrRef();
            break;
          case KindOfArray:
            *(Array*)addr = v.asCArrRef();
            break;
          case KindOfUnknown:
            *(Variant*)addr = v;
            break;
          default:
            ASSERT(false);
        }
        continue;
      }
      CVarRef v = cpt->getInitVal(p);
      if (LIKELY(p->type == KindOfUnknown)) {
        *(Variant*)addr = v;
      } else {
        switch (p->type) {
          case KindOfBoolean:
            *(bool*)addr = v;
            break;
          case KindOfInt64:
            *(int64*)addr = v;
            break;
          case KindOfDouble:
            *(double*)addr = v;
            break;
          case KindOfString:
            *(String*)addr = v;
            break;
          case KindOfArray:
            *(Array*)addr = v;
            break;
          default:
            ASSERT(false);
        }
      }
    }
    s = s->next;
  }
}

bool Globals::declareConstant(CStrRef name, Variant &constant,
                              CVarRef value) {
  if (!value.isAllowedAsConstantValue()) {
    raise_warning("Constants may only evaluate to scalar values");
    return false;
  }
  if (!m_dynamicConstants.exists(name)) {
    m_dynamicConstants.set(name, value);
    constant = value;
    return true;
  }
  raise_warning("Constant %s already defined", name.data());
  return false;
}

bool Globals::defined(CStrRef name) {
  return m_dynamicConstants.exists(name);
}

Variant Globals::getConstant(CStrRef name) {
  return m_dynamicConstants[name];
}

Array Globals::getDynamicConstants() const {
  return m_dynamicConstants;
}

Variant Globals::getByIdx(ssize_t pos, Variant& k) {
  return getRefByIdx(pos, k);
}

CVarRef Globals::getRefByIdx(ssize_t pos, Variant& k) {
  if (pos < -1) {
    ArrayData *arr = Array::get();
    pos = wrapIter(pos);
    k = arr->getKey(pos);
    return arr->getValueRef(pos);
  }
  ASSERT(false);
  throw FatalErrorException("bad code generation");
}
ssize_t Globals::getIndex(const char* s, strhash_t prehash) const {
  return Array::get()->getIndex(s);
}
ssize_t Globals::size() const {
  return staticSize() + Array::size();
}
bool Globals::empty() const {
  return staticSize() == 0 && Array::size() == 0;
}
ssize_t Globals::staticSize() const { return 0; }

ssize_t Globals::iter_begin() const {
  if (empty()) return ArrayData::invalid_index;
  if (staticSize() > 0) {
    return 0;
  }
  return wrapIter(Array::get()->iter_begin());
}
ssize_t Globals::iter_end() const {
  if (empty()) return ArrayData::invalid_index;
  if (Array::size() > 0) {
    return wrapIter(Array::get()->iter_end());
  }
  return staticSize() - 1;
}
ssize_t Globals::iter_advance(ssize_t prev) const {
  ArrayData *arr = Array::get();
  if (prev < -1) {
    return wrapIter(arr->iter_advance(wrapIter(prev)));
  }
  ssize_t next = prev + 1;
  if (next == staticSize()) {
    if (arr) return wrapIter(arr->iter_begin());
    return ArrayData::invalid_index;
  }
  return next;
}
ssize_t Globals::iter_rewind(ssize_t prev) const {
  if (prev < -1) {
    ArrayData *arr = Array::get();
    ASSERT(arr);
    ssize_t next = arr->iter_rewind(wrapIter(prev));
    if (next == ArrayData::invalid_index) {
      if (staticSize() > 0) {
        return staticSize() - 1;
      }
      return ArrayData::invalid_index;
    } else {
      return wrapIter(next);
    }
  }
  ssize_t next = prev - 1;
  if (next < 0) return ArrayData::invalid_index;
  return next;
}

void Globals::getFullPos(FullPos &pos) {
  ArrayData *arr = Array::get();
  arr->getFullPos(pos);
}

bool Globals::setFullPos(const FullPos &pos) {
  ArrayData *arr = Array::get();
  return arr->setFullPos(pos);
}

Array Globals::getDefinedVars() {
  Array ret = Array::Create();
  for (ssize_t iter = iter_begin(); iter != ArrayData::invalid_index;
       iter = iter_advance(iter)) {
    Variant k;
    Variant v = getByIdx(iter, k);
    ret.set(k, v);
  }
  return ret;
}

ssize_t Globals::wrapIter(ssize_t it) const {
  if (it != ArrayData::invalid_index) {
    return -(it+2);
  }
  return ArrayData::invalid_index;
}

#ifdef HPHP_VERSION
#undef HPHP_VERSION
#endif
#define HPHP_VERSION(v) return #v;
const char* getHphpCompilerVersion() {
#include "../../version"
}

const char* getHphpCompilerId() {
#ifdef COMPILER_ID
  return COMPILER_ID;
#else
  return "";
#endif
}

///////////////////////////////////////////////////////////////////////////////
}
