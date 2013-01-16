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

#include <runtime/base/global_array_wrapper.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

void GlobalArrayWrapper::release() {
}

ssize_t GlobalArrayWrapper::vsize() const {
  return m_globals->size();
}

Variant GlobalArrayWrapper::getKey(ssize_t pos) const {
  Variant k;
  m_globals->getByIdx(pos, k);
  return k;
}
Variant GlobalArrayWrapper::getValue(ssize_t pos) const {
  Variant k;
  return m_globals->getByIdx(pos, k);
}
CVarRef GlobalArrayWrapper::getValueRef(ssize_t pos) const {
  Variant k;
  return m_globals->getRefByIdx(pos, k);
}
bool GlobalArrayWrapper::noCopyOnWrite() const { return true; }

bool GlobalArrayWrapper::exists(int64   k) const {
  return exists(String(k));
}

bool GlobalArrayWrapper::exists(const StringData* k) const {
  return m_globals->exists(StrNR(k));
}

CVarRef GlobalArrayWrapper::get(int64   k, bool error /* = false */) const {
  return get(String(k));
}

CVarRef GlobalArrayWrapper::get(const StringData* k,
                                bool error /* = false */) const {
  if (exists(k)) {
    return m_globals->get(StrNR(k));
  }
  return null_variant;
}

ssize_t GlobalArrayWrapper::getIndex(int64 k) const {
  String s = toString(k);
  return m_globals->getIndex(s.data(), s->hash());
}

ssize_t GlobalArrayWrapper::getIndex(const StringData* k) const {
  return m_globals->getIndex(k->data(), k->hash());
}

ArrayData *GlobalArrayWrapper::lval(int64   k, Variant *&ret, bool copy,
    bool checkExist /* = false */) {
  return lval(String(k), ret, copy);
}

ArrayData *GlobalArrayWrapper::lval(StringData* k, Variant *&ret,
                                    bool copy, bool checkExist /* = false */) {
  ret = &m_globals->get(StrNR(k));
  return NULL;
}
ArrayData* GlobalArrayWrapper::lvalNew(Variant *&ret, bool copy) {
  ret = &m_globals->lvalAt();
  return NULL;
}

ArrayData *GlobalArrayWrapper::set(int64   k, CVarRef v, bool copy) {
  ArrayData::set(String(k), v, copy);
  return NULL;
}

ArrayData *GlobalArrayWrapper::set(StringData* k, CVarRef v, bool copy) {
  m_globals->get(StrNR(k)).assignVal(v);
  return NULL;
}

ArrayData *GlobalArrayWrapper::setRef(int64   k, CVarRef v, bool copy) {
  ArrayData::setRef(String(k), v, copy);
  return NULL;
}

ArrayData *GlobalArrayWrapper::setRef(StringData* k, CVarRef v,
                                      bool copy) {
  m_globals->get(StrNR(k)).assignRef(v);
  return NULL;
}

ArrayData *GlobalArrayWrapper::remove(int64   k, bool copy) {
  return remove(String(k), copy);
}

ArrayData *GlobalArrayWrapper::remove(const StringData* k, bool copy) {
  unset(m_globals->get(StrNR(k)));
  return NULL;
}

ArrayData *GlobalArrayWrapper::copy() const {
  return NULL;
}

ArrayData *GlobalArrayWrapper::append(CVarRef v, bool copy) {
  m_globals->append(v);
  return NULL;
}
ArrayData *GlobalArrayWrapper::appendRef(CVarRef v, bool copy) {
  m_globals->appendRef(v);
  return NULL;
}
ArrayData *GlobalArrayWrapper::appendWithRef(CVarRef v, bool copy) {
  m_globals->appendWithRef(v);
  return NULL;
}

ArrayData *GlobalArrayWrapper::append(const ArrayData *elems, ArrayOp op,
                                      bool copy) {
  ((Array*)m_globals)->get()->append(elems, op, false);
  return NULL;
}

ArrayData *GlobalArrayWrapper::pop(Variant &value) {
  throw NotSupportedException(__func__, "manipulating globals array");
}

ArrayData *GlobalArrayWrapper::dequeue(Variant &value) {
  throw NotSupportedException(__func__, "manipulating globals array");
}

ArrayData *GlobalArrayWrapper::prepend(CVarRef v, bool copy) {
  throw NotSupportedException(__func__, "manipulating globals array");
}

ssize_t GlobalArrayWrapper::iter_begin() const {
  return m_globals->iter_begin();
}
ssize_t GlobalArrayWrapper::iter_end() const {
  return m_globals->iter_end();
}
ssize_t GlobalArrayWrapper::iter_advance(ssize_t prev) const {
  return m_globals->iter_advance(prev);
}
ssize_t GlobalArrayWrapper::iter_rewind(ssize_t prev) const {
  return m_globals->iter_rewind(prev);
}

Variant GlobalArrayWrapper::reset() {
  m_pos = m_globals->iter_begin();
  return value(m_pos);
}

Variant GlobalArrayWrapper::prev() {
  m_pos = m_globals->iter_rewind(m_pos);
  return value(m_pos);
}

Variant GlobalArrayWrapper::current() const {
  ssize_t p = m_pos;
  return value(p);
}

Variant GlobalArrayWrapper::next() {
  m_pos = m_globals->iter_advance(m_pos);
  return value(m_pos);
}

Variant GlobalArrayWrapper::end() {
  m_pos = m_globals->iter_end();
  return value(m_pos);
}

Variant GlobalArrayWrapper::key() const {
  if (isInvalid()) return null;
  Variant k;
  m_globals->getByIdx(m_pos, k);
  return k;
}

Variant GlobalArrayWrapper::value(ssize_t &pos) const {
  if (isInvalid()) return false;
  Variant k;
  return m_globals->getByIdx(m_pos, k);
}

static StaticString s_value("value");
static StaticString s_key("key");

Variant GlobalArrayWrapper::each() {
  if (!isInvalid()) {
    ArrayInit init(4);
    Variant key = getKey(m_pos);
    Variant value = getValue(m_pos);
    init.set(1, value);
    init.set(s_value, value, true);
    init.set(0, key);
    init.set(s_key, key, true);
    m_pos = m_globals->iter_advance(m_pos);
    return Array(init.create());
  }
  return false;
}

void GlobalArrayWrapper::getFullPos(FullPos &fp) {
  if (m_pos == ArrayData::invalid_index) {
    fp.pos = ArrayData::invalid_index;
  } else if (m_pos < m_globals->staticSize()) {
    fp.pos = m_pos;
  } else {
    m_globals->getFullPos(fp);
  }
}

bool GlobalArrayWrapper::setFullPos(const FullPos &fp) {
  if (fp.pos != ArrayData::invalid_index) {
    if (m_pos < m_globals->staticSize()) return true;
    ArrayData *data = m_globals->getArrayData();
    if (data) {
      data->reset();
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

CVarRef GlobalArrayWrapper::currentRef() {
  Variant k;
  return m_globals->getRefByIdx(m_pos, k);
}

CVarRef GlobalArrayWrapper::endRef() {
  Variant k;
  return m_globals->getRefByIdx(m_globals->iter_end(), k);
}

ArrayData* GlobalArrayWrapper::escalateForSort() {
  raise_warning("Sorting the $GLOBALS array is not supported");
  return this;
}
void GlobalArrayWrapper::ksort(int sort_flags, bool ascending) {}
void GlobalArrayWrapper::sort(int sort_flags, bool ascending) {}
void GlobalArrayWrapper::asort(int sort_flags, bool ascending) {}
void GlobalArrayWrapper::uksort(CVarRef cmp_function) {}
void GlobalArrayWrapper::usort(CVarRef cmp_function) {}
void GlobalArrayWrapper::uasort(CVarRef cmp_function) {}

///////////////////////////////////////////////////////////////////////////////
}
