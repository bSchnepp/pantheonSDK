/**
 * @file pantheon.h
 * @brief Definition for types and error codes
 * @copyright Brian Schnepp
 */

#ifndef PANTHEON_SERVICES_SYSM_H_
#define PANTHEON_SERVICES_SYSM_H_

#include "../types.h"

typedef struct SysmServiceName
{
	union
	{
		uint64_t Integer;
		char Name[8];
	};
} SysmServiceName;

#endif