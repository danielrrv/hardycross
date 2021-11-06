#include "types.h"

#ifndef DATA_STRUCTURE_H
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
typedef struct node_t
{
	int vertex;
	struct node_t **next;
} node_t;

typedef struct data_t
{
	float resistence;
	float rate;
} data_t;

typedef struct edge_t
{
	data_t *data;
	node_t *nodes[2];
} edge_t;

typedef struct graph_t
{
	int number_of_vertices;
	node_t **adj;
	edge_t **edges;
} graph_t;

// typedef struct LinkedList{
// 	Node * nodes;
// }LinkedList;

//Prototypes
node_t *create_node(graph_t *, int);
graph_t *create_graph(int);
void static add_node(graph_t *, node_t *);
void add_edge(graph_t *, node_t *, node_t *);
void print_graph(graph_t *);
void static link_nodes(node_t *, node_t *, int);
node_t **unique_nodes(node_t **);
bool in_array(node_t *, node_t **);
edge_t *create_edge(graph_t *, node_t *, node_t *, data_t *);

#endif