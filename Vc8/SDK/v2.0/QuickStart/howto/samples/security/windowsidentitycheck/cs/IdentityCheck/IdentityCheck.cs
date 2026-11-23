//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
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
using System;
using System.Security;
using System.Security.Permissions;
using System.Security.Principal;

[assembly:SecurityPermission(SecurityAction.RequestMinimum, ControlPrincipal=true)]

namespace Microsoft.Samples
{
	public sealed class IdentityCheck 
	{
		private IdentityCheck()
		{
		}

		public static void Main() 
		{

			AppDomain.CurrentDomain.SetPrincipalPolicy(PrincipalPolicy.WindowsPrincipal);

			WindowsPrincipal user = (WindowsPrincipal)System.Threading.Thread.CurrentPrincipal;

			Console.WriteLine("User name: {0}", user.Identity.Name);
			Console.WriteLine("Authentication type: {0}", user.Identity.AuthenticationType);
			Console.WriteLine("Is in Administrators group: {0}", user.IsInRole(WindowsBuiltInRole.Administrator));
			Console.WriteLine("Is in Users group: {0}", user.IsInRole(WindowsBuiltInRole.User));

			try
			{
				Console.WriteLine("\n{0}", DeclAdminCheck());
			}
			catch (Exception e)
			{
				if (e is SecurityException & ((SecurityException)e).PermissionType == typeof(PrincipalPermission))
				{
					Console.WriteLine("\nDeclarative check for Administrators group failed!");
				}
				else
				{
					Console.WriteLine("\nException occurred: {0}\n", e);
				}
			}			

			try 
			{
				Console.WriteLine("\n{0}", DeclUserCheck());
			}
			catch(Exception e) 
			{

				if (e is SecurityException && ((SecurityException)e).PermissionType != null &&
						((SecurityException)e).PermissionType == typeof(PrincipalPermission))
				{
					Console.WriteLine("\nDeclarative check for Users group failed!");
				}
				else 
				{
					Console.WriteLine("\nException occurred: {0}\n", e);
				}
			}			

			Console.Write("\nPress Enter to exit...");
			Console.Read();

		}

		[PrincipalPermission(SecurityAction.Demand, Role=@"BUILTIN\Administrators")]
		private static string DeclAdminCheck() 
		{

			return "Declarative check for Administrators group passed!";

		}

		[PrincipalPermission(SecurityAction.Demand, Role=@"BUILTIN\Users")]
		private static string DeclUserCheck() 
		{

			return "Declarative check for Users group passed!";

		}

	}
}
