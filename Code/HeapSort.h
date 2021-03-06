#pragma once
#include "BaseSorting.h"
class HeapSort :
		public BaseSorting
{
public:
		HeapSort(size_t n = 0) : BaseSorting(n) {}
		HeapSort(const vector<int> &vec) : BaseSorting(vec) {}
		HeapSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		HeapSort(const string& file_name) : BaseSorting(file_name) {}
		HeapSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~HeapSort() {}
		HeapSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual string name() const { return string("HeapSort"); }

private:
		void HeapSortTlk(size_t);
		void pull(size_t parent, size_t temp_size);
};


