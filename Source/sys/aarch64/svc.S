.macro SVC_DEF name
	.section .text.\name
	.align 2
	.globl \name
	.type \name, @function
	.cfi_startproc
\name:
.endm

.macro SVC_END name
	.cfi_endproc
.endm

.section ".text"

SVC_DEF SvcExitProcess
	mov w8, #0
	svc #0
	ret
SVC_END

SVC_DEF SvcForkProcess
	mov w8, #1
	svc #0
	ret
SVC_END

SVC_DEF SvcLogText
	mov w8, #2
	svc #0
	ret
SVC_END

SVC_DEF SvcAllocateBuffer
	mov w8, #3
	svc #0
	ret
SVC_END

SVC_DEF SvcCreateThread
	mov w8, #4
	svc #0
	ret
SVC_END

SVC_DEF SvcCreateNamedEvent
	mov w8, #5
	svc #0
	ret
SVC_END

SVC_DEF SvcSignalEvent
	mov w8, #6
	svc #0
	ret
SVC_END

SVC_DEF SvcClearEvent
	mov w8, #7
	svc #0
	ret
SVC_END

SVC_DEF SvcResetEvent
	mov w8, #8
	svc #0
	ret
SVC_END

SVC_DEF SvcPollEvent
	mov w8, #9
	svc #0
	ret
SVC_END

SVC_DEF SvcYield
	mov w8, #10
	svc #0
	ret
SVC_END

SVC_DEF SvcExitThread
	mov w8, #11
	svc #0
	ret
SVC_END

SVC_DEF SvcExecute
	mov w8, #12
	svc #0
	ret
SVC_END

SVC_DEF SvcCreatePort
	mov w8, #13
	svc #0
	ret
SVC_END

SVC_DEF SvcConnectToPort
	mov w8, #14
	svc #0
	ret
SVC_END

SVC_DEF SvcConnectToNamedPort
	mov w8, #15
	svc #0
	ret
SVC_END

SVC_DEF SvcAcceptConnection
	mov w8, #16
	svc #0
	ret
SVC_END

SVC_DEF SvcReplyAndRecieve
	mov w8, #17
	svc #0
	ret
SVC_END

SVC_DEF SvcCloseHandle
	mov w8, #18
	svc #0
	ret
SVC_END

SVC_DEF SvcSendRequest
	mov w8, #19
	svc #0
	ret
SVC_END