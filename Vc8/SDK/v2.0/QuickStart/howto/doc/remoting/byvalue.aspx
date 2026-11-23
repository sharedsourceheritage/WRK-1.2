<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Pass An Object to a Server By Value?</h4>

<p>The <a href="byreference.aspx">Pass an Object to a Server by Reference</a> section illustrated that local objects are always passed by
value when you call a remote function.  To demonstrate this concept, you need change the previous example.<p>

<p>The first step is to create the object you need to pass to the server.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
using System;
namespace Microsoft.Samples.Remoting.RemotingSamples {

    [serializable]
    public class ForwardMe {

        private int mValue = 1;

        public void CallMe() {
            mValue++;
        }

        public int getValue() {
            return mValue;
        }
    }
}
</Tab>
<Tab Name="VB">
Imports System
Namespace Microsoft.Samples.Remoting.RemotingSamples

    <Serializable> Public Class ForwardMe
        Dim mValue As Integer = 1

        Public Sub CallMe()
            mValue += 1
        End Sub

        Public Function getValue() As Integer
            Return mValue
        End Function
    End Class
End Namespace

</Tab>
<Tab Name="C++">

using namespace System;
using namespace System::Runtime::Remoting;

namespace RemotingSamples
{
    [Serializable]
    public ref class ForwardMe
    {
    private:
	int mValue;

    public:
	ForwardMe()
	{
	    mValue = 1;
	}

	void CallMe()
	{
	   mValue++;
	}

	int getValue()
	{
	    return mValue;
	}
    };
}
</Tab>
</Acme:TabControl>
<p>


This class is flagged with the [serializable] custom attribute, which allows it to be
streamed to and from the server.  When you run the sample, the client reports the
value of the counter to be one. Since the server calls the <b>CallMe</b> method on
the object five times, the value of the counter when the object is returned
is six.  Note that the client has two instances of the <b>ForwardMe</b> class
after calling the <b>remote</b> method: the instance that was passed and a copy of
the instance that was returned.<p>

<Acme:LangSwitch runat="server">
<CsTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/byvalue/server.src"
  Icon="../../../images/genicon.gif"
  Caption="C# Passing by Value"
  SamplePath="HowTo\Samples\Remoting\byvalue\"
  runat="server" />
</CsTemplate>
<VbTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/byvalue/server.src"
  Icon="../../../images/genicon.gif"
  Caption="VB Passing by Value"
  SamplePath="HowTo\Samples\Remoting\byvalue\"
  runat="server" />
</VbTemplate>
<CpTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/byvalue/server.src"
  Icon="../../../images/genicon.gif"
  SamplePath="HowTo\Samples\Remoting\byvalue\"
  Caption="C++ Passing by Value"
  runat="server" />
</CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/byvalue/server.src"
  Icon="../../../images/genicon.gif"
  Caption="J# Passing by Value"
  SamplePath="HowTo\Samples\Remoting\byvalue\"
  runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>
<p>

</asp:Content>


