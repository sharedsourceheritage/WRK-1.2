/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
    <copyright file="VsPkg.h" company="Microsoft">
        Copyright (c) Microsoft Corporation.  All rights reserved.
     </copyright>  
***************************************************************************/
#ifndef __VSPKG_H_
#define __VSPKG_H_


#include "stdafx.h"
#include "MyToolWindow.h"

using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::Win32;
using namespace Microsoft::VisualStudio::OLE::Interop;
using namespace Microsoft::VisualStudio::Shell;

typedef Microsoft::VisualStudio::OLE::Interop::IServiceProvider IOleServiceProvider;
typedef Microsoft::VisualStudio::Shell::Package VSPackage;

[assembly: ComVisible(true)];

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
                    [DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
                    [ProvideMenuResource(1000, 1)]
                    [RegisterLoadKey("Professional", "8.0", "Managed Tool Window (C++)", "Microsoft", 1)]
                    [InstalledProductRegistration(ProductName = "Managed Tool Window (C++)", ProductDetails = "Sample package demonstrating a Tool Window in Managed C++.", ProductId = "8.0")]
                    [ProvideToolWindow(__typeof(Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::MyToolWindow))]
                    [Guid("AD5B3373-1F9E-442f-969F-94A92FBBAA2C")]
                    public __gc    class
                    ToolWindow : public VSPackage
                    {
                        public:
                            ToolWindow()
                            {
                                Trace::WriteLine("Entering constructor for: {0}", this->ToString());
                            }
                            // VSPackage methods
                            virtual void Dispose(bool);
                        protected:
                            virtual void Initialize();
                        private:
                            //Helper methods
                            //Shows the Tool window
                            void ShowToolWindow(System::Object *  sender, System::EventArgs *  e);
                        private:
                            //member variables
                            IVsWindowFrame* windowFrame;

                    };//Class ToolWindow
                }//ns ToolWindowMCPP
            }//ns Samples
        }//ns VSIP
    }//ns VisualStudio
}//ns Microsoft
#endif // __VSPKG_H_
