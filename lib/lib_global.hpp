#ifndef LIB_GLOBAL_HPP
#define LIB_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(LIB_LIBRARY)
#  define LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIB_GLOBAL_HPP
