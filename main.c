#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

struct Node
{
	int vertex;
	struct Node *next;
};
struct Node *createNode(int V)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->vertex = V;
	node->next = NULL;
	return node;
};
struct Graph
{
	int numberOfVertices;
	struct Node **adj;
};
struct Graph *createGraph(int V)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->numberOfVertices = V;
	graph->adj = (struct Node **)malloc(V * sizeof(struct Node));
	int i;
	for (i = 0; i < V; i++)
	{
		graph->adj[i] = NULL;
	}
	return graph;
};

void addEdge(struct Graph *graph, int src, int dest)
{
	// Add edge from s to d
	struct Node *newNode = createNode(dest);
	newNode->next = graph->adj[src];
	graph->adj[src] = newNode;

	// Add edge from d to s
	newNode = createNode(src);
	newNode->next = graph->adj[dest];
	graph->adj[dest] = newNode;
};

void printGraph(struct Graph *graph)
{
	int v;
	for (v = 0; v < graph->numberOfVertices; v++)
	{
		struct Node *temp = graph->adj[v];
		printf("\n Vertex %d\n: ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
};

int main(int argc, char *argv[])
{
	struct Graph *graph = createGraph(8);
	addEdge(graph, 2, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 5);
	addEdge(graph, 7, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 8, 4);
	printGraph(graph);
	//printf("Indentifier:\t\t%d\n", node1.indentifier);
	return 0;
}