
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/
#pragma once

class PrimitiveToken {
public:
	FIGTYPE type;
	string value;
	PrimitiveToken(){};
	~PrimitiveToken(){};

	//These two are strictly so the compiler will work
	//with tokens.  They are never called
	bool operator<(const PrimitiveToken& x) const {return true;};
	bool operator==(const PrimitiveToken& x) const {return true;};

	bool AreYouAnArrow();
	bool AreYouACircle();
	bool AreYouARectangle();
	int IntegerValue();
};

typedef std::vector<PrimitiveToken> PrimitiveTokenVector;