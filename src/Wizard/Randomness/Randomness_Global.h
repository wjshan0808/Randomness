#ifndef H_RANDOMNESS_GLOBAL_H
#define H_RANDOMNESS_GLOBAL_H

//
#if defined(_MSC_VER) || defined(__NT__) \
    || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) \
    || defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   define  Q_DECL_EXPORT __declspec(dllexport)
#   define  Q_DECL_IMPORT __declspec(dllimport)
#else
#   define  Q_DECL_EXPORT __attribute__((visibility("default")))
#   define  Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

//
#if defined(RANDOMNESS_LIBRARY)
#   define  RANDOMNESS_EXPORT Q_DECL_EXPORT
#else
#   define  RANDOMNESS_EXPORT Q_DECL_IMPORT
#endif



#endif // !H_RANDOMNESS_GLOBAL_H
