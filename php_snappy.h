/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Joe Watkins <joe.watkins@live.co.uk>                         |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_SNAPPY_H
#define PHP_SNAPPY_H

PHP_MINFO_FUNCTION(snappy);

PHP_FUNCTION(snappy_compress);
PHP_FUNCTION(snappy_validate);
PHP_FUNCTION(snappy_uncompress);

extern zend_module_entry snappy_module_entry;
#define phpext_snappy_ptr &snappy_module_entry

#define PHP_SNAPPY_EXTNAME "snappy"
#define PHP_SNAPPY_VERSION "0.1"

#endif	/* PHP_SNAPPY_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
