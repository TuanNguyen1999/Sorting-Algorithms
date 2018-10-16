#pragma once
#include "BaseSorting.h"
class CoutingSort :	public BaseSorting
{
public:
		CoutingSort(size_t n = 0) : BaseSorting(n) {}
		CoutingSort(const std::vector<int> &vec) : BaseSorting(vec) {}
		CoutingSort(const int* arr, size_t n) : BaseSorting(arr, n) {}
		CoutingSort(const std::string& file_name) : BaseSorting(file_name) {}
		CoutingSort(const BaseSorting& obj) : BaseSorting(obj) {}
		CoutingSort& operator=(const BaseSorting& obj);
		virtual ~CoutingSort() {}

		virtual long long sort(size_t = 100);
		virtual std::string name() const;

private:
		void CoutingTlk(size_t, const int flag, int n);
};

