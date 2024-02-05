#include <iostream>
#include <chrono>
#include "Task_One_Header.h"

//author Sosnov.K.A

using namespace std;
using namespace chrono;

int main()
{
	srand(time(0)); //для рандомного сида рандомайзера

	//тесты

	unsigned long N = 3000;
	long* A = new long[N]; 

	auto t0 = steady_clock::now();
	FillArray(A, N);
	SortArray(A, N);
	SaveArray(A, N, "Array.txt");
	auto t1 = steady_clock::now();
	auto delta1 = duration_cast<milliseconds>(t1 - t0).count();
	cout << delta1 << " ms" << endl;
	auto delta2 = duration_cast<seconds>(t1 - t0).count();
	cout << delta2 << " s" << endl;
}
