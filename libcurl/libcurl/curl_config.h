/* file      : libcurl/curl_config.h -*- C -*-
 * license   : cURL License; see accompanying COPYING file
 */

#ifndef LIBCURL_CURL_CONFIG_H
#define LIBCURL_CURL_CONFIG_H

/* For the semantics of the following macros refer to upstream's configure.ac,
 * .m4, lib/curl_config.h.cmake and lib/config-win32.h files.
 *
 * Note that we will explicitly undefine macros that should not be defined.
 * While this is not technically required, it simplifies the change tracking
 * (see ../README-DEV). As a bonus we also make sure that they are not get
 * eventually defined by some system headers.
 */

/* These macros are defined via the -D preprocessor option. Keep them listed
 * (in this exact form) for the change tracking (see ../README-DEV).

#define OS
#define VERSION

  */

/* See the ../../README-DEV for the SSL backend and CA information lookup
 * configuration.
 */
#define USE_OPENSSL 1
#define USE_TLS_SRP 1

#if (defined(__APPLE__) && defined(__clang__)) || defined(_WIN32)
#  define CURL_WITH_MULTI_SSL        1
#  if defined(__APPLE__)
#    define USE_SECTRANSP            1
#    define CURL_DEFAULT_SSL_BACKEND "secure-transport"
#  else
#    define USE_SCHANNEL             1
#    define CURL_DEFAULT_SSL_BACKEND "schannel"
#  endif
#endif

#undef  CURL_CA_BUNDLE
#undef  CURL_CA_PATH
#define CURL_CA_FALLBACK 1

#define CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG 1

#undef  HAVE_BORINGSSL
#undef  USE_WOLFSSL

/* Enabled features.
 */
#define ENABLE_IPV6 1
#define HAVE_ZLIB_H 1
#define HAVE_LIBZ   1

#undef CURL_DISABLE_COOKIES
#undef CURL_DISABLE_CRYPTO_AUTH
#undef CURL_DISABLE_DICT
#undef CURL_DISABLE_DOH
#undef CURL_DISABLE_FILE
#undef CURL_DISABLE_FTP
#undef CURL_DISABLE_GOPHER
#undef CURL_DISABLE_HTTP
#undef CURL_DISABLE_HTTP_AUTH
#undef CURL_DISABLE_IMAP
#undef CURL_DISABLE_MIME
#undef CURL_DISABLE_LIBCURL_OPTION
#undef CURL_DISABLE_NETRC
#undef CURL_DISABLE_PARSEDATE
#undef CURL_DISABLE_POP3
#undef CURL_DISABLE_PROGRESS_METER
#undef CURL_DISABLE_PROXY
#undef CURL_DISABLE_RTSP
#undef CURL_DISABLE_SHUFFLE_DNS
#undef CURL_DISABLE_SMB
#undef CURL_DISABLE_SMTP
#undef CURL_DISABLE_TELNET
#undef CURL_DISABLE_TFTP
#undef CURL_DISABLE_VERBOSE_STRINGS

/* Diabled features.
 */
#define CURL_DISABLE_LDAP  1
#define CURL_DISABLE_LDAPS 1

#undef USE_WIN32_LDAP
#undef HAVE_LDAP_SSL
#undef HAVE_LDAP_SSL_H
#undef HAVE_LDAP_URL_PARSE

#undef USE_LIBSSH
#undef USE_LIBSSH2
#undef HAVE_LIBSSH2_H
#undef HAVE_LIBSSH_LIBSSH_H
#undef USE_AMISSL
#undef USE_GNUTLS
#undef USE_GNUTLS_NETTLE
#undef USE_ARES
#undef USE_ESNI
#undef USE_LIBPSL
#undef USE_MANUAL
#undef USE_MBEDTLS
#undef USE_MESALINK
#undef USE_METALINK
#undef USE_NGHTTP2
#undef USE_NGHTTP3
#undef USE_NGTCP2
#undef USE_NSS
#undef USE_OPENLDAP
#undef USE_ALTSVC
#undef USE_LIBRTMP
#undef USE_QUICHE

/* Specific for (non-) Linux.
 */
#ifdef __linux__
#  define HAVE_FSETXATTR_5 1
#  define HAVE_LINUX_TCP_H 1
#else
#  define HAVE_SETMODE 1
#endif

/* Specific FreeBSD.
 */
#ifdef __FreeBSD__
#  define HAVE_MEMRCHR 1
#endif

/* Specific for MacOS.
 */
#ifdef __APPLE__
#  define HAVE_FSETXATTR_6         1
#  define HAVE_MACH_ABSOLUTE_TIME  1
#  define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Specific for FreeBSD and Linux.
 */
#if defined(__FreeBSD__) || defined(__linux__)
#  define HAVE_MSG_NOSIGNAL 1
#  define HAVE_POLL_FINE    1
#endif

/* Specific for FreeBSD and Mac OS.
 */
#if defined(__FreeBSD__) || defined(__APPLE__)
#  define HAVE_SYS_SOCKIO_H 1
#endif

/* Specific for Linux and Mac OS.
 */
#if defined(__linux__) || defined(__APPLE__)
#  define HAVE_FSETXATTR 1
#endif

/* Specific for POSIX.
 */
#ifndef _WIN32
#  define HAVE_ARPA_INET_H       1
#  define HAVE_IFADDRS_H         1
#  define HAVE_NETDB_H           1
#  define HAVE_NETINET_IN_H      1
#  define HAVE_NETINET_TCP_H     1
#  define HAVE_NET_IF_H          1
#  define HAVE_POLL_H            1
#  define HAVE_PWD_H             1
#  define HAVE_ALARM             1
#  define HAVE_FCNTL_O_NONBLOCK  1
#  define HAVE_FNMATCH           1
#  define HAVE_GETEUID           1
#  define HAVE_GETIFADDRS        1
#  define HAVE_GETPWUID          1
#  define HAVE_GETPWUID_R        1
#  define HAVE_GETTIMEOFDAY      1
#  define HAVE_GMTIME_R          1
#  define HAVE_IF_NAMETOINDEX    1
#  define HAVE_IOCTL_FIONBIO     1
#  define HAVE_IOCTL_SIOCGIFADDR 1
#  define HAVE_PIPE              1
#  define HAVE_POSIX_STRERROR_R  1
#  define HAVE_SIGACTION         1
#  define HAVE_SIGSETJMP         1
#  define HAVE_SOCKETPAIR        1
#  define HAVE_STRERROR_R        1
#  define HAVE_SYS_IOCTL_H       1
#  define HAVE_SYS_POLL_H        1
#  define HAVE_SYS_SELECT_H      1
#  define HAVE_SYS_SOCKET_H      1
#  define HAVE_SYS_UN_H          1
#  define HAVE_SYS_WAIT_H        1
#  define HAVE_TERMIOS_H         1
#  define HAVE_UTIMES            1
#  define NTLM_WB_ENABLED        1
#  define USE_UNIX_SOCKETS       1

#  define CURL_SA_FAMILY_T      sa_family_t
#  define GETHOSTNAME_TYPE_ARG2 size_t

#  define NTLM_WB_FILE          "/usr/bin/ntlm_auth"
#  define RANDOM_FILE           "/dev/urandom"

#  define CURL_EXTERN_SYMBOL    __attribute__ ((__visibility__ ("default")))

/* Specific for Windows.
 */
#else
#  define HAVE_PROCESS_H           1
#  define HAVE_STRUCT_POLLFD       1
#  define USE_WIN32_CRYPTO         1
#  define HAVE_CLOSESOCKET         1
#  define HAVE_IOCTLSOCKET_FIONBIO 1
#  define HAVE_IO_H                1
#  define HAVE_SYS_UTIME_H         1
#  define HAVE_WINDOWS_H           1
#  define HAVE_WINSOCK2_H          1
#  define HAVE_WINSOCK_H           1
#  define USE_WIN32_IDN            1
#  define USE_WIN32_LARGE_FILES    1
#  define USE_WINDOWS_SSPI         1
#  define WANT_IDN_PROTOTYPES      1

#  undef SOCKET
#  undef USE_LWIPSOCK
#  undef USE_WIN32_SMALL_FILES

/* The upstream's logic of defining the macro is quite hairy. Let's not
 * reproduce it here and see how it goes.
 */
#  undef _WIN32_WINNT

/* For these ones sensible defaults are defined in lib/curl_setup.h.
 */
#  undef CURL_SA_FAMILY_T
#  undef GETHOSTNAME_TYPE_ARG2
#  undef USE_WINSOCK

/* Unused on Windows (see include/curl/curl.h for details).
 */
#  undef CURL_EXTERN_SYMBOL
#endif

/* Specific for GNU C Library.
 */
#ifdef __GLIBC__
#  define HAVE_GETHOSTBYNAME_R   1
#  define HAVE_GETHOSTBYNAME_R_6 1
#  undef HAVE_GETHOSTBYNAME_R_3
#  undef HAVE_GETHOSTBYNAME_R_5
#endif

/* Specific for (non-) VC.
 */
#ifndef _MSC_VER
#  define HAVE_BASENAME                1
#  define HAVE_CLOCK_GETTIME_MONOTONIC 1
#  define HAVE_INET_NTOP               1
#  define HAVE_INET_PTON               1
#  define HAVE_LIBGEN_H                1
#  define HAVE_PTHREAD_H               1
#  define HAVE_SETJMP_H                1
#  define HAVE_SIGNAL                  1
#  define HAVE_STRCASECMP              1
#  define HAVE_STRINGS_H               1
#  define HAVE_STRING_H                1
#  define HAVE_STRTOK_R                1
#  define HAVE_SYS_PARAM_H             1
#  define HAVE_SYS_TIME_H              1
#  define HAVE_UNISTD_H                1
#  define HAVE_UTIME_H                 1
#  define HAVE_VARIADIC_MACROS_GCC     1
#  define TIME_WITH_SYS_TIME           1
#  define USE_THREADS_POSIX            1
#  undef  USE_THREADS_WIN32
#else
#  define NEED_MALLOC_H     1
#  define USE_THREADS_WIN32 1
#  undef  USE_THREADS_POSIX
#endif

/* Common for all supported OSes/compilers.
 */
#define HAVE_ASSERT_H                   1
#define HAVE_STDBOOL_H                  1
#define HAVE_BOOL_T                     1
#define HAVE_ERRNO_H                    1
#define HAVE_FCNTL_H                    1
#define HAVE_WS2TCPIP_H                 1
#define HAVE_SIGNAL_H                   1
#define HAVE_LOCALE_H                   1
#define HAVE_SETLOCALE                  1
#define HAVE_GETADDRINFO                1
#define HAVE_FREEADDRINFO               1
#define HAVE_GETADDRINFO_THREADSAFE     1
#define HAVE_FTRUNCATE                  1
#define HAVE_GETHOSTBYNAME              1
#define HAVE_GETHOSTNAME                1
#define HAVE_GETPEERNAME                1
#define HAVE_GETSOCKNAME                1
#define HAVE_LONGLONG                   1
#define HAVE_OPENSSL_VERSION            1
#define HAVE_SOCKET                     1
#define HAVE_SELECT                     1
#define HAVE_SIG_ATOMIC_T               1
#define HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID 1
#define HAVE_STRDUP                     1
#define HAVE_STRTOLL                    1
#define HAVE_STRUCT_SOCKADDR_STORAGE    1
#define HAVE_STRUCT_TIMEVAL             1
#define HAVE_SYS_STAT_H                 1
#define HAVE_SYS_TYPES_H                1
#define HAVE_TIME_H                     1
#define HAVE_UTIME                      1
#define HAVE_VARIADIC_MACROS_C99        1
#define STDC_HEADERS                    1

#undef _ALL_SOURCE
#undef _LARGE_FILES
#undef HAVE_LBER_H
#undef HAVE_NETINET_IN6_H
#undef HAVE_GSSAPI_GSSAPI_GENERIC_H
#undef HAVE_GSSAPI_GSSAPI_H
#undef HAVE_IDN2_H
#undef HAVE_LIBIDN2
#undef HAVE_BROTLI
#undef EGD_SOCKET
#undef DEBUGBUILD
#undef HAVE_DECL_GETPWUID_R_MISSING
#undef HAVE_GETPASS_R
#undef HAVE_GNUTLS_ALPN_SET_PROTOCOLS
#undef HAVE_GNUTLS_CERTIFICATE_SET_X509_KEY_FILE2
#undef HAVE_GNUTLS_OCSP_REQ_INIT
#undef HAVE_GSSAPI
#undef HAVE_GSSGNU
#undef HAVE_IOCTLSOCKET_CAMEL_FIONBIO
#undef HAVE_OLD_GSSMIT
#undef HAVE_PK11_CREATEMANAGEDGENERICOBJECT
#undef HAVE_PROTO_BSDSOCKET_H
#undef HAVE_RAND_EGD
#undef HAVE_SETSOCKOPT_SO_NONBLOCK
#undef HAVE_SIG_ATOMIC_T_VOLATILE
#undef HAVE_SSLV2_CLIENT_METHOD
#undef HAVE_STRCMPI
#undef HAVE_STROPTS_H
#undef HAVE_TERMIO_H
#undef HAVE_TIME_T_UNSIGNED
#undef HAVE_WOLFSSLV3_CLIENT_METHOD
#undef HAVE_WOLFSSL_GET_PEER_CERTIFICATE
#undef HAVE_WOLFSSL_USEALPN
#undef HAVE_WRITABLE_ARGV
#undef NEED_MEMORY_H
#undef NEED_REENTRANT
#undef NEED_THREAD_SAFE

#undef CURLDEBUG
#undef HAVE_GETNAMEINFO
#undef GETNAMEINFO_QUAL_ARG1
#undef GETNAMEINFO_TYPE_ARG1
#undef GETNAMEINFO_TYPE_ARG2
#undef GETNAMEINFO_TYPE_ARG46
#undef GETNAMEINFO_TYPE_ARG7

#undef HAVE_RECVFROM
#undef RECVFROM_TYPE_ARG1
#undef RECVFROM_TYPE_ARG2
#undef RECVFROM_TYPE_ARG3
#undef RECVFROM_TYPE_ARG4
#undef RECVFROM_TYPE_ARG5
#undef RECVFROM_TYPE_ARG6
#undef RECVFROM_TYPE_RETV

/* While upstream defines the macro for Clang, it fails to build for older
 * version of Clang on Mac OS. Thus, we never define it.
 */
#undef HAVE_BUILTIN_AVAILABLE

/* send()
 */
#define HAVE_SEND        1
#ifndef _WIN32
#  define SEND_TYPE_ARG1 int
#  define SEND_TYPE_ARG2 void *
#  define SEND_TYPE_ARG3 size_t
#  define SEND_TYPE_ARG4 int
#  define SEND_TYPE_RETV ssize_t
#else
#  define SEND_TYPE_ARG1 SOCKET
#  define SEND_TYPE_ARG2 char *
#  define SEND_TYPE_ARG3 int
#  define SEND_TYPE_ARG4 int
#  define SEND_TYPE_RETV int
#endif

/* recv()
 */
#define HAVE_RECV        1
#ifndef _WIN32
#  define RECV_TYPE_ARG1 int
#  define RECV_TYPE_ARG2 void *
#  define RECV_TYPE_ARG3 size_t
#  define RECV_TYPE_ARG4 int
#  define RECV_TYPE_RETV ssize_t
#else
#  define RECV_TYPE_ARG1 SOCKET
#  define RECV_TYPE_ARG2 char *
#  define RECV_TYPE_ARG3 int
#  define RECV_TYPE_ARG4 int
#  define RECV_TYPE_RETV int
#endif

/* Types and type sizes.
 */
#ifndef _WIN32
#  define SIZEOF_SHORT  __SIZEOF_SHORT__
#  define SIZEOF_INT    __SIZEOF_INT__
#  define SIZEOF_LONG   __SIZEOF_LONG__
#  define SIZEOF_SIZE_T __SIZEOF_SIZE_T__

/* There is no way to exactly tell these type sizes at the preprocessing time,
 * so we define them as the most probable ones. We check this assumption at
 * the compile time using _Static_assert() in assert.c.
 */
#  define SIZEOF_OFF_T  __SIZEOF_LONG__
#  define SIZEOF_TIME_T __SIZEOF_LONG__
#else
#  define SIZEOF_SHORT    2
#  define SIZEOF_INT      4
#  define SIZEOF_LONG     4
#  define SIZEOF_OFF_T    4
#  ifdef _WIN64
#    define SIZEOF_TIME_T 8
#    define SIZEOF_SIZE_T 8
#  else
#    define SIZEOF_TIME_T 8
#    define SIZEOF_SIZE_T 4
#  endif
#  define in_addr_t unsigned long

/* Inspired by lib/config-win32.h.
 */
#  if defined(_MSC_VER) && !defined(_SSIZE_T_DEFINED)
#    if defined(_WIN64)
#      define ssize_t __int64
#    else
#      define ssize_t int
#    endif
#    define _SSIZE_T_DEFINED
#  endif
#endif

/* Is always 8 bytes for any platform that provides a 64-bit signed integral
 * data type (see include/curl/system.h for details) and we can parobably
 * assume that's the case for the platforms we build for. We also check this
 * at the compile time using _Static_assert() in assert.c.
 */
#define SIZEOF_CURL_OFF_T 8

#define RETSIGTYPE     void
#define SEND_QUAL_ARG2 const

/* We can probably assume that on platforms we build for, these keywords/types
 * doesn't require definition.

#undef const
#undef inline
#undef size_t
#undef ssize_t

*/

#endif /* LIBCURL_CURL_CONFIG_H */
