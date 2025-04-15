#include <vector>
#include "Merge_Sort.h"

using namespace std;


void Merge(vector<int>& A, int p, int q, int r)
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

void Merge_Sort(vector<int>& A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}