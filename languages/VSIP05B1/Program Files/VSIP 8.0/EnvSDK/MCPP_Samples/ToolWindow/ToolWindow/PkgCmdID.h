/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
	<copyright file="PkgCmd.h" company="Microsoft">
	    Copyright (c) Microsoft Corporation.  All rights reserved.
	 </copyright>  
***************************************************************************/
#ifndef __PKGCMDID_H_
#define __PKGCMDID_H_

#include "stdafx.h"
//Add Comments
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
					class PkgCmdIDList
					{
						public:
							//The ID of the command to be executed
							static const int CmdMyTool = 0x101;
					};

				};
			};
		};
	};
};

#endif // __PKGCMDID_H_
