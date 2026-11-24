
void
PrintSYSTEM_TIMEOFDAY_INFORMATION(
   SYSTEM_TIMEOFDAY_INFORMATION *Str
   );

void
PrintSYSTEM_TIMEOFDAY_INFORMATION(
   SYSTEM_TIMEOFDAY_INFORMATION *Str
   )
{
   printf("\nSYSTEM_TIMEOFDAY_INFORMATION:\n");
   printf("   BootTime	0x%I64x\n", Str->BootTime.QuadPart);
   printf("   CurrentTime	0x%I64x\n", Str->CurrentTime.QuadPart);
   printf("   TimeZoneBias	0x%I64x\n", Str->TimeZoneBias.QuadPart);
   printf("   TimeZoneId	%ld\n", Str->TimeZoneId);
   printf("   Reserved	%ld\n", Str->Reserved);
   printf("   BootTimeBias	0x%I64x\n", Str->BootTimeBias);
   printf("   SleepTimeBias	0x%I64x\n", Str->SleepTimeBias);
   return;
} // PrintSYSTEM_TIMEOFDAY_INFORMATION

