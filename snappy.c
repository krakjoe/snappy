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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_snappy.h"

#include <snappy-c.h>

/* {{{ snappy_arginfo */
ZEND_BEGIN_ARG_INFO_EX(snappy_arginfo, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ snappy_functions[]
 */
const zend_function_entry snappy_functions[] = {
	PHP_FE(snappy_compress,		snappy_arginfo)	
	PHP_FE(snappy_validate,		snappy_arginfo)
	PHP_FE(snappy_uncompress,	snappy_arginfo)
	PHP_FE_END
};
/* }}} */

/* {{{ snappy_module_entry
 */
zend_module_entry snappy_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SNAPPY_EXTNAME,
	snappy_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(snappy),
	PHP_SNAPPY_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SNAPPY
ZEND_GET_MODULE(snappy)
#endif

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(snappy)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "snappy support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ proto string snappy_compress(string data)
   Compress data using snappy compression */
PHP_FUNCTION(snappy_compress)
{
	char     *data = NULL, 
             *cdata = NULL;
	uint     dlen;
	size_t   clen;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &data, &dlen) == FAILURE) {
		return;
	}
	
	clen = snappy_max_compressed_length(dlen);

	if (clen) {
		cdata = (char*) emalloc(clen);
		if (snappy_compress((const char*)data, dlen, cdata, &clen) == SNAPPY_OK) {
			ZVAL_STRINGL(return_value, cdata, clen, 1);
		}
		efree(cdata);
	}
}
/* }}} */

/* {{{ proto boolean snappy_validate(string data)
   Tells if data can be uncompressed without error */
PHP_FUNCTION(snappy_validate)
{
	char     *cdata = NULL;
	uint     clen;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &cdata, &clen) == FAILURE) {
		return;
	}
	
	RETURN_BOOL((snappy_validate_compressed_buffer(cdata, clen)==SNAPPY_OK));
} /* }}} */

/* {{{ proto string snappy_uncompress(string data)
   Decompress data using snappy compression */
PHP_FUNCTION(snappy_uncompress)
{
	char     *data = NULL, 
             *cdata = NULL;
	size_t   dlen;
	uint     clen;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &cdata, &clen) == FAILURE) {
		return;
	}
	
	if (snappy_uncompressed_length((const char*)cdata, clen, &dlen) == SNAPPY_OK) {
		data = (char*) emalloc(dlen);
		if (snappy_uncompress((const char*)cdata, clen, data, &dlen) == SNAPPY_OK) {
			ZVAL_STRINGL(return_value, data, dlen, 1);
		}
		efree(data);
	}
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
