/* file      : libcurl/assert.c -*- C -*-
 * license   : cURL License; see accompanying COPYING file
 */

#include <curl_config.h>

#ifdef _MSC_VER
#  include <windows.h> // C_ASSERT()
#endif

#include <time.h>
#include <sys/types.h>

#include <curl/curl.h>

/*  Make sure that some assumptions made at the preprocessing stage are true.
 */

/* _Static_assert() is introduced in C11, is available for GCC and Clang by
 * default since they support C99, and is not supported by VC at all.
 */
#ifdef _MSC_VER
#  define _Static_assert(C, M) C_ASSERT (C)
#endif

_Static_assert (sizeof (off_t)  == SIZEOF_OFF_T,  "unexpected off_t size");
_Static_assert (sizeof (time_t) == SIZEOF_TIME_T, "unexpected time_t size");

_Static_assert (sizeof (curl_off_t) == SIZEOF_CURL_OFF_T,
                "unexpected curl_off_t size");
