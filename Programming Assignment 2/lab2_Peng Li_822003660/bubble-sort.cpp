//============================================================================
// Name        : bubble-sort.cpp
// Author      : Qian Zhou
// Date        : Sep 24, 2014
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class Sort
  */
    resetNumCmps(); // reset number of comparisons
    for (int i = 1; i < size ; i++ ) {
        bool cont = false;
        for (int j=0; j< size - i; j++) {
            num_cmps++;
            if (A[j+1] < A[j]) {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                cont = true;
            }
        }
        if (!cont) break;
    }
}
