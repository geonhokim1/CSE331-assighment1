#include <vector>
#include "Intro_Sort.h"

using namespace std;



void IntroInsertion(vector<int>& A, int p, int r)
{
    int k;
    for(int i = p + 1 ; i <= r ; i++)
    {
        k = i;
        for(int j = i - 1 ; j >= p ; j--)
        {
            if(A[k] < A[j]) 
            {
                swap(A[k], A[j]);
                k--;
            }
            else break;
        }
    }
}

void IntroMaxHeapify(vector<int>& A, int i, int heap_size, int p)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;

    if(L < heap_size && A[p + L] > A[p + largest]) largest = L;
    if(R < heap_size && A[p + R] > A[p + largest]) largest = R;
    if(largest != i)
    {
        swap(A[p + i], A[p + largest]);
        IntroMaxHeapify(A, largest, heap_size, p);
    }
}

void IntroBuildMaxHeap(vector<int>& A, int p, int r)
{
    int heap_size = r - p + 1;
    for(int i = heap_size/2 - 1 ; i >= 0 ; i--) IntroMaxHeapify(A, i, heap_size, p);
}

void IntroHeapSort(vector<int>& A, int p, int r)
{
    IntroBuildMaxHeap(A, p, r);
    int heap_size = r - p + 1;
    for(int i = heap_size - 1 ; i > 0 ; i--)
    {
        swap(A[p], A[p + i]);
        heap_size--;
        IntroMaxHeapify(A, 0, heap_size, p);
    }
}

int IntroPartition(vector<int>& A, int p, int r)
{
    int pivot = A[r];
    int i = p-1;
    for(int j = p ; j < r ; j++)
    {
        if(pivot >= A[j])
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r], A[i+1]);
    return i+1;
}

void IntroQuick(vector<int>& A, int p, int r, int depth_limit)
{
    if(r - p + 1 < 16)
    {
        IntroInsertion(A, p, r);
        return;
    }
    if(depth_limit == 0)
    {
        IntroHeapSort(A, p, r);
        return;
    }

    if(p < r)
    {
       int q = IntroPartition(A, p, r);
       IntroQuick(A, p, q - 1, depth_limit - 1);
       IntroQuick(A, q + 1, r, depth_limit - 1);
    }
}

void Intro_Sort(vector<int>& A)
{
    int n = A.size();
    int depth_limit = 0;
    while(true)
    {
        if(n < (1 << depth_limit)) break;
        depth_limit++;
    }
    depth_limit = (depth_limit-1) << 1;

    IntroQuick(A, 0, n-1, depth_limit);
}