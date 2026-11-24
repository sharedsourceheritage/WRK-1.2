
void
PrintSYSTEM_BASIC_INFORMATION(
   SYSTEM_BASIC_INFORMATION *Str
   );

void
PrintSYSTEM_BASIC_INFORMATION(
   SYSTEM_BASIC_INFORMATION *Str
   )
{
   printf("\nSYSTEM_BASIC_INFORMATION:\n");
   printf("   Reserved	%ld\n", Str->Reserved);
   printf("   TimerResolution	%ld\n", Str->TimerResolution);
   printf("   PageSize	%ld\n", Str->PageSize);
   printf("   NumberOfPhysicalPages	0x%ld\n", Str->NumberOfPhysicalPages);
   printf("   LowestPhysicalPageNumber	0x%ld\n", Str->LowestPhysicalPageNumber);
   printf("   HighestPhysicalPageNumber	0x%ld\n", Str->HighestPhysicalPageNumber);
   printf("   AllocationGranularity	%ld\n", Str->AllocationGranularity);
   printf("   MinimumUserModeAddress	0x%Ix\n", Str->MinimumUserModeAddress);
   printf("   MaximumUserModeAddress	0x%Ix\n", Str->MaximumUserModeAddress);
   printf("   ActiveProcessorsAffinityMask	0x%Ix\n", Str->ActiveProcessorsAffinityMask);
   printf("   NumberOfProcessors	%d\n", Str->NumberOfProcessors);
   return;
} // PrintSYSTEM_BASIC_INFORMATION

