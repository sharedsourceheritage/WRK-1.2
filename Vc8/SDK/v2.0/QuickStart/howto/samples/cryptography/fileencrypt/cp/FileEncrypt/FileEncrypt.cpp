//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using namespace System;
using namespace IO;
using namespace Security::Cryptography;


ref class FileEncrypt
{
public:
static array<Byte>^ ConvertStringToByteArray(String^ s)
{
    array<Char>^ ca = s->ToCharArray();
    array<Byte>^ ba = gcnew array<Byte>(ca->Length);

    for (int i=0; i < ba->Length; i++)
	{
		ba[i] = static_cast<Byte>(ca[i]);
	}
    return ba;
}

static void Main()
{
    //Creating a file stream
	FileStream^ fs  = gcnew FileStream("EncryptedFile.txt", FileMode::Create, FileAccess::Write);

	Console::WriteLine("Enter Some Text to be stored in encrypted file:");
	String^ strinput = Console::ReadLine();

    array<Byte>^ bytearrayinput = ConvertStringToByteArray(strinput);

    //DES instance with random key
    DESCryptoServiceProvider^ des = gcnew DESCryptoServiceProvider();
    //create DES Encryptor from this instance
    ICryptoTransform^ desencrypt = des->CreateEncryptor();
    //Create Crypto Stream that transforms file stream using des encryption
	CryptoStream^ cryptostream = gcnew CryptoStream(fs, desencrypt, CryptoStreamMode::Write);

    //write out DES encrypted file
    cryptostream->Write(bytearrayinput, 0, bytearrayinput->Length);

    cryptostream->Close();

    //create file stream to read encrypted file back
	FileStream^ fsread = gcnew FileStream("EncryptedFile.txt", FileMode::Open, FileAccess::Read);

    //create DES Decryptor from our des instance
    ICryptoTransform^ desdecrypt = des->CreateDecryptor();

    //create crypto stream set to read and do a des decryption transform on incoming bytes
	CryptoStream^ cryptostreamDecr = gcnew CryptoStream(fsread, desdecrypt, CryptoStreamMode::Read);
    //print out the contents of the decrypted file
	Console::WriteLine( (gcnew StreamReader(cryptostreamDecr))->ReadToEnd() );

	Console::WriteLine ();
	Console::WriteLine ("Press Enter to continue...");
	Console::ReadLine();
   }
};

// This is the entry point for this application
void main()
{
	FileEncrypt::Main();
};

