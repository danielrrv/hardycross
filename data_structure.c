
#include "data_structure.h"
#include "types.h"

//Implementation to create Nodes
Node *create_node(Graph* graph, int vtx)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = (Node **)malloc(sizeof(Node) * (graph->number_of_vertices - 1));
	node->vertex = vtx;
	int i;
	for (i = 0; i < graph->number_of_vertices - 1; i++)
		node->next[i] = NULL;
	if(!in_array(node, graph->adj)){
			add_node(graph, node);
	}else{
		fprintf(stderr, "The vertex %d already exist\n\n", vtx);
		exit(1);
	}
	return node;
};

void static add_node(Graph *graph, Node *node)
{
	int i  =0;
	while(i<graph->number_of_vertices){
		if(graph->adj[i]==NULL){
			graph->adj[i] = node;
			break;
		}
		i++;

	}
}

Graph *create_graph(int V)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->number_of_vertices = V;
	graph->adj = (Node **)malloc(V * sizeof(Node));
	int i;
	for (i = 0; i < V; i++)
		graph->adj[i] = NULL;
	return graph;
};

//Implemention to add edges to the graph
void add_edge(Graph *graph, Node *src, Node *dest)
{
	link_nodes(src, dest, graph->number_of_vertices);
	link_nodes(dest, src, graph->number_of_vertices);
};

void static link_nodes(Node *src, Node *dest, int V)
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

Node ** unique_nodes(Node ** nodes){
	int length = sizeof(nodes) / sizeof(Node);
	
	return nodes;	
}

bool in_array(Node * value, Node ** values){
	Node **indirect = values;
	while(*indirect!=NULL){
		if((*indirect)->vertex == value->vertex)
			return true;
		indirect++;
	}
	return false; 
}

// void generate_table(grap){

// }

// void print_graph(Graph *graph)
// {
// 	int v;
// 	for (v = 0; v < graph->number_of_vertices; v++)
// 	{
// 		Node *temp = graph->adj[v];
// 		printf("\n Vertex %d: ", v);
// 		while (temp)
// 		{
// 			printf("%d -> ", temp->vertex);
// 			temp = temp->next;
// 		}
// 		printf("\n");
// 	}
// };
