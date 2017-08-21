/*
 * Custom Matrix Library - Function Prototypes
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t i;
	size_t j;
	double **matrix;
} mat_t;

void mat_malloc(mat_t *head, size_t i, size_t j);

void mat_free(mat_t *head);

void print_mat(mat_t *head);

void scale_mat(mat_t *head, double scale);

void add_mat(mat_t *h1, mat_t *h2, mat_t *sum);

void subt_mat(mat_t *h1, mat_t *h2, mat_t *diff)

#endif