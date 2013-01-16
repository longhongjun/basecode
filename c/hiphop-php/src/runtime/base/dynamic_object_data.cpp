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

#include <runtime/base/complex_types.h>
#include <runtime/base/dynamic_object_data.h>
#include <runtime/base/array/array_init.h>
#include <runtime/base/externals.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/class_info.h>
#include <util/util.h>

namespace HPHP {

/////////////////////////////////////////////////////////////////////////////
// constructor/destructor

DynamicObjectData::DynamicObjectData(const ObjectStaticCallbacks *cb,
                                     const char* pname,
                                     ObjectData* r /* = NULL */) :
    ObjectData(cb, r != this), root(r ? r : this) {
  setId(r);
  if (pname) {
    CountableHelper h(root);
    parent = create_object_only(pname, root);
    setAttributes(parent.get());
  }
}

DynamicObjectData::~DynamicObjectData() {
  /*
   * we cant allow the normal SmartPtr destructor
   * to take care of this, since that would call
   * release, which would call destruct. But
   * destruct has already been called by the time
   * we get here
   */
  if (!parent.isNull()) {
    ObjectData *p = parent.detach();
    ASSERT(p->getCount() == 1);
    delete p;
  }
}

void DynamicObjectData::init() {
  if (!parent.isNull()) {
    parent->init();
  }
}

void DynamicObjectData::setRoot(ObjectData *r) {
  root = r;
  if (!parent.isNull()) {
    parent->setRoot(r);
  }
}
ObjectData *DynamicObjectData::getRoot() {
  return root;
}

///////////////////////////////////////////////////////////////////////////////
// instance methods and properties

void DynamicObjectData::o_getArray(Array &props, bool pubOnly /* = false */)
const {
  if (!parent.isNull()) {
    ClassInfo::GetArray(parent.get(), parent->o_getClassPropTable(),
                        props, pubOnly ?
                        ClassInfo::GetArrayPublic : ClassInfo::GetArrayAll);
  } else {
    ObjectData::o_getArray(props, pubOnly);
  }
}

void DynamicObjectData::o_setArray(CArrRef props) {
  if (!parent.isNull()) {
    ClassInfo::SetArray(parent.get(), parent->o_getClassPropTable(), props);
  } else {
    ObjectData::o_setArray(props);
  }
}

Array DynamicObjectData::o_toArray() const {
  if (!parent.isNull()) {
    return parent->o_toArray();
  } else {
    return ObjectData::o_toArray();
  }
}

Array DynamicObjectData::o_getDynamicProperties() const {
  if (!parent.isNull()) {
    return parent->o_getDynamicProperties();
  } else {
    return ObjectData::o_getDynamicProperties();
  }
}

Variant DynamicObjectData::doCall(Variant v_name, Variant v_arguments,
                                  bool fatal) {
  if (!parent.isNull()) {
    return parent->doCall(v_name, v_arguments, fatal);
  } else {
    return ObjectData::doCall(v_name, v_arguments, fatal);
  }
}

Variant DynamicObjectData::doRootCall(Variant v_name, Variant v_arguments,
                                      bool fatal) {
  return root->doCall(v_name, v_arguments, fatal);
}

///////////////////////////////////////////////////////////////////////////////
// magic methods that user classes can override, and these are default handlers
// or actions to take:

Variant DynamicObjectData::t___destruct() {
  if (!parent.isNull()) {
    return parent->t___destruct();
  } else {
    return ObjectData::t___destruct();
  }
}
Variant DynamicObjectData::t___set(Variant v_name, Variant v_value) {
  if (!parent.isNull()) {
    return parent->t___set(v_name, withRefBind(v_value));
  } else {
    return ObjectData::t___set(v_name, withRefBind(v_value));
  }
}

Variant DynamicObjectData::t___get(Variant v_name) {
  if (!parent.isNull()) {
    return parent->t___get(v_name);
  } else {
    return ObjectData::t___get(v_name);
  }
}

bool DynamicObjectData::t___isset(Variant v_name) {
  if (!parent.isNull()) {
    return parent->t___isset(v_name);
  } else {
    return ObjectData::t___isset(v_name);
  }
}

Variant DynamicObjectData::t___unset(Variant v_name) {
  if (!parent.isNull()) {
    return parent->t___unset(v_name);
  } else {
    return ObjectData::t___unset(v_name);
  }
}

Variant DynamicObjectData::t___sleep() {
  if (!parent.isNull()) {
    Variant ret = parent->t___sleep();
    if (!parent->getAttribute(HasSleep)) {
      // When the parent also has the default implementation in ObjectData,
      // the attribute HasSleep should be cleared both in the parent and the
      // current object.
      clearAttribute(HasSleep);
    }
    return ret;
  } else {
    return ObjectData::t___sleep();
  }
}

Variant DynamicObjectData::t___wakeup() {
  if (!parent.isNull()) {
    return parent->t___wakeup();
  } else {
    return ObjectData::t___wakeup();
  }
}

String DynamicObjectData::t___tostring() {
  if (!parent.isNull()) {
    return parent->t___tostring();
  } else {
    return ObjectData::t___tostring();
  }
}

Variant DynamicObjectData::t___clone() {
  if (!parent.isNull()) {
    return parent->t___clone();
  } else {
    return ObjectData::t___clone();
  }
}

Variant &DynamicObjectData::___offsetget_lval(Variant v_name) {
  if (!parent.isNull()) {
    return parent->___offsetget_lval(v_name);
  } else {
    return ObjectData::___offsetget_lval(v_name);
  }
}

const CallInfo *DynamicObjectData::t___invokeCallInfoHelper(void *&extra) {
  if (!parent.isNull()) {
    return parent->t___invokeCallInfoHelper(extra);
  } else {
    return ObjectData::t___invokeCallInfoHelper(extra);
  }
}

///////////////////////////////////////////////////////////////////////////////
}
