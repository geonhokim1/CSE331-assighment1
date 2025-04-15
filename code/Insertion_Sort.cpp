#include <vector>

using namespace std;

void Insertion_Sort(vector<int>& A)
{
    int n = A.size();
    int k;
    for(int i = 1 ; i < n ; i++)
    {
        k = i;
        for(int j = i - 1 ; j >= 0 ; j--)
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