#ifndef TIM_SORT_H
#define TIM_SORT_H

#include <vector>

using namespace std;

void TimInsertion(vector<int>& A, int p, int r);
void TimMerge(vector<int>& A, int p, int q, int r);
void Tim_Sort(vector<int>& A);

#endif