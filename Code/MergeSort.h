#pragma once
#include "BaseSorting.h"
class MergeSort : public BaseSorting
{
public:
		MergeSort(size_t n = 0) : BaseSorting(n) {}
		MergeSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		MergeSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		MergeSort(const std::string& file_name) : BaseSorting(file_name) {}
		MergeSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~MergeSort() {}
		MergeSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual std::string name() const { return std::string("MergeSort"); }

private:
		void partition(int low, int high);
		void merging(int low, int mid, int high);
		void MergeSortTlk(int);
};

