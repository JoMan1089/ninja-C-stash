/*
 * Custom Matrix Library - Function Definitions
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include "matrix.h"

void mat_malloc(mat_t *head, size_t i, size_t j)
{
	head->i = i;
	head->j = j;
	head->matrix = malloc(i * sizeof(double *));
	//printf("%zu bytes allocated\n", i * sizeof(double *));
	if (!head->matrix) {
		printf("Allocation Failed\n");
		return;
	}
	size_t ctr;
	for (ctr = 0; ctr < i; ctr++) {
		//printf("ctr = %zu\n", ctr);
		head->matrix[ctr] = malloc(j * sizeof(double));
		//printf("%zu bytes allocated\n", j * sizeof(double));
		if (!head->matrix[ctr]) {
			printf("Allocation Failed\n");
			return;
		}
	}
	return;
}

void mat_free(mat_t *head)
{
	size_t ctr;
	for (ctr = 0; ctr < head->i; ctr++) {
		free(head->matrix[ctr]);
		head->matrix[ctr] = NULL;
	}
	free(head->matrix);
	head->matrix = NULL;
	head->i = 0;
	head->j = 0;
}

void print_mat(mat_t *head){
	size_t i, j;
	printf("MATRIX: i = %zu, j = %zu, Address = %p\n", head->i, head->j, head->matrix);
	for (i = 0; i < head->i; i++) {
		for (j = 0; j < head->j; j++) {
			printf ("%7.2lf ", head->matrix[i][j]);
		}
		printf("\n");
	}
}

void scale_mat(mat_t *head, double scale)
{
	size_t i, j;
	for (i = 0; i < head->i; i++) {
		for (j = 0; j < head->j; j++) {
			head->matrix[i][j] = head->matrix[i][j] * scale;
		}
	}
}

void add_mat(mat_t *h1, mat_t *h2, mat_t *sum)
{
	if ( !((h1->i == h2->i) && (h1->j == h2->j)) ){
		printf("Error: Cannot add, matrices not the same size.\n");
		return;
	}
	size_t i, j;
	for (i = 0; i < h1->i; i++) {
		for (j = 0; j < h1->j; j++) {
			sum->matrix[i][j] = h1->matrix[i][j] + h2->matrix[i][j];
		}
	}
	return;
}

void subt_mat(mat_t *h1, mat_t *h2, mat_t *diff)
{
	if ( !((h1->i == h2->i) && (h1->j == h2->j)) ){
		printf("Error: Cannot add, matrices not the same size.\n");
		return;
	}
	size_t i, j;
	for (i = 0; i < h1->i; i++) {
		for (j = 0; j < h1->j; j++) {
			diff->matrix[i][j] = h1->matrix[i][j] - h2->matrix[i][j];
		}
	}
	return;
}