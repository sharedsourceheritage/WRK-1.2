/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
    <copyright file="MyToolWindow.h" company="Microsoft">
        Copyright (c) Microsoft Corporation.  All rights reserved.
     </copyright>  
***************************************************************************/
#ifndef __MYTOOLWINDOW_H_
#define __MYTOOLWINDOW_H_

#pragma once
#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::VisualStudio::Shell::Interop;

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
                    /**
                    ***    <summary> 
                    ***        The user control that gets hosted in the tool Window
                    *** </summary>
                    **/
                    public __gc    
                    class MyControl : public System::Windows::Forms::UserControl
                    {
                    public: 
                        MyControl(void)
                        {
                            InitializeComponent();
                            WindowFrame = 0;
                        }
                        
                    protected: 
                        void Dispose(Boolean disposing)
                        {
                            if (disposing && components)
                            {
                                components->Dispose();
                            }
                            __super::Dispose(disposing);
                        } 

                        virtual bool ProcessDialogChar(__wchar_t charCode)
                        {
                            if (charCode != ' ' && ProcessMnemonic(charCode))
                            {
                                return true;
                            }
                            return __super::ProcessDialogChar(charCode);
                        }

                    private: 
                        System::Windows::Forms::Button *  button1;

                    private:
                        /// <summary>
                        /// Required designer variable.
                        /// </summary>
                        System::ComponentModel::Container* components;

                        /// <summary>
                        /// Required method for Designer support - do not modify
                        /// the contents of this method with the code editor.
                        /// </summary>        
                        void InitializeComponent(void)
                        {
                            this->button1 = new System::Windows::Forms::Button();
                            this->SuspendLayout();
                            // 
                            // button1
                            // 
                            this->button1->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                                | System::Windows::Forms::AnchorStyles::Left) 
                                | System::Windows::Forms::AnchorStyles::Right);
                            this->button1->BackColor = System::Drawing::SystemColors::Control;
                            this->button1->Location = System::Drawing::Point(32, 32);
                            this->button1->Name = S"button1";
                            this->button1->Size = System::Drawing::Size(75, 80);
                            this->button1->TabIndex = 1;
                            this->button1->Text = S"&Click Me!";
                            this->button1->Click += new System::EventHandler(this, &Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::MyControl::button1_Click);
                            // 
                            // MyToolWindow
                            // 
                            this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
                            this->Controls->Add(this->button1);
                            this->Name = S"MyToolWindow";
                            this->ResumeLayout(false);

                        }
                        
                    private:
                        System::Void button1_Click(System::Object *  sender, System::EventArgs *  e);
                    public:
                        //Property to get and set the window frame
                        __property IVsWindowFrame* get_WindowFrame() {return _WindowFrame;} ;
                        __property void set_WindowFrame(IVsWindowFrame* pFrame){_WindowFrame = pFrame;};
                        //Window frame to that hosts my tool window
                        IVsWindowFrame* _WindowFrame;

                    };

                    [Guid("4D97D6B5-7682-4147-BA1B-D3A739B0E45D")]
                    public __gc    
                    class MyToolWindow : public Microsoft::VisualStudio::Shell::ToolWindowPane
                    {
                    public:
                        MyToolWindow() : Microsoft::VisualStudio::Shell::ToolWindowPane(0)
                        {
                            Caption = "Managed Tool Window (C++)";
                            control = new MyControl();
                        }

                        virtual IWin32Window __gc* get_Window() { return static_cast<IWin32Window __gc*>(control); }

                    protected:
                        virtual void Dispose(Boolean disposing)
                        {
                            if ( disposing )
                            {
                                IVsWindowFrame __gc* windowFrame = static_cast<IVsWindowFrame __gc*>(get_Frame());
                                if (0 != windowFrame)
                                {
                                    windowFrame->CloseFrame((unsigned int)__FRAMECLOSE::FRAMECLOSE_SaveIfDirty);
                                }
                            }
                            __super::Dispose(disposing);
                        }

                        MyControl __gc* control;

                    };

                }//ns ToolWindowMCPP
            }//ns Samples
        }//ns VSIP
    }//ns VisualStudio
}//ns Microsoft

#endif //__MYTOOLWINDOW_H_