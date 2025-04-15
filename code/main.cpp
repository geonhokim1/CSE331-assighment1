#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <numeric>

#include "Merge_Sort.h"
#include "Heap_Sort.h"
#include "Bubble_Sort.h"
#include "Insertion_Sort.h"
#include "Selection_Sort.h"
#include "Quick_Sort.h"

#include "Library_Sort.h"
#include "Tim_Sort.h"
#include "Cocktail_Shaker_Sort.h"
#include "Comb_Sort.h"
#include "Tournament_Sort.h"
#include "Intro_Sort.h"

using namespace std;

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Can't open output.txt" << endl;
        return 1;
    }

    vector<string> files;
    for (int i = 1; i < argc; ++i) {
        files.push_back(argv[i]);
    }

    vector<string> algorithms = {"Merge Sort", "Heap Sort", "Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort",
                                 "Library Sort", "Tim Sort", "Cocktail Shaker Sort", "Comb Sort", "Tournament Sort", "Intro Sort"};


    for (const auto& algo : algorithms) {
        outputFile << algo << " Average Execution Times:\n";
        
        for (const string& filename : files) {
            double total_duration = 0.0;

            for (int repeat = 0; repeat < 10; ++repeat) {
                std::ifstream file(filename);
                if (!file) {
                    cerr << "Can't read: " << filename << endl;
                    continue;
                }

                std::vector<int> arr;
                int num;
                while (file >> num) {
                    arr.push_back(num);
                }
                file.close();

                auto start = std::chrono::high_resolution_clock::now();


                if (algo == "Merge Sort") Merge_Sort(arr, 0, arr.size() - 1);
                else if (algo == "Heap Sort") Heap_Sort(arr);
                else if (algo == "Bubble Sort") Bubble_Sort(arr);
                else if (algo == "Insertion Sort") Insertion_Sort(arr);
                else if (algo == "Selection Sort") Selection_Sort(arr);
                else if (algo == "Quick Sort") Quick_Sort(arr, 0, arr.size() - 1);

                else if (algo == "Library Sort") Library_Sort(arr);
                else if (algo == "Tim Sort") Tim_Sort(arr);
                else if (algo == "Cocktail Shaker Sort") Cocktail_Shaker_Sort(arr);
                else if (algo == "Comb Sort") Comb_Sort(arr);
                else if (algo == "Tournament Sort") Tournament_Sort(arr);
                else if (algo == "Intro Sort") Intro_Sort(arr);

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = end - start;

                total_duration += duration.count();


                cout << filename << " execution time: " << duration.count() << " Sec" << endl;

                if (!isSorted(arr)) cerr << filename << " It is NOT sorted." << endl;
            }

            double avg_duration = total_duration / 10; 
            outputFile << filename << " average execution time: " << avg_duration << " Sec\n";
        }
    }
    outputFile.close();
    cout << "output.txt is saved." << endl;

    return 0;
}
