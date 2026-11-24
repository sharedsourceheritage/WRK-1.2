
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include <stdarg.h>
#include <stdio.h>

#include "project.h"


/*---------------------------------------------------------
  DebugContext
  This is just for easy parameter passing
-----------------------------------------------------------*/
struct DebugContext
{
  IDebugSymbolProvider* pprovider;
  IDebugAddress*        paddress;
  IDebugBinder*         pbinder;
};

/*---------------------------------------------------------
  Prototypes for parsing
-----------------------------------------------------------*/
typedef const OLECHAR*  InputStr;

static HRESULT EvalExpr      ( in DebugContext* pcontext, inout InputStr& pszInput, out BSTR* pbstrErrorMessage, out VARIANT* pvarValue);
static HRESULT EvalPrefix    ( in DebugContext* pcontext, inout InputStr& pszInput, out BSTR* pbstrErrorMessage, out VARIANT* pvarValue);

static HRESULT EvalFactor    ( in DebugContext* pcontext, inout InputStr& pszInput, out BSTR* pbstrErrorMessage, out VARIANT* pvarValue);
static HRESULT EvalIdentifier( in DebugContext* pcontext, inout InputStr& pszInput, out BSTR* pbstrErrorMessage, out VARIANT* pvarValue);
static HRESULT EvalNumber    ( in DebugContext* pcontext, inout InputStr& pszInput, out BSTR* pbstrErrorMessage, out VARIANT* pvarValue);

static void SkipWhiteSpace( inout InputStr& pszInput );
static void SetErrorMessage( out BSTR* pbstrErrorMessage, in LPCOLESTR pszFormat, in ... );


/*---------------------------------------------------------
  Evaluate/Parse
-----------------------------------------------------------*/
HRESULT Parse( in LPCOLESTR pszExpr, out BSTR* pbstrErrorMessage )
{
  return Evaluate( NULL, NULL, NULL, pszExpr, pbstrErrorMessage, NULL );
}

HRESULT Evaluate( in  IDebugSymbolProvider* pprovider,
                  in  IDebugAddress*        paddress,
                  in  IDebugBinder*         pbinder,
                  in  LPCOLESTR             pszExpr,
                  out BSTR*                 pbstrErrorMessage,
                  out VARIANT*              pvarValue  )
{
  REFARG(pszExpr);
  if (pbstrErrorMessage) *pbstrErrorMessage = NULL;
  if (pvarValue)        VariantInit(pvarValue);

  HRESULT hr;

  //create a context
  DebugContext* pcontext = NULL;
  if (pprovider && paddress && pbinder)
  {
    pcontext = ALLOC(DebugContext);
    if (!pcontext) return E_OUTOFMEMORY;

    pcontext->pprovider = pprovider;
    pcontext->paddress  = paddress;
    pcontext->pbinder   = pbinder;
  }
  
  //evaluate (or parse)
  LPCOLESTR pszInput = pszExpr;
  SkipWhiteSpace( pszInput );
  
  hr = EvalExpr( pcontext, pszInput, pbstrErrorMessage, pvarValue );
  FREE(pcontext);

  if (hr != S_OK)
  {
    SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_INVALIDEXPR), 
                     (pszInput[0] == 0 ? OLE("end") : pszInput) );
    if (pvarValue) VariantClear(pvarValue);
    return hr;
  }
  
  if (*pszInput != 0)   
  {
    SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_NOTATEND), 
                     (pszInput[0] == 0 ? OLE("end") : pszInput) );
    if (pvarValue) VariantClear(pvarValue);
    return S_FALSE;
  }

  return S_OK;
}



/*---------------------------------------------------------
  Character classification
-----------------------------------------------------------*/
bool isWhiteChar( in wchar_t c )
{
  return (iswspace(c) != 0);
}

bool isOperatorChar( in wchar_t c )
{
  static LPCOLESTR opChars = OLE("^+-*/!=><&|");

  return (wcschr(opChars,c) != NULL);
}

bool isIdentifierStartChar( in wchar_t c )
{
  return (iswalpha(c) != 0);
}

bool isIdentifierChar( in wchar_t c )
{
  return (iswalnum(c) || c == OLE('_'));
}


/*---------------------------------------------------------
  Expressions
-----------------------------------------------------------*/

/*---------------------------------------------------------
  Binary Operators
-----------------------------------------------------------*/
enum Assoc
{
  AssocUnknown, AssocLeft, AssocRight, AssocNone
};

struct BinaryOpInfo
{
  LPCOLESTR       pszName;
  Assoc           assoc;
  int             precedence;
  HRESULT         (*eval)(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result );
  VARTYPE         typeX;
  VARTYPE         typeY;
  VARTYPE         typeResult;
};


/*---------------------------------------------------------
  Binary operator Evaluation functions
-----------------------------------------------------------*/
HRESULT Or(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = x.boolVal || y.boolVal; 
  return S_OK;
}

HRESULT And(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = x.boolVal && y.boolVal;  
  return S_OK;
}


HRESULT Lt(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal < y.lVal); 
  return S_OK;
}

HRESULT Gt(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal > y.lVal); 
  return S_OK;
}

HRESULT Lte(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal <= y.lVal); 
  return S_OK;
}

HRESULT Gte(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal >= y.lVal); 
  return S_OK;
}

HRESULT Eq(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal == y.lVal); 
  return S_OK;
}

HRESULT Neq(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.lVal != y.lVal); 
  return S_OK;
}


HRESULT BitOr(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal | y.lVal; 
  return S_OK;
}

HRESULT BitAnd(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal & y.lVal; 
  return S_OK;
}

HRESULT BitXor(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal ^ y.lVal; 
  return S_OK;
}


HRESULT Plus(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal + y.lVal; 
  return S_OK;
}

HRESULT Minus(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal - y.lVal; 
  return S_OK;
}

HRESULT Mul(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal * y.lVal; 
  return S_OK;
}

HRESULT Div(in VARIANT& x, in VARIANT& y, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = 0;
  if (y.lVal == 0)
  {
    SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_DIVIDEBYZERO) );
    return S_FALSE;
  }

  result.lVal = x.lVal/y.lVal;
  return S_OK;
}


/*---------------------------------------------------------
  Binary operators: EvalBinaryOp
-----------------------------------------------------------*/
BinaryOpInfo binaryOpTable[] =
{
  { OLE("||"),  AssocLeft, 1, Or,     VT_BOOL,  VT_BOOL,  VT_BOOL },
  { OLE("&&"),  AssocLeft, 1, And,    VT_BOOL,  VT_BOOL,  VT_BOOL },

  { OLE("<"),   AssocNone, 2, Lt,     VT_I4,    VT_I4,    VT_BOOL },
  { OLE(">"),   AssocNone, 2, Gt,     VT_I4,    VT_I4,    VT_BOOL },
  { OLE("<="),  AssocNone, 2, Lte,    VT_I4,    VT_I4,    VT_BOOL },
  { OLE(">="),  AssocNone, 2, Gte,    VT_I4,    VT_I4,    VT_BOOL },
  { OLE("=="),  AssocNone, 2, Eq,     VT_I4,    VT_I4,    VT_BOOL },
  { OLE("!="),  AssocNone, 2, Neq,    VT_I4,    VT_I4,    VT_BOOL },
  
  { OLE("|"),   AssocLeft, 3, BitOr,  VT_I4,    VT_I4,    VT_I4   },
  { OLE("&"),   AssocLeft, 3, BitAnd, VT_I4,    VT_I4,    VT_I4   },
  { OLE("^"),   AssocLeft, 3, BitXor, VT_I4,    VT_I4,    VT_I4   },

  { OLE("+"),   AssocLeft, 4, Plus,   VT_I4,    VT_I4,    VT_I4   },
  { OLE("-"),   AssocLeft, 4, Minus,  VT_I4,    VT_I4,    VT_I4   },
  
  { OLE("*"),   AssocLeft, 5, Mul,    VT_I4,    VT_I4,    VT_I4   },
  { OLE("/"),   AssocLeft, 5, Div,    VT_I4,    VT_I4,    VT_I4   },
  
  { NULL,       AssocUnknown, 0, NULL,VT_EMPTY, VT_EMPTY, VT_EMPTY}
};


HRESULT EvalBinaryOp( in    int            precedence, 
                      in    Assoc          assoc, 
                      inout InputStr&      pszInput,
                      out   BSTR*          pbstrErrorMessage,
                      out   BinaryOpInfo** ppopinfo )

{
  OUTARG(ppopinfo);

  InputStr pszInputEnd = pszInput;
  while (*pszInputEnd && isOperatorChar(*pszInputEnd)) { pszInputEnd++; }

  unsigned tokenLen = (unsigned) (pszInputEnd - pszInput);
  if (tokenLen == 0) return S_FALSE;

  for (BinaryOpInfo* pbinaryOp = binaryOpTable; pbinaryOp->pszName; pbinaryOp++)
  {
    if (wcsncmp(pszInput,pbinaryOp->pszName,tokenLen) == 0 && (wcslen(pbinaryOp->pszName) <= tokenLen)) 
    { 
      if (precedence > pbinaryOp->precedence)
      {
        return S_FALSE;
      }
      else if (precedence == pbinaryOp->precedence)
      {
        if (assoc == AssocLeft)
        {
          if (pbinaryOp->assoc != AssocLeft)
          {
            SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_AMBIGIOUSASSOC), pbinaryOp->pszName );
            return E_FAIL;
          }
          else
            return S_FALSE;
        }
        else if (assoc == AssocNone || (assoc == AssocRight && pbinaryOp->assoc != AssocRight))
        {
          SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_AMBIGIOUSASSOC), pbinaryOp->pszName );
          return E_FAIL;
        }
      }

      *ppopinfo = pbinaryOp;
      pszInput   = pszInput + wcslen(pbinaryOp->pszName);
      SkipWhiteSpace( pszInput );
      return S_OK;
    }
  }

  return S_FALSE;
}


/*---------------------------------------------------------
  Expressions: EvalExpr
-----------------------------------------------------------*/
HRESULT EvalExprEx(in    int            precedence, 
                   in    Assoc          assoc, 
                   in    DebugContext*  pcontext,    
                   inout InputStr&      pszInput,
                   out   BSTR*          pbstrErrorMessage,
                   out   VARIANT*       pvarValue  )
{
  HRESULT hr;

  hr = EvalFactor( pcontext, pszInput, pbstrErrorMessage, pvarValue );
  if (hr != S_OK) return hr;

  BinaryOpInfo* pbinaryOp = NULL;  
  hr = EvalBinaryOp( precedence, assoc, pszInput, pbstrErrorMessage, &pbinaryOp );    
  if (FAILED(hr)) return S_FALSE;

  while (hr == S_OK)
  {
    VARIANT valueY;
    VariantInit( &valueY );
    hr = EvalExprEx( pbinaryOp->precedence, pbinaryOp->assoc, pcontext, pszInput, pbstrErrorMessage, &valueY );
    if (hr != S_OK) return hr;

    if (pcontext)
    {
      if (!pvarValue) { VariantClear(&valueY); return E_INVALIDARG; }

      VARIANT varY;
      VariantInit(&varY);
      hr = VariantValueCoerce( pcontext->pbinder, pbinaryOp->typeY, valueY, &varY );      
      VariantClear(&valueY);
      if (FAILED(hr)) { SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_ILLEGALOPERANDS), pbinaryOp->pszName ); return hr; }

      VARIANT varX;
      VariantInit(&varX);
      hr = VariantValueCoerce( pcontext->pbinder, pbinaryOp->typeX, *pvarValue, &varX );
      if (FAILED(hr)) { SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_ILLEGALOPERANDS), pbinaryOp->pszName ); VariantClear(&varY); return hr; }

      VariantClear(pvarValue);
      hr = pbinaryOp->eval( varX, varY, pbstrErrorMessage, *pvarValue );
      VariantClear(&varX);
      VariantClear(&varY);
      if (hr != S_OK) return hr;

      pvarValue->vt = pbinaryOp->typeResult;    
    }

    hr = EvalBinaryOp( precedence, assoc, pszInput, pbstrErrorMessage, &pbinaryOp );
    if (FAILED(hr)) return S_FALSE;
  }

  return S_OK;
}


HRESULT EvalExpr(in    DebugContext*  pcontext,    
                 inout InputStr&      pszInput,
                 out   BSTR*          pbstrErrorMessage,
                 out   VARIANT*       pvarValue  )
{
  return EvalExprEx( 0, AssocUnknown, pcontext, pszInput, pbstrErrorMessage, pvarValue );
}



/*---------------------------------------------------------
  Unary Expression
-----------------------------------------------------------*/
struct UnaryOpInfo
{
  LPCOLESTR   pszName;
  HRESULT     (*eval)(in VARIANT& x, out BSTR* pbstrErrorMessage, out VARIANT& result );
  VARTYPE     typeX;
  VARTYPE     typeResult;
};


/*---------------------------------------------------------
  Unary Expression: Evaluation functions
-----------------------------------------------------------*/
HRESULT Not(in VARIANT& x, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.boolVal = (x.boolVal == 0);
  return S_OK;
}

HRESULT Negate(in VARIANT& x, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = -x.lVal;
  return S_OK;
}

HRESULT Id(in VARIANT& x, out BSTR* pbstrErrorMessage, out VARIANT& result )
{
  result.lVal = x.lVal;
  return S_OK;
}

/*---------------------------------------------------------
  Unary Expression: Operator table
-----------------------------------------------------------*/
UnaryOpInfo unaryOpTable[] =
{
  { OLE("!"),   Not,    VT_BOOL,  VT_BOOL },
  { OLE("-"),   Negate, VT_I4,    VT_I4   },
  { OLE("+"),   Id,     VT_I4,    VT_I4   },

  { NULL,       NULL,   VT_EMPTY, VT_EMPTY}
};


/*---------------------------------------------------------
  Prefix Expression
-----------------------------------------------------------*/
HRESULT EvalUnaryOp(inout InputStr&      pszInput,
                    out   BSTR*          pbstrErrorMessage,
                    out   UnaryOpInfo**  ppopinfo )
{
  OUTARG(ppopinfo);

  InputStr pszInputEnd = pszInput;
  while (*pszInputEnd && isOperatorChar(*pszInputEnd)) { pszInputEnd++; }

  unsigned tokenLen = (unsigned) (pszInputEnd - pszInput);
  if (tokenLen == 0) return S_FALSE;

  for (UnaryOpInfo* pUnaryOp = unaryOpTable; pUnaryOp->pszName; pUnaryOp++)
  {
    if (wcsncmp(pszInput,pUnaryOp->pszName,tokenLen) == 0 && (wcslen(pUnaryOp->pszName) <= tokenLen))
    {
      *ppopinfo = pUnaryOp;
      pszInput   = pszInput + wcslen(pUnaryOp->pszName);
      SkipWhiteSpace( pszInput );
      return S_OK;
    }
  }

  return S_FALSE;
}


HRESULT EvalPrefix( in    DebugContext*  pcontext,    
                         inout InputStr&      pszInput,                         
                         out   BSTR*          pbstrErrorMessage,
                         out   VARIANT*       pvarValue  )
{
  HRESULT hr;
  
  UnaryOpInfo* pUnaryOp;
  hr = EvalUnaryOp( pszInput, pbstrErrorMessage, &pUnaryOp );
  if (FAILED(hr)) return hr;
 
  if (hr == S_OK)
  {
    if (pcontext)      
    {
      if (!pvarValue) return E_INVALIDARG; 

      VARIANT varX;
      VariantInit(&varX);
      hr = VariantValueCoerce( pcontext->pbinder, pUnaryOp->typeX, *pvarValue, &varX );      
      if (FAILED(hr)) { SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_ILLEGALOPERAND), pUnaryOp->pszName ); return hr; }

      VariantClear(pvarValue);
      hr = pUnaryOp->eval( varX, pbstrErrorMessage, *pvarValue );
      VariantClear(&varX);
      if (hr != S_OK) return hr;       

      pvarValue->vt = pUnaryOp->typeResult;
    }
  }
  
  return EvalFactor( pcontext, pszInput, pbstrErrorMessage, pvarValue );
}


/*---------------------------------------------------------
  Expression Factor
-----------------------------------------------------------*/
HRESULT EvalFactor(in    DebugContext*  pcontext,    
                   inout InputStr&      pszInput,                         
                   out   BSTR*          pbstrErrorMessage,
                   out   VARIANT*       pvarValue  )
{
  if (isIdentifierStartChar(*pszInput))
  {
    return EvalIdentifier( pcontext, pszInput, pbstrErrorMessage, pvarValue );
  }
  else if (iswdigit(*pszInput))
  {
    return EvalNumber( pcontext, pszInput, pbstrErrorMessage, pvarValue );
  }
  else if (*pszInput == OLE('('))
  {
    HRESULT hr;
    pszInput++;
    SkipWhiteSpace(pszInput);

    hr = EvalExpr( pcontext, pszInput, pbstrErrorMessage, pvarValue );
    if (hr != S_OK) return hr;

    if (*pszInput != OLE(')'))
    {
      SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_UNBALANCEDPARENS) );
      return S_FALSE;
    }
    
    pszInput++;
    SkipWhiteSpace(pszInput);
    return S_OK;
  }
  else 
  {
    return S_FALSE;
  }
}


/*---------------------------------------------------------
  Identifiers
-----------------------------------------------------------*/
HRESULT EvalIdentifier(in    DebugContext*  pcontext,    
                       inout InputStr&      pszInput,                         
                       out   BSTR*          pbstrErrorMessage,
                       out   VARIANT*       pvarValue  )
{
  InputStr pszInputStart = pszInput;
  while (*pszInput && isIdentifierChar(*pszInput)) { pszInput++; }
  if (pszInput - pszInputStart == 0) return S_FALSE;

  if (pcontext)
  {
    HRESULT hr;
    BSTR ident = NULL;
    ident = SysAllocStringLen( pszInputStart, (UINT)(pszInput - pszInputStart) );
    if (!ident) return E_OUTOFMEMORY;

    IDebugField* pfield;
    hr = FieldLookup( pcontext->pprovider, pcontext->paddress, ident, &pfield );
    if (hr == S_FALSE) 
    {
      SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_NOTINSCOPE), ident );
    }
    FREEBSTR(ident);
    if (hr != S_OK) return hr;    

    hr = FieldGetValue( pfield, pvarValue );
    RELEASE(pfield);
    if (FAILED(hr)) return hr;
  }
  
  SkipWhiteSpace( pszInput );
  return S_OK;
}


/*---------------------------------------------------------
  Numbers
-----------------------------------------------------------*/    
long StringToNumber( in InputStr pszInput, in int count, in int radix )
{
  long number = 0;

  for( int i = 0; i < count; i++)
  {
    if (iswdigit(pszInput[i])) 
    {
      number = radix*number + (pszInput[i] - OLE('0'));
    }
    else
    {
      number = radix*number + (towlower(pszInput[i]) - OLE('a') + 10);
    }
  }

  return number;
}

HRESULT EvalNumber(in    DebugContext*  pcontext,    
                   inout InputStr&      pszInput,                         
                   out   BSTR*          pbstrErrorMessage,
                   out   VARIANT*       pvarValue  )
{
  int numberLen = 0;
  int radix     = 10;

  if ((wcsncmp(pszInput, OLE("0x"), 2) == 0) || (wcsncmp(pszInput, OLE("0X"), 2) == 0))
  {
    //hexadecimal
    radix  = 16;
    pszInput += 2;
    
    while (pszInput[numberLen] && iswxdigit(pszInput[numberLen])) { numberLen++; }
        
    if (numberLen == 0) 
    {
      SetErrorMessage( pbstrErrorMessage, GetString(IDS_ERR_EXPECTHEXADECIMAL), pszInput );
      return E_FAIL;
    }        
  }
  else
  {
    //decimal 
    radix = 10;
    while (pszInput[numberLen] && iswdigit(pszInput[numberLen])) { numberLen++; }
    if (numberLen == 0) return S_FALSE;
  }

  if (pvarValue)
  {  
    pvarValue->vt = VT_I4;
    pvarValue->lVal = StringToNumber( pszInput, numberLen, radix );
  }

  pszInput = pszInput + numberLen;
  SkipWhiteSpace( pszInput );
  return S_OK;
}


/*---------------------------------------------------------
  Whitespace
-----------------------------------------------------------*/
void SkipWhiteSpace( in InputStr& pszInput )
{
  while (*pszInput && isWhiteChar(*pszInput)) pszInput++;
}


/*---------------------------------------------------------
  SetErrorMessage
-----------------------------------------------------------*/
void SetErrorMessage( BSTR* pbstrErrorMessage, LPCOLESTR pszFormat, ... )
{
  if (!pszFormat) return;
  if (pbstrErrorMessage == NULL || *pbstrErrorMessage != NULL) return;
  
  va_list args;
  va_start( args, pszFormat );

  OLECHAR buffer[128+1];
  _vsnwprintf( buffer, 128, pszFormat, args );
  buffer[128] = 0;

  *pbstrErrorMessage = SysAllocString( buffer );

  va_end( args );
  return;
}

