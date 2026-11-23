<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>

<asp:content id="Content1" contentplaceholderid="MainBody" runat="Server">

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ImageMap" runat="server">
  ImageMap
</Acme:TypeRef>
</h2>

<p>
Use the ImageMap control to create an image that contains defined hotspot 
regions. When a user clicks a hot spot region, the control can either generate 
a post back to the server or navigate to a specified URL. For example, you can 
use this control to display a map of a geographical region. When a user clicks 
a specific region on the map, the control navigates to a URL that provides 
additional data about the selected region. You can also use this control to 
generate a post back to the server and run specific code based on the hot spot 
region that was clicked. For example, you can use an ImageMap control to capture 
user responses such as votes. When a user clicks the hot spot region defined for 
yes votes, code is called to record a yes response in a database. When a user 
clicks on the hot spot region defined for no votes, a no response is recorded. 
You can also mix these two scenarios within a single ImageMap control. For 
example, you can specify one hot spot region to navigate to a URL and another 
hot spot region to post back to the server.
</p>

<p>
The following example illustrates navigating to different URLs based on the
region of the image that is clicked.
</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageMap/ImageMap1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageMap/ImageMap1.src"
        Caption="C# ImageMap Navigate URL"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageMap/ImageMap1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageMap/ImageMap1.src"
        Caption="VB ImageMap Navigate URL"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<p>
The following example illustrates running different server code based on the
region of the image that is clicked.
</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageMap/ImageMap2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageMap/ImageMap2.src"
        Caption="C# ImageMap Run Server Code"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageMap/ImageMap2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageMap/ImageMap2.src"
        Caption="VB ImageMap Run Server Code"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:content>
