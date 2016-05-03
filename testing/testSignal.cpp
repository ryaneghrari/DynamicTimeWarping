#include "Signal.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string fileName = argv[1];
	string fileName2 = argv[2];

	Signal s(fileName);
	Signal s2(fileName2);

	return (0);
}
