#pragma once
#include "BaseSorting.h"
class QuickSort : public BaseSorting
{
public:
		QuickSort(size_t n = 0) : BaseSorting(n) {}
		QuickSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		QuickSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		QuickSort(const std::string& file_name) : BaseSorting(file_name) {}
		QuickSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~QuickSort() {}
		QuickSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual std::string name() const { return std::string("QuickSort"); }

private:
		void QuickSortTlk(int low, int high);
		size_t find_pivot_index(size_t pivot, int low, int high);
};

