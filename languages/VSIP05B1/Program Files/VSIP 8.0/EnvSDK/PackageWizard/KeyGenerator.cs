//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Text;
using System.Runtime.InteropServices;

namespace PackageWizard
{
    class KeyGenerator
    {
        /// <summary>
        /// Create a Key and saves it to the specified file
        /// </summary>
        /// <param name="keyFileName">File to be created with the key in it</param>
        public static void CreateNewKeyFile(string keyFileName)
        {
            IntPtr keyBlob = IntPtr.Zero;
            UInt16 size = 0;

            // Get a strong name key
            StrongNameKeyGen(null, 0, out keyBlob, out size);

            // Move the key to a byte array
            byte[] blob = new byte[size];
            for(int i=0; i<size; ++i)
            {
                blob[i] = Marshal.ReadByte(keyBlob, i);
            }

            // Write the key to file
            using (System.IO.FileStream outputFile = System.IO.File.Create(keyFileName))
            {
                outputFile.Write(blob, 0, size);
            }
        }

        [DllImport("mscoree.dll")]
        private static extern bool StrongNameKeyGen(
            string keyContainerName,
            UInt16 flags,
            out IntPtr keyBlob,
            out UInt16 size);
    }
}