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
#include <runtime/ext_hhvm/ext_hhvm.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/array/array_init.h>
#include <runtime/ext/ext.h>
#include <runtime/vm/class.h>
#include <runtime/vm/runtime.h>
#include <exception>

namespace HPHP {

/*
void HPHP::f_thrift_protocol_write_binary(HPHP::Object const&, HPHP::String const&, long long, HPHP::Object const&, int, bool)
_ZN4HPHP30f_thrift_protocol_write_binaryERKNS_6ObjectERKNS_6StringExS2_ib

transportobj => rdi
method_name => rsi
msgtype => rdx
request_struct => rcx
seqid => r8
strict_write => r9
*/

void fh_thrift_protocol_write_binary(Value* transportobj, Value* method_name, long long msgtype, Value* request_struct, int seqid, bool strict_write) asm("_ZN4HPHP30f_thrift_protocol_write_binaryERKNS_6ObjectERKNS_6StringExS2_ib");

TypedValue * fg1_thrift_protocol_write_binary(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_thrift_protocol_write_binary(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  if ((args-5)->m_type != KindOfBoolean) {
    tvCastToBooleanInPlace(args-5);
  }
  if ((args-4)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-4);
  }
  if ((args-3)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-3);
  }
  if ((args-2)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-2);
  }
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  fh_thrift_protocol_write_binary((Value*)(args-0), (Value*)(args-1), (long long)(args[-2].m_data.num), (Value*)(args-3), (int)(args[-4].m_data.num), (bool)(args[-5].m_data.num));
  return rv;
}

TypedValue* fg_thrift_protocol_write_binary(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 6LL) {
      if ((args-5)->m_type == KindOfBoolean && (args-4)->m_type == KindOfInt64 && (args-3)->m_type == KindOfObject && (args-2)->m_type == KindOfInt64 && IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfObject) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        fh_thrift_protocol_write_binary((Value*)(args-0), (Value*)(args-1), (long long)(args[-2].m_data.num), (Value*)(args-3), (int)(args[-4].m_data.num), (bool)(args[-5].m_data.num));
        frame_free_locals_no_this_inl(ar, 6);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_thrift_protocol_write_binary(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 6);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("thrift_protocol_write_binary", count, 6, 6, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 6);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_thrift_protocol_read_binary(HPHP::Object const&, HPHP::String const&, bool)
_ZN4HPHP29f_thrift_protocol_read_binaryERKNS_6ObjectERKNS_6StringEb

(return value) => rax
_rv => rdi
transportobj => rsi
obj_typename => rdx
strict_read => rcx
*/

TypedValue* fh_thrift_protocol_read_binary(TypedValue* _rv, Value* transportobj, Value* obj_typename, bool strict_read) asm("_ZN4HPHP29f_thrift_protocol_read_binaryERKNS_6ObjectERKNS_6StringEb");

TypedValue * fg1_thrift_protocol_read_binary(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_thrift_protocol_read_binary(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  if ((args-2)->m_type != KindOfBoolean) {
    tvCastToBooleanInPlace(args-2);
  }
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  fh_thrift_protocol_read_binary((rv), (Value*)(args-0), (Value*)(args-1), (bool)(args[-2].m_data.num));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_thrift_protocol_read_binary(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 3LL) {
      if ((args-2)->m_type == KindOfBoolean && IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfObject) {
        fh_thrift_protocol_read_binary((&(rv)), (Value*)(args-0), (Value*)(args-1), (bool)(args[-2].m_data.num));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_thrift_protocol_read_binary(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("thrift_protocol_read_binary", count, 3, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}




} // !HPHP

