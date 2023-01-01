/**
 * @file svc.h
 * @brief Definitions for system calls
 * @copyright Brian Schnepp
 */

#ifndef PANTHEON_SYS_SVC_H_
#define PANTHEON_SYS_SVC_H_

#include "../types.h"

Result SvcExitProcess();

Result SvcLogText(const char *Content);

Result *SvcAllocateBuffer(uint64_t Sz);

/**
 * \~english @brief Creates a thread for this process
 * \~english @param[in] Entry The entrypoint of the new thread
 * \~english @param[in] Argument The argument to provide to the entrypoint on the new thread
 * \~english @param[in] StackTop The location of the stack of the new thread
 * \~english @param[in] Priority The priority of the new thread
 * \~english @pre
 * 	- StackTop must be a valid address within the process' address space
 * 	- Priority must be between 0 and 5, with higher priority being higher values
 * \~english @post
 * 	- The thread will be placed in a Running state, and possibly have started execution
 */
Result SvcCreateThread(void (*Entry)(void*), void *Argument, void *StackTop, uint8_t Priority);

Result SvcCreateNamedEvent(const char *Name, int32_t *Read, int32_t *Write);
Result SvcSignalEvent(int32_t Handle);
Result SvcClearEvent(int32_t Handle);
Result SvcResetEvent(int32_t Handle);
bool SvcPollEvent(int32_t Handle);
Result SvcYield();
Result SvcExecute(uint8_t Handle);

/**
 * \~english @brief Creates a Port for this process
 * \~english @param[in] Name The 8-character name for this Port, if applicable.
 * \~english @param[in] MaxConnections The maximum number of connections for this Port
 * \~english @param[in] HandleServer The location to store the handle for ServerConnections
 * \~english @param[in] HandleClient The location to store the handle for ClientConnections
 * \~english @pre
 * 	- Ports will be anonymous (no name) if no 8-character name is provided.
 * 	- Permission to create named ports is restricted: if not allowed, the returned Result will reflect this
 * 	- Provided names must be 8 characters: exceeding this will result in truncation.
 * 	- Argument Name must be null-terminated, but the null character does not apply to the 8 character limit.
 */
Result SvcCreatePort(const char *Name, int64_t MaxConnections, int32_t *HandleServer, int32_t *HandleClient);
Result SvcConnectToPort(int32_t *ClientPortHandle, int32_t *OutClientConnectionHandle);
Result SvcConnectToNamedPort(const char *Name, int32_t *OutClientConnectionHandle);
Result SvcAcceptConnection(int32_t InServerPortHandle, int32_t *OutConnection);
Result SvcReplyAndRecieve(uint32_t ContentSize, uint32_t *ReplyData, int32_t *NewConnection);
Result SvcCloseHandle(int32_t Handle);
Result SvcSendRequest(int32_t Handle);

#endif