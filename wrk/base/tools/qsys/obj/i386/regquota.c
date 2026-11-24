
void
PrintSYSTEM_REGISTRY_QUOTA_INFORMATION(
   SYSTEM_REGISTRY_QUOTA_INFORMATION *Str
   );

void
PrintSYSTEM_REGISTRY_QUOTA_INFORMATION(
   SYSTEM_REGISTRY_QUOTA_INFORMATION *Str
   )
{
   printf("\nSYSTEM_REGISTRY_QUOTA_INFORMATION:\n");
   printf("   RegistryQuotaAllowed	%ld\n", Str->RegistryQuotaAllowed);
   printf("   RegistryQuotaUsed	%ld\n", Str->RegistryQuotaUsed);
   printf("   PagedPoolSize	0x%Ix\n", Str->PagedPoolSize);
   return;
} // PrintSYSTEM_REGISTRY_QUOTA_INFORMATION

