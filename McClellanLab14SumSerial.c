/*
Alex McClellan
Dr. Shore
CSC 2410
18 April 2021
Parallel RNG Program
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

double sum(double array[], int num_elements);
void gen_numbers(double numbers[], int num_elements);
double gen_rand(int min, int max);

int main(int argc, char *argv[]) {
	//Variables
	int conversion = atoi(argv[1]);
	double *ptr = (double*)malloc(conversion * sizeof(double));
	double array[conversion];
	int num_elements = conversion;

	//Timer setup
	struct timeval tstart, tstop;
	double runtime;
	gettimeofday(&tstart, NULL);
	
	//Generate numbers
	gen_numbers(array, num_elements);

	double total = sum(array, num_elements);

	//End timer
	gettimeofday(&tstop, NULL);
	runtime = tstop.tv_sec - tstart.tv_sec + (tstop.tv_usec-tstart.tv_usec)/1.e6;
	printf("Total time: %lf\n", runtime);

	//Prints random numbers if argv[] = on
	if (strcmp(argv[2], "on") == 0) {
		for (int i = 0; i < num_elements; i++) {
			printf("Random number: %i = %f\n", i, array[i]);
		}
	}

	printf("Total = %f\n", total);

	return 0;
}


double sum(double array[], int num_elements) {
	double total = 0;

	#pragma omp parallel for reduction(+:total)
	for (int i = 0; i < num_elements; i++) {
		total = total + array[i];
	}

	return total;
}

void gen_numbers(double numbers[], int num_elements) {
	double randomNumber;	

	#pragma omp parallel for
	for (int i = 0; i < num_elements; i++) {
		randomNumber = gen_rand(0,100);
		numbers[i] = randomNumber;
	}
}

double gen_rand(int min, int max)
{
	return min + (double)rand() / ((double)RAND_MAX/(max-min));
}
