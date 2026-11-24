
void
PrintSYSTEM_LEGACY_DRIVER_INFORMATION(
   SYSTEM_LEGACY_DRIVER_INFORMATION *Str
   );

void
PrintSYSTEM_LEGACY_DRIVER_INFORMATION(
   SYSTEM_LEGACY_DRIVER_INFORMATION *Str
   )
{
   printf("\nSYSTEM_LEGACY_DRIVER_INFORMATION:\n");
   printf("   VetoType	%ld\n", Str->VetoType);
   printf("   VetoList	%wZ\n", &Str->VetoList);
   return;
} // PrintSYSTEM_LEGACY_DRIVER_INFORMATION

