#include "BubbleSort.h"

BubbleSort& BubbleSort::operator=(const BaseSorting& obj)
{
		return ((*this) = BubbleSort(obj));
}
long long BubbleSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		auto t1 = std::chrono::system_clock::now();
		for (size_t i = 1; i < tempSize; i++)
		{
				for (size_t j = 0; j < tempSize - i; j++)
				{
						if (myArray[j + 1] < myArray[j])
								std::swap(myArray[j + 1], myArray[j]);
				}
		}
		auto t2 = std::chrono::system_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}

