
void
PrintSYSTEM_PERFORMANCE_INFORMATION(
   SYSTEM_PERFORMANCE_INFORMATION *Str
   );

void
PrintSYSTEM_PERFORMANCE_INFORMATION(
   SYSTEM_PERFORMANCE_INFORMATION *Str
   )
{
   printf("\nSYSTEM_PERFORMANCE_INFORMATION:\n");
   printf("   IdleProcessTime	0x%I64x\n", Str->IdleProcessTime.QuadPart);
   printf("   IoReadTransferCount	0x%I64x\n", Str->IoReadTransferCount.QuadPart);
   printf("   IoWriteTransferCount	0x%I64x\n", Str->IoWriteTransferCount.QuadPart);
   printf("   IoOtherTransferCount	0x%I64x\n", Str->IoOtherTransferCount.QuadPart);
   printf("   IoReadOperationCount	%ld\n", Str->IoReadOperationCount);
   printf("   IoWriteOperationCount	%ld\n", Str->IoWriteOperationCount);
   printf("   IoOtherOperationCount	%ld\n", Str->IoOtherOperationCount);
   printf("   AvailablePages	%ld\n", Str->AvailablePages);
   printf("   CommittedPages	0x%ld\n", Str->CommittedPages);
   printf("   CommitLimit	0x%ld\n", Str->CommitLimit);
   printf("   PeakCommitment	0x%ld\n", Str->PeakCommitment);
   printf("   PageFaultCount	%ld\n", Str->PageFaultCount);
   printf("   CopyOnWriteCount	%ld\n", Str->CopyOnWriteCount);
   printf("   TransitionCount	%ld\n", Str->TransitionCount);
   printf("   CacheTransitionCount	%ld\n", Str->CacheTransitionCount);
   printf("   DemandZeroCount	%ld\n", Str->DemandZeroCount);
   printf("   PageReadCount	%ld\n", Str->PageReadCount);
   printf("   PageReadIoCount	%ld\n", Str->PageReadIoCount);
   printf("   CacheReadCount	%ld\n", Str->CacheReadCount);
   printf("   CacheIoCount	%ld\n", Str->CacheIoCount);
   printf("   DirtyPagesWriteCount	%ld\n", Str->DirtyPagesWriteCount);
   printf("   DirtyWriteIoCount	%ld\n", Str->DirtyWriteIoCount);
   printf("   MappedPagesWriteCount	%ld\n", Str->MappedPagesWriteCount);
   printf("   MappedWriteIoCount	%ld\n", Str->MappedWriteIoCount);
   printf("   PagedPoolPages	%ld\n", Str->PagedPoolPages);
   printf("   NonPagedPoolPages	%ld\n", Str->NonPagedPoolPages);
   printf("   PagedPoolAllocs	%ld\n", Str->PagedPoolAllocs);
   printf("   PagedPoolFrees	%ld\n", Str->PagedPoolFrees);
   printf("   NonPagedPoolAllocs	%ld\n", Str->NonPagedPoolAllocs);
   printf("   NonPagedPoolFrees	%ld\n", Str->NonPagedPoolFrees);
   printf("   FreeSystemPtes	%ld\n", Str->FreeSystemPtes);
   printf("   ResidentSystemCodePage	%ld\n", Str->ResidentSystemCodePage);
   printf("   TotalSystemDriverPages	%ld\n", Str->TotalSystemDriverPages);
   printf("   TotalSystemCodePages	%ld\n", Str->TotalSystemCodePages);
   printf("   NonPagedPoolLookasideHits	%ld\n", Str->NonPagedPoolLookasideHits);
   printf("   PagedPoolLookasideHits	%ld\n", Str->PagedPoolLookasideHits);
   printf("   AvailablePagedPoolPages	%ld\n", Str->AvailablePagedPoolPages);
   printf("   ResidentSystemCachePage	%ld\n", Str->ResidentSystemCachePage);
   printf("   ResidentPagedPoolPage	%ld\n", Str->ResidentPagedPoolPage);
   printf("   ResidentSystemDriverPage	%ld\n", Str->ResidentSystemDriverPage);
   printf("   CcFastReadNoWait	%ld\n", Str->CcFastReadNoWait);
   printf("   CcFastReadWait	%ld\n", Str->CcFastReadWait);
   printf("   CcFastReadResourceMiss	%ld\n", Str->CcFastReadResourceMiss);
   printf("   CcFastReadNotPossible	%ld\n", Str->CcFastReadNotPossible);
   printf("   CcFastMdlReadNoWait	%ld\n", Str->CcFastMdlReadNoWait);
   printf("   CcFastMdlReadWait	%ld\n", Str->CcFastMdlReadWait);
   printf("   CcFastMdlReadResourceMiss	%ld\n", Str->CcFastMdlReadResourceMiss);
   printf("   CcFastMdlReadNotPossible	%ld\n", Str->CcFastMdlReadNotPossible);
   printf("   CcMapDataNoWait	%ld\n", Str->CcMapDataNoWait);
   printf("   CcMapDataWait	%ld\n", Str->CcMapDataWait);
   printf("   CcMapDataNoWaitMiss	%ld\n", Str->CcMapDataNoWaitMiss);
   printf("   CcMapDataWaitMiss	%ld\n", Str->CcMapDataWaitMiss);
   printf("   CcPinMappedDataCount	%ld\n", Str->CcPinMappedDataCount);
   printf("   CcPinReadNoWait	%ld\n", Str->CcPinReadNoWait);
   printf("   CcPinReadWait	%ld\n", Str->CcPinReadWait);
   printf("   CcPinReadNoWaitMiss	%ld\n", Str->CcPinReadNoWaitMiss);
   printf("   CcPinReadWaitMiss	%ld\n", Str->CcPinReadWaitMiss);
   printf("   CcCopyReadNoWait	%ld\n", Str->CcCopyReadNoWait);
   printf("   CcCopyReadWait	%ld\n", Str->CcCopyReadWait);
   printf("   CcCopyReadNoWaitMiss	%ld\n", Str->CcCopyReadNoWaitMiss);
   printf("   CcCopyReadWaitMiss	%ld\n", Str->CcCopyReadWaitMiss);
   printf("   CcMdlReadNoWait	%ld\n", Str->CcMdlReadNoWait);
   printf("   CcMdlReadWait	%ld\n", Str->CcMdlReadWait);
   printf("   CcMdlReadNoWaitMiss	%ld\n", Str->CcMdlReadNoWaitMiss);
   printf("   CcMdlReadWaitMiss	%ld\n", Str->CcMdlReadWaitMiss);
   printf("   CcReadAheadIos	%ld\n", Str->CcReadAheadIos);
   printf("   CcLazyWriteIos	%ld\n", Str->CcLazyWriteIos);
   printf("   CcLazyWritePages	%ld\n", Str->CcLazyWritePages);
   printf("   CcDataFlushes	%ld\n", Str->CcDataFlushes);
   printf("   CcDataPages	%ld\n", Str->CcDataPages);
   printf("   ContextSwitches	%ld\n", Str->ContextSwitches);
   printf("   FirstLevelTbFills	%ld\n", Str->FirstLevelTbFills);
   printf("   SecondLevelTbFills	%ld\n", Str->SecondLevelTbFills);
   printf("   SystemCalls	%ld\n", Str->SystemCalls);
   return;
} // PrintSYSTEM_PERFORMANCE_INFORMATION

