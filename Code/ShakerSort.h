#ifndef CL_SHAKERSORT_H_
#define CL_SHAKERSORT_H_

#include "BaseSorting.h"

class ShakerSort : public BaseSorting
{
public:
		ShakerSort(size_t n = 0) : BaseSorting(n) {}
		ShakerSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		ShakerSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		ShakerSort(const std::string& file_name) : BaseSorting(file_name) {}
		ShakerSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~ShakerSort() {}
		ShakerSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual std::string name() const { return std::string("ShakerSort"); }
};

#endif