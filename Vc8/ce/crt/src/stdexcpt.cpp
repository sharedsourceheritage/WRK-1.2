/***
*stdexcpt.cpp - defines C++ standard exception classes
*
*       Copyright (c) Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       Implementation of C++ standard exception classes which must live in
*       the main CRT, not the C++ CRT, because they are referenced by RTTI
*       support in the main CRT.
*
*        exception
*          bad_cast
*          bad_typeid
*            __non_rtti_object
*
*Revision History:
*       04-27-94  BES   Module created.
*       10-17-94  BWT   Disable code for PPC.
*       02-15-95  JWM   Minor cleanups related to Olympus bug 3716
*       07-02-95  JWM   Now generally ANSI-compliant; excess baggage removed.
*       06-01-99  PML   __exString disappeared as of 5/3/99 Plauger STL drop.
*       11-09-99  PML   Use malloc, not new, to avoid recursion (vs7#16826).
*       09-07-00  PML   Get rid of /lib:libcp directive in obj (vs7#159463)
*       03-21-01  PML   Move bad_cast, bad_typeid, __non_rtti_object function
*                       defs out of typeinfo.h so _STATIC_CPPLIB will work.
*       03-25-03  SJ    Added constructor for exception(VSWhidbey#48961)
*       03-26-03  SSM   Moved classes into std namespace (Whidbey:1832)
*       11-26-03  AJS   NULL check string in constructor/assignment operator
*                       (VSWhidbey:195434)
*       10-22-04  AGH   Reimplement assignment operator to not reconstruct
*                       destination object
*
*******************************************************************************/

#define _USE_ANSI_CPP   /* Don't emit /lib:libcp directive */

#include <stdlib.h>
#include <string.h>
#if !defined(_WIN32_WCE)
#include <eh.h>
#endif
#if !defined(_SYSCRT) || defined(_WIN32_WCE)
#include <exception>
#include <typeinfo>
#else
#include <stdexcpt.h>
#include <typeinfo.h>
#endif

#pragma warning(disable:4439)	// C4439: function with a managed parameter must have a __clrcall calling convention

#if defined(MRTDLL)
#define __CLR_OR_THIS_CALL  __clrcall
#else
#define __CLR_OR_THIS_CALL
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Implementation of class "exception"
//

#if !defined(_SYSCRT) || defined(_WIN32_WCE)
_STD_BEGIN
#endif

#ifndef _WIN32_WCE

//
// Default constructor - initialize to blank
//
__CLR_OR_THIS_CALL exception::exception ()
{
        _m_what = NULL;
        _m_doFree = 0;
}

//
// Standard constructor: initialize with copy of string
//
__CLR_OR_THIS_CALL exception::exception ( const char * const & what )
{
    if (what != NULL)
    {
		size_t _Buf_size = strlen( what ) + 1;
        _m_what = static_cast< char * >( malloc( _Buf_size ) );
        if ( _m_what != NULL )
        {
			strcpy_s( const_cast<char *>(_m_what), _Buf_size, what );
		}
    }
    else
    {
        _m_what = NULL;
    }
    _m_doFree = 1;
}

//
// Additional constructor: for the case where we should not allocate memory
//
__CLR_OR_THIS_CALL exception::exception ( const char * const & what, int)
{
        _m_what = what;
        _m_doFree = 0;
}

//
// Copy constructor
//
__CLR_OR_THIS_CALL exception::exception ( const exception & that )
{
        _m_doFree = that._m_doFree;
        if (_m_doFree)
        {
            if (that._m_what != NULL)
            {
                size_t _Buf_size = strlen( that._m_what ) + 1;
                _m_what = static_cast< char * >( malloc( _Buf_size ) );
                if (_m_what != NULL)                
                {
                    strcpy_s( const_cast<char *>(_m_what), _Buf_size, that._m_what );
                }
            }
            else
            {
                _m_what = NULL;
            }
        }
        else
           _m_what = that._m_what;
}

//
// Assignment operator: destruct, then copy-construct
//
exception& __CLR_OR_THIS_CALL exception::operator=( const exception& that )
{
        if (this != &that)
        {
            _m_doFree = that._m_doFree;
            if (_m_doFree)
            {
                if (that._m_what != NULL)
                {
                    size_t _Buf_size = strlen( that._m_what ) + 1;
#pragma warning(push)
#pragma warning(disable:4996)
                    _m_what = static_cast< char * >( malloc( _Buf_size ) );
#pragma warning(pop)
                    if (_m_what != NULL)                {
                        strcpy_s( const_cast<char *>(_m_what), 
                                  _Buf_size, that._m_what );
                    }
                }
                else
                {
                    _m_what = NULL;
                }
            }
            else
               _m_what = that._m_what;
        }
        return *this;
}

//
// Destructor: free the storage used by the message string if it was
// dynamicly allocated
//
__CLR_OR_THIS_CALL exception::~exception()
{
        if (_m_doFree)
            free( const_cast< char * >( _m_what ) );
}


//
// exception::what
//  Returns the message string of the exception.
//  Default implementation of this method returns the stored string if there
//  is one, otherwise returns a standard string.
//
const char * __CLR_OR_THIS_CALL exception::what() const
{
        if ( _m_what != NULL )
            return _m_what;
        else
            return "Unknown exception";
}

#endif // _WIN32_WCE

////////////////////////////////////////////////////////////////////////////////
//
// Implementation of class "bad_cast"
//

__CLR_OR_THIS_CALL bad_cast::bad_cast(const char * _Message)
    : exception(_Message)
{
}

__CLR_OR_THIS_CALL bad_cast::bad_cast(const bad_cast & that)
    : exception(that)
{
}

__CLR_OR_THIS_CALL bad_cast::~bad_cast()
{
}

#ifdef CRTDLL
//
// This is a dummy constructor.  Previously, the only bad_cast ctor was
// bad_cast(const char * const &).  To provide backwards compatibility
// for std::bad_cast, we want the main ctor to be bad_cast(const char *)
// instead.  Since you can't have both bad_cast(const char * const &) and
// bad_cast(const char *), we define this bad_cast(const char * const *),
// which will have the exact same codegen as bad_cast(const char * const &),
// and alias the old form with a .def entry.
//
__CLR_OR_THIS_CALL bad_cast::bad_cast(const char * const * _PMessage)
    : exception(*_PMessage)
{
}
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Implementation of class "bad_typeid"
//

__CLR_OR_THIS_CALL bad_typeid::bad_typeid(const char * _Message)
    : exception(_Message)
{
}

__CLR_OR_THIS_CALL bad_typeid::bad_typeid(const bad_typeid & that)
    : exception(that)
{
}

__CLR_OR_THIS_CALL bad_typeid::~bad_typeid()
{
}

////////////////////////////////////////////////////////////////////////////////
//
// Implementation of class "__non_rtti_object"
//

__CLR_OR_THIS_CALL __non_rtti_object::__non_rtti_object(const char * _Message)
    : bad_typeid(_Message)
{
}

__CLR_OR_THIS_CALL __non_rtti_object::__non_rtti_object(const __non_rtti_object & that)
    : bad_typeid(that)
{
}

__CLR_OR_THIS_CALL __non_rtti_object::~__non_rtti_object()
{
}

#ifndef _SYSCRT
_STD_END
#endif

