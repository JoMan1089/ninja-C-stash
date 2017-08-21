/*
 * MP1 - Vectors and Vector Operations
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>
#include <float.h>
#include <stdbool.h>

#define PI 3.14159265359

struct vector_2D_rect {
        double x;
        double y;
};

struct vector_2D_polar {
        double r;
        double theta;
};

struct vector_3D_rect {
        double x;
        double y;
        double z;
};

struct vector_3D_cylindrical {
        double rho;
        double theta;
        double z;
};

struct vector_3D_spherical {
        double r;
        double theta;
        double phi;
};

bool isequal_DBL(double dbl_1, double dbl_2);

bool isequal_vect_2D_rect(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2);

bool isequal_vect_3D_rect(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2);

double mag_2D(struct vector_2D_rect v_rect);

double mag_3D(struct vector_3D_rect v_rect);

double dot_prod_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2);

double dot_prod_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2);

double angle_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2);

double angle_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2);

struct vector_3D_rect cross_2D_input(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2);

struct vector_3D_rect cross_3D_input(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2);

struct vector_2D_rect scale_2D(struct vector_2D_rect vrect, double scale_factor);

struct vector_3D_rect scale_3D(struct vector_3D_rect vrect, double scale_factor);

struct vector_2D_polar convert_2D_rect_polar(struct vector_2D_rect v_rect);

struct vector_3D_cylindrical convert_3D_rect_cyl(struct vector_3D_rect v_rect);

struct vector_3D_spherical convert_3D_rect_sph(struct vector_3D_rect v_rect);

struct vector_2D_rect sum_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2);

struct vector_3D_rect sum_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2);

struct vector_2D_rect diff_2D(struct vector_2D_rect v_rect_minu, struct vector_2D_rect v_rect_subt);

struct vector_3D_rect diff_3D(struct vector_3D_rect v_rect_minu, struct vector_3D_rect v_rect_subt);

struct vector_2D_rect uvect_2D(struct vector_2D_rect v_rect);

struct vector_3D_rect uvect_3D(struct vector_3D_rect v_rect);

#endif