/**
 * @file tls.c
 * @brief Functions for thread local storage
 * @copyright Brian Schnepp
 */


#include "pantheon/types.h"
#include "pantheon/sys/tls.h"

/**
 * \~english @brief Obtains the thread-local storage area
 * \~english @details Obtains the thread-local storage area, which is needed
 * to perform certain operations such as IPC. The location of this area is
 * determined by the kernel, and may not be changed. However, it's contents
 * are writable by any thread in the current process: it is up to the
 * user to enforce that only the thread which the thread-local storage is
 * intended for can actually write to it's own thread-local storage.
 * <br>
 * Typically, IPC will require that some messages be parsed and "blessed" by
 * the kernel before proceeding: this is required for operations such as
 * transferring of handles and association with typical pantheon system 
 * processes.
 * 
 * \~english @return A void* pointing to where the thread-local storage is.
 * @see pantheon::ipc
 */
void *GetTLS(void)
{
	void *RetVal = 0;
	asm volatile ("mrs %0, tpidrro_el0\n" : "=r"(RetVal) ::);
	return RetVal;
}