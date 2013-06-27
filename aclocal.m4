# generated automatically by aclocal 1.11.6 -*- Autoconf -*-

# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
# 2005, 2006, 2007, 2008, 2009, 2010, 2011 Free Software Foundation,
# Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

m4_ifndef([AC_AUTOCONF_VERSION],
  [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
m4_if(m4_defn([AC_AUTOCONF_VERSION]), [2.69],,
[m4_warning([this file was generated for autoconf 2.69.
You have another version of autoconf.  It may work, but is not guaranteed to.
If you have problems, you may need to regenerate the build system entirely.
To do so, use the procedure documented by the package, typically `autoreconf'.])])

# Copyright (C) 2002, 2003, 2005, 2006, 2007, 2008, 2011 Free Software
# Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 1

# AM_AUTOMAKE_VERSION(VERSION)
# ----------------------------
# Automake X.Y traces this macro to ensure aclocal.m4 has been
# generated from the m4 files accompanying Automake X.Y.
# (This private macro should not be called outside this file.)
AC_DEFUN([AM_AUTOMAKE_VERSION],
[am__api_version='1.11'
dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
dnl require some minimum version.  Point them to the right macro.
m4_if([$1], [1.11.6], [],
      [AC_FATAL([Do not call $0, use AM_INIT_AUTOMAKE([$1]).])])dnl
])

# _AM_AUTOCONF_VERSION(VERSION)
# -----------------------------
# aclocal traces this macro to find the Autoconf version.
# This is a private macro too.  Using m4_define simplifies
# the logic in aclocal, which can simply ignore this definition.
m4_define([_AM_AUTOCONF_VERSION], [])

# AM_SET_CURRENT_AUTOMAKE_VERSION
# -------------------------------
# Call AM_AUTOMAKE_VERSION and AM_AUTOMAKE_VERSION so they can be traced.
# This function is AC_REQUIREd by AM_INIT_AUTOMAKE.
AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
[AM_AUTOMAKE_VERSION([1.11.6])dnl
m4_ifndef([AC_AUTOCONF_VERSION],
  [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
_AM_AUTOCONF_VERSION(m4_defn([AC_AUTOCONF_VERSION]))])

# Figure out how to run the assembler.                      -*- Autoconf -*-

# Copyright (C) 2001, 2003, 2004, 2005, 2006  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 5

# AM_PROG_AS
# ----------
AC_DEFUN([AM_PROG_AS],
[# By default we simply use the C compiler to build assembly code.
AC_REQUIRE([AC_PROG_CC])
test "${CCAS+set}" = set || CCAS=$CC
test "${CCASFLAGS+set}" = set || CCASFLAGS=$CFLAGS
AC_ARG_VAR([CCAS],      [assembler compiler command (defaults to CC)])
AC_ARG_VAR([CCASFLAGS], [assembler compiler flags (defaults to CFLAGS)])
_AM_IF_OPTION([no-dependencies],, [_AM_DEPENDENCIES([CCAS])])dnl
])

# AM_AUX_DIR_EXPAND                                         -*- Autoconf -*-

# Copyright (C) 2001, 2003, 2005, 2011 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 1

# For projects using AC_CONFIG_AUX_DIR([foo]), Autoconf sets
# $ac_aux_dir to `$srcdir/foo'.  In other projects, it is set to
# `$srcdir', `$srcdir/..', or `$srcdir/../..'.
#
# Of course, Automake must honor this variable whenever it calls a
# tool from the auxiliary directory.  The problem is that $srcdir (and
# therefore $ac_aux_dir as well) can be either absolute or relative,
# depending on how configure is run.  This is pretty annoying, since
# it makes $ac_aux_dir quite unusable in subdirectories: in the top
# source directory, any form will work fine, but in subdirectories a
# relative path needs to be adjusted first.
#
# $ac_aux_dir/missing
#    fails when called from a subdirectory if $ac_aux_dir is relative
# $top_srcdir/$ac_aux_dir/missing
#    fails if $ac_aux_dir is absolute,
#    fails when called from a subdirectory in a VPATH build with
#          a relative $ac_aux_dir
#
# The reason of the latter failure is that $top_srcdir and $ac_aux_dir
# are both prefixed by $srcdir.  In an in-source build this is usually
# harmless because $srcdir is `.', but things will broke when you
# start a VPATH build or use an absolute $srcdir.
#
# So we could use something similar to $top_srcdir/$ac_aux_dir/missing,
# iff we strip the leading $srcdir from $ac_aux_dir.  That would be:
#   am_aux_dir='\$(top_srcdir)/'`expr "$ac_aux_dir" : "$srcdir//*\(.*\)"`
# and then we would define $MISSING as
#   MISSING="\${SHELL} $am_aux_dir/missing"
# This will work as long as MISSING is not called from configure, because
# unfortunately $(top_srcdir) has no meaning in configure.
# However there are other variables, like CC, which are often used in
# configure, and could therefore not use this "fixed" $ac_aux_dir.
#
# Another solution, used here, is to always expand $ac_aux_dir to an
# absolute PATH.  The drawback is that using absolute paths prevent a
# configured tree to be moved without reconfiguration.

AC_DEFUN([AM_AUX_DIR_EXPAND],
[dnl Rely on autoconf to set up CDPATH properly.
AC_PREREQ([2.50])dnl
# expand $ac_aux_dir to an absolute path
am_aux_dir=`cd $ac_aux_dir && pwd`
])

# AM_CONDITIONAL                                            -*- Autoconf -*-

# Copyright (C) 1997, 2000, 2001, 2003, 2004, 2005, 2006, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 9

# AM_CONDITIONAL(NAME, SHELL-CONDITION)
# -------------------------------------
# Define a conditional.
AC_DEFUN([AM_CONDITIONAL],
[AC_PREREQ(2.52)dnl
 ifelse([$1], [TRUE],  [AC_FATAL([$0: invalid condition: $1])],
	[$1], [FALSE], [AC_FATAL([$0: invalid condition: $1])])dnl
AC_SUBST([$1_TRUE])dnl
AC_SUBST([$1_FALSE])dnl
_AM_SUBST_NOTMAKE([$1_TRUE])dnl
_AM_SUBST_NOTMAKE([$1_FALSE])dnl
m4_define([_AM_COND_VALUE_$1], [$2])dnl
if $2; then
  $1_TRUE=
  $1_FALSE='#'
else
  $1_TRUE='#'
  $1_FALSE=
fi
AC_CONFIG_COMMANDS_PRE(
[if test -z "${$1_TRUE}" && test -z "${$1_FALSE}"; then
  AC_MSG_ERROR([[conditional "$1" was never defined.
Usually this means the macro was only invoked conditionally.]])
fi])])

# Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2009,
# 2010, 2011 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 12

# There are a few dirty hacks below to avoid letting `AC_PROG_CC' be
# written in clear, in which case automake, when reading aclocal.m4,
# will think it sees a *use*, and therefore will trigger all it's
# C support machinery.  Also note that it means that autoscan, seeing
# CC etc. in the Makefile, will ask for an AC_PROG_CC use...


# _AM_DEPENDENCIES(NAME)
# ----------------------
# See how the compiler implements dependency checking.
# NAME is "CC", "CXX", "GCJ", or "OBJC".
# We try a few techniques and use that to set a single cache variable.
#
# We don't AC_REQUIRE the corresponding AC_PROG_CC since the latter was
# modified to invoke _AM_DEPENDENCIES(CC); we would have a circular
# dependency, and given that the user is not expected to run this macro,
# just rely on AC_PROG_CC.
AC_DEFUN([_AM_DEPENDENCIES],
[AC_REQUIRE([AM_SET_DEPDIR])dnl
AC_REQUIRE([AM_OUTPUT_DEPENDENCY_COMMANDS])dnl
AC_REQUIRE([AM_MAKE_INCLUDE])dnl
AC_REQUIRE([AM_DEP_TRACK])dnl

ifelse([$1], CC,   [depcc="$CC"   am_compiler_list=],
       [$1], CXX,  [depcc="$CXX"  am_compiler_list=],
       [$1], OBJC, [depcc="$OBJC" am_compiler_list='gcc3 gcc'],
       [$1], UPC,  [depcc="$UPC"  am_compiler_list=],
       [$1], GCJ,  [depcc="$GCJ"  am_compiler_list='gcc3 gcc'],
                   [depcc="$$1"   am_compiler_list=])

AC_CACHE_CHECK([dependency style of $depcc],
               [am_cv_$1_dependencies_compiler_type],
[if test -z "$AMDEP_TRUE" && test -f "$am_depcomp"; then
  # We make a subdir and do the tests there.  Otherwise we can end up
  # making bogus files that we don't know about and never remove.  For
  # instance it was reported that on HP-UX the gcc test will end up
  # making a dummy file named `D' -- because `-MD' means `put the output
  # in D'.
  rm -rf conftest.dir
  mkdir conftest.dir
  # Copy depcomp to subdir because otherwise we won't find it if we're
  # using a relative directory.
  cp "$am_depcomp" conftest.dir
  cd conftest.dir
  # We will build objects and dependencies in a subdirectory because
  # it helps to detect inapplicable dependency modes.  For instance
  # both Tru64's cc and ICC support -MD to output dependencies as a
  # side effect of compilation, but ICC will put the dependencies in
  # the current directory while Tru64 will put them in the object
  # directory.
  mkdir sub

  am_cv_$1_dependencies_compiler_type=none
  if test "$am_compiler_list" = ""; then
     am_compiler_list=`sed -n ['s/^#*\([a-zA-Z0-9]*\))$/\1/p'] < ./depcomp`
  fi
  am__universal=false
  m4_case([$1], [CC],
    [case " $depcc " in #(
     *\ -arch\ *\ -arch\ *) am__universal=true ;;
     esac],
    [CXX],
    [case " $depcc " in #(
     *\ -arch\ *\ -arch\ *) am__universal=true ;;
     esac])

  for depmode in $am_compiler_list; do
    # Setup a source with many dependencies, because some compilers
    # like to wrap large dependency lists on column 80 (with \), and
    # we should not choose a depcomp mode which is confused by this.
    #
    # We need to recreate these files for each test, as the compiler may
    # overwrite some of them when testing with obscure command lines.
    # This happens at least with the AIX C compiler.
    : > sub/conftest.c
    for i in 1 2 3 4 5 6; do
      echo '#include "conftst'$i'.h"' >> sub/conftest.c
      # Using `: > sub/conftst$i.h' creates only sub/conftst1.h with
      # Solaris 8's {/usr,}/bin/sh.
      touch sub/conftst$i.h
    done
    echo "${am__include} ${am__quote}sub/conftest.Po${am__quote}" > confmf

    # We check with `-c' and `-o' for the sake of the "dashmstdout"
    # mode.  It turns out that the SunPro C++ compiler does not properly
    # handle `-M -o', and we need to detect this.  Also, some Intel
    # versions had trouble with output in subdirs
    am__obj=sub/conftest.${OBJEXT-o}
    am__minus_obj="-o $am__obj"
    case $depmode in
    gcc)
      # This depmode causes a compiler race in universal mode.
      test "$am__universal" = false || continue
      ;;
    nosideeffect)
      # after this tag, mechanisms are not by side-effect, so they'll
      # only be used when explicitly requested
      if test "x$enable_dependency_tracking" = xyes; then
	continue
      else
	break
      fi
      ;;
    msvc7 | msvc7msys | msvisualcpp | msvcmsys)
      # This compiler won't grok `-c -o', but also, the minuso test has
      # not run yet.  These depmodes are late enough in the game, and
      # so weak that their functioning should not be impacted.
      am__obj=conftest.${OBJEXT-o}
      am__minus_obj=
      ;;
    none) break ;;
    esac
    if depmode=$depmode \
       source=sub/conftest.c object=$am__obj \
       depfile=sub/conftest.Po tmpdepfile=sub/conftest.TPo \
       $SHELL ./depcomp $depcc -c $am__minus_obj sub/conftest.c \
         >/dev/null 2>conftest.err &&
       grep sub/conftst1.h sub/conftest.Po > /dev/null 2>&1 &&
       grep sub/conftst6.h sub/conftest.Po > /dev/null 2>&1 &&
       grep $am__obj sub/conftest.Po > /dev/null 2>&1 &&
       ${MAKE-make} -s -f confmf > /dev/null 2>&1; then
      # icc doesn't choke on unknown options, it will just issue warnings
      # or remarks (even with -Werror).  So we grep stderr for any message
      # that says an option was ignored or not supported.
      # When given -MP, icc 7.0 and 7.1 complain thusly:
      #   icc: Command line warning: ignoring option '-M'; no argument required
      # The diagnosis changed in icc 8.0:
      #   icc: Command line remark: option '-MP' not supported
      if (grep 'ignoring option' conftest.err ||
          grep 'not supported' conftest.err) >/dev/null 2>&1; then :; else
        am_cv_$1_dependencies_compiler_type=$depmode
        break
      fi
    fi
  done

  cd ..
  rm -rf conftest.dir
else
  am_cv_$1_dependencies_compiler_type=none
fi
])
AC_SUBST([$1DEPMODE], [depmode=$am_cv_$1_dependencies_compiler_type])
AM_CONDITIONAL([am__fastdep$1], [
  test "x$enable_dependency_tracking" != xno \
  && test "$am_cv_$1_dependencies_compiler_type" = gcc3])
])


# AM_SET_DEPDIR
# -------------
# Choose a directory name for dependency files.
# This macro is AC_REQUIREd in _AM_DEPENDENCIES
AC_DEFUN([AM_SET_DEPDIR],
[AC_REQUIRE([AM_SET_LEADING_DOT])dnl
AC_SUBST([DEPDIR], ["${am__leading_dot}deps"])dnl
])


# AM_DEP_TRACK
# ------------
AC_DEFUN([AM_DEP_TRACK],
[AC_ARG_ENABLE(dependency-tracking,
[  --disable-dependency-tracking  speeds up one-time build
  --enable-dependency-tracking   do not reject slow dependency extractors])
if test "x$enable_dependency_tracking" != xno; then
  am_depcomp="$ac_aux_dir/depcomp"
  AMDEPBACKSLASH='\'
  am__nodep='_no'
fi
AM_CONDITIONAL([AMDEP], [test "x$enable_dependency_tracking" != xno])
AC_SUBST([AMDEPBACKSLASH])dnl
_AM_SUBST_NOTMAKE([AMDEPBACKSLASH])dnl
AC_SUBST([am__nodep])dnl
_AM_SUBST_NOTMAKE([am__nodep])dnl
])

# Generate code to set up dependency tracking.              -*- Autoconf -*-

# Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

#serial 5

# _AM_OUTPUT_DEPENDENCY_COMMANDS
# ------------------------------
AC_DEFUN([_AM_OUTPUT_DEPENDENCY_COMMANDS],
[{
  # Autoconf 2.62 quotes --file arguments for eval, but not when files
  # are listed without --file.  Let's play safe and only enable the eval
  # if we detect the quoting.
  case $CONFIG_FILES in
  *\'*) eval set x "$CONFIG_FILES" ;;
  *)   set x $CONFIG_FILES ;;
  esac
  shift
  for mf
  do
    # Strip MF so we end up with the name of the file.
    mf=`echo "$mf" | sed -e 's/:.*$//'`
    # Check whether this is an Automake generated Makefile or not.
    # We used to match only the files named `Makefile.in', but
    # some people rename them; so instead we look at the file content.
    # Grep'ing the first line is not enough: some people post-process
    # each Makefile.in and add a new line on top of each file to say so.
    # Grep'ing the whole file is not good either: AIX grep has a line
    # limit of 2048, but all sed's we know have understand at least 4000.
    if sed -n 's,^#.*generated by automake.*,X,p' "$mf" | grep X >/dev/null 2>&1; then
      dirpart=`AS_DIRNAME("$mf")`
    else
      continue
    fi
    # Extract the definition of DEPDIR, am__include, and am__quote
    # from the Makefile without running `make'.
    DEPDIR=`sed -n 's/^DEPDIR = //p' < "$mf"`
    test -z "$DEPDIR" && continue
    am__include=`sed -n 's/^am__include = //p' < "$mf"`
    test -z "am__include" && continue
    am__quote=`sed -n 's/^am__quote = //p' < "$mf"`
    # When using ansi2knr, U may be empty or an underscore; expand it
    U=`sed -n 's/^U = //p' < "$mf"`
    # Find all dependency output files, they are included files with
    # $(DEPDIR) in their names.  We invoke sed twice because it is the
    # simplest approach to changing $(DEPDIR) to its actual value in the
    # expansion.
    for file in `sed -n "
      s/^$am__include $am__quote\(.*(DEPDIR).*\)$am__quote"'$/\1/p' <"$mf" | \
	 sed -e 's/\$(DEPDIR)/'"$DEPDIR"'/g' -e 's/\$U/'"$U"'/g'`; do
      # Make sure the directory exists.
      test -f "$dirpart/$file" && continue
      fdir=`AS_DIRNAME(["$file"])`
      AS_MKDIR_P([$dirpart/$fdir])
      # echo "creating $dirpart/$file"
      echo '# dummy' > "$dirpart/$file"
    done
  done
}
])# _AM_OUTPUT_DEPENDENCY_COMMANDS


# AM_OUTPUT_DEPENDENCY_COMMANDS
# -----------------------------
# This macro should only be invoked once -- use via AC_REQUIRE.
#
# This code is only required when automatic dependency tracking
# is enabled.  FIXME.  This creates each `.P' file that we will
# need in order to bootstrap the dependency handling code.
AC_DEFUN([AM_OUTPUT_DEPENDENCY_COMMANDS],
[AC_CONFIG_COMMANDS([depfiles],
     [test x"$AMDEP_TRUE" != x"" || _AM_OUTPUT_DEPENDENCY_COMMANDS],
     [AMDEP_TRUE="$AMDEP_TRUE" ac_aux_dir="$ac_aux_dir"])
])

# Copyright (C) 1996, 1997, 2000, 2001, 2003, 2005
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 8

# AM_CONFIG_HEADER is obsolete.  It has been replaced by AC_CONFIG_HEADERS.
AU_DEFUN([AM_CONFIG_HEADER], [AC_CONFIG_HEADERS($@)])

# Do all the work for Automake.                             -*- Autoconf -*-

# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
# 2005, 2006, 2008, 2009 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 16

# This macro actually does too much.  Some checks are only needed if
# your package does certain things.  But this isn't really a big deal.

# AM_INIT_AUTOMAKE(PACKAGE, VERSION, [NO-DEFINE])
# AM_INIT_AUTOMAKE([OPTIONS])
# -----------------------------------------------
# The call with PACKAGE and VERSION arguments is the old style
# call (pre autoconf-2.50), which is being phased out.  PACKAGE
# and VERSION should now be passed to AC_INIT and removed from
# the call to AM_INIT_AUTOMAKE.
# We support both call styles for the transition.  After
# the next Automake release, Autoconf can make the AC_INIT
# arguments mandatory, and then we can depend on a new Autoconf
# release and drop the old call support.
AC_DEFUN([AM_INIT_AUTOMAKE],
[AC_PREREQ([2.62])dnl
dnl Autoconf wants to disallow AM_ names.  We explicitly allow
dnl the ones we care about.
m4_pattern_allow([^AM_[A-Z]+FLAGS$])dnl
AC_REQUIRE([AM_SET_CURRENT_AUTOMAKE_VERSION])dnl
AC_REQUIRE([AC_PROG_INSTALL])dnl
if test "`cd $srcdir && pwd`" != "`pwd`"; then
  # Use -I$(srcdir) only when $(srcdir) != ., so that make's output
  # is not polluted with repeated "-I."
  AC_SUBST([am__isrc], [' -I$(srcdir)'])_AM_SUBST_NOTMAKE([am__isrc])dnl
  # test to see if srcdir already configured
  if test -f $srcdir/config.status; then
    AC_MSG_ERROR([source directory already configured; run "make distclean" there first])
  fi
fi

# test whether we have cygpath
if test -z "$CYGPATH_W"; then
  if (cygpath --version) >/dev/null 2>/dev/null; then
    CYGPATH_W='cygpath -w'
  else
    CYGPATH_W=echo
  fi
fi
AC_SUBST([CYGPATH_W])

# Define the identity of the package.
dnl Distinguish between old-style and new-style calls.
m4_ifval([$2],
[m4_ifval([$3], [_AM_SET_OPTION([no-define])])dnl
 AC_SUBST([PACKAGE], [$1])dnl
 AC_SUBST([VERSION], [$2])],
[_AM_SET_OPTIONS([$1])dnl
dnl Diagnose old-style AC_INIT with new-style AM_AUTOMAKE_INIT.
m4_if(m4_ifdef([AC_PACKAGE_NAME], 1)m4_ifdef([AC_PACKAGE_VERSION], 1), 11,,
  [m4_fatal([AC_INIT should be called with package and version arguments])])dnl
 AC_SUBST([PACKAGE], ['AC_PACKAGE_TARNAME'])dnl
 AC_SUBST([VERSION], ['AC_PACKAGE_VERSION'])])dnl

_AM_IF_OPTION([no-define],,
[AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE", [Name of package])
 AC_DEFINE_UNQUOTED(VERSION, "$VERSION", [Version number of package])])dnl

# Some tools Automake needs.
AC_REQUIRE([AM_SANITY_CHECK])dnl
AC_REQUIRE([AC_ARG_PROGRAM])dnl
AM_MISSING_PROG(ACLOCAL, aclocal-${am__api_version})
AM_MISSING_PROG(AUTOCONF, autoconf)
AM_MISSING_PROG(AUTOMAKE, automake-${am__api_version})
AM_MISSING_PROG(AUTOHEADER, autoheader)
AM_MISSING_PROG(MAKEINFO, makeinfo)
AC_REQUIRE([AM_PROG_INSTALL_SH])dnl
AC_REQUIRE([AM_PROG_INSTALL_STRIP])dnl
AC_REQUIRE([AM_PROG_MKDIR_P])dnl
# We need awk for the "check" target.  The system "awk" is bad on
# some platforms.
AC_REQUIRE([AC_PROG_AWK])dnl
AC_REQUIRE([AC_PROG_MAKE_SET])dnl
AC_REQUIRE([AM_SET_LEADING_DOT])dnl
_AM_IF_OPTION([tar-ustar], [_AM_PROG_TAR([ustar])],
	      [_AM_IF_OPTION([tar-pax], [_AM_PROG_TAR([pax])],
			     [_AM_PROG_TAR([v7])])])
_AM_IF_OPTION([no-dependencies],,
[AC_PROVIDE_IFELSE([AC_PROG_CC],
		  [_AM_DEPENDENCIES(CC)],
		  [define([AC_PROG_CC],
			  defn([AC_PROG_CC])[_AM_DEPENDENCIES(CC)])])dnl
AC_PROVIDE_IFELSE([AC_PROG_CXX],
		  [_AM_DEPENDENCIES(CXX)],
		  [define([AC_PROG_CXX],
			  defn([AC_PROG_CXX])[_AM_DEPENDENCIES(CXX)])])dnl
AC_PROVIDE_IFELSE([AC_PROG_OBJC],
		  [_AM_DEPENDENCIES(OBJC)],
		  [define([AC_PROG_OBJC],
			  defn([AC_PROG_OBJC])[_AM_DEPENDENCIES(OBJC)])])dnl
])
_AM_IF_OPTION([silent-rules], [AC_REQUIRE([AM_SILENT_RULES])])dnl
dnl The `parallel-tests' driver may need to know about EXEEXT, so add the
dnl `am__EXEEXT' conditional if _AM_COMPILER_EXEEXT was seen.  This macro
dnl is hooked onto _AC_COMPILER_EXEEXT early, see below.
AC_CONFIG_COMMANDS_PRE(dnl
[m4_provide_if([_AM_COMPILER_EXEEXT],
  [AM_CONDITIONAL([am__EXEEXT], [test -n "$EXEEXT"])])])dnl
])

dnl Hook into `_AC_COMPILER_EXEEXT' early to learn its expansion.  Do not
dnl add the conditional right here, as _AC_COMPILER_EXEEXT may be further
dnl mangled by Autoconf and run in a shell conditional statement.
m4_define([_AC_COMPILER_EXEEXT],
m4_defn([_AC_COMPILER_EXEEXT])[m4_provide([_AM_COMPILER_EXEEXT])])


# When config.status generates a header, we must update the stamp-h file.
# This file resides in the same directory as the config header
# that is generated.  The stamp files are numbered to have different names.

# Autoconf calls _AC_AM_CONFIG_HEADER_HOOK (when defined) in the
# loop where config.status creates the headers, so we can generate
# our stamp files there.
AC_DEFUN([_AC_AM_CONFIG_HEADER_HOOK],
[# Compute $1's index in $config_headers.
_am_arg=$1
_am_stamp_count=1
for _am_header in $config_headers :; do
  case $_am_header in
    $_am_arg | $_am_arg:* )
      break ;;
    * )
      _am_stamp_count=`expr $_am_stamp_count + 1` ;;
  esac
done
echo "timestamp for $_am_arg" >`AS_DIRNAME(["$_am_arg"])`/stamp-h[]$_am_stamp_count])

# Copyright (C) 2001, 2003, 2005, 2008, 2011 Free Software Foundation,
# Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 1

# AM_PROG_INSTALL_SH
# ------------------
# Define $install_sh.
AC_DEFUN([AM_PROG_INSTALL_SH],
[AC_REQUIRE([AM_AUX_DIR_EXPAND])dnl
if test x"${install_sh}" != xset; then
  case $am_aux_dir in
  *\ * | *\	*)
    install_sh="\${SHELL} '$am_aux_dir/install-sh'" ;;
  *)
    install_sh="\${SHELL} $am_aux_dir/install-sh"
  esac
fi
AC_SUBST(install_sh)])

# Copyright (C) 2003, 2005  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 2

# Check whether the underlying file-system supports filenames
# with a leading dot.  For instance MS-DOS doesn't.
AC_DEFUN([AM_SET_LEADING_DOT],
[rm -rf .tst 2>/dev/null
mkdir .tst 2>/dev/null
if test -d .tst; then
  am__leading_dot=.
else
  am__leading_dot=_
fi
rmdir .tst 2>/dev/null
AC_SUBST([am__leading_dot])])

# Add --enable-maintainer-mode option to configure.         -*- Autoconf -*-
# From Jim Meyering

# Copyright (C) 1996, 1998, 2000, 2001, 2002, 2003, 2004, 2005, 2008,
# 2011 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 5

# AM_MAINTAINER_MODE([DEFAULT-MODE])
# ----------------------------------
# Control maintainer-specific portions of Makefiles.
# Default is to disable them, unless `enable' is passed literally.
# For symmetry, `disable' may be passed as well.  Anyway, the user
# can override the default with the --enable/--disable switch.
AC_DEFUN([AM_MAINTAINER_MODE],
[m4_case(m4_default([$1], [disable]),
       [enable], [m4_define([am_maintainer_other], [disable])],
       [disable], [m4_define([am_maintainer_other], [enable])],
       [m4_define([am_maintainer_other], [enable])
        m4_warn([syntax], [unexpected argument to AM@&t@_MAINTAINER_MODE: $1])])
AC_MSG_CHECKING([whether to enable maintainer-specific portions of Makefiles])
  dnl maintainer-mode's default is 'disable' unless 'enable' is passed
  AC_ARG_ENABLE([maintainer-mode],
[  --][am_maintainer_other][-maintainer-mode  am_maintainer_other make rules and dependencies not useful
			  (and sometimes confusing) to the casual installer],
      [USE_MAINTAINER_MODE=$enableval],
      [USE_MAINTAINER_MODE=]m4_if(am_maintainer_other, [enable], [no], [yes]))
  AC_MSG_RESULT([$USE_MAINTAINER_MODE])
  AM_CONDITIONAL([MAINTAINER_MODE], [test $USE_MAINTAINER_MODE = yes])
  MAINT=$MAINTAINER_MODE_TRUE
  AC_SUBST([MAINT])dnl
]
)

AU_DEFUN([jm_MAINTAINER_MODE], [AM_MAINTAINER_MODE])

# Check to see how 'make' treats includes.	            -*- Autoconf -*-

# Copyright (C) 2001, 2002, 2003, 2005, 2009  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 4

# AM_MAKE_INCLUDE()
# -----------------
# Check to see how make treats includes.
AC_DEFUN([AM_MAKE_INCLUDE],
[am_make=${MAKE-make}
cat > confinc << 'END'
am__doit:
	@echo this is the am__doit target
.PHONY: am__doit
END
# If we don't find an include directive, just comment out the code.
AC_MSG_CHECKING([for style of include used by $am_make])
am__include="#"
am__quote=
_am_result=none
# First try GNU make style include.
echo "include confinc" > confmf
# Ignore all kinds of additional output from `make'.
case `$am_make -s -f confmf 2> /dev/null` in #(
*the\ am__doit\ target*)
  am__include=include
  am__quote=
  _am_result=GNU
  ;;
esac
# Now try BSD make style include.
if test "$am__include" = "#"; then
   echo '.include "confinc"' > confmf
   case `$am_make -s -f confmf 2> /dev/null` in #(
   *the\ am__doit\ target*)
     am__include=.include
     am__quote="\""
     _am_result=BSD
     ;;
   esac
fi
AC_SUBST([am__include])
AC_SUBST([am__quote])
AC_MSG_RESULT([$_am_result])
rm -f confinc confmf
])

# Fake the existence of programs that GNU maintainers use.  -*- Autoconf -*-

# Copyright (C) 1997, 1999, 2000, 2001, 2003, 2004, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 6

# AM_MISSING_PROG(NAME, PROGRAM)
# ------------------------------
AC_DEFUN([AM_MISSING_PROG],
[AC_REQUIRE([AM_MISSING_HAS_RUN])
$1=${$1-"${am_missing_run}$2"}
AC_SUBST($1)])


# AM_MISSING_HAS_RUN
# ------------------
# Define MISSING if not defined so far and test if it supports --run.
# If it does, set am_missing_run to use it, otherwise, to nothing.
AC_DEFUN([AM_MISSING_HAS_RUN],
[AC_REQUIRE([AM_AUX_DIR_EXPAND])dnl
AC_REQUIRE_AUX_FILE([missing])dnl
if test x"${MISSING+set}" != xset; then
  case $am_aux_dir in
  *\ * | *\	*)
    MISSING="\${SHELL} \"$am_aux_dir/missing\"" ;;
  *)
    MISSING="\${SHELL} $am_aux_dir/missing" ;;
  esac
fi
# Use eval to expand $SHELL
if eval "$MISSING --run true"; then
  am_missing_run="$MISSING --run "
else
  am_missing_run=
  AC_MSG_WARN([`missing' script is too old or missing])
fi
])

# Copyright (C) 2003, 2004, 2005, 2006, 2011 Free Software Foundation,
# Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 1

# AM_PROG_MKDIR_P
# ---------------
# Check for `mkdir -p'.
AC_DEFUN([AM_PROG_MKDIR_P],
[AC_PREREQ([2.60])dnl
AC_REQUIRE([AC_PROG_MKDIR_P])dnl
dnl Automake 1.8 to 1.9.6 used to define mkdir_p.  We now use MKDIR_P,
dnl while keeping a definition of mkdir_p for backward compatibility.
dnl @MKDIR_P@ is magic: AC_OUTPUT adjusts its value for each Makefile.
dnl However we cannot define mkdir_p as $(MKDIR_P) for the sake of
dnl Makefile.ins that do not define MKDIR_P, so we do our own
dnl adjustment using top_builddir (which is defined more often than
dnl MKDIR_P).
AC_SUBST([mkdir_p], ["$MKDIR_P"])dnl
case $mkdir_p in
  [[\\/$]]* | ?:[[\\/]]*) ;;
  */*) mkdir_p="\$(top_builddir)/$mkdir_p" ;;
esac
])

# Helper functions for option handling.                     -*- Autoconf -*-

# Copyright (C) 2001, 2002, 2003, 2005, 2008, 2010 Free Software
# Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 5

# _AM_MANGLE_OPTION(NAME)
# -----------------------
AC_DEFUN([_AM_MANGLE_OPTION],
[[_AM_OPTION_]m4_bpatsubst($1, [[^a-zA-Z0-9_]], [_])])

# _AM_SET_OPTION(NAME)
# --------------------
# Set option NAME.  Presently that only means defining a flag for this option.
AC_DEFUN([_AM_SET_OPTION],
[m4_define(_AM_MANGLE_OPTION([$1]), 1)])

# _AM_SET_OPTIONS(OPTIONS)
# ------------------------
# OPTIONS is a space-separated list of Automake options.
AC_DEFUN([_AM_SET_OPTIONS],
[m4_foreach_w([_AM_Option], [$1], [_AM_SET_OPTION(_AM_Option)])])

# _AM_IF_OPTION(OPTION, IF-SET, [IF-NOT-SET])
# -------------------------------------------
# Execute IF-SET if OPTION is set, IF-NOT-SET otherwise.
AC_DEFUN([_AM_IF_OPTION],
[m4_ifset(_AM_MANGLE_OPTION([$1]), [$2], [$3])])

# Check to make sure that the build environment is sane.    -*- Autoconf -*-

# Copyright (C) 1996, 1997, 2000, 2001, 2003, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 5

# AM_SANITY_CHECK
# ---------------
AC_DEFUN([AM_SANITY_CHECK],
[AC_MSG_CHECKING([whether build environment is sane])
# Just in case
sleep 1
echo timestamp > conftest.file
# Reject unsafe characters in $srcdir or the absolute working directory
# name.  Accept space and tab only in the latter.
am_lf='
'
case `pwd` in
  *[[\\\"\#\$\&\'\`$am_lf]]*)
    AC_MSG_ERROR([unsafe absolute working directory name]);;
esac
case $srcdir in
  *[[\\\"\#\$\&\'\`$am_lf\ \	]]*)
    AC_MSG_ERROR([unsafe srcdir value: `$srcdir']);;
esac

# Do `set' in a subshell so we don't clobber the current shell's
# arguments.  Must try -L first in case configure is actually a
# symlink; some systems play weird games with the mod time of symlinks
# (eg FreeBSD returns the mod time of the symlink's containing
# directory).
if (
   set X `ls -Lt "$srcdir/configure" conftest.file 2> /dev/null`
   if test "$[*]" = "X"; then
      # -L didn't work.
      set X `ls -t "$srcdir/configure" conftest.file`
   fi
   rm -f conftest.file
   if test "$[*]" != "X $srcdir/configure conftest.file" \
      && test "$[*]" != "X conftest.file $srcdir/configure"; then

      # If neither matched, then we have a broken ls.  This can happen
      # if, for instance, CONFIG_SHELL is bash and it inherits a
      # broken ls alias from the environment.  This has actually
      # happened.  Such a system could not be considered "sane".
      AC_MSG_ERROR([ls -t appears to fail.  Make sure there is not a broken
alias in your environment])
   fi

   test "$[2]" = conftest.file
   )
then
   # Ok.
   :
else
   AC_MSG_ERROR([newly created file is older than distributed files!
Check your system clock])
fi
AC_MSG_RESULT(yes)])

# Copyright (C) 2001, 2003, 2005, 2011 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 1

# AM_PROG_INSTALL_STRIP
# ---------------------
# One issue with vendor `install' (even GNU) is that you can't
# specify the program used to strip binaries.  This is especially
# annoying in cross-compiling environments, where the build's strip
# is unlikely to handle the host's binaries.
# Fortunately install-sh will honor a STRIPPROG variable, so we
# always use install-sh in `make install-strip', and initialize
# STRIPPROG with the value of the STRIP variable (set by the user).
AC_DEFUN([AM_PROG_INSTALL_STRIP],
[AC_REQUIRE([AM_PROG_INSTALL_SH])dnl
# Installed binaries are usually stripped using `strip' when the user
# run `make install-strip'.  However `strip' might not be the right
# tool to use in cross-compilation environments, therefore Automake
# will honor the `STRIP' environment variable to overrule this program.
dnl Don't test for $cross_compiling = yes, because it might be `maybe'.
if test "$cross_compiling" != no; then
  AC_CHECK_TOOL([STRIP], [strip], :)
fi
INSTALL_STRIP_PROGRAM="\$(install_sh) -c -s"
AC_SUBST([INSTALL_STRIP_PROGRAM])])

# Copyright (C) 2006, 2008, 2010 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 3

# _AM_SUBST_NOTMAKE(VARIABLE)
# ---------------------------
# Prevent Automake from outputting VARIABLE = @VARIABLE@ in Makefile.in.
# This macro is traced by Automake.
AC_DEFUN([_AM_SUBST_NOTMAKE])

# AM_SUBST_NOTMAKE(VARIABLE)
# --------------------------
# Public sister of _AM_SUBST_NOTMAKE.
AC_DEFUN([AM_SUBST_NOTMAKE], [_AM_SUBST_NOTMAKE($@)])

# Check how to create a tarball.                            -*- Autoconf -*-

# Copyright (C) 2004, 2005, 2012 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 2

# _AM_PROG_TAR(FORMAT)
# --------------------
# Check how to create a tarball in format FORMAT.
# FORMAT should be one of `v7', `ustar', or `pax'.
#
# Substitute a variable $(am__tar) that is a command
# writing to stdout a FORMAT-tarball containing the directory
# $tardir.
#     tardir=directory && $(am__tar) > result.tar
#
# Substitute a variable $(am__untar) that extract such
# a tarball read from stdin.
#     $(am__untar) < result.tar
AC_DEFUN([_AM_PROG_TAR],
[# Always define AMTAR for backward compatibility.  Yes, it's still used
# in the wild :-(  We should find a proper way to deprecate it ...
AC_SUBST([AMTAR], ['$${TAR-tar}'])
m4_if([$1], [v7],
     [am__tar='$${TAR-tar} chof - "$$tardir"' am__untar='$${TAR-tar} xf -'],
     [m4_case([$1], [ustar],, [pax],,
              [m4_fatal([Unknown tar format])])
AC_MSG_CHECKING([how to create a $1 tar archive])
# Loop over all known methods to create a tar archive until one works.
_am_tools='gnutar m4_if([$1], [ustar], [plaintar]) pax cpio none'
_am_tools=${am_cv_prog_tar_$1-$_am_tools}
# Do not fold the above two line into one, because Tru64 sh and
# Solaris sh will not grok spaces in the rhs of `-'.
for _am_tool in $_am_tools
do
  case $_am_tool in
  gnutar)
    for _am_tar in tar gnutar gtar;
    do
      AM_RUN_LOG([$_am_tar --version]) && break
    done
    am__tar="$_am_tar --format=m4_if([$1], [pax], [posix], [$1]) -chf - "'"$$tardir"'
    am__tar_="$_am_tar --format=m4_if([$1], [pax], [posix], [$1]) -chf - "'"$tardir"'
    am__untar="$_am_tar -xf -"
    ;;
  plaintar)
    # Must skip GNU tar: if it does not support --format= it doesn't create
    # ustar tarball either.
    (tar --version) >/dev/null 2>&1 && continue
    am__tar='tar chf - "$$tardir"'
    am__tar_='tar chf - "$tardir"'
    am__untar='tar xf -'
    ;;
  pax)
    am__tar='pax -L -x $1 -w "$$tardir"'
    am__tar_='pax -L -x $1 -w "$tardir"'
    am__untar='pax -r'
    ;;
  cpio)
    am__tar='find "$$tardir" -print | cpio -o -H $1 -L'
    am__tar_='find "$tardir" -print | cpio -o -H $1 -L'
    am__untar='cpio -i -H $1 -d'
    ;;
  none)
    am__tar=false
    am__tar_=false
    am__untar=false
    ;;
  esac

  # If the value was cached, stop now.  We just wanted to have am__tar
  # and am__untar set.
  test -n "${am_cv_prog_tar_$1}" && break

  # tar/untar a dummy directory, and stop if the command works
  rm -rf conftest.dir
  mkdir conftest.dir
  echo GrepMe > conftest.dir/file
  AM_RUN_LOG([tardir=conftest.dir && eval $am__tar_ >conftest.tar])
  rm -rf conftest.dir
  if test -s conftest.tar; then
    AM_RUN_LOG([$am__untar <conftest.tar])
    grep GrepMe conftest.dir/file >/dev/null 2>&1 && break
  fi
done
rm -rf conftest.dir

AC_CACHE_VAL([am_cv_prog_tar_$1], [am_cv_prog_tar_$1=$_am_tool])
AC_MSG_RESULT([$am_cv_prog_tar_$1])])
AC_SUBST([am__tar])
AC_SUBST([am__untar])
]) # _AM_PROG_TAR

# Automake-1.10's AM_ENABLE_MULTILIB is buggy - it
# does not properly preserve quoting when copying
# ac_configure_args to the 'config.status' it creates.
# I guess one level of quoting is removed when the
# copying happens (by means of a 'here'-document in
# AC_OUTPUT_COMMANDS).
#
# Note that we cannot use a different name since
# automake 'knows' about AM_ENABLE_MULTILIB and
# behaves differently if we would, e.g., name the
# modified macro 'MY_ENABLE_MULTILIB'.
# Hence we hope that we can override automake/aclocal's
# definition.
#
# Below (look at the 'sed' code) we replace all occurrences
# of '$' by '\$' so that 'config.status' again says '$'.
#
# This is important if we want to pass e.g.,
#
#   --exec-prefix='${prefix}/xxx'
#
# correctly to the multisubdir configurations.
#
# AM_ENABLE_MULTILIB([MAKEFILE], [REL-TO-TOP-SRCDIR])
# ---------------------------------------------------
# Add --enable-multilib to configure.
AC_DEFUN([AM_ENABLE_MULTILIB],
[# Default to --enable-multilib
AC_ARG_ENABLE(multilib,
[  --enable-multilib       build many library versions (default)],
[case "$enableval" in
  yes) multilib=yes ;;
  no)  multilib=no ;;
  *)   AC_MSG_ERROR([bad value $enableval for multilib option]) ;;
 esac],
	      [multilib=yes])

# We may get other options which we leave undocumented:
# --with-target-subdir, --with-multisrctop, --with-multisubdir
# See config-ml.in if you want the gory details.

if test "$srcdir" = "."; then
  if test "$with_target_subdir" != "."; then
    multi_basedir="$srcdir/$with_multisrctop../$2"
  else
    multi_basedir="$srcdir/$with_multisrctop$2"
  fi
else
  multi_basedir="$srcdir/$2"
fi
AC_SUBST(multi_basedir)

# Even if the default multilib is not a cross compilation,
# it may be that some of the other multilibs are.
if test $cross_compiling = no && test $multilib = yes \
   && test "x${with_multisubdir}" != x ; then
   cross_compiling=maybe
fi

AC_OUTPUT_COMMANDS([
# Only add multilib support code if we just rebuilt the top-level
# Makefile.
case " $CONFIG_FILES " in
 *" ]m4_default([$1],Makefile)[ "*)
   ac_file=]m4_default([$1],Makefile)[ . ${multi_basedir}/config-ml.in
   ;;
esac],
		   [
srcdir="$srcdir"
host="$host"
target="$target"
with_multisubdir="$with_multisubdir"
with_multisrctop="$with_multisrctop"
with_target_subdir="$with_target_subdir"
ac_configure_args="${multilib_arg} `echo ${ac_configure_args} | sed -e 's/[$]/\\\\$/g'`"
multi_basedir="$multi_basedir"
CONFIG_SHELL=${CONFIG_SHELL-/bin/sh}
CC="$CC"
CXX="$CXX"
F77="$F77"
GCJ="$GCJ"
GFORTRAN="$GFORTRAN"])])dnl

# TILLAM_MULTISUB_INSTALLDIR
#
# tweak 'libdir' so that libraries are
# installed in proper multisubdir.
#
# For use by 'sub-packages', i.e., from
# configure.ac in a subdir of a main
# package. Only the toplevel configure.ac
# should say AM_ENABLE_MULTILIB
#
AC_DEFUN([TILLAM_MULTISUB_INSTALLDIR],
[# Install multilib into proper multisubdir
if test "${with_multisubdir+set}" = "set" ; then
  the_multisubdir="/${with_multisubdir}"
else
  the_multisubdir=
fi
AC_SUBST(libdir,[${libdir}${the_multisubdir}])])dnl


])dnl

# Certain BSPs are just variants. This macro sets
# the RTEMS_BSP_CLASS variable to the name of a 'base' BSP.
# Note that this matches mostly what RTEMS_BSP_FAMILY used to
# be...
#
AC_DEFUN([TILLAC_RTEMS_BSP_CLASS],
	[case "${rtems_bsp}" in
		pc?86*)
			RTEMS_BSP_CLASS=pc386
		;;
		psim*)
			RTEMS_BSP_CLASS=psim
		;;
		mcp750|mvme2100|mvme2307|mtx603e)
			RTEMS_BSP_CLASS=motorola_powerpc
		;;
		*)
			RTEMS_BSP_CLASS="${rtems_bsp}"
		;;
	esac
	AC_SUBST([RTEMS_BSP_CLASS])]dnl
)

# Assemble a list of BSPs in 'enable_rtemsbsp'
#
#  a) if 'enable_rtemsbsp' is not set when this macro is expanded
#     then set it to a (whitespace separated) list of all
#     BSPs found under ${with_rtems_top}/${host_cpu}-${host_os}/
#  b) if 'enable_rtemsbsp' is already set then remove all BSPs
#     from it which are not installed under
#     ${with_rtems_top}/${host_cpu}-${host_os}/
#
# -> After expanding this macro 'enable_rtemsbsp' contains a list
#    of all BSPs that are installed and -- if 'enable_rtemsbsp' was
#    initially set -- which are mentioned in 'enable_rtembsp'.
#
# TILLAC_RTEMS_CHECK_BSPS
#
# NOTE: This macro *modifies* the 'enable_rtemsbsp' variable.
#
AC_DEFUN([TILLAC_RTEMS_CHECK_BSPS],
	[AC_REQUIRE([TILLAC_RTEMS_OPTIONS])
    if test ! "${enable_rtemsbsp+set}" = "set" ; then
        _tillac_rtems_bsplist="`ls $with_rtems_top/${host_cpu}-${host_os}/ | tr '\n\r' '  '`"
	else
		_tillac_rtems_bsplist=$enable_rtemsbsp
	fi
	enable_rtemsbsp=
	AC_MSG_CHECKING([Looking for RTEMS BSPs $_tillac_rtems_bsplist])
	for _tillac_rtems_bspcand in $_tillac_rtems_bsplist ; do
		if test -d $with_rtems_top/${host_cpu}-${host_os}/$_tillac_rtems_bspcand/lib/include ; then
			if test "${enable_rtemsbsp}"xx = xx ; then
				enable_rtemsbsp="$_tillac_rtems_bspcand"
			else
				enable_rtemsbsp="$_tillac_rtems_bspcand $enable_rtemsbsp"
			fi
		fi
	done
	if test "$enable_rtemsbsp"xx = "xx" ; then
		AC_MSG_ERROR("No BSPs found")
	else
		AC_MSG_NOTICE([found \'$enable_rtemsbsp\'])
	fi]dnl
)

#dnl RTEMS_CHECK_PROG(VARIABLE, PROG-TO-CHECK-FOR, VALUE-IF-FOUND [, VALUE-IF-NOT-FOUND [, PATH [, REJECT]]])
AC_DEFUN([RTEMS_CHECK_PROG],
[
	AC_CHECK_PROG($1,$2,$3,$4,$5,$6)
	AS_IF([test -z "${$1}"],
		[AC_MSG_ERROR([program '$2' not found.])])
])

#dnl RTEMS_CHECK_TOOL(VARIABLE, PROG-TO-CHECK-FOR[, VALUE-IF-NOT-FOUND [, PATH]])
AC_DEFUN([RTEMS_CHECK_TOOL],
[
  AS_IF([test "x$build_alias" != "x$host_alias"],
    [rtems_tool_prefix=${ac_tool_prefix}])
  RTEMS_CHECK_PROG($1, ${rtems_tool_prefix}$2, ${rtems_tool_prefix}$2, $3, $4)
  AC_SUBST($1)
])

# Verify that the --with-rtems-top option has been given
# and that the directory it specifies has a subdirectory
# ${with_rtems_top}/${host_cpu}-${host_os}
#
# Throw an error if this test fails.
#
# TILLAC_RTEMS_CHECK_TOP
#
AC_DEFUN([TILLAC_RTEMS_CHECK_TOP],
	[AC_REQUIRE([AC_CANONICAL_HOST])
    AC_REQUIRE([TILLAC_RTEMS_OPTIONS])
    if TILLAC_RTEMS_OS_IS_RTEMS ; then
        if test ! "${with_rtems_top+set}" = "set" ; then
            AC_MSG_ERROR([No RTEMS topdir given; use --with-rtems-top option])
        fi
        AC_MSG_CHECKING([Checking RTEMS installation topdir])
        if test ! -d $with_rtems_top/${host_cpu}-${host_os}/ ; then
            AC_MSG_ERROR([RTEMS topdir $with_rtems_top/${host_cpu}-${host_os}/ not found])
        fi
        AC_MSG_RESULT([OK])
    fi
    ]dnl
)

# fixup the 'exec-prefix' and 'includedir' options:
#  - if either is given explicitly by the user then do nothing
#  - if user says --enable-std-rtems-installdirs then
#      prefix      -> ${rtems_top} 
#      exec-prefix -> ${prefix}/<cpu>/
#      libdir      -> ${exec-prefix}/<bsp>/lib
#      includedir  -> ${libdir}/include
#
#  - if user says nothing then
#
#      (package_subdir defaults to: target/${PACKAGE_NAME})
#
#      exec-prefix -> ${prefix}/${package_subdir}/<cpu>/<bsp>/
#      includedir  -> ${exec-prefix}/include
#    
AC_DEFUN([TILLAC_RTEMS_FIXUP_PREFIXES],
[
AC_REQUIRE([TILLAC_RTEMS_OPTIONS])
if TILLAC_RTEMS_OS_IS_RTEMS ; then
if test "${enable_std_rtems_installdirs}" = "yes" ; then
	prefix=${with_rtems_top}
	exec_prefix='${prefix}/${host_cpu}-${host_os}/'
	libdir='${exec_prefix}/'${enable_rtemsbsp}/lib
	if test "$enable_multilib" = "yes" ; then
		includedir='${exec_prefix}/include'
	else
		includedir='${libdir}/include'
	fi
	ac_configure_args="${ac_configure_args} --prefix='${prefix}'"
	ac_configure_args="${ac_configure_args} --exec-prefix='${exec_prefix}'"
	ac_configure_args="${ac_configure_args} --libdir='${libdir}'"
	ac_configure_args="${ac_configure_args} --includedir='${includedir}'"
else
# should be correct also for multilibbed build (rtems_bsp empty)
	if test "${exec_prefix}" = "NONE" ; then
		exec_prefix='${prefix}/${package_subdir}/${host_cpu}-${host_os}/'${enable_rtemsbsp}/
		ac_configure_args="${ac_configure_args} --exec-prefix='${exec_prefix}'"
	fi
	# Unfortunately we have no way to check if includedir was set by the user
	# other than scanning the argument line :-(
	tillac_rtems_includedir_set=no
	for tillac_rtems_arg in ${ac_configure_args} ; do
	case $tillac_rtems_arg in
		-includedir | --includedir | --includedi | --included | --include \
		| --includ | --inclu | --incl | --inc \
        | -includedir=* | --includedir=* | --includedi=* | --included=* | --include=* \
	    | --includ=* | --inclu=* | --incl=* | --inc=*)
		tillac_rtems_includedir_set=yes;
		;;
	*)
	    ;;
	esac
	done

	if test "${tillac_rtems_includedir_set}" = "no" ; then
		includedir='${exec_prefix}/include'
		ac_configure_args="${ac_configure_args} --includedir='${includedir}'"
	fi
fi
fi]dnl
)

# Find out if this is a multilibbed RTEMS installation
#
# Result is exit status, i.e., this macro can e.g., be used
# in a 'if MACRO ; then list; fi' statement.
#
# TILLAC_RTEMS_CPUKIT_MULTILIB
AC_DEFUN([TILLAC_RTEMS_CPUKIT_MULTILIB],
	[AC_REQUIRE([AC_CANONICAL_HOST])
	AC_REQUIRE([TILLAC_RTEMS_OPTIONS])
	test -d ${with_rtems_top}/${host_cpu}-${host_os}/include]dnl
)

# Find out if host_os is *rtems*;
#
# Result is exit status, i.e., this macro can e.g., be used
# in a 'if MACRO ; then list; fi' statement.
#
# TILLAC_RTEMS_HOSTOS_IS_RTEMS
AC_DEFUN([TILLAC_RTEMS_HOSTOS_IS_RTEMS],
	[AC_REQUIRE([AC_CANONICAL_HOST])
    case "${host_os}" in *rtems* ) : ;; *) false;; esac]dnl
)

# Find out if either '--with-rtems-top' was given or
# host_os is *rtems* (or both).
#
# Result is exit status, i.e., this macro can e.g., be used
# in a 'if MACRO ; then list; fi' statement.
#
# TILLAC_RTEMS_OS_IS_RTEMS
AC_DEFUN([TILLAC_RTEMS_OS_IS_RTEMS],
	[AC_REQUIRE([AC_CANONICAL_HOST])
    test "${with_rtems_top+set}" = "set" || TILLAC_RTEMS_HOSTOS_IS_RTEMS]dnl
)

# Find out if we are NOT at the top of the configuration 
# process, i.e., --with-rtems-top is not given OR host_os is
# *rtems*.
#
# TILLAC_RTEMS_NOT_CONFIG_TOP
AC_DEFUN([TILLAC_RTEMS_NOT_CONFIG_TOP],
	[AC_REQUIRE([AC_CANONICAL_HOST])
	test ! "${with_rtems_top+set}" = "set" || TILLAC_RTEMS_HOSTOS_IS_RTEMS]dnl
)

# This macro saves the BSP-specific variables (such as CC, CXX, CPP, ...)
# into intermediate variables from where they can be restored
# with TILLAC_RTEMS_RESET_MAKEVARS
#
# Note: this macro should not be used directly. It is expanded from
#       TILLAC_RTEMS_SETUP
#
# TILLAC_RTEMS_SAVE_MAKEVARS
AC_DEFUN([TILLAC_RTEMS_SAVE_MAKEVARS],
	[
	tillac_rtems_cc_orig="$CC"
	tillac_rtems_cxx_orig="$CXX"
	tillac_rtems_ccas_orig="$CCAS"
	tillac_rtems_cpp_orig="$CPP"
	tillac_rtems_ldflags_orig="$LDFLAGS"
	tillac_rtems_bsp_family_orig=""
	tillac_rtems_bsp_insttop_orig=""]dnl
)

# This macro restores the BSP-specific variables (such as CC, CXX, CPP, ...)
# from intermediate variables that were set by TILLAC_RTEMS_SAVE_MAKEVARS
#
# Note: this macro should not be used directly. It is expanded from
#       TILLAC_RTEMS_SETUP
#
# TILLAC_RTEMS_RESET_MAKEVARS
AC_DEFUN([TILLAC_RTEMS_RESET_MAKEVARS],
	[
	RTEMS_TILL_MAKEVARS_SET=NO
	CC="$tillac_rtems_cc_orig"
	CXX="$tillac_rtems_cxx_orig"
	CCAS="$tillac_rtems_ccas_orig"
	CPP="$tillac_rtems_cpp_orig"
	LDFLAGS="$tillac_rtems_ldflags_orig"
	RTEMS_BSP_FAMILY="$tillac_rtems_bsp_family_orig"
	RTEMS_BSP_INSTTOP="$tillac_rtems_bsp_insttop_orig"]dnl
)

# Determine critical, BSP-specific build parameters from the
# RTEMS makefiles. These parameters are cflags, gccspecs, ...
#
# Notes: this macro should not be used directly. It is expanded from
#        TILLAC_RTEMS_SETUP
#
#        4.10 eliminated RTEMS_BSP_FAMILY. This macro sets
#        RTEMS_BSP_FAMILY=$(RTEMS_BSP) if RTEMS_BSP_FAMILY is empty.
#        Thus, RTEMS_BSP_FAMILY still works in our framework
#        (but should be phased out eventually).
#
# TILLAC_RTEMS_MAKEVARS(HOST_SYSTEM, BSP)
AC_DEFUN([TILLAC_RTEMS_MAKEVARS],
	[
	AC_MSG_CHECKING([Determining RTEMS Makefile parameters for BSP:])
dnl DOWNEXT is set in leaf.cfg and we don't include that
	AC_MSG_CHECKING([for 'GNU make'])
    _tillac_make_command=""
    for a in "$MAKE" gmake gnumake make; do
		test -z "$a" && continue
        if ( sh -c "$a --version" 2>/dev/null | grep GNU >/dev/null ) ; then
			_tillac_make_command="$a"; break;
		fi
	done
	if test -z "$_tillac_make_command" ; then
		AC_MSG_ERROR([No GNU make found!])	
	else
		AC_MSG_RESULT([found: $_tillac_make_command])
	fi
	if _tillac_rtems_result=`$_tillac_make_command -s -f - rtems_makevars <<EOF_
include $with_rtems_top/$1/$2/Makefile.inc
include \\\$(RTEMS_CUSTOM)
include \\\$(CONFIG.CC)

rtems_makevars:
	@echo tillac_rtems_cpu_cflags=\'\\\$(CPU_CFLAGS) \\\$(AM_CFLAGS)\'
	@echo tillac_rtems_gccspecs=\'\\\$(GCCSPECS)\'
	@echo tillac_rtems_cpu_asflags=\'\\\$(CPU_ASFLAGS)\'
	@echo tillac_rtems_ldflags=\'\\\$(AM_LDFLAGS) \\\$(LDFLAGS)\'
	@echo tillac_rtems_cppflags=
	@echo RTEMS_BSP_FAMILY=\'\\\$(or \\\$(RTEMS_BSP_FAMILY),\\\$(RTEMS_BSP))\'
	@echo RTEMS_BSP_INSTTOP=\'\\\$(PROJECT_RELEASE)\'
EOF_
` ; then
	AC_MSG_RESULT([OK: $_tillac_rtems_result])
	else
	AC_MSG_ERROR([$_tillac_rtems_result])
	fi
	# propagate cpu_cflags and gccspecs into currently executing shell
	eval $_tillac_rtems_result
	export RTEMS_BSP_INSTTOP="$RTEMS_BSP_INSTTOP"
	export RTEMS_BSP_FAMILY="$RTEMS_BSP_FAMILY"]dnl
)

# Export the set of critical, BSP-specific build parameters 
# (cflags, gccspecs, ...) that were determined by TILLAC_RTEMS_MAKEVARS
# into the environment.
#
# This macro takes two (optional) arguments: 
#
#    <HOST_SYSTEM> and <LIBSUBDIR>
#
# The macro also, adds the paths listed in the --with-extra-incdirs and
# --with-extra-libdirs options to the cppflags and ldflags, respectively
# (adding -I, -L). If 'LIBSUBDIR' is given then it is appended to
# any of the directories listed in --with-extra-libdirs (if the LIBSUBDIR
# exists) there.
#
# Furthermore, if it is determined that RTEMS was configured for
# a multilibbed cpukit then
#  i)   -I${with_rtems_top}/${host_cpu}-${host_os}/include 
#       is added to the cppflags (if the directory exists)
#  ii)  -B${with_rtems_top}/<HOST_SYSTEM>/lib is added to the
#       gcc specs so that multilibs are found (workaround for
#       a bug in the rtems 4.9.0 makefiles)
#
# Note: this macro should not be used directly. It is expanded from
#       TILLAC_RTEMS_SETUP
#
# TILLAC_RTEMS_EXPORT_MAKEVARS([HOST_SYSTEM],[LIBSUBDIR])
AC_DEFUN([TILLAC_RTEMS_EXPORT_MAKEVARS],
	[
	AC_MSG_CHECKING([Checking if RTEMS CC & friends MAKEVARS are already set])
	if test ! "${RTEMS_TILL_MAKEVARS_SET}" = "YES"; then
		AC_MSG_RESULT([No (probably a multilibbed build)]) 
		export RTEMS_TILL_MAKEVARS_SET=YES
		# if this is a multilibbed cpukit we need to include
		if test -d $with_rtems_top/${host_cpu}-${host_os}/include ; then
			tillac_rtems_cppflags="$tillac_rtems_cppflags -I$with_rtems_top/${host_cpu}-${host_os}/include"
			# and since the RTEMS (4.9) makefiles seem to be broken
			# for multilibbed cpukits (fail to add -B <libdir>) we
			# do it here
			tillac_rtems_gccspecs="$tillac_rtems_gccspecs -B $with_rtems_top/$1/lib"
		fi
		if test "${with_extra_incdirs+set}" = "set" ; then
			for tillac_extra_incs_val in ${with_extra_incdirs} ; do
				tillac_rtems_cppflags="$tillac_rtems_cppflags -I$tillac_extra_incs_val"
			done
		fi
		if test "${with_extra_libdirs+set}" = "set" ; then
			for tillac_extra_libs_val in ${with_extra_libdirs} ; do
				if test -d $tillac_extra_libs_val/$2 ; then
					tillac_rtems_ldflags="$tillac_rtems_ldflags -L$tillac_extra_libs_val/$2"
				else
					tillac_rtems_ldflags="$tillac_rtems_ldflags -L$tillac_extra_libs_val"
				fi
			done
		fi
# evaluate tillac_rtems_cppflags, tillac_rtems_ldflags in case
# they gave a quoted shell variable on the commandline
		tillac_rtems_cppflags=`eval echo "$tillac_rtems_cppflags"`
		tillac_rtems_ldflags=`eval echo "$tillac_rtems_ldflags"`
#export forged CC & friends so that they are used by sub-configures, too
		export CC="$CC $tillac_rtems_gccspecs $tillac_rtems_cpu_cflags $tillac_rtems_cppflags"
		export CXX="$CXX $tillac_rtems_gccspecs $tillac_rtems_cpu_cflags $tillac_rtems_cppflags"
		export CCAS="$CCAS $tillac_rtems_gccspecs $tillac_rtems_cpu_asflags -DASM"
		export CPP="$CPP $tillac_rtems_gccspecs $tillac_rtems_cppflags"
#		export CFLAGS="$CFLAGS $tillac_rtems_cpu_cflags"
#		export CXXFLAGS="$CXXFLAGS  $tillac_rtems_cpu_cflags"
#		export CCASFLAGS="$CCASFLAGS $tillac_rtems_cpu_asflags -DASM"
#		export CPPFLAGS="$CPPFLAGS $tillac_rtems_cppflags"
		export LDFLAGS="$LDFLAGS $tillac_rtems_ldflags"
	else
		AC_MSG_RESULT([yes])
	fi]dnl
)

#
# Prepare for a multilibbed build
#  - check for presence of 'config-ml.in'
#  - expand AM_ENABLE_MULTILIB(MAKEFILE, REL-TO-TOP-SRCDIR)
#  - expand TILLAM_MULTISUB_INSTALLDIR (workaround so that
#    multilibs are installed into proper subdir.
#  - make sure  'enable_multilib' is set to 'no' if it was initially
#    unset; yet another little workaround...
#
# TILLAC_RTEMS_MULTILIB([MAKEFILE], [REL-TO-TOP-SRCDIR])
AC_DEFUN([TILLAC_RTEMS_MULTILIB],
	[if test -f ${srcdir}/config-ml.in || test -f $(srcdir)/../config-ml.in ; then
		AM_ENABLE_MULTILIB([$1],[$2])
		# install multilibs into MULTISUBDIR
		TILLAM_MULTISUB_INSTALLDIR
dnl		AC_SUBST(libdir,[${libdir}'$(MULTISUBDIR)'])
		# in order to properly build multilibs in sub-libraries it seems we
		# must pass the --enable-multilibs arg to sub-configures or multilibs
		# are not built there.
		# To work around, we simply set the default to 'no' so the user must
		# say --enable-multilib to get them.
		if test ! "${enable_multilib+set}" = "set" ; then
		    multilib=no
		fi
	else
		enable_multilib=no
	fi]dnl
)

# Makefile substitutions required for partial linking to
# create a cexpsh-loadable object file
AC_DEFUN([TILLAC_RTEMS_OBJLINK],
	AC_SUBST([OBJLINK],[['$(CCLD) -nostdlib -Wl,-r -o $[@]']])
	AC_SUBST([OBJEXEEXT],['.obj'])
)

# Declare --enable-rtemsbsp --with-rtems-top options
#
# TILLAC_RTEMS_OPTIONS
AC_DEFUN([TILLAC_RTEMS_OPTIONS],
	[AC_ARG_ENABLE(rtemsbsp,
		AC_HELP_STRING([--enable-rtemsbsp="bsp1 bsp2 ..."],
			[BSPs to include in build (ignore bsps not found in RTEMS installation)]dnl
		)
	)
	AC_ARG_WITH(rtems-top,
		AC_HELP_STRING([--with-rtems-top=<rtems installation topdir>],
			[point to RTEMS installation]dnl
		)
	)
	AC_ARG_WITH(extra-incdirs,
		AC_HELP_STRING([--with-extra-incdirs=<additional header dirs>],
			[point to directories with additional headers]dnl
		)
	)
	AC_ARG_WITH(extra-libdirs,
		AC_HELP_STRING([--with-extra-libdirs=<additional library dirs (w/o -L)>],
			[point to directories with additional libraries]dnl
		)
	)
	AC_ARG_WITH(hostbindir,
		AC_HELP_STRING([--with-hostbindir=<installation dir for native binaries>],
			[default is <prefix>/host/<build_alias>/bin],
		),
		[AC_SUBST([hostbindir],[$with_hostbindir])],
		[AC_SUBST([hostbindir],['$(prefix)/host/$(build_alias)/bin'])]
	)
	AC_ARG_ENABLE([std-rtems-installdirs],
		AC_HELP_STRING([--enable-std-rtems-installdirs],
		[install directly into
		the RTEMS installation directories; by default a location *outside*
		of the standard location is used. If you don't use this option you
		can also fine-tune the installation using the usual --prefix, 
		--exec-prefix, --libdir, --includedir etc. options]dnl
		)
	)
	AC_ARG_VAR([SUPERPACKAGE_NAME],[Name of a collection of packages; used to define install subdir])
	if test -z "${SUPERPACKAGE_NAME}" ; then
		AC_MSG_NOTICE([SUPERPACKAGE_NAME was empty, overriding with PACKAGE_NAME: ${PACKAGE_NAME}])
		SUPERPACKAGE_NAME="${PACKAGE_NAME}"
	else
		AC_MSG_NOTICE([SUPERPACKAGE_NAME was set: ${SUPERPACKAGE_NAME}, leaving alone])
	fi
    export SUPERPACKAGE_NAME
	AC_ARG_WITH(package-subdir,
		AC_HELP_STRING([--with-package-subdir=<path-fragment>],
			[defines part of the default exec-prefix:
             ${prefix}/${package_subdir}/${host_cpu}-${host_os}/${rtems_bsp}
            This option is overridden by either of --enable-std-rtems-installdirs
            and --exec-prefix. Defaults to 'target/${SUPERPACKAGE_NAME}']dnl
		),
		[AC_SUBST([package_subdir],[${with_package_subdir}])],
		[AC_SUBST([package_subdir],['target/${SUPERPACKAGE_NAME}'])]
	)
	AC_ARG_ENABLE(diag-hostprogs,
		AC_HELP_STRING([--enable-diag-hostprogs],
			[Enable building of some (package-specific) diagnostic (host)
             programs; probably only needed by experts])
	)
]dnl
)

# This macro assembles a list of RTEMS CPUs and if the list
# contains more than one member then it creates a build subdirectory
# for each CPU architecture, 'chdirs' into the subdirectory and recursively
# configures for the CPU.
#
# Several options affect the behavior of this macro:
#
#   --with-rtems-top
#   --host
#   --enable-rtemsbsp
#
#  1) if --with-rtems-top is NOT given (NOT RTEMS) OR if
#     --host=<xyz>-rtems was given (RTEMS CPU defined by user)
#     THEN the macro does nothing.
#
#  2) ELSE (--with-rtems-top given but --host is NOT *rtems* 
#     i)   assemble a list of all '<cpu>-rtems*' subdirectories
#          under ${with_rtems_top}
#
#     ii)  if --enable-rtemsbsp was given then remove CPU
#          architectures not being required by any of the listed
#          BSPS.
#
#     iii) for each remaining CPU architecture create a subdirectory,
#          chdir there and recursively call 'configure' again with
#          the original arguments but --host=<cpu>-rtems appended.
#
# Note: this macro should not be used directly. It is expanded from
#       TILLAC_RTEMS_SETUP
#
# TILLAC_RTEMS_CONFIG_CPUS_RECURSIVE
AC_DEFUN([TILLAC_RTEMS_CONFIG_CPUS_RECURSIVE],
	[if TILLAC_RTEMS_NOT_CONFIG_TOP ; then : ; else
	# with_rtems_top is set but host_os is not *rtems*, i.e.,
	# we have to figure out a list of CPUs/arches that are installed.
	AC_MSG_CHECKING([for all installed CPUs/architectures])
	_tillac_rtems_cpulist="`(cd $with_rtems_top; ls -d *-rtems* | tr '\n\r' '  ')`"
	AC_MSG_RESULT([Found: $_tillac_rtems_cpulist])
	# if 'enable-rtemsbsp' was given then filter away
	# architectures that match none of the BSPs
	if test "${enable_rtemsbsp+set}" = "set" ; then
		# convert space separated list into ORed (|) pattern
		_tillac_rtems_bspfilt=`echo "$enable_rtemsbsp" | sed -e 's/[[ \t]]\+/|/g'`
		AC_MSG_NOTICE([Filtering CPU/architecture list against bsps: $_tillac_rtems_bspfilt])
		_tillac_rtems_cpuall="$_tillac_rtems_cpulist"
		_tillac_rtems_cpulist=""
		AC_MSG_CHECKING([CPU/architectures matching requested BSPs])
		for _tillac_rtems_cpucand in $_tillac_rtems_cpuall ; do
			# look for directories which have a 'Makefile.inc'
			for _tillac_rtems_bspcand in `(cd $with_rtems_top/$_tillac_rtems_cpucand ; ls */Makefile.inc | tr '\n\r' '  ')` ; do
				AC_MSG_NOTICE([testing $_tillac_rtems_bspcand])
				# reduce to bsp name
				_tillac_rtems_bspcand=`dirname $_tillac_rtems_bspcand`
				if eval "case `echo $_tillac_rtems_bspcand` in $_tillac_rtems_bspfilt) : ;; *) false ;; esac" ; then
					# only add candidate to list of cpus if not already there
					if test -z "$_tillac_rtems_cpulist" ; then
						_tillac_rtems_cpulist="$_tillac_rtems_cpucand"
					else
						_tillac_rtems_cpufilt=`echo "$_tillac_rtems_cpulist" | sed -e 's/[[ \t]]\+/|/g'`
						if eval "case `echo $_tillac_rtems_cpucand` in $_tillac_rtems_cpufilt) false ;; *) : ;; esac" ; then
							_tillac_rtems_cpulist="$_tillac_rtems_cpulist $_tillac_rtems_cpucand"
						fi
					fi
				fi
			done
		done
		AC_MSG_RESULT([found: $_tillac_rtems_cpulist])
	fi
	if test "$_tillac_rtems_cpulist"xx = "xx" ; then
		AC_MSG_ERROR([No RTEMS architectures found])
	fi
	# Create directory and configure
	for _tillac_rtems_cpucand in $_tillac_rtems_cpulist ; do
		if test -d $_tillac_rtems_cpucand || mkdir $_tillac_rtems_cpucand ; then : ; else
			AC_MSG_ERROR([Unable to create subdirectory $_tillac_rtems_cpucand])
		fi
		TILLAC_RTEMS_TRIM_CONFIG_DIR(_tillac_rtems_config_dir)
		# SUB-CONFIGURE
		AC_MSG_NOTICE([Running $_tillac_rtems_config_dir/[$]0 "$ac_configure_args --host=$_tillac_rtems_cpucand" in "'$_tillac_rtems_cpucand'" subdir])
		eval \( cd $_tillac_rtems_cpucand \; $SHELL $_tillac_rtems_config_dir/"[$]0" $ac_configure_args --host=$_tillac_rtems_cpucand \)
	done
	AC_MSG_NOTICE([Creating cpu/arch level makefile])
    AC_SUBST(the_subdirs,[$_tillac_rtems_cpulist])
	AC_SUBST(the_distsub,['$(firstword '"$_tillac_rtems_cpulist"')'])
	_tillac_rtems_recursing=yes
	false
	fi]dnl
)

# This macro
#
#  - removes --enable-rtemsbsp options from the current commandline
#  - for each BSP listed in '${enable_rtemsbsp}'
#     i)   creates a BSP subdirectory in the build tree
#     ii)  chdirs into the subdirectory
#     iii) figures out a few BSP-specific build settings
#          (cflags, gcc specs, ...)
#     iv)  configures for the BSP passing the properties determined
#          under iii) along to 'configure' on the commandline.
#          Also, --enable-rtemsbsp=<this_bsp> is appended to the 
#          configure commandline.
#
# Note: this macro should not be used directly. It is expanded from
#       TILLAC_RTEMS_SETUP
#
# TILLAC_RTEMS_CONFIG_BSPS_RECURSIVE
AC_DEFUN([TILLAC_RTEMS_CONFIG_BSPS_RECURSIVE],
	[if test ! "${RTEMS_TILL_MAKEVARS_SET}" = "YES"; then
		# strip all --enable-rtemsbsp options from original
		# commandline
		AC_MSG_NOTICE([Stripping --enable-rtemsbsp option(s) from commandline])
		_tillac_rtems_config_args=""
	    eval for _tillac_rtems_arg in $ac_configure_args \; do case \$_tillac_rtems_arg in --enable-rtemsbsp\* \) \;\; \*\) _tillac_rtems_config_args=\"\$_tillac_rtems_config_args \'\$_tillac_rtems_arg\'\" \;\; esac done
		AC_MSG_NOTICE([Commandline now: $_tillac_rtems_config_args])
			
		AC_MSG_NOTICE([Creating BSP subdirectories and sub-configuring])
		TILLAC_RTEMS_SAVE_MAKEVARS
		for rtems_bsp in $enable_rtemsbsp ; do
			if test ! -d $rtems_bsp ; then
				AC_MSG_CHECKING([Creating $rtems_bsp])
				if mkdir $rtems_bsp ; then
					AC_MSG_RESULT([OK])
				else
					AC_MSG_ERROR([Failed])
				fi
			fi
			TILLAC_RTEMS_TRIM_CONFIG_DIR(_tillac_rtems_config_dir)
			TILLAC_RTEMS_RESET_MAKEVARS
			TILLAC_RTEMS_MAKEVARS(${host_cpu}-${host_os},$rtems_bsp)
			tillac_rtems_cppflags="$tillac_rtems_cppflags -I$with_rtems_top/${host_cpu}-${host_os}/$rtems_bsp/lib/include"
			TILLAC_RTEMS_EXPORT_MAKEVARS(${host_cpu}-${host_os},$rtems_bsp)
			AC_MSG_NOTICE([Running $_tillac_rtems_config_dir/[$]0 $_tillac_rtems_config_args --enable-rtemsbsp=$rtems_bsp rtems_bsp=$rtems_bsp in $rtems_bsp subdir])
			# In case user uses ${RTEMS_BSP} on commandline
			RTEMS_BSP=${rtems_bsp};
			eval \( cd $rtems_bsp \; $SHELL $_tillac_rtems_config_dir/"[$]0" $_tillac_rtems_config_args --enable-rtemsbsp=$rtems_bsp rtems_bsp=$rtems_bsp \)
		done
		TILLAC_RTEMS_RESET_MAKEVARS
		AC_MSG_NOTICE([Creating toplevel makefile])
	    AC_SUBST(the_subdirs,[$enable_rtemsbsp])
		AC_SUBST(the_distsub,['$(firstword '"$enable_rtemsbsp"')'])
	fi]dnl
)

# Grand Master Macro for RTEMS configuration.
#
# This sets up most things for a RTEMS configuration
# for multiple CPU-arches and BSPs.
#
# A package may add the optional (literal) argument
# 'domultilib'. In this case, multilib support is enabled
# and the user may configure with '--enable-multilib'.
# Note that the package must properly support multilibs!
#
# If the host system is not RTEMS (no with-rtems-top given)
# then this macro does *nothing*.
# 
# TILLAC_RTEMS_SETUP([domultilib])
AC_DEFUN([TILLAC_RTEMS_SETUP],
    [AC_REQUIRE([TILLAC_RTEMS_OPTIONS])dnl
	AM_CONDITIONAL(OS_IS_RTEMS,[TILLAC_RTEMS_OS_IS_RTEMS])
	if TILLAC_RTEMS_CONFIG_CPUS_RECURSIVE ; then
	m4_if($1,domultilib,
		[TILLAC_RTEMS_MULTILIB([Makefile],[.])],
		[AC_REQUIRE([TILLAC_RTEMS_OPTIONS])dnl
		if test "${enable_multilib}" = "yes" ; then
		 	AC_MSG_ERROR(["multilibs not supported, sorry"])
		fi]dnl
	)
	if TILLAC_RTEMS_OS_IS_RTEMS ; then
		TILLAC_RTEMS_CHECK_TOP
		AC_ARG_VAR([RTEMS_TILL_MAKEVARS_SET],[Internal use; do NOT set in environment nor on commandline])
		AC_ARG_VAR([DOWNEXT],[extension of downloadable binary (if applicable)])
		AC_ARG_VAR([APPEXEEXT], [extension of linked binary])
		AC_ARG_VAR([RTEMS_BSP_FAMILY],[Internal use; do NOT set in environment nor on commandline])
		AC_ARG_VAR([RTEMS_BSP_INSTTOP],[Internal use; do NOT set in environment nor on commandline])
		if test "$1" = "domultilib" && test "$enable_multilib" = "yes" ; then 
			if test "${enable_rtemsbsp+set}" = "set" ; then
				AC_MSG_ERROR([Cannot --enable-rtemsbsp AND --enable-multilib; build either multilibs or for particular BSP(s)])
			fi
			TILLAC_RTEMS_EXPORT_MAKEVARS(${host_cpu}-${host_os},)
		else
			TILLAC_RTEMS_CHECK_BSPS
		fi
		if test ! "${RTEMS_TILL_MAKEVARS_SET}" = "YES"; then
			TILLAC_RTEMS_CONFIG_BSPS_RECURSIVE(makefile)
			_tillac_rtems_recursing=yes
		else
			TILLAC_RTEMS_FIXUP_PREFIXES
dnl set those in the configure script so that 'configure' uses these settings when trying to compile stuff
dnl		AC_SUBST(rtems_gccspecs,   [$tillac_rtems_gccspecs])
dnl		AC_SUBST(rtems_cpu_cflags, [$tillac_rtems_cpu_cflags])
dnl		AC_SUBST(rtems_cpu_asflags,["$tillac_rtems_cpu_asflags -DASM"])
dnl		AC_SUBST(rtems_cppflags,   [$tillac_rtems_cppflags])
dnl allow a few synonyms
			AC_SUBST([rtems_bsp],        [$enable_rtemsbsp])
			AC_SUBST([RTEMS_BSP],        [$enable_rtemsbsp])
			AC_SUBST([enable_rtemsbsp],  [$enable_rtemsbsp])
			TILLAC_RTEMS_BSP_CLASS
			AC_MSG_NOTICE([Setting DOWNEXT to .ralf])
			DOWNEXT=.ralf
			AC_MSG_NOTICE([Setting APPEXEEXT to .exe])
			APPEXEEXT=.exe
			TILLAC_RTEMS_VERSTEST
			TILLAC_RTEMS_OBJLINK
		fi
	fi
	fi
	if test "${_tillac_rtems_recursing}" = "yes" ; then
		AC_CONFIG_FILES([makefile:makefile.top.in])
		AC_OUTPUT
		exit 0
		false
	fi]dnl
)

dnl m4_syscmd is executed when aclocal is run
m4_syscmd([cat - > makefile.top.am <<'EOF_'
AUTOMAKE_OPTIONS=foreign
SUBDIRS=@the_subdirs@
ACLOCAL_AMFLAGS=-I./m4
# When making a distribution we only want to 
# recurse into (any) one single BSP subdir.
DIST_SUBDIRS=@the_distsub@

# The dist-hook then removes this extra
# directory level again.
dist-hook:
	if test "$(PACKAGE_VERSION)" = "untagged" ; then echo "Need tagged version to cut distribution"; exit 1; fi
	cp -frl $(distdir)/$(DIST_SUBDIRS)/* $(distdir)
	rm -fr  $(distdir)/$(DIST_SUBDIRS)
EOF_
])

# Check for critical programs we need for building
AC_DEFUN([TILLAC_RTEMS_CHECK_TOOLS],
	[
     # Cannot conditionally use AC_PROG_CC, AC_PROG_CXX, AM_PROG_AS
	 # This is an autoconf 'feature'. Therefore we use an ugly hack
	 # to pass the gcc tests on a build system that has no native
	 # compilers.
	 if TILLAC_RTEMS_NOT_CONFIG_TOP; then : ; else
	   CC="$SHELL $srcdir/dummycxx"
	   CXX="$SHELL $srcdir/dummycxx"
	 fi
	 AC_PROG_CC
	 AC_PROG_CXX
	 AM_PROG_AS
	 if TILLAC_RTEMS_NOT_CONFIG_TOP; then
	   AC_SUBST([GCC])
	   AC_PROG_CPP
	   AC_CHECK_PROGS([HOSTCC], gcc cc)
	   RTEMS_CHECK_TOOL([AR],ar)
	   RTEMS_CHECK_TOOL([LD],ld)
	   RTEMS_CHECK_TOOL([NM],nm)
	   RTEMS_CHECK_TOOL([OBJCOPY],objcopy)
	   RTEMS_CHECK_TOOL([RANLIB],ranlib)
	   AC_PROG_INSTALL
	   AC_CHECK_PROG([INSTALL_IF_CHANGE],[install-if-change],[install-if-change],[${INSTALL}])
	 fi]dnl
)

dnl m4_syscmd is executed when aclocal is run
m4_syscmd([cat - > dummycxx <<'EOF_'
#!/bin/sh
# dummy 'compiler' to just pass the 'gcc' test
ofile="a.out"
while getopts "cgo:" opt ; do
	echo found opt $opt
	case $opt in
		o)
		ofile="$OPTARG"
		o_seen=yes
		shift
		;;
		c)
		c_seen=yes
		;;
		g)
		;;
		*)
			exit 1;
		;;
	esac
	shift
	OPTIND=1
done
if [ x"${c_seen}" = "xyes" ] && [ ! x"${o_seen}" = "xyes" ] ; then
	srcnam=`basename $1 | sed -e 's/[.][^.]*$//g'`
	ofile="${srcnam}.o"
fi
echo '#!/bin/sh'                > $ofile
echo 'echo "dummy compilation"' >> $ofile
chmod a+x $ofile

EOF_
])

# Takes one argument
#
# TILLAC_RTEMS_TRIM_CONFIG_DIR(dirvar)
#
# If 'srcdir' is a absolute path (a string
# starting with '/' then set 'dirvar' to the
# empty string; otherwise (srcdir is a relative path)
# set 'dirvar' to '../'.
#
# This macro can be used to find 'srcdir' should 
# configure decide to step into a subdirectory inside
# a build tree.
#
AC_DEFUN([TILLAC_RTEMS_TRIM_CONFIG_DIR],
	[AC_MSG_NOTICE([Trimming source directory])
	# leave absolute path alone, relative path needs
	# to step one level up
	case $srcdir in
		/* )
			$1=
		;;
		*)
			$1=../
		;;
	esac]dnl
)

# Emit two macros
#
#   'RTEMS_VERSION_LATER_THAN(major,minor,revision)'
#
# and
#
#   'RTEMS_VERSION_ATLEAST(major,minor,revision)'
#
# in config.h so applications can test for a particular
# RTEMS version and conditionally deal with API changes
# and other stuff.
# Note that sometimes (mostly during x.y.99  pre-release
# phases) such changes happen w/o an associated change in
# revision number ;-(.
#
#dnl TILLAC_RTEMS_VERSTEST
AC_DEFUN([TILLAC_RTEMS_VERSTEST],
	[AH_VERBATIM([RTEMS_VERSION_TEST],
				[
#ifndef RTEMS_VERSION_LATER_THAN
#define RTEMS_VERSION_LATER_THAN(ma,mi,re) \
	(    __RTEMS_MAJOR__  > (ma)	\
	 || (__RTEMS_MAJOR__ == (ma) && __RTEMS_MINOR__  > (mi))	\
	 || (__RTEMS_MAJOR__ == (ma) && __RTEMS_MINOR__ == (mi) && __RTEMS_REVISION__ > (re)) \
    )
#endif
#ifndef RTEMS_VERSION_ATLEAST
#define RTEMS_VERSION_ATLEAST(ma,mi,re) \
	(    __RTEMS_MAJOR__  > (ma)	\
	|| (__RTEMS_MAJOR__ == (ma) && __RTEMS_MINOR__  > (mi))	\
	|| (__RTEMS_MAJOR__ == (ma) && __RTEMS_MINOR__ == (mi) && __RTEMS_REVISION__ >= (re)) \
	)
#endif
	            ]dnl
	)]dnl
)

