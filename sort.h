#pragma once
namespace sort 
{
	// Additional functions
	void durationTest(void sort(size_t, int*), size_t size, int* arr);
	bool isSorted(size_t size, int* arr);

	// Sort functions
	void BubbleSort(size_t size, int* arr);
	void ShakerSort(size_t size, int* arr);
	void CombSort(size_t size, int* arr);
	void InsertionSort(size_t size, int* arr);
	void SelectionSort(size_t size, int* arr);
	void ShellSort(size_t size, int* arr);
	void QuickSort(size_t size, int* arr);
}