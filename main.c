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


double **reader(char *, size_t *, size_t *);
int main(int argc, char *argv[])
{

	FILE *file;
	char buffer[1024];
	file = fopen("data.txt", "r");
	size_t column;
	for (int i = 0; fgets(buffer, 1024, file); i++)
		;
	const char *tok;
	char delim[] = {","};
	int j = 0;
	tok = strtok(buffer, delim);
	while (tok != NULL)
	{
		//printf("\nToken : %s\n", tok);
		tok = strtok(NULL, delim);
		column = ++j;
	}

	size_t row = sizeof(file) - 1;
	double **data = reader("data.txt", &row, &column);
	Graph *graph = createGraph(column);
	addEdge(graph, 2, 4, 1, 0.323);
	addEdge(graph, 1, 3, 1, 0.4);
	addEdge(graph, 2, 5, 32.3, 0.05);
	addEdge(graph, 7, 2, 32.3, 0.05);
	addEdge(graph, 1, 3, 32.3, 0.05);
	addEdge(graph, 8, 4, 32.3, 0.05);
	//printGraph(graph);

	return 0;
}

double **reader(char *filename, size_t *row, size_t *column)
{

	FILE *file;
	double **data;
	data = (double **)malloc((*row) * sizeof(double *));
	for (int i = 0; i < (*row); ++i)
	{
		data[i] = (double *)malloc((*column) * sizeof(double));
	}
	file = fopen(filename, "r");
	char buffer[1024];
	int i = 0;
	for (; fgets(buffer, 1024, file) && (i < (*row));)
	{
		char *tmp = strdup(buffer);
		if (i > 0)
		{
			int j = 0;
			const char *tok;
			char delim[] = {","};
			for (tok = strtok(buffer, delim); tok && *tok; j++, tok = strtok(NULL, delim))
			{
				data[i][j] = atof(tok);
				printf("%f\t", data[i][j]);
			}
			printf("\n");
		}

		free(tmp);
		i++;
	}
	return data;
}
