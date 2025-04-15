#include <vector>
#include "Heap_Sort.h"

using namespace std;

void Max_Heapify(vector<int>& A, int i, int heap_size)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;

    if(L < heap_size && A[L] > A[largest]) largest = L;
    if(R < heap_size && A[R] > A[largest]) largest = R;
    if(largest != i)
    {
        swap(A[i], A[largest]);
        Max_Heapify(A, largest, heap_size);
    }
}

void Build_Max_Heap(vector<int>& A)
{
    int heap_size = A.size();
    for(int i = A.size()/2 - 1 ; i >= 0 ; i--) Max_Heapify(A, i, heap_size);
}

void Heap_Sort(vector<int>& A)
{
    Build_Max_Heap(A);
    int heap_size = A.size();
    for(int i = heap_size - 1 ; i > 0 ; i--)
    {
        swap(A[0], A[i]);
        heap_size--;
        Max_Heapify(A, 0, heap_size);
    }
}