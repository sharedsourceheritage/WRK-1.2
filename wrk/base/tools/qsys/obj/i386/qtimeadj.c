
void
PrintSYSTEM_QUERY_TIME_ADJUST_INFORMATION(
   SYSTEM_QUERY_TIME_ADJUST_INFORMATION *Str
   );

void
PrintSYSTEM_QUERY_TIME_ADJUST_INFORMATION(
   SYSTEM_QUERY_TIME_ADJUST_INFORMATION *Str
   )
{
   printf("\nSYSTEM_QUERY_TIME_ADJUST_INFORMATION:\n");
   printf("   TimeAdjustment	%ld\n", Str->TimeAdjustment);
   printf("   TimeIncrement	%ld\n", Str->TimeIncrement);
   printf("   Enable	%d\n", Str->Enable);
   return;
} // PrintSYSTEM_QUERY_TIME_ADJUST_INFORMATION

