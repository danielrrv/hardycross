#include "assert.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structure.h"



void print_result(char * message){
	printf("\033[1;32mPass:\033[0m %s\n", message);	
}
void TESTCASE_create_node(void){

	Node * node = createNode(3, 3.44, 3.33);
	assert(node->vertex ==3);
	print_result("TESTCASE_create_node()");
}


void TESTCASE_create_graph(void){
	Graph * graph = createGraph(10);
	assert(graph != NULL);
	print_result("TESTCASE_create_graph()");
}



void TESTCASE_add_edges(void){
	Graph * graph = createGraph(10);
	Node * node_1 = createNode(1, 3.44, 3.33);
	Node * node_2 = createNode(2, 3.44, 3.33);
	graph->adj[0] = node_1;
	graph->adj[1] = node_2;

	Node * new_node = createNode(3, 3.44, 3.33);
	node_1->next = new_node;
	new_node->next = node_1;

	

	// addEdge(graph, 1, 2, 33.3, 4.44);
	// addEdge(graph, 2, 3, 33.3, 4.44);
	// addEdge(graph, 3, 1, 33.3, 4.44);
	printf("%d", graph->number_of_vertices);
	assert((*graph->adj)->vertex==1);
	graph->adj++;
	assert((*graph->adj)->vertex==2);
	graph->adj++;
	assert((*graph->adj)->vertex==2);
	print_result("TESTCASE_add_edges()");
}





