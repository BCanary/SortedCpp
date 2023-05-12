#include "sort.h"
#include <chrono>
#include <iostream>
#include "array_funcs.h"

void sort::durationTest(void sort(size_t, int*), size_t size, int* arr) 
{
    uint64_t start_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    sort(size, arr);
    uint64_t elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start_ms;
    std::cout << std::endl;
    std::cout << "Elapsed time is: " << elapsed_ms << " ms" << std::endl;
}

bool sort::isSorted(size_t size, int* arr)
{
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            std::cout << std::endl << arr[i] << " > " << arr[i + 1] << std::endl;
            return false;
        }
    }
    return true;
}

// Sorts
void sort::BubbleSort(size_t size, int* arr)
{
    bool is_sorted = false; // Array can be sorted earlier than we iterate all of array, therefore we will end for-loop
    int temp; // Temporary variable for an array element

    for (int j = 1; j < size; j++) // First loop should be size of an array bubble sort iterations
    {
        is_sorted = true; // Our array is already sorted so far

        // Second loop will iterate an array by size-j iterations
        // End of array is already sorted by previous iterations, so we do not need to iterate it by size of array
        for (int i = 0; i < size - j; i++)
        {
            if (arr[i] > arr[i + 1]) // If first element is more than second element we should swap them
            {
                temp = arr[i]; // Save our first element
                arr[i] = arr[i + 1]; // Replace first element by the second
                arr[i + 1] = temp; // Replace second element by the saved first
                is_sorted = false; // We just swaped the element, our array is not sorted already
            }
        }
        if (is_sorted) // If our array is sorted we can already finish sorting
        {
            break;
        }
    }
}

void sort::ShakerSort(size_t size, int* arr)
{
    int temp = 0;
    bool is_sorted = true;
    for (int j = 1; j < (int)(size/2+1); j++) 
    {
        is_sorted = true;
        for (int i = j - 1; i < size - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted)
        {
            break;
        }
        for (int i = size - j; i > j - 1; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted)
        {
            break;
        }
    }
}

void sort::CombSort(size_t size, int* arr)
{
    double factor = 1.2473309;
    int interval = size - 1;
    int temp;

    while (interval >= 1)
    {
        for (int i = 0; i+interval < size; i++) {
            if (arr[i] > arr[i + interval])
            {
                temp = arr[i];
                arr[i] = arr[i + interval];
                arr[i + interval] = temp;
            }
        }
        interval /= factor;
    }

    // Somehow I always getting one or two unsorted elements, so I will sort them here
    bool is_sorted = false;
    while(!is_sorted)
    {
        is_sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                is_sorted = false;
            }
        }
    }
}

void sort::InsertionSort(size_t size, int* arr)
{
    int sorted_length = 1;
    int temp;

    while (sorted_length < size) {
        for (int i = sorted_length; i > 0; i--)
        {
            //std::cout << sorted_length << ":" << i << std::endl;
            if (arr[i] < arr[i - 1])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                //PrintArray(size, arr);
            }
            else
            {
                break;
            }
        }
        sorted_length += 1;
    }
}

void sort::SelectionSort(size_t size, int* arr)
{
    int temp = 0;
    int min = 0;
    for (int j = 0; j < size; j++)
    {
        min = j;
        for (int i = j; i < size; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
    }
}

void sort::ShellSort(size_t size, int* arr)
{
    int temp;

    for (int n = size; n != 0; n /= 2) { // Decrease gap N by dividing it by 2 until it will be 1
        for (int i = 0; (i + n) < size; i++) // Move in array by i+N to the border of it
        {
            if (arr[i] > arr[i + n]) // If i bigger than i+N swap it
            {
                temp = arr[i];
                arr[i] = arr[i + n];
                arr[i + n] = temp;
                
                for (int j = i; (j - n) > 0;) // Now move back by the N
                {
                    if (arr[j] < arr[j - n])
                    {
                        temp = arr[j];
                        arr[j] = arr[j - n];
                        arr[j - n] = temp;
                        j -= n;
                        continue; // If we did a swap we will move back again
                    }
                    break; // If not we will end our cycle
                }
            }
        }
    }
}

/*
void sort::ShellSort(size_t size, int* arr)
{
    int n = size;
    int temp;
    int count;
    int offset;

    while (n != 1)
    {
        n = (int)(n / 2);
        count = (int)(size / n);
        std::cout << std::endl << n << ":" << count << std::endl;
        for (int j = 0; j < count-1; j++)
        {
            offset = (n*j);
            for (int i = offset; i < n+offset; i++)
            {
                if (arr[i] > arr[i + n])
                {
                    temp = arr[i];
                    arr[i] = arr[i + n];
                    arr[i + n] = temp;

                    for (int c = i; c-n > 0;)
                    {
                        if (arr[c] < arr[c - n])
                        {
                            temp = arr[c];
                            arr[c] = arr[c - n];
                            arr[c - n] = temp;
                            c -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
}
*/

void QuickSort(size_t size, int* arr)
{

}