#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#define N 8
#define M 8


void mult1();

int A[N][M];
int B[N][M];
int C[N][M];

int main(void)
{
	int i, j;
	struct timeval t1, t2;
	double diff;

	srand(time(NULL));
	//Matrix A und B befüllen und C leeren
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			A[i][j]=rand()%10;
			B[i][j]=rand()%10;
			C[i][j]=0;
		}
	}
	
	gettimeofday(&t1, NULL);
	mult1();
	gettimeofday(&t2, NULL);
	


/*	gettimeofday(&t1, NULL);
	for(i = 0; i < N; i++)
	{
		for(k = 0; k < M; k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
	gettimeofday(&t2, NULL); */
	diff = (t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec+t1.tv_usec*0.000001);
	printf("Diff: %f\n", diff);

///////////////////////print A, B, C//////////////////////////
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\t");
		for(j = 0; j < M; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}

	exit(0);
}



void mult1()
{
	int i, j, k;
	#pragma omp parallel for	
	for(i = 0; i < N; i++)
	{
		for(k = 0; k < M; k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

