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

#include <runtime/base/variable_table.h>
#include <runtime/base/array/array_init.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Variant &LVariableTable::getImpl(CStrRef s) {
  // LVariableTable may have references to its values leaked, and therefore
  // cannot support escalation to ZendArray.
  if (!m_px) {
    m_px = ArrayInit((ssize_t)0, true).create();
    m_px->incRefCount();
  }
  return lvalAt(s, AccessFlags::Key);
}

Array RVariableTable::getDefinedVars() const {
  return m_px ? Array(*this) : Array::Create();
}

Array LVariableTable::getDefinedVars() {
  return m_px ? *this : Array::Create();
}


///////////////////////////////////////////////////////////////////////////////
}
