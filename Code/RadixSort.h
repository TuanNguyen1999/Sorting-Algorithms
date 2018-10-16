#ifndef CL_RADIXSORT_H_
#define CL_RADIXSORT_H_

#include "BaseSorting.h"

class RadixSort : public BaseSorting
{
public:
		RadixSort(size_t n = 0) : BaseSorting(n) {}
		RadixSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		RadixSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		RadixSort(const std::string& file_name) : BaseSorting(file_name) {}
		RadixSort(const BaseSorting& obj) : BaseSorting(obj) {}
		RadixSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual ~RadixSort() {}
		virtual std::string name() const;

private:
		void RadixTlk(size_t, const int flag, int n);
};

#endif
