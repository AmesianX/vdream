// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_DEBUG_NEW_H__
#define __V_DEBUG_NEW_H__

#ifdef _DEBUG

#include <new> // for size_t

// ----------------------------------------------------------------------------
// Overload functions
// ----------------------------------------------------------------------------
void* debug_add         (size_t size, const char* file, const int line, void* p);
void  debug_del         (void* p,     const char* file, const int line);

void* debug_malloc      (size_t size, const char* file, const int line);
void  debug_free        (void* p,     const char* file, const int line);

void* operator new      (size_t size, const char* file, const int line) throw(std::bad_alloc);
void  operator delete   (void* p,     const char* file, const int line) throw();
void  operator delete   (void* p) throw();
void* operator new[]    (size_t size, const char* file, const int line) throw(std::bad_alloc);
void  operator delete[] (void* p,     const char* file, const int line) throw();
void  operator delete[] (void* p) throw();

// ----------------------------------------------------------------------------
// Macros
// ----------------------------------------------------------------------------
#undef debug_new
#define debug_new new(__FILE__, __LINE__)

#undef new
#define new       debug_new

#undef malloc
#define malloc(A) debug_malloc((A),        __FILE__, __LINE__)

#undef free
#define free(A)   debug_free((A),          __FILE__, __LINE__)

#undef DEBUG_ADD
#define DEBUG_ADD debug_add(sizeof(*this), __FILE__, __LINE__, this)

#undef DEBUG_DEL
#define DEBUG_DEL debug_del(this,          __FILE__, __LINE__)

#endif // _DEBUG

#endif // __DEBUG_NEW_H__
