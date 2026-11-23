<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Generate and compare a hash value?</h2>

<br /><br />It is easy to generate and compare hash values using the cryptographic resources contained 
in the <b>System.Security.Cryptography</b> namespace. Because all hash functions take input of 
type <b>Byte[]</b>, it might be necessary to convert the source into a byte array before it is 
hashed.

<br /><br />To generate a hash value, create an instance of a hash algorithm and call 
<b>ComputeHash()</b> on it. The following code creates an instance of the <b>MD5</b> hash 
algorithm and calls <b>ComputeHash()</b> on it. The hash function returns a byte array
containing the hash value of the byte array <b>Input</b>

<Acme:TabControl runat="server">
<Tab Name="C#">
Byte[] HashVal = (new MD5CryptoServiceProvider()).ComputeHash(Input);
</Tab>
<Tab Name="VB">
Dim HashVal As Byte() = New MD5CryptoServiceProvider().ComputeHash(Input)
</Tab>
<Tab Name="C++">
Byte hashvalue[] = (new MD5CryptoServiceProvider)->ComputeHash(Input);
</Tab>
</Acme:TabControl>

<br /><br />Note that <b>ComputeHash()</b> is the final operation performed on an instance of a hash 
object. If another hash value needs to be generated, a new instance of a hash algorithm must 
be created.

<br /><br /><b>System.Security.Cryptography</b> contains implementations of <b>MD5</b>, <b>SHA1</b>, 
<b>SHA256</b>, <b>SHA384</b>, and <b>SHA512</b>. The following code computes a <b>SHA1</b> hash value.

<Acme:TabControl runat="server">
<Tab Name="C#">
Byte[] HashVal = (new SHA1CryptoServiceProvider()).ComputeHash(Input);
</Tab>
<Tab Name="VB">
Dim HashVal As Byte() = New SHA1CryptoServiceProvider().ComputeHash(Input)
</Tab>
<Tab Name="C++">
Byte hashvalue[] = (new SHA1CryptoServiceProvider)->ComputeHash(Input);
</Tab>
</Acme:TabControl>

<br /><br />To compare hash values, perform an element-by-element comparison of the hash value byte 
arrays.

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/hash/hash.src"
        Icon="../../images/console.gif"
        Caption="C# hash.exe"
	SamplePath="howto\samples\cryptography\hash\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/hash/hash.src"
        Icon="../../images/console.gif"
        Caption="VB hash.exe"
	SamplePath="howto\samples\cryptography\hash\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/hash/hash.src"
        Icon="../../images/console.gif"
        Caption="C++ hash.exe"
	SamplePath="howto\samples\cryptography\hash\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>
