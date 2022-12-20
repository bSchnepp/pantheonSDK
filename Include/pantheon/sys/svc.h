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
bool SvcCreateThread(void (*Entry)(void*), void *Reserved, void *StackTop, uint8_t Priority);

Result SvcCreateNamedEvent(const char *Name, int32_t *Read, int32_t *Write);
Result SvcSignalEvent(int32_t Handle);
Result SvcClearEvent(int32_t Handle);
Result SvcResetEvent(int32_t Handle);
bool SvcPollEvent(int32_t Handle);
Result SvcYield();
Result SvcExecute(uint8_t Handle);
Result SvcCreatePort(const char *Name, int64_t MaxConnections, int32_t *HandleServer, int32_t *HandleClient);
Result SvcConnectToPort(int32_t *ClientPortHandle, int32_t *OutClientConnectionHandle);
Result SvcConnectToNamedPort(const char *Name, int32_t *OutClientConnectionHandle);
Result SvcAcceptConnection(int32_t InServerPortHandle, int32_t *OutConnection);
Result SvcReplyAndRecieve(uint32_t ContentSize, uint32_t *ReplyData, int32_t *NewConnection);
Result SvcCloseHandle(int32_t Handle);
Result SvcSendRequest(int32_t Handle);

#endif