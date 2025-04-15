#include <vector>
#include "Comb_Sort.h"

using namespace std;

void Comb_Sort(vector<int>& A)
{
    int n = A.size();
    int gap = n;
    bool swap_flag = true;

    while(gap > 1 || swap_flag)
    {
        swap_flag = false;
        gap /= 1.3;
        if(gap < 1) gap = 1;

        for(int i = 0 ; i + gap < n ; i++)
        {
            if(A[i] > A[i+gap])
            {
                swap(A[i], A[i+gap]);
                swap_flag = true;
            }
        }
    }
}