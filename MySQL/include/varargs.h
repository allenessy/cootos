/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _VARARGS_H
#define	_VARARGS_H

#pragma ident	"@(#)varargs.h	1.43	04/11/19 SMI"

/*
 * This header defines the pre-standard variable argument definitions.
 * Programs using this header should migrate to using <stdarg.h>.
 *
 * The varargs definitions within this header are defined in terms of
 * implementation definitions. These implementation definitions reside
 * in <sys/va_impl.h>.  This organization enables protected use of
 * the implementation by other standard headers without introducing
 * names into the users' namespace.
 */

#include <va_impl.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef	_VA_LIST
#define	_VA_LIST
typedef __va_list va_list;
#endif

#define	va_alist		__builtin_va_alist
#define	va_dcl			__va_alist_type va_alist;
#define	va_start(list)		__va_start(list, va_alist)
#define	va_arg(list, type)	__va_arg(list, type)
#define	va_end(list)		__va_end(list)

/*
 * va_copy is a Solaris extension to provide a portable way to perform
 * a variable argument list ``bookmarking'' function.
 */
#if defined(__EXTENSIONS__) || \
	(!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX))

#define	va_copy(to, from)	__va_copy(to, from)

#endif	/* defined(__EXTENSIONS__) || (!defined(_STRICT_STDC) && ... ) */

#ifdef	__cplusplus
}
#endif

#endif	/* _VARARGS_H */
