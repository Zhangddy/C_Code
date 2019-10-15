#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int j;
	double k;
	scanf("%lf", &k);
	double i= 2.0;
	j = 0;
	double sum = 0.0;
	while ( sum <= k)
	{
		j++;
		sum += i;
		i = 0.98 *i;
	}
	printf("%d", j);
	system("pause");
	return 0;
}
