
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "PrimitiveToken.h"
 
bool PrimitiveToken::AreYouAnArrow()
{
	return (type == eType && !value.compare( "arrow" ));
};

bool PrimitiveToken::AreYouACircle()
{
	return (type == eType && !value.compare( "circle" ));
};

bool PrimitiveToken::AreYouARectangle()
{
	return (type == eType && !value.compare( "rectangle" ));
};

int PrimitiveToken::IntegerValue()
{
	return atoi(value.c_str());
};