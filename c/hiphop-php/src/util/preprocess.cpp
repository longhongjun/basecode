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

#include "preprocess.h"
#include "base.h"
#include "exception.h"
#include <xhp_preprocess.hpp>

using std::istream;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

istream *preprocessXHP(istream &input, std::iostream &output,
                       const std::string &fullPath) {
  istream *is = &input;
  string code, error;
  uint32_t errline;

  // Under HPHP, the 'include_debug' flag hurts performance and does not
  // provide any additional benefit, so it should always be set to false.
  xhp_flags_t flags;
  memset(&flags, 0, sizeof(xhp_flags_t));
  flags.eval = false;
  flags.short_tags = true;
  flags.idx_expr = true;
  flags.include_debug = false;
  flags.emit_namespaces = false;

  XHPResult res;
  {
    std::stringbuf sb;
    input >> std::noskipws >> &sb;
    string buffer = sb.str();
    res = xhp_preprocess(buffer, code, error, errline, flags);
  }

  if (res == XHPRewrote) {
    output << code;
    is = &output;
  } else if (res == XHPDidNothing) {
    is = &input;
  } else {
    ASSERT(res == XHPErred);
    throw Exception("Unable to parse XHP file: %s:%d\n%s", fullPath.c_str(),
                    (int)errline, error.c_str());
  }
  is->clear();
  is->seekg(0, std::ios::beg);
  return is;
}

///////////////////////////////////////////////////////////////////////////////
}


