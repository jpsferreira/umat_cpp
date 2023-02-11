
#ifndef CALL_TS_EXPORT_H
#define CALL_TS_EXPORT_H

#ifdef CALL_TS_STATIC_DEFINE
#  define CALL_TS_EXPORT
#  define CALL_TS_NO_EXPORT
#else
#  ifndef CALL_TS_EXPORT
#    ifdef dl_model_EXPORTS
        /* We are building this library */
#      define CALL_TS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CALL_TS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CALL_TS_NO_EXPORT
#    define CALL_TS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CALL_TS_DEPRECATED
#  define CALL_TS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef CALL_TS_DEPRECATED_EXPORT
#  define CALL_TS_DEPRECATED_EXPORT CALL_TS_EXPORT CALL_TS_DEPRECATED
#endif

#ifndef CALL_TS_DEPRECATED_NO_EXPORT
#  define CALL_TS_DEPRECATED_NO_EXPORT CALL_TS_NO_EXPORT CALL_TS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CALL_TS_NO_DEPRECATED
#    define CALL_TS_NO_DEPRECATED
#  endif
#endif

#endif /* CALL_TS_EXPORT_H */
