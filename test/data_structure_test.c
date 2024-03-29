#include "assert.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structure.h"
// #include "../no_allocate.h"

void print_result(char *message)
{
	printf("\033[1;32mPass:\033[0m %s\n", message);
}

void TESTCASE_create_graph(void)
{
	graph_t *graph = create_graph(10);
	assert(graph != NULL);
	free(graph);
	print_result("TESTCASE_create_graph()");
}

void TESTCASE_create_node(void)
{
	graph_t *graph = create_graph(10);
	node_t *node = create_node(graph, 3);
	assert(node->vertex == 3);
	assert(graph->adj[0]->vertex == 3);
	node_t *node2 = create_node(graph, 2);
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
	graph_t *graph = create_graph(10);
	node_t *node_1 = create_node(graph, 1);
	node_t *node_2 = create_node(graph, 2);
	node_t *node_3 = create_node(graph, 3);
	node_t *node_4 = create_node(graph, 4);

	add_edge(graph, node_1, node_3);
	add_edge(graph, node_1, node_4);
	add_edge(graph, node_1, node_2);

	assert((*node_1->next)->vertex == 3);
	node_1->next++;
	assert((*node_1->next)->vertex == 4);
	node_1->next++;
	assert((*node_1->next)->vertex == 2);

	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
	free(graph);

	print_result("TESTCASE_add_edges()");
}

void TESTCASE_add_nodes(void)
{
	graph_t *graph = create_graph(10);
	node_t *node_1 = create_node(graph, 1);
	node_t *node_2 = create_node(graph, 2);
	node_t *node_3 = create_node(graph, 3);
	node_t *node_4 = create_node(graph, 4);
	// Node *node_5 = create_node(graph, 2);

	assert(graph->adj[0]->vertex == 1);
	assert(graph->adj[1]->vertex == 2);
	assert(graph->adj[2]->vertex == 3);
	assert(graph->adj[3]->vertex == 4);

	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
	free(graph);

	print_result("TESTCASE_add_nodes()");
}

void TESTCASE_create_edge()
{
	graph_t *graph = create_graph(10);
	node_t *node_1 = create_node(graph, 1);
	node_t *node_2 = create_node(graph, 2);
	node_t *node_3 = create_node(graph, 3);
	node_t *node_4 = create_node(graph, 4);
	data_t *data = malloc(sizeof(data_t));
	data->rate = 0.13;
	data->resistence = 0.345;

	edge_t *edge = create_edge(graph, node_1, node_2, data);
	printf("value:%d\n", (*edge->nodes[0]).vertex);
	assert((*edge->nodes[0]).vertex == node_1->vertex);
	assert((*edge->nodes[1]).vertex == node_2->vertex);
	assert(graph->edges[0]->data->resistence > 0);

	edge_t *edge1 = create_edge(graph, node_4, node_3, data);
	assert(edge1->nodes[0]->vertex == node_4->vertex);
	assert(edge1->nodes[1]->vertex == node_3->vertex);
	assert(graph->edges[1]->data->resistence > 0);

	free(data);
	free(edge1);
	free(edge);
	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
	free(graph);
	print_result("TESTCASE_create_edge()");
}
