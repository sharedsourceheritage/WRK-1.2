
void
PrintSYSTEM_EXCEPTION_INFORMATION(
   SYSTEM_EXCEPTION_INFORMATION *Str
   );

void
PrintSYSTEM_EXCEPTION_INFORMATION(
   SYSTEM_EXCEPTION_INFORMATION *Str
   )
{
   printf("\nSYSTEM_EXCEPTION_INFORMATION:\n");
   printf("   AlignmentFixupCount	%ld\n", Str->AlignmentFixupCount);
   printf("   ExceptionDispatchCount	%ld\n", Str->ExceptionDispatchCount);
   printf("   FloatingEmulationCount	%ld\n", Str->FloatingEmulationCount);
   printf("   ByteWordEmulationCount	%ld\n", Str->ByteWordEmulationCount);
   return;
} // PrintSYSTEM_EXCEPTION_INFORMATION

