<%@ webservice language="VJ#" class="$safeitemrootname$" %>

import System.*;
import System.Web.Services.*;
import CrystalDecisions.Shared.*;
import CrystalDecisions.CrystalReports.Engine.*;
import CrystalDecisions.ReportSource.*;
import CrystalDecisions.Web.Services.*;

/** @attribute WebServiceAttribute( Namespace="http://crystaldecisions.com/reportwebservice/9.1/" ) */
public class $safeitemrootname$ extends ReportServiceBase
{
    public $safeitemrootname$()
    {
        this.set_ReportSource(this.get_Server().MapPath("$fileinputname$.rpt"));
    }
}



