#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int sommeTableau(int *T, int n){
	if (n < 0) 
		return 0;
	else {		
		return T[n] + sommeTableau(T, n-1);
		}
}

int main(){

	int T[5] = {1,3,5,7,9};
	printf("%d\n",sommeTableau(T,4));
	
	return 0;
}
