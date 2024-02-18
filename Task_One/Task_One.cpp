#include <iostream>
#include <chrono>
#include <fstream>
#include "Task_One_Header.h"
#include "TestAsrt.h"

using namespace std;
using namespace chrono;

const unsigned long ARRAY_SIZES[] = { 5000, 10000, 50000 };
const int NUM_TESTS = 5;

int main()
{
    TestA();

    srand(time(0)); // для случайного сида генератора

    ofstream outFile("Search_Times.txt");
    if (!outFile)
    {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    for (unsigned long size : ARRAY_SIZES)
    {
        long* array = new long[size];
        FillArray(array, size, 0, 128);
        SortArray(array, size);

        for (int i = 0; i < NUM_TESTS; ++i)
        {
            auto start = steady_clock::now();
            // измеряем время для каждого типа поиска
            // линейный поиск
            int linearResult = LinearSearch(array, size, getRandomNumber(0, 128));
            auto linearEnd = steady_clock::now();
            auto linearTime = duration_cast<nanoseconds>(linearEnd - start).count();
            cout << "Check " << i + 1 << endl;

            start = steady_clock::now();
            // бинарный поиск
            int binaryResult = BinarySearch(array, size, getRandomNumber(0, 128));
            auto binaryEnd = steady_clock::now();
            auto binaryTime = duration_cast<nanoseconds>(binaryEnd - start).count();
            cout << "Check II " << i + 1 << endl;

            outFile << "Array size: " << size << " | Test " << i + 1 << endl;
            outFile << "Linear Search Time: " << linearTime << " ns, Result: " << linearResult << endl;
            outFile << "Binary Search Time: " << binaryTime << " ns, Result: " << binaryResult << endl;
        }

        delete[] array;
    }

    cout << "Search times have been saved to 'Search_Times.txt'." << endl;

    return 0;
}
