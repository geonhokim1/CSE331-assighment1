#include <vector>
#include "Quick_Sort.h"

using namespace std;

int Partition(vector<int>& A, int p, int r)
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

void Quick_Sort(vector<int>& A, int p, int r)
{
    if(p < r)
    {
       int q = Partition(A, p, r);
       Quick_Sort(A, p, q - 1);
       Quick_Sort(A, q + 1, r);
    }
}