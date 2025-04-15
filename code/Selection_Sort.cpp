#include <vector>
#include "Selection_Sort.h"

using namespace std;

void Selection_Sort(vector<int>& A)
{
    int n = A.size();
    int min_idx;
    for(int i = 0 ; i < n ; i++)
    {
        min_idx = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(A[min_idx] > A[j]) min_idx = j;
        }
        if(min_idx != i) swap(A[i], A[min_idx]);
    }
}