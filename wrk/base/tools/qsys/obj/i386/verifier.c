
void
PrintSYSTEM_VERIFIER_INFORMATION(
   SYSTEM_VERIFIER_INFORMATION *Str
   );

void
PrintSYSTEM_VERIFIER_INFORMATION(
   SYSTEM_VERIFIER_INFORMATION *Str
   )
{
   printf("\nSYSTEM_VERIFIER_INFORMATION:\n");
   printf("   NextEntryOffset	%ld\n", Str->NextEntryOffset);
   printf("   Level	%ld\n", Str->Level);
   printf("   DriverName	%wZ\n", &Str->DriverName);
   printf("   RaiseIrqls	%ld\n", Str->RaiseIrqls);
   printf("   AcquireSpinLocks	%ld\n", Str->AcquireSpinLocks);
   printf("   SynchronizeExecutions	%ld\n", Str->SynchronizeExecutions);
   printf("   AllocationsAttempted	%ld\n", Str->AllocationsAttempted);
   printf("   AllocationsSucceeded	%ld\n", Str->AllocationsSucceeded);
   printf("   AllocationsSucceededSpecialPool	%ld\n", Str->AllocationsSucceededSpecialPool);
   printf("   AllocationsWithNoTag	%ld\n", Str->AllocationsWithNoTag);
   printf("   TrimRequests	%ld\n", Str->TrimRequests);
   printf("   Trims	%ld\n", Str->Trims);
   printf("   AllocationsFailed	%ld\n", Str->AllocationsFailed);
   printf("   AllocationsFailedDeliberately	%ld\n", Str->AllocationsFailedDeliberately);
   printf("   Loads	%ld\n", Str->Loads);
   printf("   Unloads	%ld\n", Str->Unloads);
   printf("   UnTrackedPool	%ld\n", Str->UnTrackedPool);
   printf("   CurrentPagedPoolAllocations	%ld\n", Str->CurrentPagedPoolAllocations);
   printf("   CurrentNonPagedPoolAllocations	%ld\n", Str->CurrentNonPagedPoolAllocations);
   printf("   PeakPagedPoolAllocations	%ld\n", Str->PeakPagedPoolAllocations);
   printf("   PeakNonPagedPoolAllocations	%ld\n", Str->PeakNonPagedPoolAllocations);
   printf("   PagedPoolUsageInBytes	0x%Ix\n", Str->PagedPoolUsageInBytes);
   printf("   NonPagedPoolUsageInBytes	0x%Ix\n", Str->NonPagedPoolUsageInBytes);
   printf("   PeakPagedPoolUsageInBytes	0x%Ix\n", Str->PeakPagedPoolUsageInBytes);
   printf("   PeakNonPagedPoolUsageInBytes	0x%Ix\n", Str->PeakNonPagedPoolUsageInBytes);
   return;
} // PrintSYSTEM_VERIFIER_INFORMATION

