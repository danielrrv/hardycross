#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include <math.h>
//#include <string.h>
//#include <float.h>
//#include <time.h>

typedef struct Node
{
	int vertex;
	struct Node *next;
	double rate;
	float resistence;
} Node;

Node *createNode(int V, double rate, float resistence)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->vertex = V;
	node->rate = rate;
	node->resistence = resistence;
	node->next = NULL;
	return node;
};
typedef struct Graph
{
	int numberOfVertices;
	Node **adj; //<--pointer of Node and defined as pointer array too.
} Graph;

Graph *createGraph(int V)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->numberOfVertices = V;
	graph->adj = (Node **)malloc(V * sizeof(Node));
	int i;
	for (i = 0; i < V; i++)
		graph->adj[i] = NULL;
	return graph;
};

void addEdge(Graph *graph, int src, int dest, double rate, float resistence)
{
	// Add edge from s to d
	Node *newNode = createNode(dest, rate, resistence);
	newNode->next = graph->adj[src];

	graph->adj[src] = newNode;

	// Add edge from d to s
	newNode = createNode(src, rate, resistence);
	newNode->next = graph->adj[dest];

	graph->adj[dest] = newNode;
};

void printGraph(Graph *graph)
{
	int v;
	for (v = 0; v < graph->numberOfVertices; v++)
	{
		Node *temp = graph->adj[v];
		printf("\n Vertex %d\n: ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
};

//!TODO:Reactivate after get csv dimmensions
double **reader(char *);
int main(int argc, char *argv[])
{
	struct Graph *graph = createGraph(8);
	addEdge(graph, 2, 4, 1, 0.323);
	addEdge(graph, 1, 3, 1, 0.4);
	addEdge(graph, 2, 5, 32.3, 0.05);
	addEdge(graph, 7, 2, 32.3, 0.05);
	addEdge(graph, 1, 3, 32.3, 0.05);
	addEdge(graph, 8, 4, 32.3, 0.05);
	printGraph(graph);

	FILE *file;
	char buffer[1024];
	const char* header;
	file = fopen("data.txt", "r");
	size_t row;
	for (int i = 0; fgets(buffer, 1024, file); i++)
	{
		header = buffer; 
		printf("line %d:\t%s", i, buffer);
	}
	const char *tok;
	const char delim[2] = ",";
	int j = 0;
	while(tok = strtok(header, delim))
	{
		if(tok != NULL)break;
		
		printf("\nToken : %s\n", tok);
		tok = strtok(NULL, header);
		row = ++j;
	}

	size_t len = sizeof(file);
	printf("%ld\n", len);
	printf("%ld", row);
	return 0;
}
//!TODO:Reactivate after get csv dimmensions
double **reader(char *filename)
{

	FILE *file;
	double **data;
	data = (double *)malloc(3 * sizeof(double *));
	for (int i=0;i < )
	file = fopen(filename, "r");

	char buffer[1024];
	int i = 0;
	for (; fgets(buffer, 1024, file) && (i < row);)
		;

	return data;
}
