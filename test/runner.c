#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TESTCASE_create_node(void);
// void TESTCASE_read_file(char *);
void TESTCASE_create_graph(void);
void TESTCASE_add_edges(void);
void TESTCASE_add_nodes(void);

int main(int argc, char *argv[])
{

	
	TESTCASE_create_graph();
	TESTCASE_create_node();
	TESTCASE_add_edges();
	TESTCASE_add_nodes();

	printf("All test are run successfully!\n\n");
	// printf("None is compiling");
	return 0;
}
