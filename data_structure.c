
#include "data_structure.h"
#include "types.h"

static instance = 0;
//Implementation to create Nodes
Node *createNode(int V, double rate, float resistence)
{
	
	DEBUG_PRINT("Creating node\n \trate:%.2f\n\tresistence:%.2f\n",rate, resistence);
	Node *node = (Node *)malloc(sizeof(Node));
	node->vertex = V;
	node->rate = rate;
	node->resistence = resistence;
	node->next = NULL;
	return node;
};
Graph *createGraph(int V)
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
void addEdge(Graph *graph, int src, int dest, double rate, float resistence)
{
	// Add edge from s to d
	Node *newNode = createNode(dest, rate, resistence);
	newNode->next = graph->adj[src];
	graph->adj[instance++] = newNode;

	// Add edge from d to s
	newNode = createNode(src, rate, resistence);
	newNode->next = graph->adj[dest];

	graph->adj[dest] = newNode;
};

void printGraph(Graph *graph)
{
	int v;
	for (v = 0; v < graph->number_of_vertices; v++)
	{
		Node *temp = graph->adj[v];
		printf("\n Vertex %d: ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
};


Node * findNode(Graph * graph,int value){
	Node * node = *graph->adj;
	while (node->vertex != value)
		node++;
	return node;
};





void copyNode(Node * from, Node * to){
	from = to;
	return;
}




