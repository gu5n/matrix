#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//void mult();

int main(void)
{
	int n = 3;
	int m = 3;
	int i, j, k;
	int A[n][m];
	int B[n][m];
	int C[n][m];
	struct timeval t1, t2;
	double diff;

	srand(time(NULL));
	//Matrix A und B befüllen und C leeren
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			A[i][j]=rand()%10;
			B[i][j]=rand()%10;
			C[i][j]=0;
		}
	}
	//mult();



	gettimeofday(&t1, NULL);
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < m; k++)
		{		
			for(j = 0; j < m; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
	gettimeofday(&t2, NULL);
	diff = (t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec+t1.tv_usec*0.000001);
	printf("Diff: %f\n", diff);

///////////////////////print A, B, C//////////////////////////
/*	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\t");
		for(j = 0; j < m; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");



	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
*/
	exit(0);
}

/*
mult()
{
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < m; k++)
		{		
			for(j = 0; j < m; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}
*/


