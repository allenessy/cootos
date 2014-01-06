/*
	Copyright 11/06/96 Sun Microsystems, Inc. All Rights Reserved
*/
/*  fstream.h -- class filebuf and fstream declarations

    Copyright 1991 by TauMetric Corporation      ALL RIGHTS RESERVED

    @(#)fstream.h	1.2  11/06/96 17:07:49
*/
#ifndef _FSTREAM_H_
#define _FSTREAM_H_

#include <sys/iostream.h>

#pragma disable_warn
class  filebuf : public streambuf {
public:
static const int openprot;	// default file protection

		// constructors, destructor
		filebuf();	// make a closed filebuf
		filebuf(int);	// make a filebuf attached to fd
		filebuf(int, char*, int); // same, with specified buffer
		~filebuf();

	int	is_open();	// is the file open
	int	fd();		// what is the file descriptor

	// open named file with mode and protection, attach to this filebuf
	filebuf* open(const char*, int, int = filebuf::openprot);

	filebuf* close();	// flush and close file
	filebuf* attach(int);	// attach this filebuf to opened file descriptor
	int	 detach();	// detach from and return the file descriptor

/*
 * These perform the streambuf functions on a filebuf
 * Get and Put pointers are kept together
 */
virtual int	overflow(int = EOF);
virtual int	underflow();
virtual int	sync();
virtual streampos  seekoff(streamoff, ios::seek_dir, int);
virtual streambuf* setbuf(char*, int);
	int	is_open_unlocked();	// is the file open
	filebuf* close_unlocked();	// flush and close file
	filebuf* open_unlocked(const char*, int, int = filebuf::openprot);
	filebuf* attach_unlocked(int);	// attach this filebuf to opened file descriptor
	int	 detach_unlocked();	// detach from and return the file descriptor


protected:
	int	xfd;		// the file descriptor, EOF if closed
	int	mode;		// the opened mode
	short	opened;		// non-zero if file is open

	streampos last_seek;	// unused			***
	char*   in_start;	// unused			***

	int	last_op();	// unused			***
	char	lahead[2];	// current input char if unbuffered ***

};
#pragma enable_warn

/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */
inline int	filebuf::is_open_unlocked()	{ return opened; }
inline int	filebuf::is_open()	{ 
  STREAM_RMUTEX_LOCK(this, lck);
  int is_open_return = opened;
  return is_open_return;
}

inline int	filebuf::fd()		{ return xfd; }


class unsafe_fstreambase : virtual public unsafe_ios {
public:
		unsafe_fstreambase();
		unsafe_fstreambase(const char*, int, int = filebuf::openprot);
		unsafe_fstreambase(int);
		unsafe_fstreambase(int _f, char*, int);
		~unsafe_fstreambase();

	void	open(const char*, int, int = filebuf::openprot);
	void	attach(int);
	int	detach();
	void	close();
	void	setbuf(char*, int);
	filebuf* rdbuf();

protected:
	void	verify(int);	// unimplemented	***

private:
	filebuf	buf;
};
/*
 * The function member marked with *** above is not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in its use.
 * If you can document any expected behavior of this function member, we
 * will try to adjust our implementation accordingly.
 */
inline filebuf* unsafe_fstreambase::rdbuf() { return &buf; }

class fstreambase : virtual public ios, public unsafe_fstreambase {
public:
		fstreambase();

		fstreambase(const char*, int, int = filebuf::openprot);
		fstreambase(int);
		fstreambase(int _f, char*, int);
		~fstreambase();

	void	open(const char*, int, int = filebuf::openprot);
	void	attach(int);
	int	detach();
	void	close();
	void	setbuf(char*, int);
	filebuf* rdbuf();
};

inline filebuf* fstreambase::rdbuf() { 
  STREAM_RMUTEX_LOCK(this, lckp);
  filebuf* rdbuf_return = unsafe_fstreambase::rdbuf();
  return rdbuf_return;
}



class ifstream : public fstreambase, public istream {
public:
		ifstream();
		ifstream(const char*, int=ios::in, int=filebuf::openprot);
		ifstream(int);
		ifstream(int, char*, int);
		~ifstream();

	filebuf* rdbuf();
	void	open(const char*, int=ios::in, int=filebuf::openprot);
};
inline filebuf* ifstream::rdbuf() { return fstreambase::rdbuf(); }
inline void	ifstream::open(const char* _n, int _m, int _p)
	{ fstreambase::open(_n, _m | ios::in, _p); }


class ofstream : public fstreambase, public ostream {
public:
		ofstream();
		ofstream(const char*, int=ios::out, int=filebuf::openprot);
		ofstream(int);
		ofstream(int _f, char*, int);
		~ofstream();

	filebuf* rdbuf();
	void open(const char*, int=ios::out, int=filebuf::openprot);
};
inline filebuf*	ofstream::rdbuf() { return fstreambase::rdbuf(); }
inline void	ofstream::open(const char* name, int m, int prot)
	{ fstreambase::open(name, m | ios::out, prot); }


class fstream : public fstreambase, public iostream {
public:
		fstream();
		fstream(const char*, int, int = filebuf::openprot);
		fstream(int);
		fstream(int _f, char*, int);
		~fstream();

	filebuf* rdbuf();
	void	open(const char *, int, int = filebuf::openprot);
};
inline filebuf* fstream::rdbuf() { return fstreambase::rdbuf(); }
inline void	fstream::open(const char* name, int m, int prot)
	{ fstreambase::open(name, m, prot); }

#endif /* _FSTREAM_H_ */

