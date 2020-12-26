#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

struct Node
{
	int indentifier;
	struct Coord
	{
		double x;
		double y;
	} position;
};

struct Edge
{
	double length;
	struct Node member1;
	struct Node member2;
};

struct Graph
{
	struct Node N[10];
	struct Edge E[10];
} graph;

void addEdge(struct Edge *edge, struct Edge *other)
{
	(*edge).length = (*other).length;

	return edge;
}

int main(int argc, char *argv[])
{
	struct Node node1;
	node1.indentifier = 10;
	node1.position.x = 1.2;
	node1.position.y = 1.5;

	printf("Indentifier:\t\t%d\n", node1.indentifier);
	return 0;
}