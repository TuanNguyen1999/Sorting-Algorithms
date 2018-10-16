#pragma once
#include "BaseSorting.h"
class BubbleSort : public BaseSorting
{
public:
		BubbleSort(size_t n = 0) : BaseSorting(n) {}
		BubbleSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		BubbleSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		BubbleSort(const std::string& file_name) : BaseSorting(file_name) {}
		BubbleSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~BubbleSort() {}
		BubbleSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual std::string name() const { return std::string("BubbleSort"); }
};

