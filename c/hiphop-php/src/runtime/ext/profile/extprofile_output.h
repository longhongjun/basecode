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

#ifndef __EXTPROFILE_OUTPUT_H__
#define __EXTPROFILE_OUTPUT_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_output.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline bool x_ob_start(CVarRef output_callback = null, int chunk_size = 0, bool erase = true) {
  FUNCTION_INJECTION_BUILTIN(ob_start);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_start(output_callback, chunk_size, erase);
}

inline void x_ob_clean() {
  FUNCTION_INJECTION_BUILTIN(ob_clean);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_ob_clean();
}

inline void x_ob_flush() {
  FUNCTION_INJECTION_BUILTIN(ob_flush);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_ob_flush();
}

inline bool x_ob_end_clean() {
  FUNCTION_INJECTION_BUILTIN(ob_end_clean);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_end_clean();
}

inline bool x_ob_end_flush() {
  FUNCTION_INJECTION_BUILTIN(ob_end_flush);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_end_flush();
}

inline void x_flush() {
  FUNCTION_INJECTION_BUILTIN(flush);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_flush();
}

inline String x_ob_get_clean() {
  FUNCTION_INJECTION_BUILTIN(ob_get_clean);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_clean();
}

inline String x_ob_get_contents() {
  FUNCTION_INJECTION_BUILTIN(ob_get_contents);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_contents();
}

inline String x_ob_get_flush() {
  FUNCTION_INJECTION_BUILTIN(ob_get_flush);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_flush();
}

inline int64 x_ob_get_length() {
  FUNCTION_INJECTION_BUILTIN(ob_get_length);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_length();
}

inline int64 x_ob_get_level() {
  FUNCTION_INJECTION_BUILTIN(ob_get_level);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_level();
}

inline Array x_ob_get_status(bool full_status = false) {
  FUNCTION_INJECTION_BUILTIN(ob_get_status);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_get_status(full_status);
}

inline String x_ob_gzhandler(CStrRef buffer, int mode) {
  FUNCTION_INJECTION_BUILTIN(ob_gzhandler);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_gzhandler(buffer, mode);
}

inline void x_ob_implicit_flush(bool flag = true) {
  FUNCTION_INJECTION_BUILTIN(ob_implicit_flush);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_ob_implicit_flush(flag);
}

inline Array x_ob_list_handlers() {
  FUNCTION_INJECTION_BUILTIN(ob_list_handlers);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_ob_list_handlers();
}

inline bool x_output_add_rewrite_var(CStrRef name, CStrRef value) {
  FUNCTION_INJECTION_BUILTIN(output_add_rewrite_var);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_output_add_rewrite_var(name, value);
}

inline bool x_output_reset_rewrite_vars() {
  FUNCTION_INJECTION_BUILTIN(output_reset_rewrite_vars);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_output_reset_rewrite_vars();
}

inline void x_hphp_crash_log(CStrRef name, CStrRef value) {
  FUNCTION_INJECTION_BUILTIN(hphp_crash_log);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_hphp_crash_log(name, value);
}

inline void x_hphp_stats(CStrRef name, int64 value) {
  FUNCTION_INJECTION_BUILTIN(hphp_stats);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_hphp_stats(name, value);
}

inline int64 x_hphp_get_stats(CStrRef name) {
  FUNCTION_INJECTION_BUILTIN(hphp_get_stats);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_get_stats(name);
}

inline Array x_hphp_get_status() {
  FUNCTION_INJECTION_BUILTIN(hphp_get_status);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_get_status();
}

inline Array x_hphp_get_iostatus() {
  FUNCTION_INJECTION_BUILTIN(hphp_get_iostatus);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_get_iostatus();
}

inline void x_hphp_set_iostatus_address(CStrRef name) {
  FUNCTION_INJECTION_BUILTIN(hphp_set_iostatus_address);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_hphp_set_iostatus_address(name);
}

inline Variant x_hphp_get_timers(bool get_as_float = true) {
  FUNCTION_INJECTION_BUILTIN(hphp_get_timers);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_get_timers(get_as_float);
}

inline Variant x_hphp_output_global_state(bool serialize = true) {
  FUNCTION_INJECTION_BUILTIN(hphp_output_global_state);
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_output_global_state(serialize);
}

inline int64 x_hphp_instruction_counter() {
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_instruction_counter();
}

inline Variant x_hphp_get_hardware_counters() {
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_get_hardware_counters();
}

inline bool x_hphp_set_hardware_events(CStrRef events = null) {
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  return f_hphp_set_hardware_events(events);
}

inline void x_hphp_clear_hardware_events() {
  TAINT_OBSERVER(TAINT_BIT_NONE, TAINT_BIT_NONE);
  f_hphp_clear_hardware_events();
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_OUTPUT_H__
