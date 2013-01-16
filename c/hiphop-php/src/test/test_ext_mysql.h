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

#ifndef __TEST_EXT_MYSQL_H__
#define __TEST_EXT_MYSQL_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <test/test_cpp_ext.h>

///////////////////////////////////////////////////////////////////////////////

class TestExtMysql : public TestCppExt {
 public:
  virtual bool RunTests(const std::string &which);

  bool test_mysql_connect();
  bool test_mysql_pconnect();
  bool test_mysql_set_charset();
  bool test_mysql_ping();
  bool test_mysql_escape_string();
  bool test_mysql_real_escape_string();
  bool test_mysql_client_encoding();
  bool test_mysql_close();
  bool test_mysql_errno();
  bool test_mysql_error();
  bool test_mysql_warning_count();
  bool test_mysql_get_client_info();
  bool test_mysql_get_host_info();
  bool test_mysql_get_proto_info();
  bool test_mysql_get_server_info();
  bool test_mysql_info();
  bool test_mysql_insert_id();
  bool test_mysql_stat();
  bool test_mysql_thread_id();
  bool test_mysql_create_db();
  bool test_mysql_select_db();
  bool test_mysql_drop_db();
  bool test_mysql_affected_rows();
  bool test_mysql_set_timeout();
  bool test_mysql_query();
  bool test_mysql_unbuffered_query();
  bool test_mysql_db_query();
  bool test_mysql_list_dbs();
  bool test_mysql_list_tables();
  bool test_mysql_list_fields();
  bool test_mysql_list_processes();
  bool test_mysql_db_name();
  bool test_mysql_tablename();
  bool test_mysql_num_fields();
  bool test_mysql_num_rows();
  bool test_mysql_free_result();
  bool test_mysql_data_seek();
  bool test_mysql_fetch_row();
  bool test_mysql_fetch_assoc();
  bool test_mysql_fetch_array();
  bool test_mysql_fetch_lengths();
  bool test_mysql_fetch_object();
  bool test_mysql_result();
  bool test_mysql_fetch_field();
  bool test_mysql_field_seek();
  bool test_mysql_field_name();
  bool test_mysql_field_table();
  bool test_mysql_field_len();
  bool test_mysql_field_type();
  bool test_mysql_field_flags();
};

///////////////////////////////////////////////////////////////////////////////

#endif // __TEST_EXT_MYSQL_H__
