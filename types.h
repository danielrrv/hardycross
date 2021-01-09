

#include <stdlib.h>

/**
 * dimensions of the csv file as column x rovv
*/
typedef size_t dimension;
/**
 * Edge of the graph that holds nodes and theirs properties
*/
typedef struct Node
{
	int vertex;
	struct Node *next;
	double rate;
	float resistence;

} Node;
//
typedef struct Graph
{
	int numberOfVertices;
	Node **adj; //<--pointer of Node and defined as pointer array too.
} Graph;
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