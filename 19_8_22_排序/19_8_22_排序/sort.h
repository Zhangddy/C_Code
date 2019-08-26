#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* src, int n);
void InsertSort(int* src, int n);
void ShellSort(int* src, int n);
void MergeSort(int* src, int n);
void QuickSort(int* src, int n);
void dealQuickSort(int* src, int start, int end);
int doublePointerWay1(int* src, int start, int end);
void swapArgs(int* pa, int* pb);
int doublePointerWay2(int* src, int start, int end);
int digWay3(int* src, int start, int end);
int hoareWay(int* src, int start, int end);
void QuickSortNonR(int* src, int n);



#endif // !
