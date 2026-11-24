/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Vsip.DynamicMenu
{
    class GuidList
    {
        private GuidList(){}

        public static readonly Guid guidDynamicMenuPkg =        new Guid("{ce9cc1aa-4eb1-4068-b584-ffa55d7b10a9}");
        public static readonly Guid guidDynamicMenuMenuGroup =    new Guid("{2b167292-db7c-466f-aadc-ded61794b688}");
        public static readonly Guid guidDynamicMenuCmdSet =        new Guid("{38da9fea-35df-4167-ae94-daa3a5cf2de4}");


    };
}