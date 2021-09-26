
//custom header.
#include "types.h"
#include "data_structure.h"
#include "file.h"




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
