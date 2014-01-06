/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_VA_IMPL_H
#define	_SYS_VA_IMPL_H

#pragma ident	"@(#)va_impl.h	1.1	04/11/19 SMI"

/*
 * An application should not include this header directly.  Instead it
 * should be included only through the inclusion of other Sun headers,
 * specifically <stdarg.h> and <varargs.h>.
 *
 * This header serves two purposes.
 *
 * First, it provides a common set of definitions that implementations
 * of the various standards for variable argument lists may use.  These
 * various standards are implemented in <varargs.h>, <stdarg.h>,
 * <iso/stdarg_iso.h>, <iso/stdarg_c99.h>, and <sys/varargs.h>.
 *
 * Second, it provides varying implementations of the common definitions,
 * depending upon the compiler.
 */

/*
 * The common definitions exported by this header or compilers using
 * this header are:
 *
 * the macro __va_start(list, name) starting the list iteration
 * the macro __va_arg(list, type) getting the current arg and iterating
 * the macro __va_copy(to, from) to bookmark the list iteration
 * the macro __va_end(list) to end the iteration
 *
 * In addition, the following are exported via inclusion of <sys/va_list.h>:
 *
 * the identifier __builtin_va_alist for the variable list pseudo parameter
 * the type __va_alist_type for the variable list pseudo parameter
 * the type __va_list defining the type of the variable list iterator
 */

/*
 * This header uses feature macros (e.g. __BUILTIN_VA_ARG_INCR and
 * __BUILTIN_VA_STRUCT), compiler macros (e.g. __GNUC__), and processor
 * macros (e.g. __sparc) to determine the protocol appropriate to the
 * current compilation.  It is intended that the compilation system
 * define the feature, processor, and compiler macros, not the user of
 * the system.
 */

/*
 * Many compilation systems depend upon the use of special functions
 * built into the the compilation system to handle variable argument
 * lists.  These built-in symbols may include one or more of the
 * following:
 *
 *      __builtin_va_alist
 *      __builtin_va_start
 *      __builtin_va_arg_incr
 *      __builtin_stdarg_start
 *      __builtin_va_end
 *      __builtin_va_arg
 *      __builtin_va_copy
 */

/*
 * The following are defined in <sys/va_list.h>:
 *
 *      __va_alist_type
 *      __va_void()
 *      __va_ptr_base
 *      ISA definitions via inclusion of <sys/isa_defs.h>
 *
 * Inclusion of this header also makes visible the symbols in <sys/va_list.h>.
 * This header is included in <varargs.h>, <sys/varargs.h> and in <stdarg.h>
 * via inclusion of <iso/stdarg_iso.h>.
 */

/*
 * The common definitions exported by this header or compilers using
 * this header are:
 *
 * the identifier __builtin_va_alist for the variable list pseudo parameter
 * the type __va_alist_type for the variable list pseudo parameter
 * the type __va_list defining the type of the variable list iterator
 *
 * The feature macros (e.g. __BUILTIN_VA_STRUCT) and compiler macros
 * (__GNUC__) and processor macros (e.g. __amd64) are intended to be
 * defined by the compilation system, not the user of the system.
 */

#include <features.h>
#include <sys/isa_defs.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_LP64)
#define	__va_alist_type long
#else
#define	__va_alist_type int
#endif

#if defined(__STDC__) /* source language is ISO C or C++ */

#define	__va_void(expr)	((void)expr)
#define	__va_ptr_base	void

#else /* source language is K&R C */

#define	__va_void(expr)	expr
#define	__va_ptr_base	char

#endif /* __STDC__ */

#if defined(__BUILTIN_VA_STRUCT) && !defined(__lint)	/* -------- protocol */

#if defined(__amd64)	/* processor */

typedef struct __va_list_element {
	unsigned int __va_gp_offset;
	unsigned int __va_fp_offset;
	void *__va_overflow_arg_area;
	void *__va_reg_sve_area;
} __va_list[1];

/* Other ISA __va_list structures added here under #elif */

#else	/* processor */

#error("No __va_list structure defined for ISA")

#endif	/* processor */

#else  /* default */				/* ---------------- protocol */

typedef __va_ptr_base *__va_list;

#endif  /* -------------------------------------------------------- protocol */

#if defined(__lint)	/* ---------------------------------------- protocol */

#define	__va_start(list, name)	((list) = (__va_list)&name)
#define	__va_arg(list, type)	((type *)(list))[0]
#define	__va_copy(to, from)	__va_void(((to) = (from)))
/*ARGSUSED*/
static void __va_end(__va_list list) { __va_end(list); }

#elif defined(__BUILTIN_VA_STRUCT)	/* ------------------------ protocol */

/* ISA __va_list structures defined in <sys/va_list.h> */

#if defined(__STDC__)	/* source language is ISO C or C++ */

void __builtin_va_start(__va_list, ...);
void *__builtin_va_arg_incr(__va_list, ...);

#else	/* source language is K&R C */

int __builtin_va_start();
char *__builtin_va_arg_incr();

#endif	/* source language */

#define	__va_start(list, name)	__builtin_va_start(list, 0)
#define	__va_arg(list, type)	\
	((type *)__builtin_va_arg_incr(list, (type *)0))[0]
#define	__va_copy(to, from)	__va_void(((to)[0] = (from)[0]))
#define	__va_end(list)		__va_void(0)

#elif defined(__BUILTIN_VA_ARG_INCR)	/* ------------------------ protocol */

#define	__va_start(list, name)	\
	__va_void(((list) = (__va_list)&__builtin_va_alist))
#define	__va_arg(list, type)	\
	((type *)__builtin_va_arg_incr((type *)(list)))[0]
#define	__va_copy(to, from)	__va_void(((to) = (from)))
#define	__va_end(list)		__va_void(0)

#elif defined(__GNUC__)	&& ((__GNUC__ == 2 && __GNUC_MINOR >= 96) || \
	(__GNUC__ >= 3))		/* ------------------------ protocol */

#define	__va_start(list, name)	__builtin_stdarg_start(list, name)
#define	__va_arg(list, type)	__builtin_va_arg(list, type)
#define	__va_end(list)		__builtin_va_end(list)
#define	__va_copy(to, from)	__builtin_va_copy(to, from)

#else					/* ----------------------- protocol */

/*
 * Because we can not predict the compiler protocol for unknown compilers, we
 * force an error in order to avoid unpredictable behavior. For versions of
 * gcc 2.95 and earlier, variable argument lists are handled in gcc specific
 * stdarg.h and varargs.h headers created via the gcc fixincl utility. In
 * those cases, the gcc headers would override this header.
 */

#error("Unrecognized compiler protocol for variable argument lists")

#endif  /* -------------------------------------------------------- protocol */

#ifndef __GNUC_VA_LIST
#define	__GNUC_VA_LIST
typedef __va_list __gnuc_va_list;
#endif  /* __GNUC_VA_LIST */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VA_IMPL_H */
