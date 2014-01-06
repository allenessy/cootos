/*
	Copyright 05/10/04 Sun Microsystems, Inc. All Rights Reserved
*/
/*  iostream.h -- basic stream I/O declarations

    Copyright 1991, 1992 by TauMetric Corporation      ALL RIGHTS RESERVED

    @(#)iostream.h	1.8  05/10/04 09:48:01

*/

#ifndef _IOSTREAM_H_
#define _IOSTREAM_H_

// The macro IOSTREAMH is defined so as to build USL's SCL3.0
#ifndef IOSTREAMH
#define IOSTREAMH
#endif

#include "rlocks.h"

// Definition of EOF must match the one in <stdio.h>
#define EOF (-1)

// Definition of WEOF must match the one in <widec.h>
#ifndef WEOF
#define WEOF (-1)
#endif

// extract a char from int i, ensuring that zapeof(EOF) != EOF
#define	zapeof(i) ((unsigned char)(i))

typedef long streampos;		// should be int or long
typedef long streamoff;		// should be int or long
#ifdef __linux__
typedef unsigned int __wint_t;
#else
typedef long __wint_t;
#endif

class streambuf;
class istream;
class unsafe_istream;
class ostream;
class unsafe_ostream;


class unsafe_ios {
public:
	// stream status bits
	enum io_state	{
		goodbit	 = 0x00,	// no bit set: all is ok
		eofbit	 = 0x01,	// at end of file
		failbit	 = 0x02,	// last I/O operation failed
		badbit	 = 0x04,	// invalid operation attempted
		hardfail = 0x80		// unrecoverable error
		};

	// stream operation mode
	enum open_mode	{
		binary	 = 0x00,	// binary mode
		in	 = 0x01,	// open for reading
		out	 = 0x02,	// open for writing
		ate	 = 0x04,	// seek to eof upon original open
		app	 = 0x08,	// append mode: all additions at eof
		trunc	 = 0x10,	// truncate file if already exists
		nocreate = 0x20,	// open fails if file doesn't exist
		noreplace= 0x40		// open fails if file already exists
		};

	// stream seek direction
	enum seek_dir { beg=0, cur=1, end=2 };

	// formatting flags
	enum	{
		skipws	  = 0x0001,	// skip whitespace on input
		left	  = 0x0002,	// left-adjust output
		right	  = 0x0004,	// right-adjust output
		internal  = 0x0008,	// padding after sign or base indicator
		dec	  = 0x0010,	// decimal conversion
		oct	  = 0x0020,	// octal conversion
		hex	  = 0x0040,	// hexidecimal conversion
		showbase  = 0x0080,	// use base indicator on output
		showpoint = 0x0100,	// force decimal point (floating output)
		uppercase = 0x0200,	// upper-case hex output
		showpos	  = 0x0400,	// add '+' to positive integers
		scientific= 0x0800,	// use 1.2345E2 floating notation
		fixed	  = 0x1000,	// use 123.45 floating notation
		unitbuf	  = 0x2000,	// flush all streams after insertion
		stdio	  = 0x4000	// flush stdout, stderr after insertion
		};

	// constants for second parameter of seft()
static	const long basefield;		// dec | oct | hex
static	const long adjustfield;		// left | right | internal
static	const long floatfield;		// scientific | fixed

	// constructor, destructor
		unsafe_ios(streambuf*);
virtual		~unsafe_ios();

	// for reading/setting/clearing format flags
	long	flags();
	long	flags(long);
	long	setf(long _setbits, long _field);
	long	setf(long);
	long	unsetf(long);

	// reading/setting field width
	int	width();
	int	width(int);

	// reading/setting padding character
	char	fill();
	char	fill(char);

	// reading/setting digits of floating precision
	int	precision(int);
	int	precision();

	// reading/setting ostream tied to this stream
	ostream* tie(ostream*);
	ostream* tie();

	// find out about current stream state
	int	rdstate();		// return the stream state
	int	eof();			// non-zero on end of file
	int	fail();			// non-zero if an operation failed
	int	bad();			// non-zero if error occurred
	int	good();			// non-zero if no state bits set
	void	clear(int = 0);		// set the stream state
// 		operator void* ();	removed because of overloading 
// ambiguity between this and the one in ios
	int	operator! ();		// non-zero if state failed

	streambuf* rdbuf();		// get the assigned streambuf

	// for declaring additional flag bits and user words
static long	bitalloc();	// acquire a new flag bit, value returned
static int	xalloc();	// acquire a new user word, index returned
	long  & iword(int);	// return the nth user word as an int
	void* & pword(int);	// return the nth user word as a pointer

static void	sync_with_stdio();

	// obsolete, for streams 1.2 compatibility
	int	skip(int);

protected:
	// additional state flags for ispecial and ospecial
	enum { skipping = 0x100, tied = 0x200 };

	streambuf* bp;		// the associated streambuf
	ostream* x_tie;		// the tied ostream, if any
	int	state;		// status bits
	int	ispecial;	// istream status bits	***
	int	ospecial;	// ostream status bits	***
	long 	x_flags;	// formatting flag bits
	int	x_precision;	// floating-point precision on output
	int 	x_width;	// field width on output
	int	x_fill;		// padding character on output
	int	isfx_special;	// unused		***
	int	osfx_special;	// unused		***
	int	delbuf;		// unused		***
	int	assign_private;	// unused		***

/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */

		unsafe_ios();	// null constructor, does not initialize

	void	init(streambuf*);	// the actual initialization

	void	setstate(int);	// set all status bits

static	void	(*stdioflush)();

private:
	// for extra flag bits and user words
static	long	nextbit;
static	int	usercount;
	union ios_user_union *userwords;
	int	nwords;
	void	usersize(int);

	// these declarations prevent automatic copying of an ios
		unsafe_ios(unsafe_ios&);	// declared but not defined
	void	operator= (unsafe_ios&);	// declared but not defined

};
inline streambuf* unsafe_ios::rdbuf() { return bp; }
inline ostream* unsafe_ios::tie() { return x_tie; }    
inline char	unsafe_ios::fill() { return x_fill; }
inline int	unsafe_ios::precision() { return x_precision; }
inline int	unsafe_ios::rdstate() { return state; }
inline int	unsafe_ios::eof() { return state & eofbit; }
inline int	unsafe_ios::fail() { return state & (failbit | badbit | hardfail); }
inline int	unsafe_ios::bad() { return state & (badbit | hardfail); }
inline int	unsafe_ios::good() { return state == 0; }
inline long	unsafe_ios::flags() { return x_flags; }
inline int	unsafe_ios::width() { return x_width; }
inline int	unsafe_ios::width(int _w) { int _i = x_width; x_width = _w; return _i; }
inline char	unsafe_ios::fill(char _c) { char _x = x_fill; x_fill = _c; return _x; }
inline int	unsafe_ios::precision(int _p) {
			int _x = x_precision; x_precision = _p; return _x;
		}
// inline		ios::operator void* () { return fail() ? 0 : this; }
inline int	unsafe_ios::operator! () { return fail(); }


// SAFE version

class ios : virtual public unsafe_ios, public stream_MT {
public:
      // formatting enums inherited
      // constructor, destructor
         ios(streambuf*);

virtual ~ios();

      static   void ios_mutex_init();



	// for reading/setting/clearing format flags
	long	flags();
	long	flags(long);
	long	setf(long _setbits, long _field);
	long	setf(long);
	long	unsetf(long);

	// reading/setting field width
	int	width();
	int	width(int);

	// reading/setting padding character
	char	fill();
	char	fill(char);

	// reading/setting digits of floating precision
	int	precision(int);
	int	precision();

	// reading/setting ostream tied to this stream
	ostream* tie(ostream*);
	ostream* tie();

	// find out about current stream state
	int	rdstate();		// return the stream state
	int	eof();			// non-zero on end of file
	int	fail();			// non-zero if an operation failed
	int	bad();			// non-zero if error occurred
	int	good();			// non-zero if no state bits set
	void	clear(int = 0);		// set the stream state
		operator void* ();	// zero if state failed
	int	operator! ();		// non-zero if state failed

	streambuf* rdbuf();		// get the assigned streambuf

	// for declaring additional flag bits and user words
static long	bitalloc();	// acquire a new flag bit, value returned
static int	xalloc();	// acquire a new user word, index returned
	long  & iword(int);	// return the nth user word as an int
	void* & pword(int);	// return the nth user word as a pointer

static void	sync_with_stdio();

	// obsolete, for streams 1.2 compatibility
	int	skip(int);

protected:
		ios();		// null constructor, does not initialize
	void	init(streambuf*);	// the actual initialization

	void	setstate(int);	// set all status bits

static	void	(*stdioflush)();

protected:
      static stream_rmutex static_mutlock;
      static int mutex_init_count;

private:
	// these declarations prevent automatic copying of an ios
	ios(ios&);			// declared but not defined
	void    operator= (ios&);	// declared but not defined
};

inline streambuf* ios::rdbuf() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::rdbuf(); 
}
inline ostream* ios::tie() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::tie(); 
}    
inline ostream* ios::tie(ostream* s) {
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::tie(s);
}
inline int ios::rdstate() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::rdstate(); 
}
inline int ios::eof() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::eof(); 
}
inline int ios::fail() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::fail(); 
}
inline int ios::bad() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::bad();
}
inline int ios::good() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::good();
}
inline long ios::flags() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::flags(); 
}
inline long ios::flags(long l) { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::flags(l); 
}
inline int ios::width() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::width(); 
}
inline int ios::width(int _w) { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::width(_w);
}
inline char ios::fill() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::fill(); 
}
inline char ios::fill(char _c) { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::fill(_c);
}
inline int ios::precision() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::precision(); 
}
inline int ios::precision(int _p) {
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::precision(_p);
}
inline ios::operator void* () { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return (unsafe_ios::fail() ? 0 : this);
}
inline int ios::operator! () { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return unsafe_ios::operator!(); 
}

inline void ios::clear(int i) {
    STREAM_RMUTEX_LOCK(this, lckp);
    unsafe_ios::clear(i);
}

inline int ios::skip(int i) {
  STREAM_RMUTEX_LOCK(this, lckp);
  int skip_return = unsafe_ios::skip(i);
  return skip_return;
}

inline void ios::setstate(int b) {
  STREAM_RMUTEX_LOCK(this, lckp);
  unsafe_ios::setstate(b);
}


class streambuf : public stream_MT {
public:
	// constructors and destructors
	streambuf();		// make empty streambuf
	streambuf(char*, int);	// make streambuf with given char array
virtual	~streambuf();

	// use the provided char array for the buffer if possible
virtual streambuf* setbuf(char*, int);
	// WARNING:  this function is not virtual; do not override
   	streambuf* setbuf(unsigned char*, int);

	// obsolete, for streams 1.2 compatibility
	streambuf* setbuf(char*, int, int);

	// getting (extracting) characters
	int	sgetc();		// peek at next char
	int	snextc();		// advance to and return next char
	int	sbumpc();		// return current char and advance
	void	stossc();		// advance to next character
	int	sgetn(char*, int);	// get next n chars
virtual int	xsgetn(char*, int);	// implementation of sgetn
virtual int	underflow();		// fill empty buffer
	int	sputbackc(char);	// return char to input
virtual int	pbackfail(int);		// implementation of sputbackc
	int	in_avail();		// number of avail chars in buffer

	// putting (inserting) characters
	int	sputc(int);		// put one char
	int	sputn(const char*, int); // put n chars from string

virtual int	xsputn(const char* s, int n); //implementation of sputn
virtual int	overflow(int = EOF);	//  flush buffer and make more room
	int	out_waiting();		// number of unflushed chars

	// moving around in stream 
virtual streampos seekoff(streamoff, unsafe_ios::seek_dir, int = (unsafe_ios::in | unsafe_ios::out));
virtual streampos seekpos(streampos, int = (unsafe_ios::in | unsafe_ios::out));
virtual int	sync(); 

	void	dbp();		// for debugging streambuf implementations
	int	sgetc_unlocked();    // UNSAFE peek at next char
	int	snextc_unlocked();   // UNSAFE advance to and return next char
	int	sbumpc_unlocked();   // UNSAFE return current char and advance
	void	stossc_unlocked();   // UNSAFE advance to next character
	int	sgetn_unlocked(char*, int); // UNSAFE get next n chars
	int	sputbackc_unlocked(char); // UNSAFE return char to input
	int	in_avail_unlocked(); // UNSAFE number of avail chars in buffer
	int	sputc_unlocked(int);	// UNSAFE put one char
	int	sputn_unlocked(const char*, int); // UNSAFE put n chars from string
	int	out_waiting_unlocked();	//UNSAFE  number of unflushed chars

protected:
	char*	base();		// return start of buffer area
	char*	ebuf();		// return end+1 of buffer area
	int	blen();		// return length of buffer area
	char*	pbase();	// return start of put area
	char*	pptr();		// return next location in put area
	char*	epptr();	// return end+1 of put area
	char*	eback();	// return base of putback section of get area
	char*	gptr();		// return next location in get area
	char*	egptr();	// return end+1 of get area
	void	setp(char*, char*); // initialize the put pointers
	void	setg(char*, char*, char*); // initialize the get pointers
	void	pbump(int);	// advance the put pointer
	void	gbump(int);	// advance the get pointer
	void	setb(char*, char*, int = 0 ); // set the buffer area
	void	unbuffered(int);// set the buffering state
	int	unbuffered();	// non-zero if not buffered
	int	allocate();	// set up a buffer area
virtual int	doallocate();	// implementation of allocate

// UNSAFE members unlocked
	char*	base_unlocked();// UNSAFE return start of buffer area
        char*   ebuf_unlocked(); // UNSAFE
	int	blen_unlocked();// UNSAFE return length of buffer area
	char*	pbase_unlocked();// UNSAFE return start of put area
	char*	pptr_unlocked();  // UNSAFE return next location in put area
	char*	epptr_unlocked();	// UNSAFE return end+1 of put area
	char*	eback_unlocked();// UNSAFE 
	char*	gptr_unlocked();// UNSAFE return next location in get area
        char*   egptr_unlocked(); // UNSAFE
	void	setp_unlocked(char*, char*); // initialize the put pointers
	void	setg_unlocked(char*, char*, char*); // UNSAFE
	void	pbump_unlocked(int);	// advance the put pointer
	void	gbump_unlocked(int);	// advance the get pointer
	void	setb_unlocked(char*, char*, int = 0 ); // set the buffer area
	void	unbuffered_unlocked(int); // UNSAFE set the buffer state
	int	unbuffered_unlocked();	// UNSAFE non-zero if not buffered
	int	allocate_unlocked();	// UNSAFE set up a buffer area

private:
	short	alloc_;		// non-zero if buffer should be deleted
	short	unbuf_;		// non-zero if unbuffered
	char*	base_;		// start of buffer area
	char*	ebuf_;		// end+1 of buffer area
	char*	pbase_;		// start of put area
	char*	pptr_;		// next put location
	char*	epptr_;		// end+1 of put area
	char*	eback_;		// base of putback section of get area
	char*	gptr_;		// next get location
	char*	egptr_;		// end+1 of get area

	int	do_snextc();	// implementation of snextc

	// these declarations prevent copying of a streambuf
		streambuf(streambuf&);	// declared but not defined
	void	operator= (streambuf&);	// declared but not defined

};

inline char*	streambuf::base_unlocked() { 
   return base_;
}

inline char*	streambuf::base() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return base_; 
}

inline char*	streambuf::pbase_unlocked() { 
   return pbase_;
}

inline char*	streambuf::pbase() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return pbase_; 
}

inline char*	streambuf::pptr_unlocked() { return pptr_; }

inline char*	streambuf::pptr() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return pptr_;
}

inline char*	streambuf::epptr_unlocked() { return epptr_; }

inline char*	streambuf::epptr() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return epptr_; 
}

inline char*	streambuf::gptr_unlocked() {
   return gptr_;
}

inline char*	streambuf::gptr() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return gptr_; 
}

inline char* streambuf::egptr_unlocked() {
  return egptr_;
}

inline char*	streambuf::egptr()	{ 
   STREAM_RMUTEX_LOCK(this, lckp);
   return egptr_; 
}

inline char*	streambuf::eback_unlocked()	{ 
   return eback_;
}

inline char*	streambuf::eback()	{ 
   STREAM_RMUTEX_LOCK(this, lckp);
   return eback_; 
}

inline char*	streambuf::ebuf_unlocked()	{ 
  return ebuf_;
}

inline char*	streambuf::ebuf()	{ 
   STREAM_RMUTEX_LOCK(this, lckp);
   return ebuf_; 
}

inline int streambuf::unbuffered_unlocked() { 
   return unbuf_;
}

inline int	streambuf::unbuffered() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return unbuf_; 
}

inline int  streambuf::blen_unlocked() { 
   return int(ebuf_ - base_);
}

inline int	streambuf::blen() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return blen_unlocked();
}

inline streambuf* streambuf::setbuf(unsigned char* _p, int _len) {
			// call the virtual function
			return setbuf((char*)_p, _len);
		}

inline void	streambuf::pbump_unlocked(int _n) { 
   pptr_ += _n;
}

inline void	streambuf::pbump(int _n) { 
   STREAM_RMUTEX_LOCK(this, lckp);
   pbump_unlocked(_n);
}

inline void	streambuf::gbump_unlocked(int _n) { 
   gptr_ += _n; 
}

inline void	streambuf::gbump(int _n) { 
   STREAM_RMUTEX_LOCK(this, lckp);
   gbump_unlocked(_n);
}

inline void	streambuf::unbuffered_unlocked(int _unb) { 
   unbuf_ = (_unb != 0);
}

inline void	streambuf::unbuffered(int _unb) { 
   STREAM_RMUTEX_LOCK(this, lckp);
   unbuffered_unlocked(_unb);
}

inline int	streambuf::in_avail_unlocked() {
   return (egptr_ > gptr_) ? int(egptr_ - gptr_): 0;
}

inline int	streambuf::in_avail() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return in_avail_unlocked();
}

inline int	streambuf::out_waiting_unlocked() { 
     return pptr_ ? int(pptr_ - pbase_) : 0;
}

inline int	streambuf::out_waiting() { 
   STREAM_RMUTEX_LOCK(this, lckp);
   return out_waiting_unlocked();
}

inline int      streambuf::allocate_unlocked() {
   return (base_ || unbuf_) ? 0 : doallocate();
}

inline int	streambuf::allocate() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return allocate_unlocked();
}


inline int      streambuf::sgetc_unlocked() {
   return (gptr_ >= egptr_) ? underflow() : (unsigned char)(*gptr_);
}

inline int	streambuf::sgetc() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sgetc_unlocked();
}

inline int	streambuf::snextc_unlocked() {
   return (! gptr_ || (++gptr_ >= egptr_)) ? do_snextc():(unsigned char)(*gptr_);
}

inline int	streambuf::snextc() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return snextc_unlocked();
}

inline int	streambuf::sbumpc_unlocked() {
   if(gptr_ >= egptr_ && underflow() == EOF)
      return EOF;
   else
      return (unsigned char)(*gptr_++);
}

inline int	streambuf::sbumpc() {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sbumpc_unlocked();
}


inline void	streambuf::stossc_unlocked() {
   if( gptr_ >= egptr_ ) 
       underflow();
   else
       ++gptr_;
}

inline void streambuf::stossc() {
   STREAM_RMUTEX_LOCK(this, lckp);
   stossc_unlocked();
}

inline int      streambuf::sputbackc_unlocked(char _c) {
   if (gptr_ > eback_) {
	if (*--gptr_ == _c)
	    return (unsigned char) _c;
	else
	    return (unsigned char)(*gptr_ = _c) ;
   }
   else
      return pbackfail(_c);
}

inline int	streambuf::sputbackc(char _c) {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sputbackc_unlocked(_c);
}


inline int	streambuf::sputc_unlocked(int _c) {
   return (pptr_ >= epptr_) ? overflow((unsigned char)_c):
                              (unsigned char)(*pptr_++ = _c);
}

inline int	streambuf::sputc(int _c) {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sputc_unlocked(_c);
}

inline int	streambuf::sputn(const char* _s, int _n) {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sputn_unlocked(_s, _n);
}

inline int	streambuf::sgetn(char* _s, int _n) {
   STREAM_RMUTEX_LOCK(this, lckp);
   return sgetn_unlocked(_s, _n);
}



class unsafe_istream : virtual public unsafe_ios {
public:
	// constructor and destructor
		unsafe_istream(streambuf*);
virtual		~unsafe_istream();

	// Obsolete constructors, for streams 1.2 compatibility
		// obsolete: set skip via format, tie via tie() function
		unsafe_istream(streambuf*, int _sk, ostream* _t=0);
		// obsolete: use strstream
		unsafe_istream(int _sz, char*, int _sk=1);
		// obsolete: use fstream
		unsafe_istream(int _fd, int _sk=1, ostream* _t=0);

	int	ipfx(int = 0);		// input prefix function
	int	ipfx0();		// same as ipfx(0)
	int	ipfx1();		// same as ipfx(1)
	void	isfx()		{ }	// unused input suffix function

	// wchar_t
	int	wipfx(int=0);

	// set/read the get pointer's position
	unsafe_istream& seekg(streampos);
	unsafe_istream& seekg(streamoff, unsafe_ios::seek_dir);
   	streampos tellg();

	int	sync();

	/*
	 * Unformatted extraction operations
	 */
	// extract characters into an array
	unsafe_istream& get(char*, int, char = '\n');
        unsafe_istream& get(unsigned char* buf,int lim, char delim='\n') {
            return get((char*)buf, lim, delim);
        }
	unsafe_istream& read(char*, int);
	unsafe_istream& read(unsigned char* b, int n) {
	    return read((char*)b, n);
	}

	// extract characters into an array up to termination char
	unsafe_istream& getline(char*, int, char = '\n');
	unsafe_istream& getline(unsigned char* b, int l, char d = '\n') {
            return getline((char*)b, l, d);
        }

	// extract characters into a streambuf up to termination char
	unsafe_istream& get(streambuf&, char = '\n');

	// extract a single character
	unsafe_istream& get(char&);
	unsafe_istream& get(unsigned char&);
	int 	get();

	int	peek();		// return next char without extraction
	int	gcount();	// number of unformatted chars last extracted
	unsafe_istream& putback(char);	// push back char into input

	// extract and discard chars but stop at delim
	unsafe_istream& ignore(int = 1, int = EOF);

	// wchar_t
	unsafe_istream& get(wchar_t*, int, wchar_t=L'\n');
	unsafe_istream& get(wchar_t&);
	unsafe_istream& getline(wchar_t*, int, wchar_t=L'\n');
	unsafe_istream& wignore(int=1, wchar_t=WEOF);
	__wint_t peekw();

	/*
	 * Formatted extraction operations
	 */
	unsafe_istream& operator>> (unsafe_istream& (*_f)(unsafe_istream&));
	unsafe_istream& operator>> (unsafe_ios& (*_f)(unsafe_ios&) );
	unsafe_istream& operator>> (char*);
	unsafe_istream& operator>> (unsigned char*);
	unsafe_istream& operator>> (char&);
	unsafe_istream& operator>> (unsigned char&);
	unsafe_istream& operator>> (short&);
	unsafe_istream& operator>> (int&);
	unsafe_istream& operator>> (long&);
#ifndef _NO_LONGLONG
        unsafe_istream& operator>> (long long&);
#endif
	unsafe_istream& operator>> (unsigned short&);
	unsafe_istream& operator>> (unsigned int&);
	unsafe_istream& operator>> (unsigned long&);
#ifndef _NO_LONGLONG
        unsafe_istream& operator>> (unsigned long long&);
#endif
	unsafe_istream& operator>> (float&);
	unsafe_istream& operator>> (double&);
        unsafe_istream& operator>> (long double&);

	// wchar_t
	unsafe_istream& operator>>(wchar_t&);
	unsafe_istream& operator>>(wchar_t*);

	// extract from this unsafe_istream, insert into streambuf
	unsafe_istream& operator>> (streambuf*);

protected:
		unsafe_istream();
	int	do_ipfx(int);	// implementation of ipfx
	void	eatwhite();	// extract consecutive whitespace

	int	do_wipfx(int);
	void	eatwwhite();

private:
	int	gcount_;	// chars extracted by last unformatted operation
	char    do_get();	// implementation of get
        void    floatstr(char*);
        char    intstr(char*, int);

	// Related to wide char support.
	// If integrated with single-byte I/O, would add state for multiple
	// bytes "peeked" ahead.
	wchar_t peekc_;
	int	peeking_;	// boolean
};

inline int	unsafe_istream::gcount() { return gcount_; }
inline int	unsafe_istream::ipfx(int _need) {
                        if( _need ? (ispecial & ~skipping) : ispecial )
                                return do_ipfx(_need);
                        return 1;
		}
inline int	unsafe_istream::ipfx0() { return ispecial ? do_ipfx(0) : 1; }
inline int	unsafe_istream::ipfx1() {
			return (ispecial & ~skipping) ? do_ipfx(1) : 1;
		}
inline unsafe_istream& unsafe_istream::operator>> (unsigned char& _c) {
	if( ipfx0() )
	  _c = bp->in_avail_unlocked() ? bp->sbumpc_unlocked() : do_get();
	  return *this;
}
inline unsafe_istream& unsafe_istream::operator>> (char& _c) {
	if( ipfx0() )
	  _c = bp->in_avail_unlocked() ? bp->sbumpc_unlocked() : do_get();
	  return *this;
}
inline unsafe_istream&	unsafe_istream::operator>> (unsigned char* _p) {
			return *this >> (char *)_p;
		}
inline int	unsafe_istream::sync() { return bp->sync(); }
inline unsafe_istream& unsafe_istream::operator>> (unsafe_istream& (*_f) (unsafe_istream&)) {
			return (*_f)(*this);
		}
// modify for streambuf
inline unsafe_istream& unsafe_istream::get(unsigned char& _c) {
     if( ipfx1() ) {
	if( bp->in_avail_unlocked() ) _c = bp->sbumpc_unlocked();
	else _c = do_get();
	gcount_ = 1;
      }
return *this;
}
inline unsafe_istream& unsafe_istream::get(char& _c) {
     if( ipfx1() ) {
	if( bp->in_avail_unlocked()) _c = bp->sbumpc_unlocked();
	else _c = do_get();
	gcount_ = 1;
      }
      return *this;
}
inline int 	unsafe_istream::get() {
      if( ipfx1() ) {
	int _c = bp->sbumpc_unlocked();
	if( _c == EOF ) setstate(eofbit);
	else gcount_ = 1;
	return _c;
      }	else return EOF;
}
// modify streambuf call

inline int	unsafe_istream::peek() { return ipfx1() ? bp->sgetc_unlocked() : EOF; }





#pragma disable_warn
class istream :  virtual public ios, public unsafe_istream {
 public:
	// constructor and destructor
		istream(streambuf*);
virtual		~istream();

	// Obsolete constructors, for streams 1.2 compatibility
		// obsolete: set skip via format, tie via tie() function
		istream(streambuf*, int _sk, ostream* _t=0);
		// obsolete: use strstream
		istream(int _sz, char*, int _sk=1);
		// obsolete: use fstream
		istream(int _fd, int _sk=1, ostream* _t=0);

	int	ipfx(int = 0);		// input prefix function
	int	ipfx0();		// same as ipfx(0)
	int	ipfx1();		// same as ipfx(1)
	void	isfx()		{ }	// unused input suffix function

	// set/read the get pointer's position
	istream& seekg(streampos);
	istream& seekg(streamoff, unsafe_ios::seek_dir);
   	streampos tellg();

	int	sync();

	/*
	 * Unformatted extraction operations
	 */
	// extract characters into an array
	istream& get(char*, int, char = '\n');
        istream& get(unsigned char* buf,int lim, char delim='\n') {
            return get((char*)buf, lim, delim);
        }
	istream& read(char*, int);
	istream& read(unsigned char* b, int n) {
	    return read((char*)b, n);
	}

	// extract characters into an array up to termination char
	istream& getline(char*, int, char = '\n');
	istream& getline(unsigned char* b, int l, char d = '\n') {
            return getline((char*)b, l, d);
        }

	// extract characters into a streambuf up to termination char
	istream& get(streambuf&, char = '\n');

	// extract a single character
	istream& get(char&);
	istream& get(unsigned char&);
	int 	get();

	int	peek();		// return next char without extraction
	int	gcount();	// number of unformatted chars last extracted
	istream& putback(char);	// push back char into input

	// extract and discard chars but stop at delim
	istream& ignore(int = 1, int = EOF);

	// wchar_t
	istream& get(wchar_t*, int, wchar_t=L'\n');
	istream& get(wchar_t&);
	istream& getline(wchar_t*, int, wchar_t=L'\n');
	istream& wignore(int=1, wchar_t=WEOF);
	__wint_t peekw();

	/*
	 * Formatted extraction operations
	 */
	istream& operator>> (istream& (*_f)(istream&));
	istream& operator>> (ios&(*)(ios&) );
	istream& operator>> (char*);
	istream& operator>> (unsigned char*);
	istream& operator>> (char&);
	istream& operator>> (unsigned char&);
	istream& operator>> (short&);
	istream& operator>> (int&);
	istream& operator>> (long&);
#ifndef _NO_LONGLONG
        istream& operator>> (long long&);
#endif
	istream& operator>> (unsigned short&);
	istream& operator>> (unsigned int&);
	istream& operator>> (unsigned long&);
#ifndef _NO_LONGLONG
        istream& operator>> (unsigned long long&);
#endif
	istream& operator>> (float&);
	istream& operator>> (double&);
        istream& operator>> (long double&);

	// wchar_t
	istream& operator>>(wchar_t&);
	istream& operator>>(wchar_t*);

	// extract from this istream, insert into streambuf
	istream& operator>> (streambuf*);

protected:
     		istream();

	int	do_ipfx(int);	// implementation of ipfx
	void	eatwhite();	// extract consecutive whitespace
};
#pragma enable_warn

inline int istream::gcount() {
  STREAM_RMUTEX_LOCK(this, lckp);
  int gcount_return = unsafe_istream::gcount();
  return gcount_return;
}


inline int istream::ipfx(int _need) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  int ipfx_return = unsafe_istream::ipfx(_need);
  return ipfx_return;
}

inline int istream::ipfx0() {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  int ipfx0_return = unsafe_istream::ipfx0();
  return ipfx0_return;
}

inline int istream::ipfx1() {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  int ipfx1_return = unsafe_istream::ipfx1();
  return ipfx1_return;
}

inline istream& istream::operator>> (unsigned char& _c) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_istream::operator>>(_c);
  istream* oper_char_return = this;
  return *oper_char_return;
}

inline istream& istream::operator>> (char& _c) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_istream::operator>>(_c);
  istream* oper_char_return = this;
  return *oper_char_return;
}

inline istream& istream::operator>> (unsigned char* p) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_istream::operator>>(p);
  istream* oper_char_return = this;
  return *oper_char_return;
}
inline int istream::sync() {
  STREAM_RMUTEX_LOCK(this, lckp);
  int sync_return = unsafe_istream::sync();
  return sync_return;
}
inline istream& istream::operator>>(istream& (*_f) (istream&)){
    STREAM_RMUTEX_LOCK(this, lckp);
    istream& oper_istream_return = (*_f)(*this);
    return oper_istream_return;
}

inline istream& istream::get(unsigned char& _c) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_istream::get(_c);
  istream* get_return = this;
  return *get_return;
}

inline istream& istream::get(char& _c) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_istream::get(_c);
  istream* get_return = this;
  return *get_return;
}

inline int istream::get() {
     STREAM_RMUTEX_LOCK(this, lckp);
     streambuf* sb = unsafe_istream::rdbuf();
     STREAM_RMUTEX_LOCK(sb, lckp2);
     int get_return = unsafe_istream::get();
     return get_return;
}

inline int istream::peek() {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_istream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  int peek_return = unsafe_istream::peek();
  return peek_return;
}


class unsafe_ostream : virtual public unsafe_ios {
public:
	// constructors and destructor
		unsafe_ostream(streambuf*);
virtual		~unsafe_ostream();
	// Obsolete constructors, for streams 1.2 compatibility
		unsafe_ostream(int _fd); // obsolete, use fstream
		unsafe_ostream(int _sz, char*); // obsolete, use strstream

	int	opfx();		// output prefix function
	void	osfx();		// output suffix function
	unsafe_ostream& flush();

	// set/read the put pointer's position
	unsafe_ostream& seekp(streampos);
	unsafe_ostream& seekp(streamoff, unsafe_ios::seek_dir);
 	streampos tellp();

	/*
	 * Unformatted insertion operations
	 */
	unsafe_ostream& put(char);	// insert the character
	unsafe_ostream& put(unsigned char x) {
            return put((char)x);
        }
	unsafe_ostream& write(const char*, int); // insert the string
	unsafe_ostream& write(const unsigned char* b, int n) {
	    return write((const char*)b, n);
	}

	// wchar_t
	unsafe_ostream& put(wchar_t);
	unsafe_ostream& write(const wchar_t * ,int);

	/*
	 * Formatted insertion operations
	 */
	// insert the character
	unsafe_ostream& operator<< (char);
	unsafe_ostream& operator<< (unsigned char);

	unsafe_ostream& operator<< (wchar_t);
	unsafe_ostream& operator<< (const wchar_t*);

	// for the following, insert character representation of numeric value
	unsafe_ostream& operator<< (short);
	unsafe_ostream& operator<< (unsigned short);
	unsafe_ostream& operator<< (int);
	unsafe_ostream& operator<< (unsigned int);
	unsafe_ostream& operator<< (long);
	unsafe_ostream& operator<< (unsigned long);
#ifndef _NO_LONGLONG
        unsafe_ostream& operator<< (long long);
        unsafe_ostream& operator<< (unsigned long long);
#endif
	unsafe_ostream& operator<< (float);
	unsafe_ostream& operator<< (double);
        unsafe_ostream& operator<< (long double);

	// insert the null-terminated string
	unsafe_ostream& operator<< (const char*);

	// insert character representation of the value of the pointer
	unsafe_ostream& operator<< (void*);
	unsafe_ostream& operator<< (const void* p) {
            return operator<< ((void *)p);
        }

	// extract from streambuf, insert into this unsafe_ostream
	unsafe_ostream& operator<< (streambuf*);

	// manipulators
	unsafe_ostream& operator<< (unsafe_ostream& (*_f)(unsafe_ostream&));
	unsafe_ostream& operator<< (unsafe_ios& (*_f)(unsafe_ios&));

protected:
	int	do_opfx();	// implementation of opfx
	void	do_osfx();	// implementation of osfx
		unsafe_ostream();

private:
	void	outstr(const char*, const char*);
	void	outwstr(const wchar_t*, const wchar_t*);
        void    printint(const char*);
};
inline int	unsafe_ostream::opfx() { return ospecial ? do_opfx() : 1; }
inline void	unsafe_ostream::osfx() { if( x_flags & (stdio | unitbuf) ) do_osfx(); }

inline unsafe_ostream& unsafe_ostream::operator<< (char _c) {
			if( opfx() )
				if( bp->sputc_unlocked(_c) == EOF ) setstate(badbit);
			osfx();
			return *this;
		}
inline unsafe_ostream& unsafe_ostream::operator<< (unsigned char _c) {
			return *this << (char)_c;
		}
inline unsafe_ostream& unsafe_ostream::operator<< (const char* _s) {
			outstr(_s, 0);
			return *this;
		}
inline unsafe_ostream& unsafe_ostream::operator<< (short _i) { return *this << (long) _i; }
inline unsafe_ostream& unsafe_ostream::operator<< (unsigned short _i) {
			return *this << (unsigned long) _i;
		}
inline unsafe_ostream& unsafe_ostream::operator<< (int _i) { return *this << (long) _i; }
inline unsafe_ostream& unsafe_ostream::operator<< (unsigned int _i) {
			return *this << (unsigned long) _i;
		}
inline unsafe_ostream& unsafe_ostream::operator<< (float _f) { return *this << (double) _f; }
inline unsafe_ostream& unsafe_ostream::operator<< (unsafe_ostream& (*_f)(unsafe_ostream&)) {
			return (*_f)(*this);
		}
inline unsafe_ostream& unsafe_ostream::put(char _c) {
			if( bp->sputc_unlocked(_c) == EOF ) setstate(badbit);
			return *this;
		}

inline unsafe_ostream& unsafe_ostream::write(const char* _s, int _n) {
			if( ! fail() )
				if( bp->sputn_unlocked(_s, _n) != _n )
					setstate(badbit);
			return *this;
		}

#pragma disable_warn
class ostream : virtual public ios, public unsafe_ostream {
 public:
  	// constructors and destructor
		ostream(streambuf*);
virtual		~ostream();
	// Obsolete constructors, for streams 1.2 compatibility
		ostream(int _fd); // obsolete, use fstream
		ostream(int _sz, char*); // obsolete, use strstream

	int	opfx();		// output prefix function
	void	osfx();		// output suffix function
	ostream& flush();

	// set/read the put pointer's position
	ostream& seekp(streampos);
	ostream& seekp(streamoff, unsafe_ios::seek_dir);
 	streampos tellp();

	/*
	 * Unformatted insertion operations
	 */
	ostream& put(char);	// insert the character
	ostream& put(unsigned char x) {
            return put((char)x);
        }
	ostream& write(const char*, int); // insert the string
	ostream& write(const unsigned char* b, int n) {
	    return write((const char*)b, n);
	}

	// wchar_t
	ostream& put(wchar_t);
	ostream& write(const wchar_t *, int);

	/*
	 * Formatted insertion operations
	 */
	// insert the character
	ostream& operator<< (char);
	ostream& operator<< (unsigned char);

	ostream& operator<< (wchar_t);
	ostream& operator<< (const wchar_t*);

	// for the following, insert character representation of numeric value
	ostream& operator<< (short);
	ostream& operator<< (unsigned short);
	ostream& operator<< (int);
	ostream& operator<< (unsigned int);
	ostream& operator<< (long);
	ostream& operator<< (unsigned long);
#ifndef _NO_LONGLONG
        ostream& operator<< (long long);
        ostream& operator<< (unsigned long long);
#endif
	ostream& operator<< (float);
	ostream& operator<< (double);
        ostream& operator<< (long double);

	// insert the null-terminated string
	ostream& operator<< (const char*);

	// insert character representation of the value of the pointer
	ostream& operator<< (void*);
	ostream& operator<< (const void* p) {
            return operator<< ((void *)p);
        }

	// extract from streambuf, insert into this unsafe_ostream
	ostream& operator<< (streambuf*);

	// manipulators
	ostream& operator<< (ostream& (*_f)(ostream&));
	ostream& operator<< (ios& (*_f)(ios&));

protected:
	int	do_opfx();	// implementation of opfx
	void	do_osfx();	// implementation of osfx
		ostream();
};
#pragma enable_warn


inline int ostream::opfx() { 
     STREAM_RMUTEX_LOCK(this, lckp);
     int opfx_return = unsafe_ostream::opfx();
     return opfx_return;
}

inline void ostream::osfx() { 
     STREAM_RMUTEX_LOCK(this, lckp);
     unsafe_ostream::osfx();
}

inline ostream& ostream::operator<< (char _c) {
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    ostream* oper_char_return;
    unsafe_ostream::operator<<(_c);
    oper_char_return = this;
    return *oper_char_return;
}

inline ostream& ostream::operator<< (unsigned char _c) {
    return *this << (char)_c;
}
inline ostream& ostream::operator<< (const char* _s) {
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    unsafe_ostream::operator<<(_s);
    ostream* oper_char_return = this;
    return *oper_char_return;
}

inline ostream& ostream::operator<< (short _i) { 
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    unsafe_ostream::operator<<((long)_i);
    ostream* oper_short_return = this;
    return *oper_short_return;
}

inline ostream& ostream::operator<< (unsigned short _i) {
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    unsafe_ostream::operator<<((unsigned long)_i);
    ostream* oper_short_return = this;
    return *oper_short_return;
}
inline ostream& ostream::operator<< (int _i) { 
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    unsafe_ostream::operator<<((long)_i);
    ostream* oper_int_return = this;
    return *oper_int_return;
}

inline ostream& ostream::operator<< (unsigned int _i) {
    STREAM_RMUTEX_LOCK(this, lckp);
    streambuf* sb = unsafe_ostream::rdbuf();
    STREAM_RMUTEX_LOCK(sb, lckp2);
    unsafe_ostream::operator<<((unsigned long)_i);
    ostream* oper_ulong_return = this;
    return *oper_ulong_return;
}
inline ostream& ostream::operator<< (float _f) { 
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_ostream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_ostream::operator<<((double)_f);
  ostream* oper_double_return = this;
  return *oper_double_return;
}

inline ostream& ostream::operator<<(ostream&(*_f)(ostream&)) {
  STREAM_RMUTEX_LOCK(this, lckp);
  ostream& oper_ostream_return = (*_f)(*this);
  return oper_ostream_return;
}

inline ostream& ostream::put(char _c) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_ostream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_ostream::put(_c);
  ostream* put_return = this;
  return *put_return;
}

inline ostream& ostream::write(const char* _s, int _n) {
  STREAM_RMUTEX_LOCK(this, lckp);
  streambuf* sb = unsafe_ostream::rdbuf();
  STREAM_RMUTEX_LOCK(sb, lckp2);
  unsafe_ostream::write(_s, _n);
  ostream* write_return = this;
  return *write_return;
}


class unsafe_iostream : public unsafe_istream, public unsafe_ostream {
public:
		unsafe_iostream(streambuf*);
virtual		~unsafe_iostream();

protected:
		unsafe_iostream();
};

class iostream : public istream, public ostream {
public:
		iostream(streambuf*);
virtual		~iostream();

protected:
		iostream();
};


class istream_withassign : public istream {
public:
		// does no initialization
		istream_withassign();

virtual		~istream_withassign();

	// gets buffer from istream and does entire initialization
	istream_withassign& operator= (istream&);

	// associates streambuf with stream and does entire initialization
	istream_withassign& operator= (streambuf*);
};


class ostream_withassign : public ostream {
public:
		// does no initialization
		ostream_withassign();

virtual		~ostream_withassign();

	// gets buffer from istream and does entire initialization
	ostream_withassign& operator= (ostream&);

	// associates streambuf with stream and does entire initialization
	ostream_withassign& operator= (streambuf*);
};


class iostream_withassign : public iostream {
public:
		// does no initialization
		iostream_withassign();

virtual		~iostream_withassign();

	// gets buffer from stream and does entire initialization
	iostream_withassign& operator= (unsafe_ios&);

	// associates streambuf with stream and does entire initialization
	iostream_withassign& operator= (streambuf*);
};


/*
 * The predefined streams
 */
extern istream_withassign cin;
extern ostream_withassign cout;
extern ostream_withassign cerr;
extern ostream_withassign clog;
extern ostream_withassign __CC_clog;

#ifndef __SUNW_DONT_OVERRIDE_CLOG
#pragma redefine_extname clog __CC_clog
#endif

/*
 * Manipulators
 */
unsafe_ostream& endl(unsafe_ostream&);	// insert newline and flush
unsafe_ostream& ends(unsafe_ostream&);	// insert null to terminate string
unsafe_ostream& flush(unsafe_ostream&);	// flush the ostream
ostream& endl(ostream&);	// insert newline and flush
ostream& ends(ostream&);	// insert null to terminate string
ostream& flush(ostream&);	// flush the ostream

unsafe_ios&	 dec(unsafe_ios&);	// set conversion base to decimal
unsafe_ios&	 hex(unsafe_ios&);	// set conversion base to hexidecimal
unsafe_ios&	 oct(unsafe_ios&);	// set conversion base to octal
unsafe_istream& ws(unsafe_istream&);	// extract whitespace characters
ios&	 dec(ios&);		// set conversion base to decimal
ios&	 hex(ios&);		// set conversion base to hexidecimal
ios&	 oct(ios&);		// set conversion base to octal
istream& ws(istream&);		// extract whitespace characters

/*
 * The following allows proper initialization of cin, cout, cerr, clog
 */
static class Iostream_init {
public:
	Iostream_init();
	~Iostream_init();

private:
    static int	stdstatus;
    static int	initcount;
    friend	ios;
} iostream_init;

#endif /* _IOSTREAM_H_ */

