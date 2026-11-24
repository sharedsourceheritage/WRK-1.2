/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
	<copyright file="Guids.h" company="Microsoft">
	    Copyright (c) Microsoft Corporation.  All rights reserved.
	 </copyright>  
***************************************************************************/
#ifndef __GUIDS_H_
#define __GUIDS_H_


#include "stdafx.h"

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace VSIP
		{
			namespace Samples
			{
				namespace ToolWindowMCPP
				{
					public __gc
					class GuidList
					{
						private:
						        GuidList(){}

						public:
							//Tool Window Package Guid
							static Guid guidToolWindowPkg =			Guid("{AD5B3373-1F9E-442f-969F-94A92FBBAA2C}");
							//Guid for Menu group added by 
							static Guid guidToolWindowMenuGroup =	Guid("{26CB6B7B-D8D4-47dd-8A8B-4F4DB74FEFB9}");
							//Guid used for the command set associated with the menu item
							static Guid guidToolWindowCmdSet =		Guid("{8CBE33CC-CA38-4a8a-9FB9-27679773566E}");
							//Unique identifier for this tool window so the environment can retain information 
							static Guid guidToolWindowPersistance =	Guid("{4D97D6B5-7682-4147-BA1B-D3A739B0E45D}");

					};
				}
			}
		}
	}
};

#endif //__GUIDS_H_