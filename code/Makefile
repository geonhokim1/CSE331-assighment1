CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SRC = main.cpp Merge_Sort.cpp Heap_Sort.cpp Bubble_Sort.cpp Insertion_Sort.cpp Selection_Sort.cpp Quick_Sort.cpp Library_Sort.cpp Tim_Sort.cpp Cocktail_Shaker_Sort.cpp Comb_Sort.cpp Tournament_Sort.cpp Intro_Sort.cpp
HEADERS = Merge_Sort.h Heap_sort.h Bubble_Sort.h Insertion_Sort.h Selection_Sort.h Quick_Sort.h Library_Sort.h Tim_Sort.h Cocktail_Shaker_Sort.h Comb_Sort.h Tournament_Sort.h Intro_Sort.h

TARGET = sort_program

FILES = $(wildcard *.txt)

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)
	
run: $(TARGET)
	./$(TARGET) $(FILES)