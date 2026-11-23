#region Using directives

using System;
using System.Data;
using System.Data.SqlClient;
using System.IO;
using System.Security;

#endregion

/*=====================================================================

  File:     Main.cs for Handling LOB using ADO.Net Example
  Summary:  The purpose of this sample is to show:
				1) how to read binary data from a file and store the 
                   contents into a database
				2) how to retrieve binary data stored in the database 
                   and write the contents to a file
  Date:	    April 14, 2003

---------------------------------------------------------------------

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================================== */

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Connects to a database and contains the methods for reading and writing
    /// large binary objects to and from the database.
    /// </summary>
    class LargeObjectBinary
    {
        // Size of the BLOB buffer.
        // Use sp_configure (with show advanced option on) to find the optimal value.  It should be based on the network packet size.
        // In general, 4k is considered a good default for most situations.
        private const int bufferSize = 4096;

        private string connectionString;

        /// <summary>
        /// Contains methods for reading and writing large binary objects to and from the database.
        /// </summary>
        /// <param name="dataSource">Name of the server that has the sample database AdventureWorks installed on it.</param>
        public LargeObjectBinary(string dataSource)
        {
            connectionString = "data source=" + dataSource + ";initial catalog=AdventureWorks;Integrated Security=SSPI";
        }

        /// <summary>
        /// Reads large binary objects from the database into a file.  
        /// This file is saved to a file on the users machine.
        /// </summary>
        /// <param name="DocumentID">Unique identifier for a Document.</param>
        /// <param name="userDirectory">The user's appdata directory path.</param>
        /// <param name="fileName">The file name to store the contents read from the database.</param>
        public void GetDocumentFromDb(Int32 DocumentID, string userDirectory, string fileName)
        {
            SqlDataReader sqlReader = null;

            using (SqlConnection sqlConn = new SqlConnection(connectionString))
            {
                sqlConn.Open();
                using (SqlCommand sprocCommand = new SqlCommand("[Production].[usp_GetDocumentByID]", sqlConn))
                {
                    sprocCommand.CommandType = CommandType.StoredProcedure;
                    sprocCommand.Parameters.Add(new SqlParameter("@DocumentID", SqlDbType.Int));
                    sprocCommand.Parameters[0].Value = DocumentID;

                    try
                    {
                        sqlReader = sprocCommand.ExecuteReader(CommandBehavior.SequentialAccess);
                        sqlReader.Read();

                        // Create a file to hold the output.
                        fileName = userDirectory + fileName;
                        using (FileStream fileStream = new FileStream(fileName, FileMode.Create, FileAccess.Write))
                        {
                            using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
                            {
                                // The BLOB byte[] buffer to be filled by GetBytes.
                                byte[] outbyte = new byte[bufferSize];

                                // The starting position in the BLOB output.
                                long startIndex = 0;

                                // Read the bytes into outbyte[] and retain the number of bytes returned.
                                long retval = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize);

                                // Continue reading and writing while there are bytes beyond the size of the buffer.
                                while (retval == bufferSize)
                                {
                                    binaryWriter.Write(outbyte, 0, Convert.ToInt32(retval));

                                    // Reposition the start index to the end of the last buffer and fill the buffer.
                                    startIndex += bufferSize;
                                    retval = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize);
                                }

                                // Write the remaining buffer.
                                binaryWriter.Write(outbyte, 0, Convert.ToInt32(retval));
                            }
                        }
                    }
                    finally
                    {
                        sqlReader.Close();
                    }
                }
            }
        }

        /// <summary>
        /// Save the contents of a file in the database.
        /// </summary>
        /// <param name="currentDirectory">The current directory path.</param>
        /// <param name="fileName">The file name containing the contents to be read and stored in the database.</param>
        public void InsertDocument(string datafilesDirectory, string fileName, string fileExtension)
        {
            // Note:  Max limit on the input file is 2G.
            string fullFileName = datafilesDirectory + fileName;
            byte[] bytes = ReadFile(fullFileName);
            using (SqlConnection sqlConn = new SqlConnection(connectionString))
            {
                using (SqlCommand sprocCommand = new SqlCommand("[Production].[usp_InsertDocument]", sqlConn))
                {
                    sqlConn.Open();
                    sprocCommand.CommandType = CommandType.StoredProcedure;
                    // Add time to the title because there is an unique constraint on this column.
                    sprocCommand.Parameters.Add(new SqlParameter("@Title", SqlDbType.NVarChar, 50));
                    sprocCommand.Parameters[0].Value = fileName + DateTime.Now.TimeOfDay.ToString();
                    sprocCommand.Parameters.Add(new SqlParameter("@FileName", SqlDbType.NVarChar, 400));
                    sprocCommand.Parameters[1].Value = fullFileName;
                    sprocCommand.Parameters.Add(new SqlParameter("@FileExtension", SqlDbType.NVarChar, 8));
                    sprocCommand.Parameters[2].Value = fileExtension;
                    sprocCommand.Parameters.Add(new SqlParameter("@Status", SqlDbType.TinyInt));
                    sprocCommand.Parameters[3].Value = 1;
                    sprocCommand.Parameters.Add(new SqlParameter("@Document", SqlDbType.Image));
                    sprocCommand.Parameters[4].Value = bytes;
                    sprocCommand.Parameters.Add(new SqlParameter("@DocumentID", SqlDbType.Int));
                    sprocCommand.Parameters[5].Direction = ParameterDirection.Output;
                    sprocCommand.ExecuteNonQuery();
                    //int DocumentID = (int)sprocCommand.Parameters[5].Value;
                }
            }
        }

        /// <summary>
        /// Read the contents of a file and return the bytes.
        /// </summary>
        /// <param name="fileName">The name of the file to be read.</param>
        /// <returns></returns>
        private static byte[] ReadFile(string fileName)
        {
            // Open the file assuming the file is in ASCII format.
            using (BinaryReader binaryReader = new BinaryReader((Stream)File.OpenRead(fileName), System.Text.Encoding.ASCII))
            {
                long fileSize = binaryReader.BaseStream.Length;
                byte[] bytes = new Byte[fileSize];
                binaryReader.Read(bytes, 0, (int)fileSize);
                return bytes;
            }
        }
    }
}
