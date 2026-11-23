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

using System ;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Collections;
using System.Globalization;
using System.Reflection;

namespace ClassInfo {

    public class ClassNameFormatter
    {
        static public String GetClassName(Type type)
        {
            if (type.IsGenericType) {
                StringBuilder sb = new StringBuilder();
                GetClassNameInternal(type, sb);
                return HttpContext.Current.Server.HtmlEncode(sb.ToString());
            }
            else
            {
                return type.Name;
            }
        }

        static private void GetClassNameInternal(Type type, StringBuilder sb)
        {
            if (type.IsGenericType) 
            {
                String typeName = type.Name;
                int delim = typeName.IndexOf('`');
                sb.Append(typeName, 0, delim > 0 ? delim : typeName.Length);
                sb.Append('<');
                Type[] genericParameters = type.GetGenericArguments();
                for (int i = 0; i < genericParameters.Length; i++) {
                    if (genericParameters[i].IsGenericParameter) 
                    {
                        sb.Append(genericParameters[i].Name);
                    }
                    else
                    {
                        GetClassNameInternal(genericParameters[i], sb);
                    }
                    if (i < genericParameters.Length - 1) {
                        sb.Append(',');
                    }
                }
                sb.Append('>');
            }
            else
            {
                sb.Append(type.Name);
            }
        }

    }

    public class SortTable : Hashtable, IComparable {
        public String sortField;

        public SortTable() : this(null) {
        }
        public SortTable(String sField) {
           sortField = sField;
        }

        public int CompareTo(Object b) {
            if ( sortField == null ) {
                return 0;
            }
            return (String.Compare( (String)this[sortField], (String)((SortTable)b)[sortField], false, CultureInfo.InvariantCulture));
        }
    }



public class DisplayEvents : ArrayList {
    public  DisplayEvents(Type classType) {
        System.Reflection.EventInfo[] eventInfos = classType.GetEvents(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static);

        if (eventInfos == null)
            return;

        ArrayList eventTable = new ArrayList();

        for (int x=0; x<eventInfos.Length; x++) {
            SortTable eventDetails = new SortTable("Name");

            eventDetails["Assembly"]    = eventInfos[x].EventHandlerType.Assembly.ToString();
            eventDetails["Name"]        = eventInfos[x].Name;
            eventDetails["Type"]        = eventInfos[x].EventHandlerType.Name;
            eventDetails["GetType"]     = eventInfos[x].EventHandlerType.Name;
            eventDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(eventInfos[x].EventHandlerType);
            eventDetails["Namespace"]   = eventInfos[x].EventHandlerType.Namespace;

            if (eventInfos[x].IsMulticast == true) {
                eventDetails["Access"] = "multicast ";
            }

            this.Add(eventDetails);
        }
        this.Sort();
    }
}

public class DisplayFields : ArrayList
{
    public  DisplayFields(Type classType)
    {
        System.Reflection.FieldInfo[] fieldInfos = classType.GetFields(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static);

        if (fieldInfos == null)
            return;

        ArrayList fieldTable = new ArrayList();

        for (int x=0; x<fieldInfos.Length; x++)
        {
            if (fieldInfos[x].IsPublic || fieldInfos[x].IsFamily) {
                SortTable fieldDetails = new SortTable("Name");
    
                fieldDetails["Assembly"] = fieldInfos[x].GetType().Assembly.ToString();
                fieldDetails["Name"] = fieldInfos[x].Name;
                fieldDetails["Type"] = fieldInfos[x].FieldType.Name;
                if(( fieldInfos[x].FieldType.IsArray && fieldInfos[x].FieldType.Name != "Array") ||  fieldInfos[x].FieldType.IsPointer)
                {
                    fieldDetails["GetType"]     = fieldInfos[x].FieldType.GetElementType().Name;
                    fieldDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(fieldInfos[x].FieldType);
                    fieldDetails["Namespace"]   = fieldInfos[x].FieldType.GetElementType().Namespace;
                }
                else
                {
                    fieldDetails["GetType"]   = fieldInfos[x].FieldType.Name;
                    fieldDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(fieldInfos[x].FieldType);
                    fieldDetails["Namespace"] = fieldInfos[x].FieldType.Namespace;
                }
                if (fieldInfos[x].IsPublic == true)
                {
                    fieldDetails["Access"] = "public ";
                }
                else if (fieldInfos[x].IsPrivate == true)
                {
                    fieldDetails["Access"] = "private ";
                }
                else if (fieldInfos[x].IsFamily == true)
                {
                    fieldDetails["Access"] = "protected ";
                }
    
                if (fieldInfos[x].IsStatic == true)
                {
                    fieldDetails["Access"] = ((String) fieldDetails["Access"]) + "static ";
                }
    
                if (fieldInfos[x].IsLiteral == true)
                {
                    fieldDetails["Access"] = ((String) fieldDetails["Access"]) + "const ";
                }
    
                this.Add(fieldDetails);
            }
       }
         this.Sort();
    }
}

public class DisplayConstructors : ArrayList
{
    public DisplayConstructors(Type classType)
    {
        System.Reflection.ConstructorInfo[] constructorInfos = classType.GetConstructors(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static);

        if (constructorInfos == null)
            return;

        for (int x=0; x<constructorInfos.Length; x++)
        {
            if (constructorInfos[x].IsPublic || constructorInfos[x].IsFamily) {
                SortTable constructorDetails = new SortTable();
    
                constructorDetails["Assembly"] = constructorInfos[x].GetType().Assembly.ToString();
                constructorDetails["Name"] = classType.Name;
                constructorDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(classType);
    
                if (constructorInfos[x].IsPublic == true)
                {
                    constructorDetails["Access"] = "public ";
                }
                else if (constructorInfos[x].IsPrivate == true)
                {
                    constructorDetails["Access"] = "private ";
                }
                else if (constructorInfos[x].IsFamily == true)
                {
                    constructorDetails["Access"] = "protected ";
                }
    
                System.Reflection.ParameterInfo[] paramInfos = constructorInfos[x].GetParameters();
    
                if (paramInfos != null) {
                    ArrayList paramTable = new ArrayList();
                    for (int y=0; y<paramInfos.Length; y++) {
                        SortTable paramDetails = new SortTable();
                        paramDetails["Assembly"]  = paramInfos[y].GetType().Assembly.ToString();
                        paramDetails["ParamName"] = paramInfos[y].Name;
                        paramDetails["ParamType"] = paramInfos[y].ParameterType.Name;
                        if ( ( paramInfos[y].ParameterType.IsArray && paramInfos[y].ParameterType.Name !="Array" ) || paramInfos[y].ParameterType.IsPointer )
                        {
                            paramDetails["GetType"]   = paramInfos[y].ParameterType.GetElementType().Name ;
                            paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType.GetElementType());
                            paramDetails["Namespace"] = paramInfos[y].ParameterType.GetElementType().Namespace ;
                        }
    
                        else
                        {
                            paramDetails["GetType"]   = paramInfos[y].ParameterType.Name;
                            paramDetails["Namespace"] = paramInfos[y].ParameterType.Namespace ;
                            paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType);
                        }
                        paramTable.Add(paramDetails);
                    }
    
                    constructorDetails["Params"] = paramTable;
                }
    
                this.Add(constructorDetails);
            }
        }
    }
}


public class DisplayProperties : ArrayList {
    public  DisplayProperties(Type classType) {
        System.Reflection.PropertyInfo[] propertyInfos = classType.GetProperties(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static);

        if (propertyInfos == null)
            return;

        ArrayList propertyTable = new ArrayList();

        for (int x=0; x<propertyInfos.Length; x++) {

            MethodInfo getMethod = propertyInfos[x].GetGetMethod();
            MethodInfo setMethod = propertyInfos[x].GetSetMethod();
            if ((getMethod != null && (getMethod.IsPublic || getMethod.IsFamily)) ||
                (setMethod != null && (setMethod.IsPublic || setMethod.IsFamily)))
            {
                SortTable propertyDetails = new SortTable("Name");
    
                if(propertyInfos[x].GetGetMethod() != null)
                {
                    if(( propertyInfos[x].GetGetMethod().ReturnType.IsArray && propertyInfos[x].GetGetMethod().ReturnType.Name !="Array" ) || propertyInfos[x].GetGetMethod().ReturnType.IsPointer ) {
                        propertyDetails["GetType"]   = propertyInfos[x].GetGetMethod().ReturnType.GetElementType().Name;
                        propertyDetails["Namespace"] = propertyInfos[x].GetGetMethod().ReturnType.GetElementType().Namespace;
                        propertyDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(propertyInfos[x].GetGetMethod().ReturnType.GetElementType());
    
                    } else {
                        propertyDetails["GetType"]   = propertyInfos[x].GetGetMethod().ReturnType.Name;
                        propertyDetails["Namespace"] = propertyInfos[x].GetGetMethod().ReturnType.Namespace;
                        propertyDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(propertyInfos[x].GetGetMethod().ReturnType);
                    }
                    propertyDetails["Type"]      = propertyInfos[x].GetGetMethod().ReturnType.Name;
                    propertyDetails["Assembly"]  = propertyInfos[x].GetGetMethod().ReturnType.Assembly.ToString();
                    propertyDetails["Name"]      = propertyInfos[x].Name;
    
                    if (propertyInfos[x].GetGetMethod().IsPublic == true) {
                         propertyDetails["Visibility"] = "public";
                    } else if (propertyInfos[x].GetGetMethod().IsPrivate == true) {
                         propertyDetails["Visibility"] = "private";
                    } else if (propertyInfos[x].GetGetMethod().IsFamily == true) {
                        propertyDetails["Visibility"] = "protected";
                    }
    
                    if (propertyInfos[x].GetGetMethod().IsStatic == true) {
                        propertyDetails["Visibility"] = ((String) propertyDetails["Visibility"]) + " static";
                    }
    
                    if (propertyInfos[x].GetSetMethod() == null) {
                        propertyDetails["Access"] =  "[Get]" ;
                    } else {
                        propertyDetails["Access"] = "[Get , Set]" ;
                    }
    
                    System.Reflection.ParameterInfo[] paramInfos = propertyInfos[x].GetGetMethod().GetParameters();
    
                    if (paramInfos != null)
                    {
                        ArrayList paramTable = new ArrayList();
    
                        for (int y=0; y<paramInfos.Length; y++)
                        {
                            SortTable paramDetails = new SortTable();
                            paramDetails["Assembly"] = paramInfos[y].GetType().Assembly.ToString();
                            paramDetails["ParamName"] = paramInfos[y].Name;
                            paramDetails["ParamType"] = paramInfos[y].ParameterType.Name;
                            if (( paramInfos[y].ParameterType.IsArray && paramInfos[y].ParameterType.Name !="Array") ||paramInfos[y].ParameterType.IsPointer ) {
                                paramDetails["GetType"]   = paramInfos[y].ParameterType.GetElementType().Name ;
                                paramDetails["Namespace"] = paramInfos[y].ParameterType.GetElementType().Namespace ;
                                paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType.GetElementType());
                            } else {
                                paramDetails["GetType"]   = paramInfos[y].ParameterType.Name;
                                paramDetails["Namespace"] = paramInfos[y].ParameterType.Namespace ;
                                paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType);
                            }
                            paramTable.Add(paramDetails);
                        }
    
                        propertyDetails["Params"] = paramTable;
                   }
                } else if(propertyInfos[x].GetSetMethod() != null) {
    
                    propertyDetails["GetType"]   = propertyInfos[x].GetSetMethod().ReturnType.Name;
                    propertyDetails["Namespace"] = propertyInfos[x].GetSetMethod().ReturnType.Namespace;
    
                    propertyDetails["Type"]      = propertyInfos[x].GetSetMethod().ReturnType.Name;
                    propertyDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(propertyInfos[x].GetSetMethod().ReturnType);
                    propertyDetails["Assembly"]  = propertyInfos[x].GetSetMethod().ReturnType.Assembly.ToString();
                    propertyDetails["Name"]      = propertyInfos[x].Name;
    
                    if (propertyInfos[x].GetSetMethod().IsPublic == true) {
                         propertyDetails["Visibility"] = "public";
                    } else if (propertyInfos[x].GetSetMethod().IsPrivate == true) {
                         propertyDetails["Visibility"] = "private";
                    } else if (propertyInfos[x].GetSetMethod().IsFamily == true) {
                        propertyDetails["Visibility"] = "protected";
                    }
    
                    if (propertyInfos[x].GetSetMethod().IsStatic == true) {
                        propertyDetails["Visibility"] = ((String) propertyDetails["Visibility"]) + " static";
                    }
    
                    propertyDetails["Access"] = "[ Set ]" ;
                    System.Reflection.ParameterInfo[] paramInfos = propertyInfos[x].GetSetMethod().GetParameters();
    
                    if (paramInfos != null) {
                        ArrayList paramTable = new ArrayList();
    
                        for (int y=0; y<paramInfos.Length; y++) {
                            SortTable paramDetails = new SortTable();
                            paramDetails["Assembly"] = paramInfos[y].GetType().Assembly.ToString();
                            paramDetails["ParamName"] = paramInfos[y].Name;
                            paramDetails["ParamType"] = paramInfos[y].ParameterType.Name;
                            if(( paramInfos[y].ParameterType.IsArray && paramInfos[y].ParameterType.Name !="Array") || paramInfos[y].ParameterType.IsPointer) {
                                paramDetails["GetType"]   = paramInfos[y].ParameterType.GetElementType().Name ;
                                paramDetails["Namespace"] = paramInfos[y].ParameterType.GetElementType().Namespace ;
                                paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType.GetElementType());
                            } else {
                                paramDetails["GetType"]   = paramInfos[y].ParameterType.Name;
                                paramDetails["Namespace"] = paramInfos[y].ParameterType.Namespace ;
                                paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType);
                            }
                            paramTable.Add(paramDetails);
                        }
    
                        propertyDetails["Params"] = paramTable;
                   }
                }
                this.Add(propertyDetails);
            }
        }
        this.Sort();
    }
}


    public class DisplayMethods : ArrayList {
         public DisplayMethods(Type classType, String myclassname) {
             System.Reflection.MethodInfo[] methodInfos = classType.GetMethods(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static) ;

             if (methodInfos == null)
                 return;

             for (int x=0; x<methodInfos.Length; x++) {

                 if (methodInfos[x].IsPublic || methodInfos[x].IsFamily) {
                     if((String.Compare(myclassname,methodInfos[x].DeclaringType.Name,false,CultureInfo.InvariantCulture )==0)&&(methodInfos[x].IsPublic || methodInfos[x].IsFamily) && (!(methodInfos[x].IsSpecialName)) ) {
                         SortTable MethodDetails = new SortTable("Name");
    
                         MethodDetails["Assembly"] = methodInfos[x].GetType().Assembly.ToString();
                         MethodDetails["Name"] = methodInfos[x].Name;
                         MethodDetails["Type"] = methodInfos[x].ReturnType.Name;
                         if(( methodInfos[x].ReturnType.IsArray && methodInfos[x].ReturnType.Name !="Array") ||  methodInfos[x].ReturnType.IsPointer) {
                             // For Supporting Multi-Dimension Arrays as Return Type
                             Type ReturnElementType =  methodInfos[x].ReturnType.GetElementType();
                             while(ReturnElementType.IsArray) {
                                ReturnElementType =  ReturnElementType.GetElementType();
                             }
    
                             MethodDetails["GetType"]   = ReturnElementType.Name ;
                             MethodDetails["Namespace"] = ReturnElementType.Namespace ;
                             MethodDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(ReturnElementType);
    
                         } else {
    
                            MethodDetails["GetType"] = methodInfos[x].ReturnType.Name;
                            MethodDetails["Namespace"] = methodInfos[x].ReturnType.Namespace ;
                            MethodDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(methodInfos[x].ReturnType);
                         }
    
                         if (methodInfos[x].IsPublic == true) {
                             MethodDetails["Access"] = "public ";
                         } else if (methodInfos[x].IsPrivate == true) {
                             MethodDetails["Access"] = "private ";
                         } else if (methodInfos[x].IsFamily == true) {
                             MethodDetails["Access"] = "protected ";
                         }
    
                         if (methodInfos[x].IsStatic == true) {
                             MethodDetails["Access"] = ((String) MethodDetails["Access"]) + "static ";
                         }
    
                         System.Reflection.ParameterInfo[] paramInfos = methodInfos[x].GetParameters();
    
                        if (paramInfos != null) {
                            ArrayList paramTable = new ArrayList();
    
                            for (int y=0; y<paramInfos.Length; y++) {
                                SortTable paramDetails = new SortTable();
                                paramDetails["Assembly"]  = paramInfos[y].GetType().Assembly.ToString();
                                paramDetails["ParamName"] = paramInfos[y].Name;
                                paramDetails["ParamType"] = paramInfos[y].ParameterType.Name;
                                if(( paramInfos[y].ParameterType.IsArray && paramInfos[y].ParameterType.Name != "Array" )  || paramInfos[y].ParameterType.IsPointer) {
                                    paramDetails["GetType"]   = paramInfos[y].ParameterType.GetElementType().Name ;
                                    paramDetails["Namespace"] = paramInfos[y].ParameterType.GetElementType().Namespace ;
                                    paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType.GetElementType());
                                } else {
                                    paramDetails["GetType"]   = paramInfos[y].ParameterType.Name;
                                    paramDetails["Namespace"] = paramInfos[y].ParameterType.Namespace ;
                                    paramDetails["TypeDisplayName"] = ClassNameFormatter.GetClassName(paramInfos[y].ParameterType);
                                }
                                paramTable.Add(paramDetails);
                            }
    
                            MethodDetails["Params"] = paramTable;
                        }
    
                        this.Add(MethodDetails);
                     }
                }
            }
            this.Sort();
        }
    }

    public class DisplayInterfaces : ArrayList {
        public DisplayInterfaces(Type classType) {
             Type[] classInterfaces = classType.GetInterfaces();
             for(int x = 0 ; x < classInterfaces.Length ; x++) {

                if (classInterfaces[x].IsPublic) {
                    SortTable interfaceDetails = new SortTable();
    
                    interfaceDetails["Assembly"]     = classInterfaces[x].Assembly.ToString();
                    interfaceDetails["FullName"]     = classInterfaces[x].FullName;
                    interfaceDetails["GetType"]      = classInterfaces[x].Name;
                    interfaceDetails["TypeDisplayName"]  = ClassNameFormatter.GetClassName(classInterfaces[x]);
                    interfaceDetails["Namespace"]    = classInterfaces[x].Namespace;
                    this.Add(interfaceDetails);
                }
             }
         }
    }


    public class DisplaySuperclasses : ArrayList {
        public DisplaySuperclasses(Type classType) {
           Type SuperClass ;
           SortTable classDetails = new SortTable();

           classDetails["Assembly"]     = classType.Assembly.ToString();
           classDetails["FullName"]     = classType.FullName;
           classDetails["GetType"]      = classType.Name;
           classDetails["TypeDisplayName"]  = ClassNameFormatter.GetClassName(classType);
           classDetails["Namespace"]    = classType.Namespace;

           this.Add(classDetails);

           while (classType.BaseType != null) {
               SortTable superclassDetails = new SortTable();
               SuperClass =  classType.BaseType ;
               classType   =  SuperClass        ;

               superclassDetails["Assembly"]     = SuperClass.Assembly.ToString();
               superclassDetails["FullName"]     = SuperClass.FullName;
               superclassDetails["TypeDisplayName"]  = ClassNameFormatter.GetClassName(SuperClass);
               superclassDetails["GetType"]      = SuperClass.Name;
               superclassDetails["Namespace"]    = SuperClass.Namespace;

               this.Add(superclassDetails);
           }
           this.Reverse() ;
        }

    }

    public class DisplaySubClasses : ArrayList {
        private Type        classType ;
        private Module[]    CorRuntime ;
        private Type[]      CorClasses;
        private String      myclassname ;
        private Type[]      classInterfaces;

        public DisplaySubClasses(Type classtype, ArrayList ModuleName) {
            this.classType = classtype;
            myclassname = classType.FullName ;
            if (classType.IsInterface ) {
                for(int y = 0 ; y <  ModuleName.Count ;y++) {
                    CorRuntime = Assembly.Load(ModuleName[y].ToString()).GetModules();
                    CorClasses   = CorRuntime[0].GetTypes() ;

                    for(int x= 0 ; x < CorClasses.Length; x++) {
                        classType       =  CorClasses[x];
                        if (!classType.IsPublic) {
                            continue;
                        }
                        classInterfaces =  classType.GetInterfaces() ;

                        for(int  i = 0 ; i < classInterfaces.Length ; i++) {
                            if(classType.Namespace != null &&  classType.Namespace.IndexOf('<') == -1 &&
                               String.Compare(myclassname , classInterfaces[i].FullName, false, CultureInfo.InvariantCulture )==0)
                            {

                                 SortTable subclassDetails     = new SortTable("FullName");
                                 subclassDetails["Assembly"]     = classType.Assembly.ToString();
                                 subclassDetails["FullName"]     = classType.FullName;
                                 subclassDetails["TypeDisplayName"]  = ClassNameFormatter.GetClassName(classType);
                                 subclassDetails["GetType"]      = classType.Name;
                                 subclassDetails["Namespace"]    = classType.Namespace;
                                 this.Add(subclassDetails) ;
                            }
                        }
                    }
                }
            } else {
                for(int y = 0; y < ModuleName.Count ; y++) {
                    CorRuntime = Assembly.Load(ModuleName[y].ToString()).GetModules();
                    CorClasses  = CorRuntime[0].GetTypes();

                    for( int x= 0 ; x< CorClasses.Length ;x++) {
                        if (!CorClasses[x].IsPublic) {
                            continue;
                        }

                        if (classtype.IsAssignableFrom(CorClasses[x].BaseType)) {
                            SortTable subclassDetails     = new SortTable("FullName");
                            subclassDetails["Assembly"]     = CorClasses[x].Assembly.ToString();
                            subclassDetails["FullName"]     = CorClasses[x].FullName;
                            subclassDetails["GetType"]      = CorClasses[x].Name;
                            subclassDetails["TypeDisplayName"]  = ClassNameFormatter.GetClassName(CorClasses[x]);
                            subclassDetails["Namespace"]    = CorClasses[x].Namespace;
                            this.Add(subclassDetails) ;
                        }
                    }
                }
            }
            this.Sort();
        }
    }
}


 