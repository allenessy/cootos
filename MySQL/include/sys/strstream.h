/*
	Copyright 06/25/96 Sun Microsystems, Inc. All Rights Reserved
*/
/*  strstream.h -- class strstream declarations

    Copyright 1991 by TauMetric Corporation      ALL RIGHTS RESERVED

    @(#)strstream.h	1.1  06/25/96 09:37:51
*/
#ifndef _STRSTREAM_H_
#define _STRSTREAM_H_

#include <sys/iostream.h>


#pragma disable_warn
class strstreambuf : public streambuf {
public:
		strstreambuf();
		strstreambuf(int n);
		strstreambuf(void* (*a)(long), void (*f)(void*));
		strstreambuf(char* _s, int, char* _strt=0);
		~strstreambuf();

	void	freeze_unlocked(int = 1);
	void	freeze(int = 1);
        int     isfrozen_unlocked();
        int     isfrozen();
	char*	str_unlocked();
	char*	str();
virtual int	doallocate();
virtual int	overflow(int);
virtual int	underflow();
virtual streambuf* setbuf(char*, int);
virtual streampos seekoff(streamoff, unsafe_ios::seek_dir, int);

private:
	void*	(*allocf)(long);
	void	(*freef)(void*);
	short	ssbflags;
	enum	{ dynamic = 1, frozen = 2, unlimited = 4 };
	int	next_alloc;
	char*	real_end;
	void	init(char*, int, char*);
};
#pragma enable_warn

inline int strstreambuf::isfrozen_unlocked() { return (ssbflags&frozen) != 0; }
inline int strstreambuf::isfrozen() { 
    STREAM_RMUTEX_LOCK(this, lckp);
    return isfrozen_unlocked();
}

class unsafe_strstreambase : public virtual unsafe_ios {
public:
	strstreambuf* rdbuf();

protected:
		unsafe_strstreambase(char*, int, char*);
		unsafe_strstreambase();
		~unsafe_strstreambase();
private:
	strstreambuf buf;
};

inline strstreambuf* unsafe_strstreambase::rdbuf() { return &this->buf; }

class strstreambase : virtual public ios, public unsafe_strstreambase {
 public:
  	strstreambuf* rdbuf();

protected:
		strstreambase(char*, int, char*);
		strstreambase();
		~strstreambase();

};


inline strstreambuf* strstreambase::rdbuf() { return unsafe_strstreambase::rdbuf(); }

class istrstream : public strstreambase, public istream {
public:
		istrstream(char*);
		istrstream(char*, int);
		istrstream(const char*);
		istrstream(const char*, int);
		~istrstream();
};


class ostrstream : public strstreambase, public ostream {
public:
		ostrstream(char*, int, int = ios::out);
		ostrstream();
		~ostrstream();

	char*	str();
	int	pcount();
};
inline char*	ostrstream::str() { return strstreambase::rdbuf()->str(); }
inline int	ostrstream::pcount() {
			return strstreambase::rdbuf()->out_waiting();
		}


class strstream : public strstreambase, public iostream {
public:
		strstream();
		strstream(char*, int _sz, int _m);
		~strstream();

	char*	str();
};
inline char* strstream::str() { return strstreambase::rdbuf()->str(); }

#endif /* _STRSTREAM_H_ */



