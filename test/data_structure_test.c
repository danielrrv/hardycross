#include "assert.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structure.h"

void print_result(char *message)
{
	printf("\033[1;32mPass:\033[0m %s\n", message);
}


void TESTCASE_create_graph(void)
{
	Graph *graph = create_graph(10);
	assert(graph != NULL);
	free(graph);
	print_result("TESTCASE_create_graph()");
}

void TESTCASE_create_node(void)
{
	Graph *graph = create_graph(10);
	Node *node = create_node(graph, 3);
	assert(node->vertex == 3);
	assert(graph->adj[0]->vertex == 3);
	Node *node2 = create_node(graph, 2);
	assert(node2->vertex == 2);
	graph->adj++;
	assert((*graph->adj)->vertex == 2);
	
	free(node2);
	free(node);
	free(graph);
	print_result("TESTCASE_create_node()");
}

void TESTCASE_add_edges(void)
{
	Graph *graph = create_graph(10);
	Node *node_1 = create_node(graph, 1);
	Node *node_2 = create_node(graph, 2);
	Node *node_3 = create_node(graph, 3);
	Node *node_4 = create_node(graph, 4);

	add_edge(graph, node_1, node_3);
	add_edge(graph, node_1, node_4);
	add_edge(graph, node_1, node_2);

	assert((*node_1->next)->vertex==3);
	node_1->next++;
	assert((*node_1->next)->vertex==4);
	node_1->next++;
	assert((*node_1->next)->vertex==2);

	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
	// for(int i = 0; i<10; i++){
	// 	free(graph->adj[i]);
	// }
	free(graph);


	print_result("TESTCASE_add_edges()");
}



void TESTCASE_add_nodes(void)
{
	Graph *graph = create_graph(10);
	Node *node_1 = create_node(graph, 1);
	Node *node_2 = create_node(graph, 2);
	Node *node_3 = create_node(graph, 3);
	Node *node_4 = create_node(graph, 4);
	// Node *node_5 = create_node(graph, 2);

	assert(graph->adj[0]->vertex==1);
	assert(graph->adj[1]->vertex==2);
	assert(graph->adj[2]->vertex==3);
	assert(graph->adj[3]->vertex==4);

	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
	free(graph);

	print_result("TESTCASE_add_nodes()");

}

