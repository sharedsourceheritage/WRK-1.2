<%@ WebHandler Language="VJ#" Class="$safeitemrootname$" %>

import System.*;
import System.Web.*;

public class $safeitemrootname$ implements IHttpHandler {
    
    public void ProcessRequest (HttpContext context) {
        context.get_Response().set_ContentType("text/plain");
        context.get_Response().Write("Hello World");
    }
 
    public boolean get_IsReusable() {
        return false;
    }

}