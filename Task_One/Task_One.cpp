#include <iostream>
#include <chrono>
#include <fstream>
#include "Task_One_Header.h"
#include "TestAsrt.h"
#include <string>

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
        cerr << "Failed to open output file." << endl; // cerr - вывод ошибки (и что ещё?)
        return 1;
    }

    for (unsigned long size : ARRAY_SIZES)
    {
        long* array = new long[size];
        FillArray(array, size, 0, 128);
        SortArray(array, size);
        if (!IsSorted(array, (long)ARRAY_SIZES)) exit;

        for (int i = 0; i < NUM_TESTS; ++i)
        {
            auto start = steady_clock::now(); // начало отсчёта времени
            // измеряем время для каждого типа поиска
            // линейный поиск
            int linearResult = LinearSearch(array, size, getRandomNumber(0, 128));
            auto linearEnd = steady_clock::now(); // конец отсчёта времени
            auto linearTime = duration_cast<nanoseconds>(linearEnd - start).count(); // результат 1
            cout << "Check " << i + 1 << endl;

            start = steady_clock::now();  // начало отсчёта времени
            // бинарный поиск
            int binaryResult = BinarySearch(array, size, getRandomNumber(0, 128));
            auto binaryEnd = steady_clock::now(); // конец отсчёта времени
            auto binaryTime = duration_cast<nanoseconds>(binaryEnd - start).count(); // результат 1
            cout << "Check II " << i + 1 << endl;

            outFile << "Array size: " << size << " | Test " << i + 1 << endl;
            outFile << "Linear Search Time: " << linearTime << " ns, Result: " << linearResult << endl;
            outFile << "Binary Search Time: " << binaryTime << " ns, Result: " << binaryResult << endl;

            //SaveArray(array, (long)ARRAY_SIZES, to_string((long)ARRAY_SIZES));
        }

        delete[] array;
    }

    cout << "Search times have been saved to 'Search_Times.txt'." << endl;

    return 0;
}
