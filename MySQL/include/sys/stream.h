/*
	Copyright 06/25/96 Sun Microsystems, Inc. All Rights Reserved
*/
/*  stream.h -- provide a migration path from old streams to iostreams

    Copyright 1991 by TauMetric Corporation      ALL RIGHTS RESERVED

    @(#)stream.h	1.1  06/25/96 09:37:46
*/

#ifndef _STREAM_H_
#define _STREAM_H_

#include <sys/iostream.h>
#include <sys/iomanip.h>
#include <sys/stdiostream.h>
#include <sys/fstream.h>

/*
 * Simulate the whitespace object in old streams.
 * WS is an istream manipulator which eats white space, having the
 * same purpose as struct WS in old streams.
 */
istream& WS(istream&);
void eatwhite(istream&);

const int input  = ios::in;
const int output = ios::out;
const int append = ios::app;
const int atend  = ios::ate;
const int _good  = ios::goodbit;
const int _bad   = ios::badbit;
const int _fail  = ios::failbit;
const int _eof   = ios::eofbit;

typedef ios::io_state state_value;

/*
 * formatting functions, for compatibility with old-style streams
 * However, note that these are unsafe as they use a static buffer
 * For MT safety use the following section
 */
char * dec(long, int = 0);	// internal to decimal text
char * hex(long, int = 0);	// internal to hex text
char * oct(long, int = 0);	// internal to octal text
 
char * chr(int, int = 0);	// char to string
char * str(const char *, int = 0); // make fixed-width string
char * form(const char * ...);	// general formating

// MT safe formatting
char * dec_r(char*, int, long, int = 0);	// internal to decimal text
char * hex_r(char*, int, long, int = 0);	// internal to hex text
char * oct_r(char*, int, long, int = 0);	// internal to octal text
 
char * chr_r(char*, int, int, int = 0);	// char to string
char * str_r(char*, int, const char *, int = 0); // make fixed-width string
char * form_r(char*, int, const char * ...);	// general formating

#endif /* _STREAM_H_ */
