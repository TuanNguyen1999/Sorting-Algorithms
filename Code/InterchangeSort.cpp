#include "InterchangeSort.h"



InterchangeSort& InterchangeSort::operator=(const BaseSorting& obj)
{
		return ((*this) = InterchangeSort(obj));
}

long long InterchangeSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		auto t1 = std::chrono::system_clock::now();
		for (size_t i = 0; i < tempSize - 1; i++)
		{
				for (size_t j = i + 1; j < tempSize; j++)
				{
						if (myArray[j] < myArray[i])
								std::swap(myArray[i], myArray[j]);
				}
		}
		auto t2 = std::chrono::system_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}
