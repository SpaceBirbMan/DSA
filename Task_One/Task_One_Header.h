#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

//author Sosnov.K.A

/// «аполн€ет массив
template <typename T>
T* FillArray(T* array, const unsigned long N)
{
	for (int i = 0; i < N; i++)
		array[i] = rand();
	return array;
}

/// «аписывает массив в тескстовый файл
template <typename T>
void SaveArray(const T* array, const unsigned long N, const std::string name)
{
	std::ofstream out;
	out.open(name);
	//сделать выброс исключени€
	if (out.is_open())
		for (int i = 0; i < N; i++)
			out << array[i] << std::endl;
	out.close();
	std::cout << "Done" << std::endl;
}


///ѕровер€ет отсортированноость массива
 template <typename T>
 bool IsSorted(const T* array, const unsigned long N)
 {
	 bool status = true;
	 for (int i = 0; i < N - 1; i++)
		 if (array[i] > array[i + 1]) return false;
		 return status;
 }

/// —ортирует массив
template <typename T>
T* SortArray(T* array, const unsigned long N)
{
	T temp = 0; //хранилище значени€ дл€ замены чисел в массиве
	for (int i = 0; i < N - 1; i++)
	{
		if (not IsSorted(array, N)) //проверка на отсортированность массива
			if (array[i] > array[i + 1]) 
			{ 
				temp = array[i]; 
				array[i] = array[i + 1]; 
				array[i + 1] = temp; 
				//i = 0; 
			}
	}
	return array;
}
