/*  @(#)floatingpoint.h 1.2 (Sun Microsystems, Inc.) 07/10/02  */

/*  Copyright © 1998 Sun Microsystems, Inc.
 *  All rights reserved.
 *
 *  f90 IEEE arithmetic function type definitions
*/

#define fp_direction_type integer
#ifdef sparc
#define	fp_nearest	0
#define	fp_tozero	1
#define	fp_positive	2
#define	fp_negative	3
#endif
#ifdef i386
#define	fp_nearest	0
#define	fp_negative	1
#define	fp_positive	2
#define	fp_tozero	3
#endif

#define fp_precision_type integer
#ifdef i386
#define	fp_single	0
#define fp_precision_3  1
#define	fp_double	2
#define	fp_extended	3
#else
#define	fp_extended	0
#define	fp_single	1
#define	fp_double	2
#define fp_precision_3  3
#endif

#define fp_exception_type integer
#ifdef i386
#define N_IEEE_EXCEPTION 6
#define	fp_invalid	0	/* exceptions according to bit number */
#define fp_denormalized 1
#define	fp_division	2
#define	fp_overflow	3
#define	fp_underflow	4
#define	fp_inexact	5
#endif
#ifdef sparc
#define N_IEEE_EXCEPTION 5
#define	fp_inexact	0	/* exceptions according to bit number */
#define	fp_division	1
#define	fp_underflow	2
#define	fp_overflow	3
#define	fp_invalid	4
#endif

#define fp_exception_field_type integer

#define	fp_class_type integer
#define	fp_zero		0
#define	fp_subnormal	1
#define	fp_normal	2
#define	fp_infinity   	3
#define	fp_quiet	4
#define	fp_signaling	5

#define sigfpe_code_type integer
#define sigfpe_handler_type integer
#define SIGFPE_DEFAULT	%val(0)	/* default exception handling */
#define SIGFPE_IGNORE	%val(1)	/* ignore exception */
#define SIGFPE_ABORT	%val(2)	/* abort on exception */

#define	convert_external_sparc	0
#define	convert_external_pc	1
#define	convert_external_vax	2
#define	convert_external_vaxg	3
#define	convert_external_s370	4
#define	convert_external_cray	5

#define	convert_external_signed	0
#define	convert_external_unsigned 1
#define	convert_external_float	2

#define	convert_external_common	(-1)
#define	convert_external_biased	(-2)
#define	convert_external_away	(-3)
