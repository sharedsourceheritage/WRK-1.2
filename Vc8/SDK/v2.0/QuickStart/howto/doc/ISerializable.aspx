<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use ISerializable to Customize the Serialization of a Class?</h2>

<div class="indent" style="width:660">
<br /><br />This sample illustrates how to use the <b>ISerializable</b> interface to customize
the serialization of your own objects. This sample serializes objects based
on the mscorlib assembly namespace tree structure. Each object contains a
property as the name of the item and a list of children as per the real
object in the mscorlib assembly. To demonstrate the customization possible
with <b>ISerializable</b>, "(SAVED)" is appended to the namespace name to indicate
that the values are not live. When the data is read back in, this tag could
be modified or removed. Note: This sample requires the
System.Runtime.Serialization.Formatters.Soap.dll.
</div>

<h2>Example</h2>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Serialization/ISerializable/ISerializable.src"
        Icon="../../images/console.gif"
        Caption="C# ISerializable.exe"
	SamplePath="howto\samples\Serialization\ISerializable\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Serialization/ISerializable/ISerializable.src"
        Icon="../../images/console.gif"
        Caption="VB ISerializable.exe"
	SamplePath="howto\samples\Serialization\ISerializable\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Serialization/ISerializable/ISerializable.src"
        Icon="../../images/console.gif"
        Caption="C++ ISerializable.exe"
	SamplePath="howto\samples\Serialization\ISerializable\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Serialization/ISerializable/ISerializable.src"
        Icon="../../images/console.gif"
        Caption="J# ISerializable.exe"
	SamplePath="howto\samples\Serialization\ISerializable\"
        CanBeHosted="false"
        runat="server" />>	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>


