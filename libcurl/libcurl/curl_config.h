/* file      : libcurl/curl_config.h -*- C -*-
 * license   : curl License; see accompanying COPYING file
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
 * (in this exact form) for the change tracking.

#define CURL_OS
#define BUILDING_LIBCURL
#define CURL_STATICLIB

  */

/* See the ../../README-DEV for the SSL backend and CA information lookup
 * configuration.
 */
#define USE_OPENSSL 1

#ifdef _WIN32
#  define CURL_WITH_MULTI_SSL      1
#  define USE_SCHANNEL             1
#  define CURL_DEFAULT_SSL_BACKEND "schannel"
#endif

#if defined(__APPLE__) && defined(__clang__)
#  define USE_APPLE_SECTRUST 1
#else
#  undef  USE_APPLE_SECTRUST
#endif

#undef CURL_CA_NATIVE
#undef CURL_CA_SEARCH_SAFE
#undef CURL_DISABLE_CA_SEARCH

#undef  CURL_CA_BUNDLE
#undef  CURL_CA_PATH
#define CURL_CA_FALLBACK 1

#define CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG 1

#undef  USE_WOLFSSL
#undef  USE_SSLS_EXPORT

/* Enabled features.
 */
#define HAVE_LIBZ           1
#define HAVE_BROTLI         1
#define HAVE_ZSTD           1
#define CURL_ENABLE_NTLM    1
#define USE_RESOLV_THREADED 1
#define USE_IPV6            1

#undef CURL_DISABLE_COOKIES
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
#undef CURL_DISABLE_SMTP
#undef CURL_DISABLE_TELNET
#undef CURL_DISABLE_TFTP
#undef CURL_DISABLE_VERBOSE_STRINGS
#undef CURL_DISABLE_ALTSVC
#undef CURL_DISABLE_GETOPTIONS
#undef CURL_DISABLE_MQTT
#undef CURL_DISABLE_SOCKETPAIR
#undef CURL_DISABLE_HEADERS_API
#undef CURL_DISABLE_HSTS
#undef CURL_DISABLE_AWS
#undef CURL_DISABLE_BASIC_AUTH
#undef CURL_DISABLE_BEARER_AUTH
#undef CURL_DISABLE_BINDLOCAL
#undef CURL_DISABLE_DIGEST_AUTH
#undef CURL_DISABLE_FORM_API
#undef CURL_DISABLE_KERBEROS_AUTH
#undef CURL_DISABLE_NEGOTIATE_AUTH
#undef CURL_DISABLE_IPFS
#undef CURL_DISABLE_SHA512_256
#undef CURL_DISABLE_WEBSOCKETS

/* Disabled features.
 */
#define CURL_DISABLE_LDAP    1
#define CURL_DISABLE_LDAPS   1
#define CURL_DISABLE_HTTPSIG 1

#undef USE_WIN32_LDAP
#undef HAVE_LDAP_SSL
#undef HAVE_LDAP_SSL_H
#undef HAVE_LDAP_URL_PARSE
#undef USE_LIBSSH
#undef USE_LIBSSH2
#undef USE_AMISSL
#undef USE_GNUTLS
#undef USE_ARES
#undef USE_LIBPSL
#undef USE_MANUAL
#undef USE_MBEDTLS
#undef USE_NGHTTP2
#undef USE_NGHTTP3
#undef USE_NGTCP2
#undef USE_OPENLDAP
#undef USE_QUICHE
#undef USE_GSASL
#undef USE_RUSTLS
#undef USE_ECH
#undef USE_HTTP3
#undef USE_HTTPSRR
#undef USE_APPLE_FAST_UDP
#undef USE_APPLE_IDN
#undef USE_BACKTRACE
#undef USE_LIBUV
#undef USE_PROXY_HTTP3
#undef USE_RESOLV_ARES
#undef USE_WATT32
#undef HAVE_UV_H
#undef HAVE_GSSAPI_H
#undef HAVE_GSSAPPLE
#undef HAVE_GSS_SET_NEG_MECHS
#undef CURL_KRB5_VERSION

/* Specific for Linux.
 */
#ifdef __linux__
#  define HAVE_FSETXATTR_5   1
#  define HAVE_LINUX_TCP_H   1
#  define HAVE_EVENTFD       1
#  define HAVE_SYS_EVENTFD_H 1
#endif

/* Specific FreeBSD.
 */
#ifdef __FreeBSD__
#  define HAVE_MEMRCHR 1
#endif

/* Specific for MacOS.
 */
#ifdef __APPLE__
#  define HAVE_FSETXATTR_6        1
#  define HAVE_MACH_ABSOLUTE_TIME 1
#  define HAVE_MEMSET_S           1
#endif

/* Specific for FreeBSD and Linux.
 */
#if defined(__FreeBSD__) || defined(__linux__)
#  define HAVE_ACCEPT4  1
#  define HAVE_PIPE2    1
#  define HAVE_POLL     1
#  define HAVE_SENDMMSG 1
#endif

/* Specific for FreeBSD and Mac OS.
 */
#if defined(__FreeBSD__) || defined(__APPLE__)
#  define HAVE_SYS_SOCKIO_H 1
#  define HAVE_ARC4RANDOM   1
#endif

/* Specific for Linux and Mac OS.
 */
#if defined(__linux__) || defined(__APPLE__)
#  define HAVE_FSETXATTR                   1
#  define HAVE_CLOCK_GETTIME_MONOTONIC_RAW 1
#endif

/* Specific for POSIX.
 */
#ifndef _WIN32
#  define USE_UNIX_SOCKETS       1

#  define HAVE_ARPA_INET_H       1
#  define HAVE_IFADDRS_H         1
#  define HAVE_NETDB_H           1
#  define HAVE_NETINET_IN_H      1
#  define HAVE_NETINET_TCP_H     1
#  define HAVE_NET_IF_H          1
#  define HAVE_POLL_H            1
#  define HAVE_PWD_H             1
#  define HAVE_ALARM             1
#  define HAVE_FCNTL             1
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
#  define HAVE_SYS_UN_H          1
#  define HAVE_TERMIOS_H         1
#  define HAVE_UTIMES            1
#  define HAVE_SUSECONDS_T       1
#  define HAVE_NETINET_UDP_H     1
#  define HAVE_SENDMSG           1
#  define HAVE_NETINET_IP_H      1
#  define HAVE_THREADS_POSIX     1
#  define HAVE_LOCALTIME_R       1
#  define HAVE_FCHMOD            1
#  define HAVE_REALPATH          1
#  define HAVE_SA_FAMILY_T       1

#  define CURL_SA_FAMILY_T      sa_family_t
#  define GETHOSTNAME_TYPE_ARG2 size_t

#  define RANDOM_FILE           "/dev/urandom"

#  define CURL_EXTERN_SYMBOL    __attribute__ ((__visibility__ ("default")))

/* Specific for Windows.
 */
#else
#  define USE_WIN32_CRYPTO         1
#  define USE_WIN32_IDN            1
#  define USE_WINDOWS_SSPI         1

#  define HAVE_CLOSESOCKET         1
#  define HAVE_IOCTLSOCKET_FIONBIO 1
#  define HAVE_IO_H                1
#  define HAVE_SYS_UTIME_H         1

#  undef _UNICODE
#  undef UNICODE

#  undef SOCKET

/* The upstream's logic of defining the macro is quite hairy. Let's not
 * reproduce it here and see how it goes. Note that we also cannot undefine
 * it, since for MinGW GCC lib/curl_setup.h includes <_mingw.h>, which defines
 * the macro, before including this header. Keep it listed for the change
 * tracking.

#  undef _WIN32_WINNT

 */

/* For these ones sensible defaults are defined in lib/curl_setup.h.
 */
#  undef CURL_SA_FAMILY_T
#  undef GETHOSTNAME_TYPE_ARG2
#  undef WIN32_LEAN_AND_MEAN

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
#  define HAVE_LIBGEN_H                1
#  define HAVE_SIGNAL                  1
#  define HAVE_STRCASECMP              1
#  define HAVE_STRINGS_H               1
#  define HAVE_SYS_PARAM_H             1
#  define HAVE_UNISTD_H                1
#  define HAVE_UTIME_H                 1
#  define HAVE_SCHED_YIELD             1
#  define HAVE_FSEEKO                  1
#  define HAVE_DECL_FSEEKO             1
#  define HAVE_DIRENT_H                1
#  define HAVE_OPENDIR                 1
#endif

/* Common for all supported OSes/compilers.
 */
#define HAVE_STDBOOL_H                  1
#define HAVE_BOOL_T                     1
#define HAVE_FCNTL_H                    1
#define HAVE_LOCALE_H                   1
#define HAVE_SETLOCALE                  1
#define HAVE_GETADDRINFO                1
#define HAVE_FREEADDRINFO               1
#define HAVE_GETADDRINFO_THREADSAFE     1
#define HAVE_GETHOSTNAME                1
#define HAVE_GETPEERNAME                1
#define HAVE_GETSOCKNAME                1
#define HAVE_SOCKET                     1
#define HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID 1
#define HAVE_STRUCT_SOCKADDR_STORAGE    1
#define HAVE_STRUCT_TIMEVAL             1
#define HAVE_UTIME                      1
#define HAVE_STRICMP                    1
#define HAVE_STDATOMIC_H                1
#define HAVE_ATOMIC                     1

/* SSL_set0_wbio() was added in OpenSSL 1.1.0 and we don't care about earlier
 * versions.
 */
#define HAVE_SSL_SET0_WBIO              1

/* DES_ecb_encrypt() is used by NTLM. Note that it is deprecated but still
 * present in OpenSSL 3.
 */
#define HAVE_DES_ECB_ENCRYPT            1

#undef _LARGE_FILES
#undef _FILE_OFFSET_BITS

#undef HAVE_LBER_H
#undef HAVE_NETINET_IN6_H
#undef HAVE_IDN2_H
#undef HAVE_LIBIDN2
#undef HAVE_GETPASS_R
#undef HAVE_GSSAPI
#undef HAVE_GSSGNU
#undef HAVE_IOCTLSOCKET_CAMEL_FIONBIO
#undef HAVE_PROTO_BSDSOCKET_H
#undef HAVE_STRCMPI
#undef HAVE_STROPTS_H
#undef HAVE_TERMIO_H
#undef HAVE_TIME_T_UNSIGNED
#undef HAVE_WOLFSSL_GET_PEER_CERTIFICATE
#undef HAVE_WOLFSSL_USEALPN
#undef HAVE_WRITABLE_ARGV
#undef HAVE_MEMSET_EXPLICIT
#undef HAVE_CLOSESOCKET_CAMEL
#undef HAVE_GLIBC_STRERROR_R
#undef HAVE_QUICHE_CONN_SET_QLOG_FD
#undef HAVE_IOCTLSOCKET_CAMEL
#undef HAVE_MBEDTLS_DES_CRYPT_ECB
#undef HAVE_WC_DES_ECBENCRYPT
#undef HAVE_WOLFSSL_BIO_NEW
#undef HAVE_WOLFSSL_BIO_SET_SHUTDOWN
#undef HAVE_WOLFSSL_CTX_GENERATEECHCONFIG
#undef HAVE_SSL_SET1_ECH_CONFIG_LIST
#undef OPENSSL_QUIC_API2
#undef SEND_NONCONST_ARG2

#undef NEED_REENTRANT
#undef NEED_THREAD_SAFE

#undef USE_OS400CRYPTO

#undef BSD
#undef DEBUGBUILD
#undef CURL_DEBUG_GLOBAL_MEM

/* While upstream defines the macro for Clang, it fails to build for older
 * version of Clang on Mac OS. Thus, we never define it.
 */
#undef HAVE_BUILTIN_AVAILABLE

/* Note that lib/functypes.h defines the send() and recv() argument and
 * return value types.
 */
#define HAVE_SEND 1
#define HAVE_RECV 1

/* Types and type sizes.
 */
#ifndef _WIN32
#  define SIZEOF_LONG   __SIZEOF_LONG__
#  define SIZEOF_SIZE_T __SIZEOF_SIZE_T__

/* There is no way to exactly tell these type sizes at the preprocessing time,
 * so we define them as the most probable ones. We check this assumption at
 * the compile time using _Static_assert() in assert.c.
 */
#  define SIZEOF_OFF_T  __SIZEOF_LONG__
#  define SIZEOF_TIME_T __SIZEOF_LONG__
#else
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
 * data type (see include/curl/system.h for details) and we can probably
 * assume that's the case for the platforms we build for. We also check this
 * at the compile time using _Static_assert() in assert.c.
 */
#define SIZEOF_CURL_OFF_T 8

/* Define this macro in the same way as lib/curl_setup.h defines it as a
 * fallback. Also check the defined value at the compile time using
 * _Static_assert() in assert.c.
 */
#ifdef _WIN64
#  define SIZEOF_CURL_SOCKET_T 8
#else
#  define SIZEOF_CURL_SOCKET_T 4
#endif

/* We can probably assume that on platforms we build for, these keywords,
 * types, and macros do not require definition.

#undef const
#undef inline
#undef size_t
#undef ssize_t

#undef EAGAIN
#undef ENOMEM
#undef ENOSPC

#undef F_OK
#undef O_RDONLY

#undef LONG_MAX
#undef LONG_MIN

 */

#endif /* LIBCURL_CURL_CONFIG_H */
