using System;
using System.Data;
using System.Data.SqlClient;
using Microsoft.SqlServer.Server;


public partial class Triggers
{
    // Enter existing table or view for the target and uncomment the attribute line
    // [Microsoft.SqlServer.Server.SqlTrigger (Name="$safeitemname$", Target="Table1", Event="FOR UPDATE")]
    public static void $safeitemname$ ()
    {
		// Replace with your own code
		SqlContext.Pipe.Send("Trigger FIRED");
    }
}
