using System;
using System.Runtime.Serialization;

/*=====================================================================

  File:      Exceptions.cs for Result Set sample
  Summary:   Error classes 
  Date:	     November 17, 2004

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
    /// This is the base class for exceptions raised in the Adventure Works Cycles Storefront application.
    /// </summary>
    [Serializable]
    public class ResultSetException : System.Exception
    {
        public ResultSetException()
        {
        }

        public ResultSetException(string message) : base(message)
        {
        }

        public ResultSetException(String message, Exception innerException) : base(message, innerException)
        {
        }

        protected ResultSetException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }

    /// <summary>
    /// This exception is raised when a user tries to register an email address which has already been taken.
    /// </summary>
    [Serializable]
    public class InvalidStateException : ResultSetException
    {
        public InvalidStateException()
        {
        }

        public InvalidStateException(string message) : base(message)
        {
        }

        public InvalidStateException(String message, Exception innerException) : base(message, innerException)
        {
        }

        protected InvalidStateException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}
