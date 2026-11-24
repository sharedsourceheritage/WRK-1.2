
void
PrintSYSTEM_DPC_BEHAVIOR_INFORMATION(
   SYSTEM_DPC_BEHAVIOR_INFORMATION *Str
   );

void
PrintSYSTEM_DPC_BEHAVIOR_INFORMATION(
   SYSTEM_DPC_BEHAVIOR_INFORMATION *Str
   )
{
   printf("\nSYSTEM_DPC_BEHAVIOR_INFORMATION:\n");
   printf("   Spare	%ld\n", Str->Spare);
   printf("   DpcQueueDepth	%ld\n", Str->DpcQueueDepth);
   printf("   MinimumDpcRate	%ld\n", Str->MinimumDpcRate);
   printf("   AdjustDpcThreshold	%ld\n", Str->AdjustDpcThreshold);
   printf("   IdealDpcRate	%ld\n", Str->IdealDpcRate);
   return;
} // PrintSYSTEM_DPC_BEHAVIOR_INFORMATION

