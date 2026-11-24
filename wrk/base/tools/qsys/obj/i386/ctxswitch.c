
void
PrintSYSTEM_CONTEXT_SWITCH_INFORMATION(
   SYSTEM_CONTEXT_SWITCH_INFORMATION *Str
   );

void
PrintSYSTEM_CONTEXT_SWITCH_INFORMATION(
   SYSTEM_CONTEXT_SWITCH_INFORMATION *Str
   )
{
   printf("\nSYSTEM_CONTEXT_SWITCH_INFORMATION:\n");
   printf("   ContextSwitches	%ld\n", Str->ContextSwitches);
   printf("   FindAny	%ld\n", Str->FindAny);
   printf("   FindLast	%ld\n", Str->FindLast);
   printf("   FindIdeal	%ld\n", Str->FindIdeal);
   printf("   IdleAny	%ld\n", Str->IdleAny);
   printf("   IdleCurrent	%ld\n", Str->IdleCurrent);
   printf("   IdleLast	%ld\n", Str->IdleLast);
   printf("   IdleIdeal	%ld\n", Str->IdleIdeal);
   printf("   PreemptAny	%ld\n", Str->PreemptAny);
   printf("   PreemptCurrent	%ld\n", Str->PreemptCurrent);
   printf("   PreemptLast	%ld\n", Str->PreemptLast);
   printf("   SwitchToIdle	%ld\n", Str->SwitchToIdle);
   return;
} // PrintSYSTEM_CONTEXT_SWITCH_INFORMATION

