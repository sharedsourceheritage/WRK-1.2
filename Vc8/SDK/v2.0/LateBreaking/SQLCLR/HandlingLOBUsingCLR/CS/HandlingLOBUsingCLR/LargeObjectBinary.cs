using System;
using System.Data;
using System.IO;
using System.Globalization;
using System.Data.SqlClient;
using Microsoft.SqlServer.Server;

/*=====================================================================

  File:      LargeObjectBinary.cs for Large Binary Object SQLCLR Example
  Summary:   Defines SQLCLR based stored procedures for storing and 
             retrieving large binary objects between the database and
             filestores accessible from the server.
  Date:	     June 3, 2003

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
======================================================= */

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Date:		April 22, 2003
    /// Purpose:	The purpose of this sample is to show:
    ///			1) how to read binary data from a file and store the contents into a database
    ///			2) how to retrieve binary data stored in the database and write the contents to a file
    ///		This version of the sample is designed to run server side.  
    ///		Note that in Yukon Beta 1, VARBINARY(MAX) only supports 8000 bytes of data from CLR stored procedures.
    ///		Any additional data will be silently truncated.
    /// </summary>


    /// <summary>
    /// Connects to a database and contains the methods for reading and writing
    /// large binary objects to and from the database.
    /// </summary>
    public sealed class LargeObjectBinary
    {
        //Recommended chunk size for processing large amounts of data
        private const int bufferSize = 4000;

        /// <summary>
        ///	This class only contains static members, therefore it needs no public constructor.
        /// </summary>
        private LargeObjectBinary()
        {
        }


        /// <summary>
        /// Retrieves a thumbnail photograph from the database into a file assessible to the server.  
        /// </summary>
        /// <param name="photoId">Unique identifier for a product picture.</param>
        /// <param name="currentDirectory">Which folder to put the picture into.</param>
        /// <param name="fileName">What to call the picture in the specified folder.</param>
        public static void GetPhotoFromDB(Int32 photoId, string currentDirectory, string fileName)
        {
            SqlDataReader sqlReader = null;

            SqlConnection conn = new SqlConnection("context connection = true");
            conn.Open();
            
            SqlCommand sprocCommand = conn.CreateCommand();
            //Even though we are supply an int, it is a good habit to use parameters to insert
            //values into command text rather than using String.Format.  In the case of string parameters, it can
            //help prevent injection attacks.
            sprocCommand.CommandText = "SELECT ThumbNailPhoto FROM Production.ProductPhoto WHERE ProductPhotoID = @ProductPhotoID";
            sprocCommand.Parameters.Add("@ProductPhotoID", SqlDbType.Int);
            sprocCommand.Parameters[0].Value = photoId;

            //TODO: Is getting chunks the best way to retrieve LOB from the database?  Is there a limit?
            try
            {
                sqlReader = sprocCommand.ExecuteReader( //CommandBehavior.SequentialAccess
                    );
                if (sqlReader == null)
                {
                    LogError(currentDirectory, "ExecuteReader failed!");
                }
                else
                {
                    if (sqlReader.Read())
                    {
                        // Create a file to hold the output.
                        if (!Directory.Exists(currentDirectory))
                            Directory.CreateDirectory(currentDirectory);
                        fileName = currentDirectory + fileName;
                        using (FileStream fileStream = new FileStream(fileName,
                                                                      FileMode.
                                                                      OpenOrCreate,
                                                                      FileAccess.
                                                                      Write))
                        {
                            using (BinaryWriter binaryWriter =
                                                new BinaryWriter(
                                fileStream))
                            {
                                // The BLOB byte[] buffer to be filled by GetBytes.
                                byte[] outbyte = new byte[bufferSize];

                                // The starting position in the BLOB output.
                                long startIndex = 0;

                                // Read the bytes into outbyte[] and retain the number of bytes returned.
                                long retval = sqlReader.GetBytes(0, startIndex,
                                                                 outbyte, 0,
                                                                 bufferSize);

                                // Continue reading and writing while there are bytes beyond the size of the buffer.
                                while (retval == bufferSize)
                                {
                                    binaryWriter.Write(outbyte);

                                    // Reposition the start index to the end of the last buffer and fill the buffer.
                                    startIndex += bufferSize;
                                    retval = sqlReader.GetBytes(0, startIndex,
                                                                outbyte, 0,
                                                                bufferSize);
                                }

                                // Write the remaining buffer.
                                binaryWriter.Write(outbyte);
                                //TODO:  Shouldn't need to flush here because the close will do it for me?
                                //binaryWriter.Flush();
                            }
                        }
                    }
                    else
                        LogError(currentDirectory, "No row returned!");
                }
            }
            catch (SqlException e)
            {
                LogError(currentDirectory, String.Format(CultureInfo.InvariantCulture, "Unable to copy binary contents from database.  Error: {0}", e.ToString()));
            }
            finally
            {
                if (sqlReader != null)
                    sqlReader.Close();
            }
        }

        /// <summary>
        /// Saves a thumbnail picture into the database from a file accessible to the server.
        /// </summary>
        /// <param name="photoId">Unique identifier for a product picture.</param>
        /// <param name="currentDirectory">Which folder to get the picture from.</param>
        /// <param name="fileName">What the picture in the specified folder is called.</param>
        public static void PutPhotoIntoDB(Int32 photoId, string currentDirectory, string fileName)
        {
            //TODO: Is there a limit on how large the LOB can be?
            string fullFileName = currentDirectory + fileName;
            byte[] bytes = ReadFile(fullFileName);

            try
            {
                SqlConnection conn = new SqlConnection("context connection = true");
                conn.Open();

                SqlCommand sprocCommand = conn.CreateCommand();
                sprocCommand.CommandText = "dbo.usp_UpdateImage";
                sprocCommand.CommandType = CommandType.StoredProcedure;

                sprocCommand.Parameters.Add(new SqlParameter("@ProductPhotoID", SqlDbType.Int));
                // Add time to the short name because there is an unique constraint on this column.
                sprocCommand.Parameters[0].Value = photoId;
                sprocCommand.Parameters.Add(new SqlParameter("@ThumbNailPhoto", SqlDbType.VarBinary));
                sprocCommand.Parameters[1].Value = bytes;
                sprocCommand.ExecuteNonQuery();
            }
            catch (SqlException e)
            {
                LogError(currentDirectory, String.Format(CultureInfo.InvariantCulture, "Unable to update binary contents into the database.  Error: {0}", e.ToString()));
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

        /// <summary>
        ///	Appends a message to a file accessible to the server.  When System.Diagnostics is available from
        /// CLR Sprocs this should be changed to use the event log.
        /// </summary>
        /// <param name="currentDirectory">Which folder the message log file resides in</param>
        /// <param name="errorMessage">The text to add to the message log file</param>
        private static void LogError(string currentDirectory, string errorMessage)
        {
            using (FileStream errorLogStream = new FileStream(currentDirectory + "error.log", FileMode.Append, FileAccess.Write))
            {
                using (StreamWriter errorLogWriter = new StreamWriter(errorLogStream))
                {
                    errorLogWriter.WriteLine(errorMessage);
                }
            }
        }
    }
}
