<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Encrypt and Decrypt a file?</h2>

<br /><br />The <b>CryptoStream</b> class in the <b>System.Security.Cryptography</b> namespace is used
to easily define cryptographic transforms on any data stream. The constructor is defined as
the following: <b>CryptoStream</b> (<b>Stream</b> argument, <b>ICryptoTransform</b>
transform, <b>CryptoStreamMode</b> mode).

<br /><br /><b>Stream</b> argument - Defines the stream on which the cryptographic transform
is to be performed. Any stream that derives from <b>System.IO.Stream</b> can be plugged in
here. For example, pass in an instance of <b>System.IO.FileStream</b> to perform a
cryptographic transform on a file. Because <b>CryptoStream</b> derives from <b>Stream</b>,
it is possible to use <b>CryptoStream</b> to define cryptographic transforms on other
cryptographic streams. This makes it possible to chain objects that implement
<b>CryptoStream</b> together, for example encrypting a file and computing the hash for the
encryption in a single operation.

<br /><br /><b>ICrypto Transform</b>transform - Defines the cryptographic transform that is
to be performed on the stream. Because every class that derives from <b>HashAlgorithm</b>
implements the <b>ICryptoTransform</b> interface, an instance of a hash algorithm can be
passed in here to take the hash of a stream. All symmetric encryption or decryption algorithms
that derive from the <b>SymmetricAlgorithm</b> class have <b>CreateEncryptor()</b> and
<b>CreateDecryptor()</b> functions that return an instance of an <b>ICryptoTransform</b>
implementation. To define a <b>TripleDES</b> encryption on a given stream, call the
<b>CreateEncryptor()</b> function on an instance of a <b>TripleDES</b> implementation and
pass the result into the <b>CryptoStream</b> constructor. Generally, any class that
implements <b>ICryptoTransform</b> can be passed into the <b>CryptoStream</b> constructor.

<br /><br /><b>CryptoStreamMode</b> mode - Defines whether you are reading from or writing
to the stream. To write to a <b>CryptoStream</b> you must pass <b>CryptoStreamMode.Write</b>
into the <b>CryptoStream</b> constructor. To read from the stream, <b>CryptoStreamMode.Read</b>
must be passed into the constructor.

<br /><br />The <b>CryptoStream</b> class contains the standard stream member functions to either read
a byte array from the stream or write a byte array to the stream. The <b>CryptoStream</b>
class handles the buffering internally when reading from or writing to the stream.
Application code needs only to provide the byte buffer and call the appropriate read or write
method on the stream.

<br /><br />The following sample code shows the creation of a <b>CryptoStream</b> to encrypt a file
using the <b>DES</b> algorithm. First, the <b>FileStream</b> that will contain the encrypted
file is created. Then, an instance of a <b>DES</b> implementation is created. If an instance
of a symmetric or asymmetric algorithm is created without explicit constructor arguments,
a random key (or public or private key pair) is generated and default properties are set that
cover most encryption or decryption scenarios. A <b>DES</b> encryptor object is created on the
<b>DES</b> instance. Next, a <b>CryptoStream</b> is created by passing the <b>FileStream</b>
instance and the <b>DES</b> encryptor into the <b>CryptoStream</b> constructor; the stream
is set to write mode. Finally, we write a byte array of plain text to the stream and close
the stream. The result is a file named "EncryptedFile.txt" which contains the <b>DES</b>
encryption of <b>bytearrayinput</b>.
<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
FileStream fs  = new FileStream("EncryptedFile.txt",FileMode.Create,FileAccess.Write);
DESCryptoServiceProvider des = new DESCryptoServiceProvider();
ICryptoTransform desencrypt = des.CreateEncryptor();
CryptoStream cryptostream = new CryptoStream(fs,desencrypt,CryptoStreamMode.Write);
cryptostream.Write(bytearrayinput,0,bytearrayinput.Length);
cryptostream.Close();
</Tab>
<Tab Name="VB">
Dim fs As New FileStream("EncryptedFile.txt", FileMode.Create, FileAccess.Write)
Dim des As New DESCryptoServiceProvider()
Dim desencrypt As ICryptoTransform = des.CreateEncryptor()
Dim cryptostream As New CryptoStream(fs, desencrypt, CryptoStreamMode.Write)
cryptostream.Write(bytearrayinput, 0, bytearrayinput.Length)
cryptostream.Close()
</Tab>
<Tab Name="C++">
FileStream *fs  = new FileStream(S"EncryptedFile.txt", FileMode::Create, FileAccess::Write);
Console::WriteLine("Enter Some Text to be stored in encrypted file:");
String *strinput = Console::ReadLine();
Byte bytearrayinput[] = ConvertStringToByteArray(strinput);
DESCryptoServiceProvider *des = new DESCryptoServiceProvider();
ICryptoTransform *desencrypt = des->CreateEncryptor();
CryptoStream *cryptostream = new CryptoStream(fs, desencrypt, CryptoStreamMode::Write);
cryptostream->Write(bytearrayinput, 0, bytearrayinput->Length);
cryptostream->Close();
</Tab>
</Acme:TabControl>
<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/fileencrypt/encrypt.src"
        Icon="../../images/console.gif"
        Caption="C# fileencrypt.exe"
	SamplePath="howto\samples\cryptography\fileencrypt\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/fileencrypt/encrypt.src"
        Icon="../../images/console.gif"
        Caption="VB fileencrypt.exe"
	SamplePath="howto\samples\cryptography\fileencrypt\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/cryptography/fileencrypt/encrypt.src"
        Icon="../../images/console.gif"
        Caption="C++ fileencrypt.exe"
	SamplePath="howto\samples\cryptography\fileencrypt\"
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

