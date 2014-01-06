/*
	Copyright 05/10/04 Sun Microsystems, Inc. All Rights Reserved
*/
/* rlocks.h -- classes that provide locking support for mt-safe libC

  @(#)rlocks.h	1.2  05/10/04 09:47:28

    The following classes are defined:
       stream_rmutex   To implement recursive mutex locks.
                       used internally by iostreams library.
       stream_MT       Base class, provides interface for a class
                       that wants to be locked.
       stream_locker   To lock/unlock iostream objects.

*/

#ifndef _RLOCKS_H
#define _RLOCKS_H

#ifdef _REENTRANT
#define STREAM_REENTRANT(x)         x
#define STREAM_RMUTEX_LOCK(m, sym)      \
    stream_locker  sym(m, stream_locker::lock_defer); \
    if (test_safe_flag()) sym.lock()
#else
#define STREAM_REENTRANT(x)
#define STREAM_RMUTEX_LOCK(m, sym)  
#endif

typedef char stream_bool_t;
typedef unsigned int __thread_t;
struct __mutex_t;
struct __mutex_attr;

// Class stream_rmutex implements recursive mutex locks.
// Note: this class is supposed to be used only by iostreams and
//       not by a user program.
class stream_rmutex {
private:
    __mutex_t   *mutex;
    union {
	struct libthread_data {
	    __thread_t  owner;
	    int         count;
	} ltd;
	__mutex_attr  *attr;
    } data;

    // Initialization is not done in a constructor because of 
    // special needs of static objects of this class.
    void rmutex_init();   // initialization routine
    void rmutex_lock();
    void rmutex_unlock();
    ~stream_rmutex();

    friend class ios;
    friend class streambuf;
    friend class stream_MT;
    friend class stream_locker;
    friend class Iostream_init;
};

// Class stream_MT is used as a base class. It provides the interface 
// for a class that wants to be mt-safe.
class stream_MT {
private:
    stream_rmutex   mutlock;
    stream_bool_t   safe_flag;  // 1: safe object, 0: unsafe object
protected:
    stream_rmutex&  get_rmutex() { return mutlock; }
public:
    enum { unsafe_object=0, safe_object=1 };
    stream_MT() { safe_flag = safe_object; }
    stream_MT(stream_bool_t flag) { safe_flag = flag; }
    stream_bool_t test_safe_flag() { return safe_flag; }
    void set_safe_flag(stream_bool_t flag) { 
        STREAM_REENTRANT(mutlock.rmutex_lock());
        safe_flag = flag; 
        STREAM_REENTRANT(mutlock.rmutex_unlock());
    }

    friend class stream_locker;
    friend class Iostream_init;
};

// Class stream_locker to lock/unlock stream_MT's.
// Only local objects should be created for this class.
// If used with static/global objects, the member functions
// of this class will be mt-unsafe.
class stream_locker {
private:
    stream_rmutex  *lockp;
    int            lock_count;

    void do_lock() {
        lock_count++;
        lockp->rmutex_lock();
    }
    void do_lock_set(stream_rmutex *ptr, int lock_flag) {
        lockp = ptr;
        lock_count = 0;
        if (lock_flag)
            do_lock();
    }
    void do_unlock() {
        if (lock_count) {
            lockp->rmutex_unlock();
            lock_count--;
        }
    }

public:
    enum lock_choice { lock_defer=0, lock_now=1 };

    stream_locker(stream_MT& obj, lock_choice lock_flag=lock_now) { 
        do_lock_set(&(obj.get_rmutex()), lock_flag); 
    }
    stream_locker(stream_MT *ptr, lock_choice lock_flag=lock_now) { 
        do_lock_set(&(ptr->get_rmutex()), lock_flag); 
    }
    stream_locker(stream_rmutex&  mut, lock_choice lock_flag=lock_now) { 
        do_lock_set(&mut, lock_flag); 
    }
    stream_locker(stream_rmutex  *ptr, lock_choice lock_flag=lock_now) { 
        do_lock_set(ptr, lock_flag); 
    }
    ~stream_locker() { do_unlock(); }

    void lock() { do_lock(); }
    void unlock() { do_unlock(); }
};

#endif

