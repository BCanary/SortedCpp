#pragma once

namespace array_funcs
{
	// Array functions
	int* GenerateArray(size_t n);
	int GetRandomInteger(int min, int max);
	void ShuffleArray(size_t size, int* arr, unsigned int rounds);
	int* CopyArray(size_t size, int* arr);

	void PrintArray(size_t size, int* arr);
	void printMatrix(size_t size_row, size_t size_collumn, int** matrix);
}