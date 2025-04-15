#ifndef Intro_SORT_H
#define Intro_SORT_H

#include <vector>

using namespace std;

void IntroInsertion(vector<int>& A, int p, int r);
void IntroMaxHeapify(vector<int>& A, int i, int heap_size, int p);
void IntroBuildMaxHeap(vector<int>& A, int p, int r);
void IntroHeapSort(vector<int>& A,int p, int r);
int IntroPartition(vector<int>& A, int p, int r);
void IntroQuick(vector<int>& A, int p, int r, int depth_limit);
void Intro_Sort(vector<int>& A);

#endif