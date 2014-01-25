#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	long long x = 1000000000;
	freopen("in.txt", "w", stdout);
	for(int i = 0;i<x;++i){
		printf("%d\n", i);
	}
	return 0;
}