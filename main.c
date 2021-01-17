#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//custom header.
#include "types.h"


//Implementation to create Nodes
Node *createNode(int V, double rate, float resistence)
{
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
	graph->numberOfVertices = V;
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
		printf("\n Vertex %d: ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
};

//Declarations
//Declaration to read csv file or comma-delimited files.
double **reader(char *, size_t, size_t);
void report(const char * message);

int main(int argc, char *argv[])
{
	//declare a filename
	char filename[55];
	//fill it empty \0
	memset(filename,'\0', 55);
	if(2 > argc){
		report("Provide a filepath");
		return EXIT_FAILURE;
	}
	strcpy(filename, argv[1]);
	//Implementation to get csv dimenssions.
	FILE *file;
	char buffer[1024];
	//TODO: This can fail. Add Error handling.
	file = fopen(filename, "r");
	dimension column;
	for (int i = 0; fgets(buffer, 1024, file); i++)
		;
	const char *tok;
	const char *delim = ",";
	int j = 0;
	tok = strtok(buffer, delim);
	while (tok != NULL)
	{
		tok = strtok(NULL, delim);
		column = ++j;
	}

	dimension row = sizeof(file) - 1;
	fclose(file);
	double **data = reader("data.txt", row, column);
	Graph *graph = createGraph(row);
	for (int i = 0; i < row; i++)
	{
		addEdge(graph, data[i][(int)node1], data[i][(int)node2], data[i][(int)rate], data[i][(int)resistence]);
	}
	printGraph(graph);

	return 0;
}

double **reader(char *filename, dimension row, dimension column)
{

	FILE *file;
	double **data;
	data = (double **)malloc(row * sizeof(double *));
	for (int i = 0; i < row; ++i)
	{
		data[i] = (double *)malloc(column * sizeof(double));
	}
	file = fopen(filename, "r");
	char buffer[1024];
	int i = 0;
	for (; fgets(buffer, 1024, file) && (i < row);)
	{
		char *tmp = strdup(buffer);
		if (i > 0)
		{
			int j = 0;
			const char *tok;
			char delim[] = {","};
			for (tok = strtok(buffer, delim); tok!=NULL && *tok; j++, tok = strtok(NULL, delim))
			{
				data[i][j] = atof(tok);
				printf("%.2f\t", data[i][j]);
			}
			printf("\n");
		}
		free(tmp);
		i++;
	}
	fclose(file);
	return data;
}

void report (const char * message){
		printf("\033[1;31mException:\033[0m %s\n", message);
}
//END OF THE SOURCE.
