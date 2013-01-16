###############################################################################
#
# Handle command line switches, and directories
#
# Author: mwilliams (02/2010)
#
###############################################################################
#
# NOTE: $(PWD) is not set correctly when make is invoked
# using "make -Cdir". We need the actual current
# directory, not the one that make was invoked from
CWD := $(shell readlink -f `pwd`)

ifdef USE_HHVM
ifneq ($(USE_HHVM),1)
$(error USE_HHVM must either be unset, or equal to 1)
endif
endif

ifeq ($(notdir $(MAKE)),emake)
export MAKE
override USE_CCACHE :=
override NO_DISTCC := 1
endif

ifneq ($(origin DIRS_INCLUDED), override)
override DIRS_INCLUDED := 1
unexport DIRS_INCLUDED

# This is to make sure "make" without any target will actually "make all".
overall: all quiet-1

# Add quiet as a dependent to prevent "nothing to do for... warnings from make"
.PHONY: quiet quiet-%
quiet quiet-%:
	@true

###############################################################################
# The exact revision of external repositories that HPHP builds against.

FBCODE_REV = 0c8b962b192eb655b7da1d9dcc1730427705c160
FBCODE_THIRD_PARTY_REV = 1b76b1fdef117650883ae1568fcf2777ad9a00c1

ifndef FBCODE_EXTERNALS_ROOT
FBCODE_EXTERNALS_ROOT = /mnt/gvfs/third-party/$(FBCODE_THIRD_PARTY_REV)
endif

ifndef FBCODE_HOME
export FBCODE_HOME=/mnt/gvfs/fbcode/$(FBCODE_REV)
endif

export FBCODE_BIN=$(LIB_DIR)/_fbcode_bin

###############################################################################
# Command line switches. For example, "make RELEASE=1".

V ?= @
NO_PRINT = $(if $(V),--no-print-directory,)
INFINITE_LOOP_DETECTION = 1
INFINITE_RECURSION_DETECTION = 1
REQUEST_TIMEOUT_DETECTION = 1

# This requires the patched libmysql
MYSQL_MILLISECOND_TIMEOUT = 1

-include $(wildcard $(PROJECT_ROOT)/local/*.mk)

# This normally generates debug symbols, but you may also use this in your
# code to output extra debugging information.
#DEBUG = 1
#DEBUG_MEMORY_LEAK = 1
#DEBUG_APC_LEAK = 1
#DEBUG_RACE_CONDITION = 1

ifdef VALGRIND

DEBUG_MEMORY_LEAK=1
NO_TCMALLOC=1

else

ifdef RELEASE
override DEBUG=
unexport DEBUG
override DEBUG_MEMORY_LEAK=
override DEBUG_RACE_CONDITION=
override RELEASE=1
endif

endif # VALGRIND

# Use jemalloc by default.
ifndef NO_JEMALLOC
USE_JEMALLOC = 1
endif

# This normally adds -O3 tag to generate the most optimized code targeted for
# production build.
ifndef DEBUG
RELEASE = 1
endif

ifndef DEBUG_MEMORY_LEAK
ifndef DEBUG_RACE_CONDITION

# For hotprofiler instrumentation
HOTPROFILER = 1

# Only use jemalloc *or* tcmalloc.
ifdef USE_JEMALLOC
override NO_TCMALLOC = 1
override GOOGLE_TCMALLOC =
endif # USE_JEMALLOC

ifndef NO_TCMALLOC
# For google profilers
#GOOGLE_CPU_PROFILER = 1
#GOOGLE_HEAP_PROFILER = 1

# Whether to link with tcmalloc.a
GOOGLE_TCMALLOC = 1
endif

# For GNU profiler - gprof.
#PROFILE = 1

# For GNU coverage - gcov.
#COVERAGE = 1

endif # DEBUG_RACE_CONDITION
endif # DEBUG_MEMORY_LEAK

ifndef NO_SNAPPY
HAVE_SNAPPY = 1
endif

###############################################################################
# Directories

ifdef USE_ICC
ifndef ICC
override USE_ICC:=
endif
endif

ifdef OUTDIR_BY_TYPE
ifndef OUTPUT_ROOT
OUTPUT_ROOT := bin
endif
OUT_EXTS := \
	$(if $(USE_HHVM),-hhvm) \
	$(if $(USE_HHVM_GC),-gc) \
	$(if $(USE_LLVM),-llvm) \
	$(if $(USE_ICC),-icc) \
	$(if $(USE_JEMALLOC),-je) \
	$(if $(NO_TCMALLOC),,-tc) \
	$(if $(PROFILE),-pg) \
	$(if $(CHECKED),-ck) \
	$(if $(VALGRIND),-vg) \
	$(if $(DEBUG),-g,-O)

EMPTY:=
SPACE:=$(EMPTY) $(EMPTY)
OUT_EXT := $(subst $(SPACE),,$(strip $(OUT_EXTS)))
endif

ABS_PROJECT_ROOT := $(shell cd $(PROJECT_ROOT) && readlink -f `pwd`)

ifdef OUTPUT_ROOT

OUT_DIRNAME := $(OUTPUT_ROOT)$(OUT_EXT)
OUTPUT_REL := $(patsubst /%,,$(patsubst ~%,,$(OUTPUT_ROOT)))

OUT_TOP := $(if $(OUTPUT_REL),$(ABS_PROJECT_ROOT)/)$(OUT_DIRNAME)
OUT_ABS := $(OUT_TOP)$(patsubst $(ABS_PROJECT_ROOT)%,%,$(CWD))
OUT_DIR := $(OUT_ABS)/

LIB_DIR := $(OUT_TOP)
HPHP_LIB := $(LIB_DIR)
OUT_TOP := $(OUT_TOP)/
HPHP := $(OUT_TOP)hphp
HHVM := $(OUT_TOP)hhvm
HPHP_OPTIONS := $(OUT_TOP)hphp_options

else

OUT_TOP :=
OUT_DIR :=
OUT_ABS := $(shell pwd)
LIB_DIR := $(ABS_PROJECT_ROOT)/bin
ifdef HPHP_LIB
ifneq ($(HPHP_LIB),$(HPHP_ROOT)/bin)
LIB_DIR := $(HPHP_LIB)
endif
endif
HPHP := $(PROJECT_ROOT)/src/hphp/hphp
HHVM := $(PROJECT_ROOT)/src/hhvm/hhvm
HPHP_OPTIONS := $(LIB_DIR)/hphp_options

endif

ifndef HPHP_LIB
HPHP_LIB := $(ABS_PROJECT_ROOT)/bin
endif

ifdef SHARED
# Clear USE_JEMALLOC, since it may have already been set by the parent make.
# Ideally we would actually undefine USE_JEMALLOC:
#   override undefine USE_JEMALLOC
# However, the undefine feature is only available in GNU make 3.82 and later.
override USE_JEMALLOC =
override GOOGLE_TCMALLOC =
endif

MKDIR = mkdir -p
RMDIR = rm -fR
EXT_DIR = /home/engshare/externals/cpp/hphp/$(OS)

%/.mkdir :
	$(V)-$(MKDIR) $(@D)
	$(V)touch $@

dirinfo:
	@echo $(ABS_PROJECT_ROOT) $(OUT_TOP) \
$(if $(VALGRIND),VG-)$(if $(USE_HHVM),VM)\
$(if $(USE_HHVM_GC),GC)$(if $(PROFILE),P)$(if $(DEBUG),D,R)\
$(if $(CHECKED),C)$(if $(USE_ICC),-I)$(if $(USE_LLVM),-L)\

endif
