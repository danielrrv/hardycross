

#include <stdlib.h>


#ifndef _TYPES_H_
#define _TYPES_H_



#ifdef DEBUG 
	#define DEBUG_LOG 1
#else
 	#define DEBUG_LOG 0
#endif

#define DEBUG_PRINT(format,...) do {if(DEBUG_LOG) fprintf(stderr, format, __VA_ARGS__); }while (0)


/**
 * dimensions of the csv file as column x rovv
*/
typedef size_t dimension;
/**
 * Edge of the graph that holds nodes and theirs properties
*/
typedef struct Node {
	int vertex;
	struct Node *next;
	double rate;
	float resistence;

} Node;
//
typedef struct{
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

//Prototypes
Node *createNode(int , double , float);
Graph *createGraph(int);
void addEdge(Graph *, int, int , double, float);
void printGraph(Graph * );
//helpers functions
double **reader(char *, size_t, size_t);
void report(const char * message);

#endif// _TYPES_H