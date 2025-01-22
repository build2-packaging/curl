/* file      : tests/basic/driver.c
 * license   : curl License; see accompanying COPYING file
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>  /* strcmp() */

#include <curl/curl.h>

/* Usage: argv[0] <URL>
 *
 * Request the specified URL following location for 3xx responses and print
 * the 200 response body to stdout.
 *
 * --verbose
 *     Print additional information (API calls, HTTP headers, etc) to stderr.
 */
int
main (int argc, char* argv[])
{
  int v = 0;

  int i = 1;
  for (; i < argc; ++i)
  {
    const char* o = argv[i];

    if (strcmp (o, "--verbose") == 0)
      v = 1;
    else
      break;
  }

  assert (i + 1 == argc);

  const char* url = argv[i];

  int r = 1;

  if (v != 0)
    fprintf (stderr, "calling curl_global_init()\n");

  curl_global_init (CURL_GLOBAL_DEFAULT);

  if (v != 0)
    fprintf (stderr, "calling curl_easy_init()\n");

  CURL* curl = curl_easy_init ();

  if (curl != NULL)
  {
    if (v != 0)
      fprintf (stderr, "calling curl_easy_setopt()\n");

    curl_easy_setopt (curl, CURLOPT_URL, url);
    curl_easy_setopt (curl, CURLOPT_TIMEOUT, 600L);      /* 10 mins. */

    char agent[] = "libcurl-test/" LIBCURL_VERSION;
    curl_easy_setopt (curl, CURLOPT_USERAGENT, agent);

    if (v != 0)
      curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);

    if (v != 0)
      fprintf (stderr, "calling curl_easy_perform()\n");

    CURLcode cr = curl_easy_perform (curl);

    if (cr == CURLE_OK)
    {
      if (v != 0)
        fprintf (stderr, "calling curl_easy_getinfo()\n");

      long status;
      cr = curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status);

      if (cr == CURLE_OK)
      {
        if (status == 200 || (status >= 300 && status < 400))
        {
          if (v != 0)
            fprintf (stderr, "calling fflush()\n");

          /* Flush the response body.
           */
          if (fflush (stdout) != 0)
            fprintf (stderr, "failed to flush stdout\n");

          r = 0;
        }
        else
          fprintf (stderr, "HTTP error: status code %ld\n", status);
      }
      else
        fprintf (stderr,
                 "failed to get HTTP status code: %s\n",
                 curl_easy_strerror (cr));
    }
    else
      fprintf (stderr,
               "failed to request '%s': %s\n",
               url,
               curl_easy_strerror (cr));

    curl_easy_cleanup (curl);
  }
  else
    fprintf (stderr, "curl_easy_init() failed\n");

  if (v != 0)
    fprintf (stderr, "calling curl_global_cleanup()\n");

  curl_global_cleanup ();

  /* Make sure the verbose output and diagnostics is printed properly.
   */
  if (fflush (stderr) != 0)
    r = 1;

  return r;
}
