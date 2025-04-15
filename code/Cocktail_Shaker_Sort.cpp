#include <vector>
#include "Cocktail_Shaker_Sort.h"

using namespace std;

void Cocktail_Shaker_Sort(vector<int>& A)
{
    int n = A.size();
    int front_point = 0;
    int rear_point = n - 1;
    bool swap_flag;

    while(front_point < rear_point)
    {
        swap_flag = false;
        for(int i = front_point ; i < rear_point ; i++)
        {
            if(A[i] > A[i+1]) 
            {
                swap(A[i], A[i+1]);
                swap_flag = true;
            }
        }
        rear_point--;
        if(swap_flag == false) break;

        swap_flag = false;
        for(int j = rear_point ; j > front_point ; j--)
        {
            if(A[j-1] > A[j]) 
            {
                swap(A[j-1], A[j]);
                swap_flag = true;
            }
        }
        front_point++;
        if(swap_flag == false) break;    
    }
}