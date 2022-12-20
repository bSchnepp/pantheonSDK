/**
 * @file tls.c
 * @brief Functions for thread local storage
 * @copyright Brian Schnepp
 */


#include "pantheon/types.h"
#include "pantheon/sys/tls.h"

void *GetTLS(void)
{
	void *RetVal = 0;
	asm volatile ("mrs %0, tpidrro_el0\n" : "=r"(RetVal) ::);
	return RetVal;
}