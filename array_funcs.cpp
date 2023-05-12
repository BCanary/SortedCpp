#include "array_funcs.h"
#include <iostream>

int* array_funcs::GenerateArray(size_t n)
{
    /*
        Generate an Array with n length and
        return a pointer to that array.

        size_t: n - count of elements
    */
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    return arr;
}

void array_funcs::PrintArray(size_t size, int* arr)
{
    /*
        Print an array by pointer.

        size_t: size - size of a dynamic array
        int*: arr - pointer to an array
    */
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i == size - 1)
        {
            break;
        }
        std::cout << ",";
    }
    std::cout << "]";
}


int array_funcs::GetRandomInteger(int min, int max)
{
    return (min + rand() % max);
}

void array_funcs::ShuffleArray(size_t size, int* arr, unsigned int rounds)
{
    /*
        Shuffle an array. Moves all elements in array by random position by round count.
        size_t: size - size of a dynamic array
        int*: arr - pointer to an array
        unsigned int: round - count of shuffling
    */
    int temp;
    int random_index;
    for (int round = 0; round < rounds; round++)
    {
        for (int i = 0; i < size; i++)
        {
            random_index = GetRandomInteger(0, size - 1);
            temp = arr[i];
            arr[i] = arr[random_index];
            arr[random_index] = temp;
        }
    }
}

int* array_funcs::CopyArray(size_t size, int* arr)
{
    int* new_array = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_array[i] = arr[i];
    }
    return new_array;
}

void array_funcs::printMatrix(size_t size_row, size_t size_collumn, int** matrix)
{
    for (int i = 0; i < size_row; i++)
    {
        for (int j = 0; j < size_collumn; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}