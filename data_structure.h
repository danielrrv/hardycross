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
	struct Node ** next;
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
Node *create_node(Graph *, int);
Graph *create_graph(int);
void static add_node(Graph *, Node *);
void add_edge(Graph *, Node *, Node *);
void print_graph(Graph *);
void static link_nodes(Node *, Node *, int );
Node ** unique_nodes(Node **);
bool in_array(Node * , Node ** );


#endif