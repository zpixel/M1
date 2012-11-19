#include <stdio.h>
#include <stdlib.h>


int* exctract(int *T, int n, int a, int b)
{
	int *res=(int*)malloc(n*sizeof(int));
	int compt = 0;
	
	for (int i = 0 ; i < n ; i++)
    	{
		if (T[i] >= a && T[i] <= b)
		{
			res[compt] = T[i];
			compt++;
		}
    	}
		return res;
}

void afficher (int *T, int n)
{
	for (int i=0; i < n; i++)
	{
		printf("%d\t",T[i]);
	}

}

int main() {

	int T[5] = {1,3,5,7,9};
	int *pRes = NULL;
	
	pRes = exctract(T, 5, 2, 5);
	afficher(T, 5);
	printf("\n");
	afficher (pRes, 5);

	return 0;
}
