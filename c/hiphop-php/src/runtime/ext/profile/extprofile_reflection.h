/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
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

#ifndef __EXTPROFILE_REFLECTION_H__
#define __EXTPROFILE_REFLECTION_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_reflection.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline Array x_hphp_get_extension_info(CStrRef name) {
  return f_hphp_get_extension_info(name);
}

inline Array x_hphp_get_method_info(CVarRef cname, CVarRef name) {
  return f_hphp_get_method_info(cname, name);
}

inline Array x_hphp_get_closure_info(CVarRef closure) {
  return f_hphp_get_closure_info(closure);
}

inline Variant x_hphp_get_class_constant(CVarRef cls, CVarRef name) {
  return f_hphp_get_class_constant(cls, name);
}

inline Array x_hphp_get_class_info(CVarRef name) {
  return f_hphp_get_class_info(name);
}

inline Array x_hphp_get_function_info(CStrRef name) {
  return f_hphp_get_function_info(name);
}

inline Variant x_hphp_invoke(CStrRef name, CArrRef params) {
  return f_hphp_invoke(name, params);
}

inline Variant x_hphp_invoke_method(CVarRef obj, CStrRef cls, CStrRef name, CArrRef params) {
  return f_hphp_invoke_method(obj, cls, name, params);
}

inline bool x_hphp_instanceof(CObjRef obj, CStrRef name) {
  return f_hphp_instanceof(obj, name);
}

inline Object x_hphp_create_object(CStrRef name, CArrRef params) {
  return f_hphp_create_object(name, params);
}

inline Variant x_hphp_get_property(CObjRef obj, CStrRef cls, CStrRef prop) {
  return f_hphp_get_property(obj, cls, prop);
}

inline void x_hphp_set_property(CObjRef obj, CStrRef cls, CStrRef prop, CVarRef value) {
  f_hphp_set_property(obj, cls, prop, value);
}

inline Variant x_hphp_get_static_property(CStrRef cls, CStrRef prop) {
  return f_hphp_get_static_property(cls, prop);
}

inline void x_hphp_set_static_property(CStrRef cls, CStrRef prop, CVarRef value) {
  f_hphp_set_static_property(cls, prop, value);
}

inline String x_hphp_get_original_class_name(CStrRef name) {
  return f_hphp_get_original_class_name(name);
}

inline bool x_hphp_scalar_typehints_enabled() {
  return f_hphp_scalar_typehints_enabled();
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_REFLECTION_H__
