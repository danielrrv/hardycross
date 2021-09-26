#include "types.h"
#ifndef FILE_MACROS_HARDY
#define FILE_MACROS_HARDY

typedef struct
{
	dimension row;
	dimension column;

} CSV;


/**
 * Columns of the csv file.
*/
enum column
{
	node1 = 0,
	node2 = 1,
	rate = 2,
	resistence = 3
};



double **reader(char *, size_t, size_t);
void report(const char *message);
CSV *get_column_row_function(char *);


#endif