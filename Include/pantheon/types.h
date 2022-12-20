/**
 * @file pantheon.h
 * @brief Definition for types and error codes
 * @copyright Brian Schnepp
 */

#ifndef PANTHEON_TYPES_H_
#define PANTHEON_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Kernel Object handle
 */
typedef int32_t Handle;

/**
 * @brief Kernel error result 
 */
typedef uint32_t Result;


#define R_SUCCEEDED(r) ((r)==0)
#define R_FAILED (r) (!(R_SUCCEEDED(r)))

enum {
	ErrorTypeUnknown = 0,
	ErrorTypeKernel = (1ULL << 24),
	ErrorTypeSysm = (2ULL << 24),
	ErrorTypePrgm = (3ULL << 24),
};

enum {
	ErrorCode_Kernel_Fail = 1,
	ErrorCode_Kernel_OOM = 2,
	ErrorCode_Kernel_PortClosed = 3,
	ErrorCode_Kernel_ConnectionClosed = 3,
};

#define R_ORIGINATOR(r) (r & ((1ULL << 24) - 1))
#define R_REASON(R) (r & ~((1ULL << 24) - 1))

#endif