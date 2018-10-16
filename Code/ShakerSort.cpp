#include "ShakerSort.h"

ShakerSort& ShakerSort::operator=(const BaseSorting& obj)
{
		return ((*this) = ShakerSort(obj));
}
long long ShakerSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;


		int low = 0, high = tempSize - 1;
		bool bSorted = true;

		auto t1 = std::chrono::system_clock::now();
		while (low < high)
		{
				if (!bSorted)		break;
				bSorted = false;

				for (int i = low; i < high; i++)
				{
						if (myArray[i] > myArray[i + 1])
						{
								std::swap(myArray[i], myArray[i + 1]);
								bSorted = true;
						}
				}
				high--;

				for (int i = high; i > low; i--)
				{
						if (myArray[i] < myArray[i - 1])
						{
								std::swap(myArray[i], myArray[i - 1]);
								bSorted = true;
						}
				}
				low++;
		}
		auto t2 = std::chrono::system_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}

