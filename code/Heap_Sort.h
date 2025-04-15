#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

using namespace std;

void Max_Heapify(vector<int>& A, int i, int heap_size);
void Build_Max_Heap(vector<int>& A);
void Heap_Sort(vector<int>& A);

#endif