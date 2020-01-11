/* file      : tests/basic/driver.c
 * copyright : Copyright (c) 2009-2019 Code Synthesis Tools CC
 * license   : cURL License; see accompanying COPYING file
 */
#include <stdio.h>
#include <assert.h>

#include <curl/curl.h>

/* Usage: argv[0] <URL>
 *
 * Request the specified URL and print the response to stdout.
 */
int
main (int argc, char* argv[])
{
  assert (argc == 2);

  const char* url = argv[1];

  curl_global_init (CURL_GLOBAL_DEFAULT);

  int r = 1;

  CURL* curl = curl_easy_init ();

  if (curl != NULL)
  {
    curl_easy_setopt (curl, CURLOPT_URL, url);

    CURLcode cr = curl_easy_perform (curl);

    if (cr == CURLE_OK)
      r = 0;
    else
      fprintf (stderr,
               "failed to request '%s': %s\n",
               url,
               curl_easy_strerror (cr));

    curl_easy_cleanup (curl);
  }
  else
    fprintf (stderr, "curl_easy_init() failed\n");

  curl_global_cleanup ();
  return r;
}
