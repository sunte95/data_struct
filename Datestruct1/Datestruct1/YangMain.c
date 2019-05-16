#include<stdio.h>
#include<stdlib.h>
#include"DivideAndConquer.h"
main() {
	int a = 7, b = 5, c = 8,Max;
	Max= Max3(a, b, c);
	printf("%d", Max);
	 system("pause" );
	 int List[] = {3,6,2,7,4,1};
	 int left,  right,Sum;
	  //Sum=DivideAndConquer(List[left], left=0, right=5);
	  Sum = DivideAndConquer(List, 0, 5);
	  printf("%d", Sum);
	  system("pause");
	// MaxsubseqSum3( List[left], 6);
	// system("pause");
}