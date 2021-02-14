#include "types.h"





CSV *get_column_row_function(char *source)
{

	CSV *dimension_csv = (CSV *)malloc(sizeof(CSV));
	//declare a filename
	char filename[55];
	//fill it empty \0
	memset(filename, '\0', 55);

	strcpy(filename, source);
	//Implementation to get csv dimenssions.
	FILE *file = NULL;
	char buffer[1024];
	//TODO: This can fail. Add Error handling.
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "File %s: %s\n", filename, strerror(errno));
		exit(1);
	}

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
	dimension_csv->column = column;
	dimension_csv->row = row;
	return dimension_csv;
}

double **reader(char *filename,  dimension row, dimension column)
{
	

	assert(column == 4 && "Csv file does not have 4 columns");
	FILE *file = NULL;
	double **data;
	data = (double **)malloc(row * sizeof(double *));
	for (int i = 0; i < row; ++i)
	{
		data[i] = (double *)malloc(column * sizeof(double));
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "File %s: %s\n", filename, strerror(errno));
		exit(1);
	}
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
			for (tok = strtok(buffer, delim); tok != NULL && *tok; j++, tok = strtok(NULL, delim))
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