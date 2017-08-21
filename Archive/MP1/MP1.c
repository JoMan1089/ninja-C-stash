/*
 * MP1 - Vectors and Vector Operations
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include <unistd.h>
#include "safe_input.h"
#include "vector.h"

#define INPUT_ARRAY_MAX 16
#define EXIT_CMD "Exit"
#define MENU_CMD "Menu"
#define FBD_MAX_VECTORS 8
#define SLEEP_TIME 0

#define TEST_NUM_MAX 999999999999999 // highest possible 15 digit number
#define TEST_NUM_MIN -99999999999999 // lowest possible 15 digit number

void display_menu(void);
void select_2D_3D(char iArr[], size_t size, void (*fnc_2D)(char iArr[], size_t), void (*fnc_3D)(char iArr[], size_t));
void choose_option(char iArr[], size_t size);
struct vector_2D_rect get_2D_vector(char iArr[], size_t size);
struct vector_3D_rect get_3D_vector(char iArr[], size_t size);
void model_2D(char iArr[], size_t size);
void model_3D(char iArr[], size_t size);
void display_mag_2D(char iArr[], size_t size);
void display_mag_3D(char iArr[], size_t size);
void display_sum_2D(char iArr[], size_t size);
void display_sum_3D(char iArr[], size_t size);
void display_diff_2D(char iArr[], size_t size);
void display_diff_3D(char iArr[], size_t size);
void display_uvect_2D(char iArr[], size_t size);
void display_uvect_3D(char iArr[], size_t size);
void display_scale_2D(char iArr[], size_t size);
void display_scale_3D(char iArr[], size_t size);
void display_dot_prod_2D(char iArr[], size_t size);
void display_dot_prod_3D(char iArr[], size_t size);
void display_angle_2D(char iArr[], size_t size);
void display_angle_3D(char iArr[], size_t size);
void display_cross_prod_2D(char iArr[], size_t size);
void display_cross_prod_3D(char iArr[], size_t size);
void display_FBD_2D(char iArr[], size_t size);
void display_FBD_3D(char iArr[], size_t size);

int main()
{
	char inputArr[INPUT_ARRAY_MAX];
	display_menu();
	for (;(strncmp(inputArr, EXIT_CMD, strlen(EXIT_CMD)) != 0);) {
		if (strncmp(inputArr, MENU_CMD, strlen(MENU_CMD)) == 0) {
			display_menu();
		}
		printf("\nWhat do you want to do?\n");
		get_input(inputArr, sizeof(inputArr));
		string_toproper(inputArr, strlen(inputArr));
			// Test code
			char testArr1[] = "sAmPle";
			string_toproper(testArr1, strlen(testArr1));
			assert(strncmp(testArr1,"Sample",strlen(testArr1)) == 0);
			// End Test code
		if (strncmp(inputArr, EXIT_CMD, strlen(EXIT_CMD)) == 0) {
			return 0;
		}
		if (strlen(inputArr) == 1) {
			choose_option(inputArr, sizeof(inputArr));
		}
		else {
			printf("Please Input a single character from \"A - J\"\n");
			printf("Enter \"Menu\" to display the Menu\n");
			printf("Enter \"Exit\" to Exit the program\n");
		}
	}
	return 0;
}


void display_menu(void)
{
	printf("MP1: Vectors and Vector Operations\n\n");
	printf("What do you want to do? Type \"Exit\" to terminate the program.\n");
	printf("[A] Display a Vector in Different Coordinate Systems\n");
	printf("[B] Display the Magnitude of a Vector\n");
	printf("[C] Determine the Sum of Two Vectors\n");
	printf("[D] Determine the Difference of Two Vectors\n");
	printf("[E] Determine the Unit Vector of a Given Vector\n");
	printf("[F] Scale a Vector\n");
	printf("[G] Determine the Dot Product of Two Vectors\n");
	printf("[H] Determine the Angle Between Two Vectors\n");
	printf("[I] Determine the Cross Product of Two Vectors\n");
	printf("[J] Determine if a Given Free Body Diagram is in Equilibrium\n");
}

void select_2D_3D(char iArr[], size_t size, void (*fnc_2D)(char iArr[], size_t), void (*fnc_3D)(char iArr[], size_t))
{
	for (;(strncmp(iArr, EXIT_CMD, strlen(EXIT_CMD)) && (strncmp(iArr, MENU_CMD, strlen(MENU_CMD))));) {
		printf("2D or 3D?\n");
		get_input(iArr, size);
		string_toproper(iArr, strlen(iArr));
		if (strncmp(iArr, EXIT_CMD, strlen(EXIT_CMD)) == 0) {
			return;
		}
		if (iArr[0] == '2') {
			printf("You selected 2D\n");
			(*fnc_2D)(iArr, size);
			sleep(SLEEP_TIME);
			strncpy(iArr, MENU_CMD, strlen(MENU_CMD));
		}
		else if (iArr[0] == '3') {
			printf("You selected 3D\n");
			(*fnc_3D)(iArr, size);
			sleep(SLEEP_TIME);
			strncpy(iArr, MENU_CMD, strlen(MENU_CMD));
		}
		else {
			printf("Please Input \"2\" or \"3\"\n");
			printf("Enter \"Menu\" to return to the menu\n");
			printf("Enter \"Exit\" to Exit the program\n");
		}
	}
}

void choose_option(char iArr[], size_t size) 
{
	switch (toupper(iArr[0])) {
		case 'A':
			printf("Display a Vector in Different Coordinate Systems\n");
			select_2D_3D(iArr, size, model_2D, model_3D);
			break;
		case 'B':
			printf("Display the Magnitude of a Vector\n");
			
			select_2D_3D(iArr, size, display_mag_2D, display_mag_3D);
			break;
		case 'C':
			printf("Determine the Sum of Two Vectors\n");
			select_2D_3D(iArr, size, display_sum_2D, display_sum_3D);
			break;
		case 'D':
			printf("Determine the Difference of Two Vectors\n");
			select_2D_3D(iArr, size, display_diff_2D, display_diff_3D);
			break;
		case 'E':
			printf("Determine the Unit Vector of the Given Vector\n");
			select_2D_3D(iArr, size, display_uvect_2D, display_uvect_3D);
			break;
		case 'F':
			printf("Scale a Vector\n");
			select_2D_3D(iArr, size, display_scale_2D, display_scale_3D);
			break;
		case 'G':
			printf("Determine Dot Product of two Vectors\n");
			select_2D_3D(iArr, size, display_dot_prod_2D, display_dot_prod_3D);
			break;
		case 'H':
			printf("Determine the Angle Between two Vectors\n");
			select_2D_3D(iArr, size, display_angle_2D, display_angle_3D);
			break;
		case 'I':
			printf("Determine the Cross Product of Two Vectors\n");
			select_2D_3D(iArr, size, display_cross_prod_2D, display_cross_prod_3D);
			break;
		case 'J':
			printf("Determine if a Given Free Body Diagram is in Equilibrium\n");
			select_2D_3D(iArr, size, display_FBD_2D, display_FBD_3D);
			break;
		default:
			printf("Please Input a valid menu item (A - J)\n");
			printf("Enter \"Exit\" to Exit the program\n");
			break;
	}
	return;
}

struct vector_2D_rect get_2D_vector(char iArr[], size_t size)
{
	struct vector_2D_rect rect_vector = {
		0,
		0
	};
	short i;
	printf("Input a 2D Vector in Rectangular Coordinates\n");
	for (i = 0; i <= 1;) { // gets i + 1 inputs
		get_input(iArr, size);
		string_toproper(iArr, strlen(iArr));
		if (string_isradix(iArr, string_len(iArr, size))) {
			if (i == 0) {
				rect_vector.x = atof(iArr);
			}
			else if (i == 1) {
				rect_vector.y = atof(iArr);
			}
			i++;
		}
		else {
			printf("Input is not a number please try again.\n");
			printf("Input a Vector in Rectangular Coordinates\n");
		}
	}
	return rect_vector;
}

struct vector_3D_rect get_3D_vector(char iArr[], size_t size)
{
	struct vector_3D_rect rect_vector = {
		0,
		0,
		0,
	};
	short i;
	printf("Input a 3D Vector in Rectangular Coordinates\n");
	for (i = 0; i <= 2;) { // gets i + 1 inputs
		get_input(iArr, size);
		string_toproper(iArr, strlen(iArr));
		if (string_isradix(iArr, string_len(iArr, size))) {
			if (i == 0) {
				rect_vector.x = atof(iArr);
			}
			else if (i == 1) {
				rect_vector.y = atof(iArr);
			}
			else if (i == 2) {
				rect_vector.z = atof(iArr);
			}
			i++;
		}
		else {
			printf("Input is not a number please try again.\n");
			printf("Input a Vector in Rectangular Coordinates\n");
		}
	}
	return rect_vector;
}

void model_2D(char iArr[], size_t size)
{
	struct vector_2D_rect rect_vector = get_2D_vector(iArr, size);
	printf("You input the Vector <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
	struct vector_2D_polar polar_vector = convert_2D_rect_polar(rect_vector);
	printf("Your Vector <%.2lf, %.2lf> is <%.2lf, %.2lf> in Rectangular Form\n", rect_vector.x, rect_vector.y, rect_vector.x, rect_vector.y);
	printf("Your Vector <%.2lf, %.2lf> is <%lf, %lf> in Polar Form\n\n", rect_vector.x, rect_vector.y, polar_vector.r, polar_vector.theta);
}

void model_3D(char iArr[], size_t size)
{
	struct vector_3D_rect rect_vector = get_3D_vector(iArr, size);
	printf("You input the Vector <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
	struct vector_3D_cylindrical cyl_vector = convert_3D_rect_cyl(rect_vector);
	struct vector_3D_spherical sph_vector = convert_3D_rect_sph(rect_vector);
	printf("Your Vector <%.2lf, %.2lf, %.2lf> is <%.2lf, %.2lf, %.2lf> in Rectangular Form\n", rect_vector.x, rect_vector.y, rect_vector.z, rect_vector.x, rect_vector.y, rect_vector.z);
	printf("Your Vector <%.2lf, %.2lf, %.2lf> is <%lf, %lf, %lf> in Cylindrical Form\n", rect_vector.x, rect_vector.y, rect_vector.z, cyl_vector.rho, cyl_vector.theta, cyl_vector.z);
	printf("Your Vector <%.2lf, %.2lf, %.2lf> is <%lf, %lf, %lf> in Spherical Form\n\n", rect_vector.x, rect_vector.y, rect_vector.z, sph_vector.r, sph_vector.theta, sph_vector.phi);
	
}

void display_mag_2D(char iArr[], size_t size)
{
	struct vector_2D_rect rect_vector = get_2D_vector(iArr, size);
	double mag = mag_2D(rect_vector);
	printf("You input the Vector <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
	printf("The Magnitude of your Vector is %lf\n\n", mag);
}

void display_mag_3D(char iArr[], size_t size)
{
	struct vector_3D_rect rect_vector = get_3D_vector(iArr, size);
	double mag = mag_3D(rect_vector);
	printf("You input the Vector <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
	printf("The Magnitude of your Vector is %lf\n\n", mag);
}

void display_sum_2D(char iArr[], size_t size)
{
	printf("Vector 1:\n");
	struct vector_2D_rect rect_vector1 = get_2D_vector(iArr, size);
	printf("Vector 2:\n");
	struct vector_2D_rect rect_vector2 = get_2D_vector(iArr, size);
	struct vector_2D_rect rect_vector_sum = sum_2D(rect_vector1, rect_vector2);
	printf("The sum of Vectors <%.2lf, %.2lf> and <%.2lf, %.2lf> is <%.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector2.x, rect_vector2.y, rect_vector_sum.x, rect_vector_sum.y);
}

void display_sum_3D(char iArr[], size_t size)
{
	printf("Vector 1:\n");
	struct vector_3D_rect rect_vector1 = get_3D_vector(iArr, size);
	printf("Vector 2:\n");
	struct vector_3D_rect rect_vector2 = get_3D_vector(iArr, size);
	struct vector_3D_rect rect_vector_sum = sum_3D(rect_vector1, rect_vector2);
	printf("The sum of Vectors <%.2lf, %.2lf, %.2lf> and <%.2lf, %.2lf, %.2lf> is <%.2lf, %.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector1.z, rect_vector2.x, rect_vector2.y, rect_vector2.z, rect_vector_sum.x, rect_vector_sum.y, rect_vector_sum.z);
}

void display_diff_2D(char iArr[], size_t size)
{
	printf("Vector 1:\n");
	struct vector_2D_rect rect_vector1 = get_2D_vector(iArr, size);
	printf("Vector 2:\n");
	struct vector_2D_rect rect_vector2 = get_2D_vector(iArr, size);
	struct vector_2D_rect rect_vector_diff = diff_2D(rect_vector1, rect_vector2);
	printf("The difference of Vectors <%.2lf, %.2lf> and <%.2lf, %.2lf> is <%.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector2.x, rect_vector2.y, rect_vector_diff.x, rect_vector_diff.y);
}

void display_diff_3D(char iArr[], size_t size)
{
	printf("Vector 1:\n");
	struct vector_3D_rect rect_vector1 = get_3D_vector(iArr, size);
	printf("Vector 2:\n");
	struct vector_3D_rect rect_vector2 = get_3D_vector(iArr, size);
	struct vector_3D_rect rect_vector_diff = diff_3D(rect_vector1, rect_vector2);
	printf("The difference of Vectors <%.2lf, %.2lf, %.2lf> and <%.2lf, %.2lf, %.2lf> is <%.2lf, %.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector1.z, rect_vector2.x, rect_vector2.y, rect_vector2.z, rect_vector_diff.x, rect_vector_diff.y, rect_vector_diff.z);
}

void display_uvect_2D(char iArr[], size_t size)
{
	struct vector_2D_rect rect_vector = get_2D_vector(iArr, size);
	if (!isequal_DBL(mag_2D(rect_vector), 0)) {
		struct vector_2D_rect unit_rect_vector = uvect_2D(rect_vector);
		printf("You input the Vector <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
		printf("Its corresponding Unit Vector is <%lf, %lf>\n\n", unit_rect_vector.x, unit_rect_vector.y);
	}
	else {
		printf("You input the Vector <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
		printf("The Zero Vector has no corresponding Unit Vector\n\n");
	}
	
}

void display_uvect_3D(char iArr[], size_t size)
{
	struct vector_3D_rect rect_vector = get_3D_vector(iArr, size);
	if (!isequal_DBL(mag_3D(rect_vector), 0)) {
		struct vector_3D_rect unit_rect_vector = uvect_3D(rect_vector);
		printf("You input the Vector <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
		printf("Its corresponding Unit Vector is <%lf, %lf, %lf>\n\n", unit_rect_vector.x, unit_rect_vector.y, unit_rect_vector.z);
	}
	else {
		printf("You input the Vector <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
		printf("The Zero Vector has no corresponding Unit Vector\n\n");
	}
}

void display_scale_2D(char iArr[], size_t size)
{
	struct vector_2D_rect rect_vector = get_2D_vector(iArr, size);
	printf("You input the Vector <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
	printf("Input Scale Factor\n");
	get_input(iArr, size);
	double scale = atof(iArr);
	rect_vector = scale_2D(rect_vector, scale);
	printf("The Scaled version is <%.2lf, %.2lf>\n", rect_vector.x, rect_vector.y);
}

void display_scale_3D(char iArr[], size_t size)
{
	struct vector_3D_rect rect_vector = get_3D_vector(iArr, size);
	printf("You input the Vector <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
	printf("Input Scale Factor\n");
	get_input(iArr, size);
	double scale = atof(iArr);
	rect_vector = scale_3D(rect_vector, scale);
	printf("The Scaled version is <%.2lf, %.2lf, %.2lf>\n", rect_vector.x, rect_vector.y, rect_vector.z);
}

void display_dot_prod_2D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_2D_rect rect_vector1 = get_2D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_2D_rect rect_vector2 = get_2D_vector(iArr, size);
	double dot_prod = dot_prod_2D(rect_vector1, rect_vector2);
	printf("The Dot Product of Vectors <%.2lf, %.2lf> and <%.2lf, %.2lf> is %lf\n", rect_vector1.x, rect_vector1.y, rect_vector2.x, rect_vector2.y, dot_prod);
	
}
void display_dot_prod_3D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_3D_rect rect_vector1 = get_3D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_3D_rect rect_vector2 = get_3D_vector(iArr, size);
	double dot_prod = dot_prod_3D(rect_vector1, rect_vector2);
	printf("The Dot Product of Vectors <%.2lf, %.2lf, %.2lf> and <%.2lf, %.2lf, %.2lf> is %lf\n", rect_vector1.x, rect_vector1.y, rect_vector1.z, rect_vector2.x, rect_vector2.y, rect_vector2.z, dot_prod);
}


void display_angle_2D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_2D_rect rect_vector1 = get_2D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_2D_rect rect_vector2 = get_2D_vector(iArr, size);
	double angle = angle_2D(rect_vector1, rect_vector2);
	printf("The Angle Between <%.2lf, %.2lf> and <%.2lf, %.2lf> is %lf\n", rect_vector1.x, rect_vector1.y, rect_vector2.x, rect_vector2.y, angle);
}

void display_angle_3D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_3D_rect rect_vector1 = get_3D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_3D_rect rect_vector2 = get_3D_vector(iArr, size);
	double angle = angle_3D(rect_vector1, rect_vector2);
	printf("The Angle Between <%.2lf, %.2lf, %.2lf> and <%.2lf, %.2lf, %.2lf> is %lf\n", rect_vector1.x, rect_vector1.y, rect_vector1.z, rect_vector2.x, rect_vector2.y, rect_vector2.z, angle);	
}

void display_cross_prod_2D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_2D_rect rect_vector1 = get_2D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_2D_rect rect_vector2 = get_2D_vector(iArr, size);
	struct vector_3D_rect vector_cross = cross_2D_input(rect_vector1, rect_vector2);
	printf("The Cross Product of <%.2lf, %.2lf> and <%.2lf, %.2lf> is <%.2lf, %.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector2.x, rect_vector2.y, vector_cross.x, vector_cross.y, vector_cross.z);
	
}
void display_cross_prod_3D(char iArr[], size_t size)
{
	printf("Vector 1\n");
	struct vector_3D_rect rect_vector1 = get_3D_vector(iArr, size);
	printf("Vector 2\n");
	struct vector_3D_rect rect_vector2 = get_3D_vector(iArr, size);
	struct vector_3D_rect vector_cross = cross_3D_input(rect_vector1, rect_vector2);
	printf("The Cross Product of <%.2lf, %.2lf, %.2lf> and <%.2lf, %.2lf, %.2lf> is <%.2lf, %.2lf, %.2lf>\n", rect_vector1.x, rect_vector1.y, rect_vector1.z, rect_vector2.x, rect_vector2.y, rect_vector2.z, vector_cross.x, vector_cross.y, vector_cross.z);
}

void display_FBD_2D(char iArr[], size_t size)
{
	int v_ctr = 0;
	for (;(v_ctr <= 0) || (v_ctr > FBD_MAX_VECTORS);) {
		printf("How many Vectors are in the FBD?\n");
		get_input(iArr, size);
		v_ctr = atoi(iArr);
		if ((v_ctr <= 0) || (v_ctr > FBD_MAX_VECTORS)) {
			printf("Please input a value between 1 and %d", FBD_MAX_VECTORS);
		}
	}
	struct vector_2D_rect vector_sum = {
			0,
			0
	};
	int i;
	for (i = 1; i <= v_ctr; i++) {
		printf("Vector %d\n", i);
		struct vector_2D_rect rect_vector = get_2D_vector(iArr, size);
		vector_sum = sum_2D(vector_sum, rect_vector);
	}
	printf("The Resultant Force is <%.2lf, %.2lf>\n", vector_sum.x, vector_sum.y);
	if (isequal_DBL(mag_2D(vector_sum), 0)) {
		printf("The System is in Equilibrium\n\n");
	}
	else {
		printf("The System is not in Equilibrium\n\n");
	}
}

void display_FBD_3D(char iArr[], size_t size)
{
	int v_ctr = 0;
	for (;(v_ctr <= 0) || (v_ctr > FBD_MAX_VECTORS);) {
		printf("How many Vectors are in the FBD?\n");
		get_input(iArr, size);
		v_ctr = atoi(iArr);
		if ((v_ctr <= 0) || (v_ctr > FBD_MAX_VECTORS)) {
			printf("Please input a value between 1 and %d", FBD_MAX_VECTORS);
		}
	}
	struct vector_3D_rect vector_sum = {
			0,
			0,
			0
	};
	int i;
	for (i = 1; i <= v_ctr; i++) {
		printf("Vector %d\n", i);
		struct vector_3D_rect rect_vector = get_3D_vector(iArr, size);
		vector_sum = sum_3D(vector_sum, rect_vector);
	}
	printf("The Resultant Force is <%.2lf, %.2lf, %.2lf>\n", vector_sum.x, vector_sum.y, vector_sum.z);
	if (isequal_DBL(mag_3D(vector_sum), 0)) {
		printf("The System is in Equilibrium\n\n");
	}
	else {
		printf("The System is not in Equilibrium\n\n");
	}
}