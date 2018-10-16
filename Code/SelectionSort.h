#ifndef CL_SELECTIONSORT_H_
#define CL_SELECTIONSORT_H_

#include "BaseSorting.h"
class SelectionSort : public BaseSorting
{
public:
		SelectionSort(size_t n = 0) : BaseSorting(n) {}
		SelectionSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		SelectionSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		SelectionSort(const std::string& file_name) : BaseSorting(file_name) {}
		SelectionSort(const BaseSorting& obj) : BaseSorting(obj) {}
		SelectionSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual ~SelectionSort() {}
		virtual std::string name() const;
};

#endif
