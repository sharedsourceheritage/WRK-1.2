/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "coloritem.h"
#include <ctype.h>
#include "strsafe.h"

#ifdef VS6
#define FF_STRIKETHROUGH  2
#endif

/*---------------------------------------------------------
  Prototypes
---------------------------------------------------------*/
void parseProperties( in ColorItem& colorItem, in const wchar_t* style );

/*---------------------------------------------------------
  ColorItem
---------------------------------------------------------*/
ColorItem::ColorItem( in BSTR description, in BSTR style )
{
  TRACE_CREATE( "ColorItem", static_cast<IVsColorableItem*>(this) );

  m_refCount    = 1;
  m_description = ::SysAllocString(description);
  m_foreColor   = CI_USERTEXT_FG;
  m_backColor   = CI_USERTEXT_BK;
  m_fontFlags   = 0;

  parseProperties( *this, style );

}


ColorItem::~ColorItem()
{
  TRACE_DESTROY( static_cast<IVsColorableItem*>(this) );
  ::SysFreeString(m_description);
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP ColorItem::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsColorableItem)
  {
    TRACE("ColorItem::QueryInterface for IUnknown/IVsColorableItem");
    *obj = static_cast<IVsColorableItem*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) ColorItem::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) ColorItem::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}

/*---------------------------------------------------------
  IVsColorableItem
-----------------------------------------------------------*/
STDMETHODIMP ColorItem::GetDefaultColors (out COLORINDEX* foreColor, out COLORINDEX* backColor )
{
  if (foreColor) *foreColor = m_foreColor;
  if (backColor) *backColor = m_backColor;
  return S_OK;
}

STDMETHODIMP ColorItem::GetDefaultFontFlags ( out DWORD* fontFlags )
{
  if (fontFlags) *fontFlags = m_fontFlags;
  return S_OK;
}

STDMETHODIMP ColorItem::GetDisplayName ( out BSTR* description )
{
  if (description) *description = ::SysAllocString(m_description);
  return S_OK;
}



/*---------------------------------------------------------
  Font weights & Text decoration
---------------------------------------------------------*/
struct FontFlagInfo 
{
  const wchar_t* name;
  DWORD          flag;
};

static FontFlagInfo fontWeightTable[] =
{ 
  { L"normal", 0 },
  { L"bold",   FF_BOLD },
  { L"100",    0 },
  { L"200",    0 },
  { L"300",    0 },
  { L"400",    0 },
  { L"500",    0 },  
  { L"600",    FF_BOLD },
  { L"700",    FF_BOLD },
  { L"800",    FF_BOLD },
  { L"900",    FF_BOLD },
  { L"bolder", FF_BOLD },
  { L"lighter",0 },
  { NULL,      0 }
};

static FontFlagInfo textDecorationTable[] =
{
  { L"line-through",    FF_STRIKETHROUGH },
  { L"strike-through",  FF_STRIKETHROUGH },
  { NULL, 0 }
};

/*---------------------------------------------------------
  Colors
---------------------------------------------------------*/
struct ColorInfo 
{
  const wchar_t* name;
  COLORINDEX     color;
};

static ColorInfo fgColorTable[] = 
{
   { L"auto",       CI_USERTEXT_FG      }
  ,{ L"text",       CI_USERTEXT_FG      }
  ,{ L"selected",   CI_SYSSEL_FG        }
  ,{ L"inactive",   CI_SYSINACTSEL_FG   }
  ,{ L"plaintext",  CI_SYSPLAINTEXT_FG  }    
  ,{ NULL,          CI_USERTEXT_FG      }
};

static ColorInfo bgColorTable[] =
{
   { L"auto",       CI_USERTEXT_BK      }
  ,{ L"text",       CI_USERTEXT_BK      }
  ,{ L"selected",   CI_SYSSEL_BK        }
  ,{ L"inactive",   CI_SYSINACTSEL_BK   }
  ,{ L"margin",     CI_SYSWIDGETMGN_BK  }
  ,{ L"plaintext",  CI_SYSPLAINTEXT_BK  }
  ,{ NULL,          CI_USERTEXT_BK      }
}; 

static ColorInfo colorTable[] =
{
   //VS predefined colors
   { L"black",      CI_BLACK       }
  ,{ L"white",      CI_WHITE       }
  ,{ L"maroon",     CI_MAROON      }
  ,{ L"darkgreen",  CI_DARKGREEN   }
  ,{ L"brown",      CI_BROWN       }
  ,{ L"darkblue",   CI_DARKBLUE    }
  ,{ L"purple",     CI_PURPLE      }
  ,{ L"aquamarine", CI_AQUAMARINE  }
  ,{ L"lightgray",  CI_LIGHTGRAY   }
  ,{ L"darkgray",   CI_DARKGRAY    }
  ,{ L"red",        CI_RED         }
  ,{ L"green",      CI_GREEN       }
  ,{ L"yellow",     CI_YELLOW      }
  ,{ L"blue",       CI_BLUE        }
  ,{ L"magenta",    CI_MAGENTA     }
  ,{ L"cyan",       CI_CYAN        }

  //Extra CSS defined colors in the VGA set
  ,{ L"lime",   CI_GREEN      }
  ,{ L"aqua",   CI_AQUAMARINE }
  ,{ L"fuchsia",CI_MAGENTA    }
  ,{ L"gray",   CI_DARKGRAY   }
  ,{ L"silver", CI_LIGHTGRAY  }
  ,{ L"olive",  CI_BROWN      }
  ,{ L"teal",   CI_BLUE       }
  ,{ L"navy",   CI_DARKBLUE   }
    
  ,{ NULL,      CI_USERTEXT_FG }
};


/*---------------------------------------------------------
  Text kinds
---------------------------------------------------------*/
struct TextKindInfo
{
  const wchar_t*  name;
  ULONG           index;
};

static TextKindInfo textKindTable[] =
{
  { L"humantext",   HUMAN_TEXT_ATTR },
  { L"programtext", 0               },
  { NULL,           0               }
};


/*---------------------------------------------------------
  Table lookups
---------------------------------------------------------*/
COLORINDEX lookupColor( const wchar_t* token, bool isForeGround )
{
    ColorInfo* info;

    //first try general color table
    for (info = colorTable; info->name; info++)
        if (strICompare( info->name, token ) == 0) return info->color;

    //then try specific background/foreground table
    if (isForeGround) info = fgColorTable;
                 else info = bgColorTable;

    for (; info->name; info++)
        if (strICompare( info->name, token ) == 0) return info->color;

    return info->color;         
}

DWORD lookupFontFlag( FontFlagInfo* table, const wchar_t* token )
{
    FontFlagInfo* info;

    for( info = table; info->name; info++)
        if (strICompare( info->name, token ) == 0)  return info->flag;
    
    return info->flag;
}


ULONG lookupTextKind( const wchar_t* value )
{
    TextKindInfo* info;

    for( info = textKindTable; info->name; info++)
      if (strICompare( info->name, value ) == 0) return info->index;

    return info->index;
}

/*---------------------------------------------------------
  property setters
---------------------------------------------------------*/
void setColor( ColorItem& colorItem, const wchar_t* value, bool isForeGround )
{
  if (isForeGround) colorItem.m_foreColor = lookupColor(value,isForeGround);
              else  colorItem.m_backColor = lookupColor(value,isForeGround);
}

void setFontWeight( ColorItem& colorItem, const wchar_t* value )
{
  colorItem.m_fontFlags |= lookupFontFlag( fontWeightTable, value);
}

void setTextDecoration( ColorItem& colorItem, const wchar_t* value )
{
  colorItem.m_fontFlags |= lookupFontFlag( textDecorationTable, value );
}

void setTextKind( ColorItem& colorItem, const wchar_t* value )
{
  //actually, the colorizer should adjust the colorclass 
  //with the HUMANTEXT flag if necessary; this implies building
  //a translation table just for the colorizer...yuck!

  //for now, we simply ignore this flag
}


//short hands
void setFgColor( ColorItem& colorItem, const wchar_t* value )
{
  setColor( colorItem, value, true );
}

void setBgColor( ColorItem& colorItem, const wchar_t* value )
{
  setColor( colorItem, value, false );
}

void setBold( ColorItem& colorItem, const wchar_t* value )
{
  setFontWeight( colorItem, L"bold" );
}

void setLineThrough( ColorItem& colorItem, const wchar_t* value )
{
  setTextDecoration( colorItem, L"line-through" );
}

void setHumanText( ColorItem& colorItem, const wchar_t* value )
{
  setTextKind( colorItem, L"humantext" );
}

/*---------------------------------------------------------
  Get the property setter
---------------------------------------------------------*/
struct PropertyInfo
{
  const wchar_t* name;
  void (*setter)( ColorItem& colorItem, const wchar_t* value );
};

static PropertyInfo propertyTable[] =
{
  //official
  { L"color",             setFgColor    },
  { L"background-color",  setBgColor    },
  { L"font-weight",       setFontWeight },
  { L"text-decoration",   setTextDecoration },
  { L"text-kind",         setTextKind   },

  //shorthands
  { L"bgcolor",           setBgColor    },
  { L"bold",              setBold       },
  { L"strike-through",    setLineThrough},
  { L"line-through",      setLineThrough},
  { L"humantext",         setHumanText  },
  { NULL, NULL }
};

void setProperty( ColorItem& colorItem, const wchar_t* name, const wchar_t* value )
{
  PropertyInfo* info;
  for (info = propertyTable; info->name; info++)
  {
    if (strICompare(name,info->name) == 0) 
    {
      info->setter( colorItem, value );
      return;
    }
  }
  return;
}

/*---------------------------------------------------------
  Parse a style specification
---------------------------------------------------------*/
const wchar_t* skipWhiteSpace( const wchar_t* str )
{
  while (iswspace(*str) || *str == L'{' || *str == L'}')
  {
    str++;
  }
  return str;
}


const wchar_t* parseProperty( ColorItem& colorItem, const wchar_t* str )
{
  const int MaxName = 255;

  wchar_t name[MaxName+1];
  wchar_t value[MaxName+1];
  int i;

  //scan the name
  i = 0;
  while (iswalpha(*str) || *str == L'-')
  {
    if (i < MaxName) name[i] = *str;
    i++;
    str++;
  }
  if (i < MaxName) name[i] = 0;
              else name[MaxName] = 0;
  str = skipWhiteSpace(str);
  
  //try to parse the value
  if (*str != L':')
  {
    StringCchCopy( value, MaxName, L"default" );
  }
  else
  {
    str++; //skip ':'
    str = skipWhiteSpace(str);
    
    //scan the value
    i = 0;
    while (iswalnum(*str) || *str == L'#')
    {
      if (i < MaxName) value[i] = *str;
      i++;
      str++;
    }
    if (i < MaxName) value[i] = 0;
                else value[MaxName] = 0;
    str = skipWhiteSpace(str);
  }

  //set the property
  setProperty( colorItem, name, value );
  return str;
}

void parseProperties( ColorItem& colorItem, const wchar_t* str )
{
  if (str == NULL) return;

  //skip leading whitespace
  str = skipWhiteSpace( str );

  while (*str != 0 && *str != L'}')
  {
    if (*str == L';')
    {
      //skip the semicolon
      str++;
    }
    else if (iswalpha(*str)) 
    {
      //parse and set the property
      str = parseProperty(colorItem,str);
    }
    else
    {
      //something bad is happening, skip till next ';' or '}' or '\0'
      while (*str != L';' && *str != L'}' && *str != 0)
      {
        str++;
      }
    }
    
    //always skip whitespace after a token
    str = skipWhiteSpace(str);
  }

  return;
}
                
