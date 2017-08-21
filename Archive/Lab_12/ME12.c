#include <stdio.h>
#include <stdlib.h>
#include "string_ext.h"
#include "safe_input.h"

#define MAXSIZE 1024

typedef struct edge {
	int dest;
	int cost;
} edge_t;

void lookup (int node, edge_t **map);

int main()
{
	FILE *fp;
	char iArr[MAXSIZE];
	
	printf("Reading adjacency list:\n");
	
	fp = fopen("maze_me12_sample1", "r");
	if(!fp) {
		printf("Error Opening File\n");
		return -1;
	}
	printf("Adjacency list read sucessfully!\n");
	
	int nodes = 0;
	//int edges = 0;
	
	if (fgets(iArr, MAXSIZE, fp) != NULL) {
		nodes = atoi( strtok(iArr, " "));
		//edges = atoi( strtok(NULL, " "));
		//printf("nodes = %d\tedges = %d\n", nodes, edges);
	}
	
	printf("Number of nodes is %d\n\n", nodes);
	
	edge_t **node_map = malloc(nodes * sizeof(edge_t));
	if (!node_map) {
		printf("Error Allocating Memory\n");
		printf("Freeing Allocated Memory\n");
		fclose(fp);
		return -1;
	}
	//printf("%zu bytes allocated\n", nodes * sizeof(edge_t));
	
	int i;
	for (i = 0; i < nodes; i++) { // initializes 2D Array with an End Of Row (EOR).
		node_map[i] = malloc(sizeof(edge_t));
		if (!node_map[i]) {
			printf("Error Allocating Memory\n");
			printf("Freeing Allocated Memory\n");
			free(node_map);
			fclose(fp);
			return -1;
		}
		//printf("%zu bytes allocated\n", sizeof(edge_t));
		node_map[i][0].dest = i; //EOR.dest = source
		node_map[i][0].cost = 0; //EOR.cost = elements in row
		//printf("[%d][0].dest = %d\t\t[%d][0].cost = %d\n", i, node_map[i][0].dest, i, node_map[i][0].cost);
	}
	
	for(;fgets(iArr, MAXSIZE, fp) != NULL;) {
		int src = atoi( strtok(iArr, " "));
		int dest = atoi( strtok(NULL, " "));
		int cost = atoi( strtok(NULL, " "));
		//printf("S-D-C: %d-%d-%d\n", src, dest, cost);
		int ctr;
		for (ctr = 0; ctr < 2; ctr++) {
			for (i = 0; node_map[src][i].dest != src; i++); // finds End Of Row
			//printf("[%d][%d].dest = %d\t\t[%d][%d].cost = %d\n", src, i, node_map[src][i].dest, src, i, node_map[src][i].cost);

			int end_i = i; //Stores EOR position

			edge_t *tmp_p = realloc(node_map[src], (node_map[src][end_i].cost + 2) * sizeof(edge_t)); //resizes row
			if (!tmp_p) {
				printf("Reallocation Failed\n");
				printf("Freeing Allocated Memory\n");
				for (i = 0; i < nodes; i++)
					free(node_map[i]);
				free(node_map);
				fclose(fp);
				return -1;
			}
			//printf("%zu bytes allocated\n", (node_map[src][end_i].cost + 1) * sizeof(edge_t));
			node_map[src] = tmp_p;
			tmp_p = NULL;

			node_map[src][end_i + 1].dest = node_map[src][end_i].dest; //EOR.dest = source
			node_map[src][end_i + 1].cost = node_map[src][end_i].cost + 1; //EOR.cost = elements in row
			node_map[src][end_i].dest = dest;
			node_map[src][end_i].cost = cost;
			//printf("[%d][%d].dest = %d\t\t[%d][%d].cost = %d\n", src, end_i, node_map[src][end_i].dest, src, end_i, node_map[src][end_i].cost);
			//printf("[%d][%d].dest = %d\t\t[%d][%d].cost = %d\n", src, end_i + 1, node_map[src][end_i + 1].dest, src, end_i + 1, node_map[src][end_i + 1].cost);

			int tmp_i = 0;
			tmp_i = src; // Bi-directional functionality. Switch src & dest
			src = dest;
			dest = tmp_i;
		}
	}
	
	for (;strncmp(iArr, "Exit", sizeof("Exit"));) {
		printf("Enter a node to examine (Presss Ctrl+C or enter \"Exit\" to exit): ");
		int num = 0;
		get_input(iArr, MAXSIZE);
		num = atoi(iArr);
		if ((num >= 0) && (num < nodes)) {
			lookup(num, node_map);
		}
		else if (!strncmp(iArr, "Exit", sizeof("Exit"))) {
			break;
		}
		else {
			printf("Out of bounds: Please input a value between 0 and %d", nodes - 1);
		}
		string_toproper(iArr, strlen(iArr));
		printf("\n");
	}
	
	printf("Freeing Allocated Memory\n");
	for (i = 0; i < nodes; i++)
		free(node_map[i]);
	free(node_map);
	fclose(fp);
	
	return 0;
}

void lookup (int node, edge_t **map)
{
	printf("Neigbors of node %d are:\n", node);
	int i = 0;
	for (i = 0; map[node][i].dest != node; i++) {
		printf("Node %d with edge cost %d\n", map[node][i].dest, map[node][i].cost);
	}
	printf("--END\n");
}