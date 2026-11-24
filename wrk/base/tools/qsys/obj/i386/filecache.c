
void
PrintSYSTEM_FILECACHE_INFORMATION(
   SYSTEM_FILECACHE_INFORMATION *Str
   );

void
PrintSYSTEM_FILECACHE_INFORMATION(
   SYSTEM_FILECACHE_INFORMATION *Str
   )
{
   printf("\nSYSTEM_FILECACHE_INFORMATION:\n");
   printf("   CurrentSize	0x%Ix\n", Str->CurrentSize);
   printf("   PeakSize	0x%Ix\n", Str->PeakSize);
   printf("   PageFaultCount	%ld\n", Str->PageFaultCount);
   printf("   MinimumWorkingSet	0x%Ix\n", Str->MinimumWorkingSet);
   printf("   MaximumWorkingSet	0x%Ix\n", Str->MaximumWorkingSet);
   printf("   CurrentSizeIncludingTransitionInPages	0x%Ix\n", Str->CurrentSizeIncludingTransitionInPages);
   printf("   PeakSizeIncludingTransitionInPages	0x%Ix\n", Str->PeakSizeIncludingTransitionInPages);
   printf("   TransitionRePurposeCount	%ld\n", Str->TransitionRePurposeCount);
{ int idx; for ( idx = 0; idx < 1; idx++ ) {
   printf("   spare[%ld]	%ld\n", idx, Str->spare[idx]);
} }
   return;
} // PrintSYSTEM_FILECACHE_INFORMATION

