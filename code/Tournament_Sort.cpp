#include <vector>
#include "Tournament_Sort.h"

using namespace std;

void Tournament_Sort(vector<int>& A)
{
    int n = A.size();
    int height = 0;
    while(true)
    {
        if(n < (1 << height)) break;
        height++;
    }
    int leaf_node = (1 << height);
    vector<int> tree(2 * leaf_node, 2147483647);

    for(int i = 0 ; i < n ; i++) tree[leaf_node+i] = A[i];

    for(int j = 0 ; j < n ; j++)
    {
        for(int k = leaf_node-2 ; k >= 0 ; k--)
        {
            if(tree[2*k+1] <= tree[2*k+2]) tree[k] = tree[2*k+1];
            else tree[k] = tree[2*k+2];
        }

        A[j] = tree[0];
        for(int l = leaf_node ; l < 2*leaf_node ; l++) 
        {
            if(tree[l] == tree[0]) 
            {
                tree[l] = 2147483647; 
                break;
            }
        }
    }
}