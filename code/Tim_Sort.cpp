#include <vector>
#include "Tim_Sort.h"

using namespace std;

void TimInsertion(vector<int>& A, int p, int r)
{
    int k;
    for(int i = p + 1 ; i < r + 1 ; i++)
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

void TimMerge(vector<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(A.begin() + p, A.begin() + q + 1);
    vector<int> R(A.begin() + q + 1, A.begin() + r + 1);

    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j]) A[k++] =  L[i++];
        else A[k++] =  R[j++];
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

void Tim_Sort(vector<int>& A)
{
    int n = A.size();

    for(int i = 0 ; i < n ; i += 32)
    {
        if(i + 31 > n) TimInsertion(A, i, n-1);
        else TimInsertion(A, i, i+31);
    }
    
    int q, r;
    for (int j = 32 ; j < n ; j = 2 * j)
    {
        for (int p = 0 ; p < n ; p += 2 * j)
        {
            if(p + j - 1 > n - 1) q = n - 1;
            else q = p + j - 1;
            
            if((p + 2 * j - 1) > (n - 1)) r = n - 1;
            else r = p + 2 * j - 1;

            if (q < r) {
                TimMerge(A, p, q, r);
            }
        }
    }
}