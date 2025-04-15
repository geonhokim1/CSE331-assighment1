#include <vector>
#include "Bubble_Sort.h"

using namespace std;

void Bubble_Sort(vector<int>& A)
{
    int n = A.size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n-1 ; j++)
        {
            if(A[j] > A[j+1]) swap(A[j], A[j+1]);
        }
    }
}