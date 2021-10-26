#include <stdio.h>
#include <stdlib.h>

int main()
{
	long double min, max, summ, DR;
	long int i, N;
	double* mas1;
	int* mas2;

	DR = 0.0;
	summ = 0.0;
	min = 0.0;
	max = 0.0;
	i = 0;
	N = 0;

	printf("Enter the number of random numbers ");
	scanf_s("%d", &N);
	printf("Enter the minimum number of the range ");
	scanf_s("%lf", &min);
	printf("Enter the maximum number of the range ");
	scanf_s("%lf", &max);

	if ((max <= min) || (max <= 0.0) || (min <= 0.0) || (N <= 0))
	{
		printf("Error: incorrect data\n");
		return 0;
	}

	mas1 = (double*)malloc(N * sizeof(double));
	mas2= (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
	{
		mas1[i] = (((((double)rand()) / RAND_MAX) * (max - min)) + min);
		DR = (mas1[i] - (int)mas1[i]) * 1000000;

		if (DR == 0)
			mas2[i] = 0;
		else
		{		
			mas2[i] = (int)DR;
		while (mas2[i] % 10 == 0)
			mas2[i] = mas2[i] / 10;
		}
	}

		for (i = 0; i < N; i++)
			if (mas2[i] < N)
			{
				summ = summ - mas1[mas2[i]];
				mas1[mas2[i]] = 0.0;
			}

		for (i = 0; i < N; i++)
			summ = summ + mas1[i];

		printf("The sum is %lf\n", summ);

	free(mas1);
	free(mas2);
	return 0;
}