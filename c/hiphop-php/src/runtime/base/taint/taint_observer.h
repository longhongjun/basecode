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

#ifndef __HPHP_TAINT_OBSERVER_H__
#define __HPHP_TAINT_OBSERVER_H__

#ifdef TAINTED

#include <util/thread_local.h>
#include <runtime/base/taint/taint_data.h>

/**
 * The purpose of this class is to keep track of which strings are getting
 * "read" and which strings are getting created. This allows us to taint
 * strings by modifying the idl, and saves us from having taint related
 * code spread all over the HPHP codebase. This code is meant to be created
 * in the stack. You can therefore not make calls such as new TaintObserver().
 *
 * While adding convenience, the TaintObserver system has some downsides,
 * which are explained further in the README.
 */

// This flag is marked in the taints of $_GET, $_POST, and relevant $_COOKIE
// and $_SERVER keys and values. It is never passed and is used to ensure that
// we never modify the initial traces given to these strings.
#define TAINT_FLAG_ORIG         (0x80000000)
#define TAINT_ISSET_ORIG(bits)  ((bits) & TAINT_FLAG_ORIG)

// This flag is set in a TaintObserver's m_current_taint when it encounters
// an HTML-untainted string. It allows us to determine when an HTML-tainted
// string first makes contact with a clean string. If both this flag and the
// HTML bit itself are set at the time of String creation (i.e., mutation),
// then we capture trace data.
#define TAINT_FLAG_HTML_CLEAN   (0x40000000)

namespace HPHP {

class TaintObserver {
public:
  // The standard TaintObserver constructor. By default, registered taints in
  // a TaintObserver are propagated to all strings created or mutated within
  // its scope. Setting m_set_mask or m_clear_mask will, respectively,
  // forcibly apply or remove taints to/from new strings.
  TaintObserver(taint_t set_mask, taint_t clear_mask)
      : m_set_mask(set_mask), m_clear_mask(clear_mask), m_previous(*instance),
        m_cap_stack(m_previous ? m_previous->m_cap_stack : false) {
    *instance = this;
  }

  // Setting m_cap_stack turns all TaintObserver ops, besides construction and
  // destruction, into no-ops. This allows us to turn off tainting when in
  // particularly sensitive HPHP-internal scopes.
  TaintObserver(bool cap) : m_previous(*instance), m_cap_stack(cap) {
    *instance = this;
  }

  ~TaintObserver() { *instance = m_previous; }

  // This functions needs to be called whenever data inside strings is accessed.
  static void RegisterAccessed(const TaintData& td);

  // This function needs to be called whenever a string is created or mutated.
  static void RegisterMutated(TaintData& td, const char *s);

  static bool IsActive() { return *instance && !(*instance)->m_cap_stack; }

private:
  TaintData m_current_taint;
  taint_t m_set_mask;
  taint_t m_clear_mask;
  TaintObserver* m_previous;
  bool m_cap_stack;

  static DECLARE_THREAD_LOCAL(TaintObserver*, instance);

  // Disallow new, copy constructor, and assignment operator.
  void* operator new(long unsigned int size);
  TaintObserver(const TaintObserver&);
  TaintObserver& operator=(const TaintObserver&);
};

}

// Helper macro. If you use TAINT_OBSERVER, you don't need to
// wrap things in #ifdef TAINTED ... #endif
#define TAINT_OBSERVER(set, clear) \
  TaintObserver taint_observer((set), (clear))

#define TAINT_OBSERVER_CAP_STACK() \
  TaintObserver taint_observer(true)

#define TAINT_OBSERVER_REGISTER_ACCESSED(td) \
  TaintObserver::RegisterAccessed((td))

#define TAINT_OBSERVER_REGISTER_MUTATED(td, s) \
  TaintObserver::RegisterMutated((td), (s))

#else

#define TAINT_OBSERVER(set, clear) /* do nothing (note: not ; friendly) */
#define TAINT_OBSERVER_CAP_STACK() /* do nothing */
#define TAINT_OBSERVER_REGISTER_ACCESSED(td) /* do nothing */
#define TAINT_OBSERVER_REGISTER_MUTATED(td, s) /* do nothing */

#endif // TAINTED

#endif // __HPHP_TAINT_OBSERVER_H__
