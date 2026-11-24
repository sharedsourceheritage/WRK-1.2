
void
PrintSYSTEM_DEVICE_INFORMATION(
   SYSTEM_DEVICE_INFORMATION *Str
   );

void
PrintSYSTEM_DEVICE_INFORMATION(
   SYSTEM_DEVICE_INFORMATION *Str
   )
{
   printf("\nSYSTEM_DEVICE_INFORMATION:\n");
   printf("   NumberOfDisks	%ld\n", Str->NumberOfDisks);
   printf("   NumberOfFloppies	%ld\n", Str->NumberOfFloppies);
   printf("   NumberOfCdRoms	%ld\n", Str->NumberOfCdRoms);
   printf("   NumberOfTapes	%ld\n", Str->NumberOfTapes);
   printf("   NumberOfSerialPorts	%ld\n", Str->NumberOfSerialPorts);
   printf("   NumberOfParallelPorts	%ld\n", Str->NumberOfParallelPorts);
   return;
} // PrintSYSTEM_DEVICE_INFORMATION

