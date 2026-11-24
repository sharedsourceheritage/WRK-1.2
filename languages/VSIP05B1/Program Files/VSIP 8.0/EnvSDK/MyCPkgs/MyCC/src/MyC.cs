
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

namespace MyC
{
 
/*
 * My simple C compiler
 *
 * Brad Merrill
 * 17-Apr-1999
 */
using System;

public class MyC
{
public const int MAXBUF = 512;
public const int MAXSTR = 128;

/* main program */
public static int Main()
  {
  try
    {
    String[] args = Environment.GetCommandLineArgs();
    Io prog = new Io(args);
    Tok tok = new Tok(prog);
    Parse p = new Parse(prog, tok);
    p.program();
    prog.Finish();
    return 0;
    }
  catch (Exception e)
    {
    Console.WriteLine("Compiler aborting: "+e.ToString());
    return -1;
    }
  }
}
}
