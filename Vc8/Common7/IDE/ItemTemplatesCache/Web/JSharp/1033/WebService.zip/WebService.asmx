<%@ WebService Language= "VJ#" Class="$safeitemrootname$" %>

import System.Web.*;
import System.Web.Services.*;
import System.Web.Services.Protocols.*;

/** @attribute WebService(Namespace = "http://tempuri.org/") */
/** @attribute WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)*/
public class $safeitemrootname$ extends System.Web.Services.WebService {

	/** @attribute WebMethod() */
	public String HelloWorld() {
		return "Hello World";
	}

}
