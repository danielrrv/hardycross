

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <assert.h>

#ifndef HARDYCROSS_TYPES_H_
#define HARDYCROSS_TYPES_H_

#ifdef DEBUG
#define DEBUG_LOG 1
#else
#define DEBUG_LOG 0
#endif

#define DEBUG_PRINT(format, ...)                  \
	do                                            \
	{                                             \
		if (DEBUG_LOG)                            \
			fprintf(stderr, format, __VA_ARGS__); \
	} while (0)

/**
 * dimensions of the csv file as column x rovv
*/
typedef size_t dimension;



//helpers functions


#endif // HARDYCROSS_TYPES_H_