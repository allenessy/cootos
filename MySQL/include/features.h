/*
 * Copyright (c) 2006, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _FEATURES_H
/*
 * Include GNU's features.h
 */
#include_next <features.h>

/* 
 * features.h defines __GLIBC_HAVE_LONG_LONG macro only for select
 * compilers. While we're not in that list, define the macro here.
 * Needed for int64_t and other features
 */
#define __GLIBC_HAVE_LONG_LONG  1

#if __SUNPRO_CC_COMPAT=='G'
#undef __flexarr
#define __flexarr [0]
#endif


#if defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199901L)
#undef __USE_ISOC99
#endif

#endif
