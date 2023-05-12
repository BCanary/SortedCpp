#include <iostream>
#include "sort.h"
#include "array_funcs.h"
#include "crypto.h"

int main()
{
    srand((unsigned int)time(0));

    size_t n = 20000;
    int* arr = array_funcs::GenerateArray(n);
    array_funcs::ShuffleArray(n, arr, 10);
    //int* arr = new int[n] {12, 34, 25, 15, 67, 23, 11, 86};
    int* array_copy = array_funcs::CopyArray(n, arr);

    
    //array_funcs::PrintArray(n, arr);
    //std::cout << std::endl;
    //sort::QuickSort(n, arr);
    //std::cout << sort::isSorted(n, arr) << std::endl;
    //array_funcs::PrintArray(n, arr);
    
    
    std::cout << "Comb Sort: ";
    sort::durationTest(sort::CombSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;
    
    std::cout << "Shell Sort: ";
    arr = array_funcs::CopyArray(n, array_copy);
    sort::durationTest(sort::ShellSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;

    std::cout << "Selection Sort: ";
    arr = array_funcs::CopyArray(n, array_copy);
    sort::durationTest(sort::SelectionSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;

    std::cout << "Insertion Sort: ";
    arr = array_funcs::CopyArray(n, array_copy);
    sort::durationTest(sort::InsertionSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;

    std::cout << "Shake Sort: ";
    arr = array_funcs::CopyArray(n, array_copy);
    sort::durationTest(sort::ShakerSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;

    std::cout << "Bubble Sort: ";
    arr = array_funcs::CopyArray(n, array_copy);
    sort::durationTest(sort::BubbleSort, n, arr);
    std::cout << " > " << sort::isSorted(n, arr) << std::endl;
    

    //for (int i = 1; i < 21; i++)
    //{
    //    std::cout << i << ":" << crypto::euler(i) << std::endl;
    //}
    
    /*int a = 17;
    int b = 6;

    std::cout << crypto::gcd(a, b) << std::endl;
    std::cout << crypto::recurrentEuclid(a, b) << std::endl;
    std::cout << crypto::extendedEuclid(a, b) << std::endl;
    //std::cout << crypto::iterativeEuclid(a, b) << std::endl;*/


    //int n = 11;
    //std::cout << crypto::euler(n - 1) << std::endl;
    //int** matrix = crypto::generateGroup(n, crypto::powmod);
    //array_funcs::printMatrix(n, n, matrix);
    //std::cout << crypto::L(6, n) << std::endl;

    //std::cout << crypto::powmod(32,12,12);      

    std::cout << std::endl;


    system("pause");
}