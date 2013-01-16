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

#ifndef __INSIDE_HPHP_COMPLEX_TYPES_H__
#error Directly including 'type_object.h' is prohibited. \
       Include 'complex_types.h' instead.
#endif

#ifndef __HPHP_OBJECT_H__
#define __HPHP_OBJECT_H__

#include <runtime/base/util/smart_ptr.h>
#include <runtime/base/object_data.h>
#include <runtime/base/type_string.h>
#include <runtime/base/hphp_value.h>
#include <runtime/base/gc_roots.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

#define null_object Object::s_nullObject

class ArrayIter;
class MutableArrayIter;

#ifdef HHVM_GC
typedef GCRootTracker<ObjectData> ObjectBase;
#else
typedef SmartPtr<ObjectData> ObjectBase;
#endif

/**
 * Object type wrapping around ObjectData to implement reference count.
 */
class Object : protected ObjectBase {
 public:
  Object() {}

  static const Object s_nullObject;

  ObjectData* get() const { return m_px; }
  void reset() { ObjectBase::reset(); }

  ObjectData* operator->() const {
    if (!m_px) throw_null_pointer_exception();
    return m_px;
  }

  /**
   * Constructors
   */
  Object(ObjectData *data) : ObjectBase(data) { }
  Object(CObjRef src) : ObjectBase(src.m_px) { }

  ~Object();

  /**
   * Informational
   */
  bool isNull() const {
    return m_px == NULL;
  }
  bool isResource() const {
    return m_px && m_px->isResource();
  }
  bool instanceof(CStrRef s) const {
    return m_px && m_px->o_instanceof(s);
  }
  int64 hashForIntSwitch(int64 firstNonZero, int64 noMatch) const {
    return m_px ? m_px->o_toInt64() : 0;
  }
  int64 hashForStringSwitch(
      int64 firstTrueCaseHash,
      int64 firstNullCaseHash,
      int64 firstFalseCaseHash,
      int64 firstZeroCaseHash,
      int64 firstHash,
      int64 noMatchHash,
      bool &needsOrder) const {
    if (!m_px) {
      needsOrder = false;
      return firstNullCaseHash;
    }
    needsOrder = true;
    return firstHash;
  }

  static Object CreateDummy(ObjectData*(*cooFunc)());
  static Object CreateDummy(ObjectData*(*cooFunc)(ObjectData*));

  template <class T> T& cast() { return *static_cast<T*>(this); }
  template <class T> const T& cast() const {
    return *static_cast<const T*>(this);
  }
  ArrayIter begin(CStrRef context = null_string) const;

  MutableArrayIter begin(Variant *key, Variant &val,
                         CStrRef context = null_string) const;

  /**
   * getTyped() and is() are intended for use with classes only. Using
   * these functions with an interface will cause a compile time error.
   * It is also worth noting that these functions have not been tested
   * with redeclared classes or classes that have a redeclared ancestor
   * in the inheritance hierarchy.
   */
  template<typename T>
  T *getTyped(bool nullOkay = false, bool badTypeOkay = false) const {
    CT_ASSERT_DESCENDENT_OF_OBJECTDATA(T);

    ObjectData *cur = m_px;
    if (!cur) {
      if (!nullOkay) {
        throw_null_pointer_exception();
      }
      return NULL;
    }
    while (true) {
      T *px = dynamic_cast<T*>(cur);
      if (!px) {
        cur = cur->getRedeclaredParent();
        if (cur) continue;
        if (!badTypeOkay) {
          throw InvalidObjectTypeException(m_px->o_getClassName());
        }
        return NULL;
      }

      // Assert that casting does not adjust the 'this' pointer
      ASSERT((void*)px == (void*)cur);
      return px;
    }
  }
  template<typename T>
  bool is() const {
    return getTyped<T>(true, true) != NULL;
  }
  template<typename T>
  T *cast() const {
    return getTyped<T>();
  }

  ObjectData *objectForCall() const {
    if (m_px) return m_px;
    throw_call_non_object();
  }

  /**
   * Type conversions
   */
  bool   toBoolean() const { return m_px ? m_px->o_toBoolean() : false;}
  char   toByte   () const { return m_px ? m_px->o_toInt64() : 0;}
  short  toInt16  () const { return m_px ? m_px->o_toInt64() : 0;}
  int    toInt32  () const { return m_px ? m_px->o_toInt64() : 0;}
  int64  toInt64  () const { return m_px ? m_px->o_toInt64() : 0;}
  double toDouble () const { return m_px ? m_px->o_toDouble() : 0;}
  String toString () const { return m_px ? m_px->t___tostring() : String();}
  Array  toArray  () const;
  Variant toKey   () const;

  int64 toInt64ForCompare() const;
  double toDoubleForCompare() const;

  /**
   * Comparisons
   */
  bool same (CObjRef v2) const { return m_px == v2.get();}
  bool equal(CObjRef v2) const;
  bool less (CObjRef v2) const;
  bool more (CObjRef v2) const;

  /**
   * Unresolved objects will go through these two functions than the ones
   * on SmartObject<T>.
   */
  Variant o_get(CStrRef propName, bool error = true,
                CStrRef context = null_string) const;
  Variant o_getPublic(CStrRef propName, bool error = true) const;
  Variant o_set(CStrRef s, CVarRef v, CStrRef context = null_string);
  Variant o_set(CStrRef s, RefResult v, CStrRef context = null_string);
  Variant o_setRef(CStrRef s, CVarRef v, CStrRef context = null_string);
  Variant o_setPublic(CStrRef s, CVarRef v);
  Variant o_setPublic(CStrRef s, RefResult v);
  Variant o_setPublicRef(CStrRef s, CVarRef v);
  Variant &o_lval(CStrRef propName, CVarRef tmpForGet,
                  CStrRef context = null_string);
  Variant &o_unsetLval(CStrRef s, CVarRef tmpForGet,
                       CStrRef context = null_string);
  bool o_isset(CStrRef propName, CStrRef context = null_string) const;
  bool o_empty(CStrRef propName, CStrRef context = null_string) const;
  void o_unset(CStrRef propName, CStrRef context = null_string) const;
  template<typename T, int op>
  T o_assign_op(CStrRef propName, CVarRef val, CStrRef context = null_string);
  Variant o_argval(bool byRef, CStrRef propName, bool error = true,
      CStrRef context = null_string);
  /**
   * Input/Output
   */
  void serialize(VariableSerializer *serializer) const;
  bool unserialize(std::istream &in);

  void setToDefaultObject();

  // Transfer ownership of our reference to this object.
  ObjectData *detach() {
    ObjectData *ret = m_px;
    m_px = NULL;
    return ret;
  }

 private:
  static void compileTimeAssertions() {
    CT_ASSERT(offsetof(Object, m_px) == offsetof(Value, m_data));
  }
};

///////////////////////////////////////////////////////////////////////////////
// ObjNR

class ObjNR {
public:
  explicit ObjNR(ObjectData *data) {
    m_px = data;
  }

  Object& asObject() {
    return *reinterpret_cast<Object*>(this); // XXX
  }

  const Object& asObject() const {
    return const_cast<ObjNR*>(this)->asObject();
  }

private:
  ObjectData* m_px;
  static void compileTimeAssertions() {
    BOOST_STATIC_ASSERT((offsetof(ObjNR, m_px) == kExpectedMPxOffset));
  }
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_OBJECT_H__
