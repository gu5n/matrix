/* This program generates matrix A, B and C, fills them with random numbers */
/* and multiplies A and B. The multiplication is split up into 8 threads.   */
/* The elapsed time to fill matrix C will be prompted.                      */
/* Version: 0.1                                                             */
/* Author: Christoph Ablöscher                                              */
/* Date 03.04.17                                                            */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#define N 800
#define M 800


void mult1();
void mult2();
void mult3();
void mult4();
void mult5();
void mult6();
void mult7();
void mult8();

int A[N][M];
int B[N][M];
int C[N][M];

int main(void)
{
	pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;
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
	
	if(gettimeofday(&t1, NULL) != 0)
		perror("errno");
	if(pthread_create(&thread1, NULL, (void *)mult1, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread2, NULL, (void *)mult2, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread3, NULL, (void *)mult3, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread4, NULL, (void *)mult4, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread5, NULL, (void *)mult5, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread6, NULL, (void *)mult6, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread7, NULL, (void *)mult7, NULL) != 0)
		perror("thread create error");
	if(pthread_create(&thread8, NULL, (void *)mult8, NULL) != 0)
		perror("thread create error");
	if(pthread_join( thread1, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread2, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread3, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread4, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread5, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread6, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread7, NULL) != 0)
		perror("thread join error");
	if(pthread_join( thread8, NULL) != 0)
		perror("thread join error");
	if(gettimeofday(&t2, NULL) != 0)
		perror("errno");
	


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
	printf("elapsed time: %f\n", diff);

///////////////////////print A, B, C//////////////////////////
/*	for(i = 0; i < N; i++)
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
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
*/
	exit(0);
}



void mult1()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = 0; k < (M/8); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult2()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (M/8); k < (M/4); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult3()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (M/4); k < (3*M/8); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult4()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (3*M/8); k < (M/2); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult5()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (M/2); k < (5*M/8); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult6()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (5*M/8); k < (3*M/4); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}


void mult7()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (3*M/4); k < (7*M/8); k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void mult8()
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(k = (7*M/8); k < M; k++)
		{		
			for(j = 0; j < M; j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}


