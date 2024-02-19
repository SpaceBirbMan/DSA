#pragma once
#include <iostream>
#include <cassert>
#include "Task_One_Header.h"

void TestA() {
    const unsigned long ARRAY_SIZE = 5;
    long array[ARRAY_SIZE];
    FillArray(array, ARRAY_SIZE, 0, 10); // ��������� ������ ���������� ������� � ���������

    // ������������ ������� IsSorted
    assert(!IsSorted(array, ARRAY_SIZE));

    ///��� ���� ������������ ������� � ������
    // � ��������
    //� �����


    // ������������ ������� SortArray
    SortArray(array, ARRAY_SIZE);
    assert(IsSorted(array, ARRAY_SIZE));

    //long A[10]{ 1,4,5,3,6,8,9,7,2,0 };
    // ������������� ������� QuickSort
    //QuickSort(A, 0, 100);
    //assert(IsSorted(A, 10));
    array[0] = 5;
    // ������������ ������� LinearSearch
    for (int i = 0; i < ARRAY_SIZE; ++i) { //����� ������, ������ ������
        assert(LinearSearch(array, ARRAY_SIZE, (long)5) == 0);
    }

    // ������������ ������� BinarySearch
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        assert(BinarySearch(array, ARRAY_SIZE, (long)5) == 0);
    }

    std::cout << "All tests passed successfully!" << std::endl;
}
