#include <stdio.h>
#include "iostream"
using namespace std;
int main (int argc, char const *argv[])
{	
	freopen ("input.txt", "r", stdin);
	int  x;
	scanf("%d", &x);
	printf("%d\n", x);
	printf("Hello, World\n");
	return 0;
}