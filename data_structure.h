#include "types.h"

#ifndef  DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

//Adjacency Matrix: 

/**
 * Edge of the graph that holds nodes and theirs properties
 * 
 * The Node is the mininum piece of the problem. 
 * Each node has at  most n-1 relationships with other nodes.
 * 
 * Each node has bi-directional relationship with others.
 * The node should know the reference of its node it has relationship with.
 * The graph keeps the number of vertix(n) equivalent to number of nodes.
 * Each time a relationship is established, both nodes keeps reference from each other.
 * Each node has at most n-1 relationships with other nodes. however the allocation is dynamic based upon the new relationships.
*/
typedef struct Node
{
	int vertex;
	struct Node * next;
	double rate;
	float resistence;
} Node;


typedef struct
{
	int number_of_vertices;
	Node ** adj;
} Graph;




// typedef struct LinkedList{
// 	Node * nodes;
// }LinkedList;

//Prototypes
Node *createNode(int, double, float);
Graph *createGraph(int);
void addEdge(Graph *, Node *, Node *, double, float);
void printGraph(Graph *);
Node * findNode(Graph *,int);

void add_element_to_matrix(Node*);



// LinkedList * create_linked_list(int);
// void add_element(Node*);
// void remove_element(Node*);
// void find_element_index(int);
// void find 

#endif