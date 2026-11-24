
void
PrintSYSTEM_PROCESSOR_IDLE_INFORMATION(
   SYSTEM_PROCESSOR_IDLE_INFORMATION *Str
   );

void
PrintSYSTEM_PROCESSOR_IDLE_INFORMATION(
   SYSTEM_PROCESSOR_IDLE_INFORMATION *Str
   )
{
   printf("\nSYSTEM_PROCESSOR_IDLE_INFORMATION:\n");
   printf("   IdleTime	0x%I64x\n", Str->IdleTime);
   printf("   C1Time	0x%I64x\n", Str->C1Time);
   printf("   C2Time	0x%I64x\n", Str->C2Time);
   printf("   C3Time	0x%I64x\n", Str->C3Time);
   printf("   C1Transitions	%ld\n", Str->C1Transitions);
   printf("   C2Transitions	%ld\n", Str->C2Transitions);
   printf("   C3Transitions	%ld\n", Str->C3Transitions);
   printf("   Padding	%ld\n", Str->Padding);
   return;
} // PrintSYSTEM_PROCESSOR_IDLE_INFORMATION

