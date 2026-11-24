
void
PrintSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION(
   SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *Str
   );

void
PrintSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION(
   SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *Str
   )
{
   printf("\nSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION:\n");
   printf("   IdleTime	0x%I64x\n", Str->IdleTime.QuadPart);
   printf("   KernelTime	0x%I64x\n", Str->KernelTime.QuadPart);
   printf("   UserTime	0x%I64x\n", Str->UserTime.QuadPart);
   printf("   DpcTime	0x%I64x\n", Str->DpcTime.QuadPart);
   printf("   InterruptTime	0x%I64x\n", Str->InterruptTime.QuadPart);
   printf("   InterruptCount	%ld\n", Str->InterruptCount);
   return;
} // PrintSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION

