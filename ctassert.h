#ifndef CTASSERT_H
#define CTASSERT_H

#if 0
#define __CONCAT1(x,y)  x ## y
#define __CONCAT(x,y)   __CONCAT1(x,y)
#endif

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"

#define CTASSERT(cond) \
	typedef char __CONCAT(__ctassert, __COUNTER__)[(cond) ? 0 : -1]

#endif
