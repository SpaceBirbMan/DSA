#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

//author Sosnov.K.A

/// Получение случайного числа
#include <random>

/// Рандомайзер, кочующий второй год из файла в файл
long getRandomNumber(long min, long max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long> distrib(min, max);
	return distrib(gen);
}
//для float найти

/// Заполняет массив
template <typename T>
T* FillArray(T* array, const unsigned long N, unsigned long min, unsigned long max) //size_t везде для индексов в т.ч.
{
	for (int i = 0; i < N; i++)
		array[i] = getRandomNumber(min, max);
	return array;
}

/// Записывает массив в тескстовый файл
template <typename T>
void SaveArray(const T* array, const unsigned long N, const std::string &name)
{
	std::ofstream out;
	out.open(name);
	// todo: сделать выброс исключения
	if (out.is_open())
		for (int i = 0; i < N; i++)
			out << array[i] << std::endl;
	out.close();
	std::cout << "Done" << std::endl;
}


/// Проверяет отсортированноость массива
 template <typename T>
 bool IsSorted(const T* array, const unsigned long N)
 {
	 bool status = true;
	 for (int i = 0; i < N - 1; i++)
		 if (array[i] > array[i + 1]) return false;
		 return status;
 }

/// Сортирует массив
 template <typename T>
 T* SortArray(T* array, const unsigned long N) //дополнить как сортирует
 {
	 bool swapped; // лучше так, потому что IsSorted будет долго работать на больших массивах
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
		 // если на данной итерации не было обменов, значит массив уже отсортирован
		 if (!swapped)
			 break;
	 }
	 return array;
 }


/// Ищет элемент в отсортированном массиве методом бинарного поиска
/// На вход: массив любого типа, размер, ключ			//везде так и поточнее/покороче
/// На выход: положение элеметна в массиве
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

/// Ищет элемент в неотсортированном массиве методом линейного поиска
/// На вход: массив любого типа, размер, ключ
/// На выход: положение элеметна в массиве
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

template <typename T> // работать отказывается
int Partition(T* array, int low, int high)
{
	T pivot = array[high]; // Опорный элемент
	int i = low - 1; // Индекс меньшего элемента

	for (int j = low; j <= high - 1; j++)
	{
		// Если текущий элемент меньше или равен опорному
		if (array[j] <= pivot)
		{
			i++; // Увеличиваем индекс меньшего элемента
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return i + 1;
}
template <typename T>
void QuickSort(T* array, int low, int high) // min и max выбираются исходя из данных, а как, я не понимаю
{
	if (low < high)
	{
		int pivot = Partition(array, low, high); // Находим опорный элемент
		QuickSort(array, low, pivot - 1); // Сортируем элементы меньше опорного
		QuickSort(array, pivot + 1, high); // Сортируем элементы больше опорного
	}
}

//////////////////////////////