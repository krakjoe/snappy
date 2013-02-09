dnl $Id$
dnl config.m4 for extension snappy

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(snappy, for snappy support,
Make sure that the comment is aligned:
[  --with-snappy             Include snappy support])

if test "$PHP_SNAPPY" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-snappy -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/snappy.h"  # you most likely want to change this
  dnl if test -r $PHP_SNAPPY/$SEARCH_FOR; then # path given as parameter
  dnl   SNAPPY_DIR=$PHP_SNAPPY
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for snappy files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SNAPPY_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SNAPPY_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the snappy distribution])
  dnl fi

  dnl # --with-snappy -> add include path
  dnl PHP_ADD_INCLUDE($SNAPPY_DIR/include)

  dnl # --with-snappy -> check for lib and symbol presence
  dnl LIBNAME=snappy # you may want to change this
  dnl LIBSYMBOL=snappy # you most likely want to change this 

  PHP_CHECK_LIBRARY(snappy, snappy_compress,
  [
    PHP_ADD_LIBRARY_WITH_PATH(snappy, $SNAPPY_DIR/lib, SNAPPY_SHARED_LIBADD)
    AC_DEFINE(HAVE_SNAPPYLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong snappy lib version or lib not found])
  ],[
    -L$SNAPPY_DIR/lib -lm
  ])
  
  PHP_SUBST(SNAPPY_SHARED_LIBADD)

  PHP_NEW_EXTENSION(snappy, snappy.c, $ext_shared)
fi
