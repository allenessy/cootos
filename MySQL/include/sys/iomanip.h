/*
	Copyright 04/03/09 Sun Microsystems, Inc. All Rights Reserved
*/
/*  iomanip.h -- streams I/O manipulator declarations

    Copyright 1991 by TauMetric Corporation      ALL RIGHTS RESERVED

    @(#)iomanip.h	1.1  15 Jan 1992 15:57:47

*/
#ifndef _IOMANIP_H_
#define _IOMANIP_H_

#include <sys/iostream.h>
#include <generic.h>

#define SMANIP(typ)	name2(smanip_, typ)
#define SAPP(typ)	name2(sapply_, typ)
#define IMANIP(typ)	name2(imanip_, typ)
#define OMANIP(typ)	name2(omanip_, typ)
#define IOMANIP(typ)	name2(iomanip_, typ)
#define IAPP(typ)	name2(iapply_, typ)
#define OAPP(typ)	name2(oapply_, typ)
#define IOAPP(typ)	name2(ioapply_, typ)

#define IOMANIPdeclare(typ)						\
class SMANIP(typ) {							\
	ios& (*_fn)(ios&, typ);						\
	typ _ag;							\
public:									\
	SMANIP(typ)(ios& (*_f)(ios&, typ), typ _a) : _fn(_f), _ag(_a) {}\
	friend istream& operator>>(istream& _s, SMANIP(typ)& _f) {	\
			(*_f._fn)(_s, _f._ag); return _s; }		\
	friend istream& operator>>(istream& _s, const SMANIP(typ)& _f) {\
			(*_f._fn)(_s, _f._ag); return _s; }		\
	friend ostream& operator<<(ostream& _s, SMANIP(typ)& _f) {	\
			(*_f._fn)(_s, _f._ag); return _s; }		\
	friend ostream& operator<<(ostream& _s, const SMANIP(typ)& _f) {\
			(*_f._fn)(_s, _f._ag); return _s; }		\
	};								\
class SAPP(typ) {							\
	ios& (*_fn)(ios&, typ);						\
public:									\
	SAPP(typ)(ios& (*_f)(ios&, typ)) : _fn(_f) { }			\
	SMANIP(typ) operator()(typ _z) { return SMANIP(typ)(_fn, _z); }	\
	};								\
class IMANIP(typ) {							\
	istream& (*_fn)(istream&, typ);					\
	typ _ag;							\
public:									\
	IMANIP(typ)(istream& (*_f)(istream&, typ), typ _z ) :		\
		_fn(_f), _ag(_z) { }					\
	friend istream& operator>>(istream& _s, IMANIP(typ)& _f) {	\
		return(*_f._fn)(_s, _f._ag); }				\
	friend istream& operator>>(istream& _s, const IMANIP(typ)& _f) {\
		return(*_f._fn)(_s, _f._ag); }				\
	};								\
class IAPP(typ) {							\
	istream& (*_fn)(istream&, typ);					\
public:									\
	IAPP(typ)(istream& (*_f)(istream&, typ)) : _fn(_f) { }		\
	IMANIP(typ) operator()(typ _z) {				\
		return IMANIP(typ)(_fn, _z); }				\
	};								\
class OMANIP(typ) {							\
	ostream& (*_fn)(ostream&, typ);					\
	typ _ag;							\
public:									\
	OMANIP(typ)(ostream& (*_f)(ostream&, typ), typ _z ) :		\
		_fn(_f), _ag(_z) { }					\
	friend ostream& operator<<(ostream& _s, OMANIP(typ)& _f) { 	\
		return(*_f._fn)(_s, _f._ag); }				\
	friend ostream& operator<<(ostream& _s, const OMANIP(typ)& _f) {\
		return(*_f._fn)(_s, _f._ag); }				\
	};								\
class OAPP(typ) {							\
	ostream& (*_fn)(ostream&, typ);					\
public:									\
	OAPP(typ)(ostream& (*_f)(ostream&, typ)) : _fn(_f) { }		\
	OMANIP(typ) operator()(typ _z) {				\
		return OMANIP(typ)(_fn, _z); }				\
	};								\
class IOMANIP(typ) {							\
	iostream& (*_fn)(iostream&, typ);				\
	typ _ag;							\
public:									\
	IOMANIP(typ)(iostream& (*_f)(iostream&, typ), typ _z ) :	\
		_fn(_f), _ag(_z) { }					\
	friend istream& operator>>(iostream& _s, IOMANIP(typ)& _f) {	\
		return(*_f._fn)(_s, _f._ag); }				\
	friend istream& operator>>(iostream& _s, const IOMANIP(typ)& _f) {\
		return(*_f._fn)(_s, _f._ag); }				\
	friend ostream& operator<<(iostream& _s, IOMANIP(typ)& _f) {	\
		return(*_f._fn)(_s, _f._ag); }				\
	friend ostream& operator<<(iostream& _s, const IOMANIP(typ)& _f) {\
		return(*_f._fn)(_s, _f._ag); }				\
	};								\
class IOAPP(typ) {							\
	iostream& (*_fn)(iostream&, typ);				\
public:									\
	IOAPP(typ)(iostream& (*_f)(iostream&, typ)) : _fn(_f) { }	\
	IOMANIP(typ) operator()(typ _z) { return IOMANIP(typ)(_fn, _z); }\
	}



IOMANIPdeclare(int);
IOMANIPdeclare(long);

// set the conversion base to 0, 8, 10, or 16
smanip_int 	setbase(int _b);

// clear the flags bitvector according to the bits set in b
smanip_long	resetiosflags(long _b);

// set the flags bitvector according to the bits set in b
smanip_long	setiosflags(long _b);

// set fill character for padding a field
smanip_int	setfill(int _f);

// set the floating-point precision to n digits
smanip_int	setprecision(int _n);

// set the field width to n
smanip_int	setw(int _n);

#endif /* _IOMANIP_H_ */
