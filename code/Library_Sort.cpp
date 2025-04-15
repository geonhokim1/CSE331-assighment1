#include <vector>
#include "Library_Sort.h"

using namespace std;

void LibraryInsert(vector<int>& S, int k)
{
    int p = 0;
    int q;
    int r = S.size() - 1;
    
    int insert_location;

    while (p <= r)
    {
        q = p + (r - p) / 2;

        if (k < S[q]) r = q - 1;
        else if (S[q] < k) p = q + 1;
        else
        {
            insert_location = q;
            break;
        }
    }
    if(insert_location != -1) insert_location = p;

    S.insert(S.begin() + insert_location, k);
}


void Library_Sort(vector<int>& A)
{
    int n = A.size();
    vector<int> S;
    int k;

    for (int i = 0; i < n; i++)
    {
        k = A[i];
        LibraryInsert(S, k);
    }

    A = S;
}