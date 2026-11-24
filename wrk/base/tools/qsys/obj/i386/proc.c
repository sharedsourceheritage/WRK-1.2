
void
PrintSYSTEM_PROCESSOR_INFORMATION(
   SYSTEM_PROCESSOR_INFORMATION *Str
   );

void
PrintSYSTEM_PROCESSOR_INFORMATION(
   SYSTEM_PROCESSOR_INFORMATION *Str
   )
{
   printf("\nSYSTEM_PROCESSOR_INFORMATION:\n");
   printf("   ProcessorArchitecture	%u\n", Str->ProcessorArchitecture);
   printf("   ProcessorLevel	%u\n", Str->ProcessorLevel);
   printf("   ProcessorRevision	%u\n", Str->ProcessorRevision);
   printf("   Reserved	%u\n", Str->Reserved);
   printf("   ProcessorFeatureBits	%ld\n", Str->ProcessorFeatureBits);
   return;
} // PrintSYSTEM_PROCESSOR_INFORMATION

