#ifndef CL_InterchangeSort_H_
#define CL_InterchangeSort_H_

#include "BaseSorting.h"

class InterchangeSort : public BaseSorting
{
public:
		InterchangeSort(size_t n = 0) : BaseSorting(n) {}
		InterchangeSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		InterchangeSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		InterchangeSort(const std::string& file_name) : BaseSorting(file_name) {}
		InterchangeSort(const BaseSorting& obj) : BaseSorting(obj) {}
		virtual ~InterchangeSort() {}
		InterchangeSort& operator=(const BaseSorting& obj);
		virtual long long sort(size_t = 100);
		virtual std::string name() const { return std::string("InterchangeSort"); }
};

#endif
