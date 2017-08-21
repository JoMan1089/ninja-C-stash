/*
 * MP1 - Vectors and Vector Operations
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include <stdio.h>
#include "vector.h"

bool isequal_DBL(double dbl_1, double dbl_2)
{
	if (fabs(dbl_1-dbl_2) < DBL_EPSILON) {
		return true;
	}
	return false;
}

double mag_2D(struct vector_2D_rect v_rect)
{
	double mag = sqrt(pow(v_rect.x, 2) + pow(v_rect.y, 2));
	return mag;
}

double mag_3D(struct vector_3D_rect v_rect)
{
	double mag = sqrt(pow(v_rect.x, 2) + pow(v_rect.y, 2) + pow(v_rect.z, 2));
	return mag;
}

struct vector_2D_rect scale_2D(struct vector_2D_rect v_rect, double scale_factor)
{
	v_rect.x = v_rect.x * scale_factor;
	v_rect.y = v_rect.y * scale_factor;
	return v_rect;
}

struct vector_3D_rect scale_3D(struct vector_3D_rect v_rect, double scale_factor)
{
	v_rect.x = v_rect.x * scale_factor;
	v_rect.y = v_rect.y * scale_factor;
	v_rect.z = v_rect.z * scale_factor;
	return v_rect;
}

struct vector_2D_polar convert_2D_rect_polar(struct vector_2D_rect v_rect)
{
	struct vector_2D_polar v_polar = {
		0,
		0
	};
	v_polar.r = mag_2D(v_rect);
	v_polar.theta = atan2(v_rect.y, v_rect.x);
	return v_polar;
}

struct vector_3D_cylindrical convert_3D_rect_cyl(struct vector_3D_rect v_rect)
{
	struct vector_3D_cylindrical v_cyl = {
		0,
		0,
		0
	};
	v_cyl.rho = sqrt(pow(v_rect.x, 2) + pow(v_rect.y, 2));
	if ((v_rect.x == 0) && (v_rect.y == 0)) {
		v_cyl.theta = 0;
	}
	else if (v_rect.x >= 0) {
		v_cyl.theta = asin(v_rect.y / v_cyl.rho);
	}
	else if (v_rect.x == 0) {
		v_cyl.theta = atan2(v_rect.y, v_rect.x);
	}
	else if (v_rect.x < 0) {
		v_cyl.theta = PI - asin(v_rect.y / v_cyl.rho);
	}
	v_cyl.z = v_rect.z;
	return v_cyl;
}

struct vector_3D_spherical convert_3D_rect_sph(struct vector_3D_rect v_rect)
{
	struct vector_3D_spherical v_sph = {
		0,
		0,
		0
	};
	v_sph.r = mag_3D(v_rect);
	v_sph.theta = acos(v_rect.z / v_sph.r);
	v_sph.phi = atan2(v_rect.y, v_rect.x);
	return v_sph;
}

struct vector_2D_rect sum_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2)
{
	struct vector_2D_rect v_rect_sum = {
		0,
		0
	};
	v_rect_sum.x = v_rect1.x + v_rect2.x;
	v_rect_sum.y = v_rect1.y + v_rect2.y;
	return v_rect_sum;
}

struct vector_3D_rect sum_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2)
{
	struct vector_3D_rect v_rect_sum = {
		0,
		0,
		0
	};
	v_rect_sum.x = v_rect1.x + v_rect2.x;
	v_rect_sum.y = v_rect1.y + v_rect2.y;
	v_rect_sum.z = v_rect1.z + v_rect2.z;
	return v_rect_sum;
}

struct vector_2D_rect diff_2D(struct vector_2D_rect v_rect_minu, struct vector_2D_rect v_rect_subt)
{
	struct vector_2D_rect v_rect_diff = {
		0,
		0
	};
	v_rect_diff.x = v_rect_minu.x - v_rect_subt.x;
	v_rect_diff.y = v_rect_minu.y - v_rect_subt.y;
	return v_rect_diff;
}

struct vector_3D_rect diff_3D(struct vector_3D_rect v_rect_minu, struct vector_3D_rect v_rect_subt)
{
	struct vector_3D_rect v_rect_diff = {
		0,
		0,
		0
	};
	v_rect_diff.x = v_rect_minu.x - v_rect_subt.x;
	v_rect_diff.y = v_rect_minu.y - v_rect_subt.y;
	v_rect_diff.z = v_rect_minu.z - v_rect_subt.z;
	return v_rect_diff;
}

bool isequal_vect_2D_rect(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2)
{
	if (fabs(mag_2D(diff_2D(v_rect1, v_rect2))) < DBL_EPSILON) {
		return true;
	}
	return false;
}

bool isequal_vect_3D_rect(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2)
{
	if (fabs(mag_3D(diff_3D(v_rect1, v_rect2))) < DBL_EPSILON) {
		return true;
	}
	return false;
}

struct vector_2D_rect uvect_2D(struct vector_2D_rect v_rect)
{
	if (!isequal_DBL(mag_2D(v_rect), 0)) {
		v_rect = scale_2D(v_rect, (1/mag_2D(v_rect)));
		return v_rect;
	}
	return v_rect;
}

struct vector_3D_rect uvect_3D(struct vector_3D_rect v_rect)
{
	if (!isequal_DBL(mag_3D(v_rect), 0)) {
		v_rect = scale_3D(v_rect, (1/mag_3D(v_rect)));
		return v_rect;
	}
	return v_rect;
}

double dot_prod_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2)
{
	double dot_prod = ((v_rect1.x * v_rect2.x) + (v_rect1.y * v_rect2.y));
	return dot_prod;
}

double dot_prod_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2)
{
	double dot_prod = ((v_rect1.x * v_rect2.x) + (v_rect1.y * v_rect2.y) + (v_rect1.z * v_rect2.z));
	return dot_prod;
}

double angle_2D(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2)
{
	double angle = acos(dot_prod_2D(v_rect1, v_rect2) / (mag_2D(v_rect1) * mag_2D(v_rect2)));
	return angle;
}

double angle_3D(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2)
{
	double angle = acos(dot_prod_3D(v_rect1, v_rect2) / (mag_3D(v_rect1) * mag_3D(v_rect2)));
	return angle;
}

struct vector_3D_rect cross_2D_input(struct vector_2D_rect v_rect1, struct vector_2D_rect v_rect2)
{
	struct vector_3D_rect v_cross = {
		0,
		0,
		0
	};
	v_cross.z = (v_rect1.x * v_rect2.y) - (v_rect1.y * v_rect2.x);
	return v_cross;
}

struct vector_3D_rect cross_3D_input(struct vector_3D_rect v_rect1, struct vector_3D_rect v_rect2)
{
	struct vector_3D_rect v_cross = {
		0,
		0,
		0
	};
	v_cross.x = (v_rect1.y * v_rect2.z) - (v_rect1.z * v_rect2.y);
	v_cross.y = (v_rect1.z * v_rect2.x) - (v_rect1.x * v_rect2.z);
	v_cross.z = (v_rect1.x * v_rect2.y) - (v_rect1.y * v_rect2.x);
	return v_cross;
}