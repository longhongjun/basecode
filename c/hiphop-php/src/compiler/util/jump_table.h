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

#ifndef __JUMP_TABLE_H__
#define __JUMP_TABLE_H__

#include <compiler/code_generator.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
class JumpTableBase {
  public:
  virtual bool ready() const = 0;
  virtual void next() = 0;
  virtual const char *key() const = 0;
  virtual ~JumpTableBase() {}
};

class JumpTable : public JumpTableBase {
public:
  JumpTable(CodeGenerator &cg, const std::vector<const char*> &keys,
            bool caseInsensitive, bool hasPrehash, bool useString,
            bool quiet = false);
  bool ready() const;
  void next();
  const char *key() const;
  int current() const;
  bool last() const;
  int size() const { return m_size; }
protected:
  CodeGenerator &m_cg;
  CodeGenerator::MapIntToStringVec::const_iterator m_iter;
  CodeGenerator::MapIntToStringVec m_table;
  uint m_subIter;
  int m_size;
  bool m_quiet;
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // __JUMP_TABLE_H__
