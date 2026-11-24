
void
PrintSYSTEM_KERNEL_DEBUGGER_INFORMATION(
   SYSTEM_KERNEL_DEBUGGER_INFORMATION *Str
   );

void
PrintSYSTEM_KERNEL_DEBUGGER_INFORMATION(
   SYSTEM_KERNEL_DEBUGGER_INFORMATION *Str
   )
{
   printf("\nSYSTEM_KERNEL_DEBUGGER_INFORMATION:\n");
   printf("   KernelDebuggerEnabled	%d\n", Str->KernelDebuggerEnabled);
   printf("   KernelDebuggerNotPresent	%d\n", Str->KernelDebuggerNotPresent);
   return;
} // PrintSYSTEM_KERNEL_DEBUGGER_INFORMATION

