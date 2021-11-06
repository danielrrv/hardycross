
#include "data_structure.h"
#include "types.h"

//Implementation to create Nodes
node_t * create_node(graph_t *graph, int vtx)
{
	node_t * node = (node_t *)malloc(sizeof(node_t));
	node->next = (node_t **)malloc(sizeof(node_t) * (graph->number_of_vertices - 1));
	node->vertex = vtx;
	int i;
	for (i = 0; i < graph->number_of_vertices - 1; i++)
		node->next[i] = NULL;
		
	if (in_array(node, graph->adj))
	{
		fprintf(stderr, "The vertex %d already exist\n\n", vtx);
		exit(1);
		
	}
	add_node(graph, node);
	return node;
};

void static add_node(graph_t *graph, node_t *node)
{
	int i = 0;
	while (i < graph->number_of_vertices)
	{
		if (graph->adj[i] == NULL)
		{
			graph->adj[i] = node;
			break;
		}
		i++;
	}
}

graph_t *create_graph(int V)
{
	graph_t * graph = (graph_t *)malloc(sizeof(graph_t));
	graph->number_of_vertices = V;
	graph->adj = (node_t **)malloc(V * sizeof(node_t));
	int i;
	for (i = 0; i < V; i++)
		graph->adj[i] = NULL;
	graph->edges = NULL;
	return graph;
};

//Implemention to add edges to the graph
void add_edge(graph_t *graph, node_t *src, node_t *dest)
{
	link_nodes(src, dest, graph->number_of_vertices);
	link_nodes(dest, src, graph->number_of_vertices);
};

void static link_nodes(node_t *src, node_t *dest, int V)
{
	int i = 0;
	while (i <= V - 1)
	{
		if (src->next[i] == NULL)
		{
			src->next[i] = dest;
			break;
		}
		i++;
	}
}


bool in_array(node_t*value, node_t **values)
{
	node_t **indirect = values;
	while (*indirect != NULL)
	{
		if ((*indirect)->vertex == value->vertex)
			return true;
		indirect++;
	}
	return false;
}



edge_t * create_edge(graph_t * graph,node_t * node_1, node_t * node_2, data_t * data){
	int static no_edges = 0;
	edge_t * edge  = (edge_t*)malloc(sizeof(edge_t));
	edge->data = data; 
	edge->nodes[0] = node_1;
	edge->nodes[1] = node_2;
	if(graph->edges==NULL){
		graph->edges = (edge_t **)malloc(sizeof(edge_t*));
		graph->edges[no_edges] = edge;
	}else{
		// size_t len = *(&graph->edges-1) + 1; 
		graph->edges = (edge_t **)realloc(graph->edges,++no_edges);
		graph->edges[no_edges] = edge;
	}
	printf("creating the edges\nnode[0]:\t%d\nnode[1]:\t%d\n", node_1->vertex, node_2->vertex );
	return edge;
}