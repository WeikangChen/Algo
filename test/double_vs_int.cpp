// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

#define N 100000000
typedef int TP;
int main ()
{
	TP t = 0;
	for (int i = 0; i < N; ++i) {
		TP x = i;
		TP y = 2 * i;
		t = x * 10000 / y;
	}
	return 0;
}
