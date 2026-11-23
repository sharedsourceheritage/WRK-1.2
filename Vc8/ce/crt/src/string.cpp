// string -- template string support functions
#include <istream>
_STD_BEGIN


_MRTIMP2 void __cdecl _String_base::_Xlen()
	{	// report a length_error
	_THROW(length_error, "string too long");
	}

_MRTIMP2 void __cdecl _String_base::_Xran()
	{	// report an out_of_range error
	_THROW(out_of_range, "invalid string position");
	}

_MRTIMP2 void __cdecl _String_base::_Xinvarg()
	{	// report an out_of_range error
	_THROW(invalid_argument, "invalid string argument");
	}

_STD_END

/*
 * Copyright (c) 1992-2005 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V4.05:0009 */
