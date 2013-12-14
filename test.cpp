#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "12345";
	int  x;
	sscanf(s.c_str(), "%d", &x);
	printf("%d\n", x);
	return 0;
}