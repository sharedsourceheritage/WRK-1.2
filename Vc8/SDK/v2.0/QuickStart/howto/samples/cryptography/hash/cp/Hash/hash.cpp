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
using namespace System::IO;
using namespace System::Security;
using namespace System::Security::Cryptography;

public ref class HashTest
{
public:
    static array<Byte>^ ConvertStringToByteArray(String^ s)
    {
        array<Char>^ ca = s->ToCharArray();
        array<Byte>^ ba = gcnew array<Byte>(ca->Length);
        for(int i = 0; i < ba->Length; i++)
            ba[i] = static_cast<Byte>(ca[i]);
        return ba;
    }

    static void Main()
    {
        String^ s1, ^s2;

        Console::WriteLine("Enter String 1 To Hash:");
        s1 = Console::ReadLine();
        Console::WriteLine("Enter String 2 To Hash:");
        s2 = Console::ReadLine();

        //Convert s1 to byte array
        array<Byte>^ data1ToHash= ConvertStringToByteArray(s1);    
        //Convert s2 to byte array
        array<Byte>^ data2ToHash = ConvertStringToByteArray(s2);

        //Create hash value from String 1 using MD5 instance returned by Crypto Config system
        array<Byte>^ hashvalue1 = (safe_cast<HashAlgorithm ^>(CryptoConfig::CreateFromName("MD5")))->ComputeHash(data1ToHash);

        Console::WriteLine(String::Concat("Hash Value of String 1:", BitConverter::ToString(hashvalue1)));

        //Create hash value of String 2 using directly created instance of the MD5 class
        array<Byte>^ hashvalue2 = (gcnew MD5CryptoServiceProvider)->ComputeHash(data2ToHash);

        Console::WriteLine(String::Concat("Hash Value of String 2:", BitConverter::ToString(hashvalue2)));


        //Memberwise compare of hash value bytes
        int i = 0;
        bool same = true;
        do
        {
            if (hashvalue1[i] != hashvalue2[i])
            {
                same = false;
                break;
            }
            i++;
        } while(i < hashvalue1->Length);

        if (same)
            Console::WriteLine("The hash values of String 1 and String 2 are the same!");
        else
            Console::WriteLine("The hash values of String 1 and String 2 are not the same!");

        Console::Write("Please Press Return to continue");
        s1 = Console::ReadLine();
    }
};

// This is the entry point for this application
void main()
{
    HashTest::Main();
}
