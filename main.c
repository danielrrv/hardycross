
//custom header.
#include "types.h"

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


int main(int argc, char *argv[])
{
	if (2 > argc)
	{
		report("Provide a filepath");
		exit(1);
	}
	CSV *dimensions_csv = get_column_row_function(argv[1]);

	double **data = reader("data.txt", dimensions_csv->row, dimensions_csv->column);
	
	Graph *graph = createGraph(dimensions_csv->row);
	for (int i = 0; i <dimensions_csv->row; i++)
	{
		addEdge(graph, data[i][(int)node1], data[i][(int)node2], data[i][(int)rate], data[i][(int)resistence]);
	}
	printGraph(graph);

	return 0;
}


void report (const char * message){
		printf("\033[1;31mException:\033[0m %s\n", message);
}
//END OF THE SOURCE.
