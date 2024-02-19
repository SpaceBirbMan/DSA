#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

//author Sosnov.K.A

/// ��������� ���������� �����
#include <random>

/// �����������, �������� ������ ��� �� ����� � ����
long getRandomNumber(long min, long max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long> distrib(min, max);
	return distrib(gen);
}
//��� float �����

/// ��������� ������
template <typename T>
T* FillArray(T* array, const unsigned long N, unsigned long min, unsigned long max) //size_t ����� ��� �������� � �.�.
{
	for (int i = 0; i < N; i++)
		array[i] = getRandomNumber(min, max);
	return array;
}

/// ���������� ������ � ���������� ����
template <typename T>
void SaveArray(const T* array, const unsigned long N, const std::string &name)
{
	std::ofstream out;
	out.open(name);
	// todo: ������� ������ ����������
	if (out.is_open())
		for (int i = 0; i < N; i++)
			out << array[i] << std::endl;
	out.close();
	std::cout << "Done" << std::endl;
}


/// ��������� ������������������ �������
 template <typename T>
 bool IsSorted(const T* array, const unsigned long N)
 {
	 bool status = true;
	 for (int i = 0; i < N - 1; i++)
		 if (array[i] > array[i + 1]) return false;
		 return status;
 }

/// ��������� ������
 template <typename T>
 T* SortArray(T* array, const unsigned long N) //��������� ��� ���������
 {
	 bool swapped; // ����� ���, ������ ��� IsSorted ����� ����� �������� �� ������� ��������
	 for (int i = 0; i < N - 1; ++i)
	 {
		 swapped = false;
		 for (int j = 0; j < N - i - 1; ++j)
		 {
			 if (array[j] > array[j + 1])
			 {
				 T temp = array[j];
				 array[j] = array[j + 1];
				 array[j + 1] = temp;
				 swapped = true;
			 }
		 }
		 // ���� �� ������ �������� �� ���� �������, ������ ������ ��� ������������
		 if (!swapped)
			 break;
	 }
	 return array;
 }


/// ���� ������� � ��������������� ������� ������� ��������� ������
/// �� ����: ������ ������ ����, ������, ����			//����� ��� � ��������/��������
/// �� �����: ��������� �������� � �������
template <typename T>
int BinarySearch(const T* array, const unsigned long N, const T& key)
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == key)
			return mid;
		if (array[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

/// ���� ������� � ����������������� ������� ������� ��������� ������
/// �� ����: ������ ������ ����, ������, ����
/// �� �����: ��������� �������� � �������
template <typename T>
int LinearSearch(const T* array, unsigned long N, const T& key)
{
	for (int i = 0; i < N; ++i)
	{
		if (array[i] == key)
			return i;
	}
	return -1;
}

///// Powered by ChatGPT /////

template <typename T> // �������� ������������
int Partition(T* array, int low, int high)
{
	T pivot = array[high]; // ������� �������
	int i = low - 1; // ������ �������� ��������

	for (int j = low; j <= high - 1; j++)
	{
		// ���� ������� ������� ������ ��� ����� ��������
		if (array[j] <= pivot)
		{
			i++; // ����������� ������ �������� ��������
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return i + 1;
}
template <typename T>
void QuickSort(T* array, int low, int high) // min � max ���������� ������ �� ������, � ���, � �� �������
{
	if (low < high)
	{
		int pivot = Partition(array, low, high); // ������� ������� �������
		QuickSort(array, low, pivot - 1); // ��������� �������� ������ ��������
		QuickSort(array, pivot + 1, high); // ��������� �������� ������ ��������
	}
}

//////////////////////////////