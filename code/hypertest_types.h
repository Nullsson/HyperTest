#ifndef HYPERTEST_TYPES_H
#define HYPERTEST_TYPES_H
#pragma once

#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <float.h>

inline void
UNITTEST_ZeroSize(size_t Size, void *Pointer)
{
	//TODO: Performance check
	uint8_t *Byte = (uint8_t *)Pointer;
	while (Size--)
	{
		*Byte++ = 0;
	}
}

#define UNITTEST_ZeroStruct(Instance) UNITTEST_ZeroSize(sizeof(Instance), &(Instance))

#endif // HYPERTEST_TYPES_H