#include "RadixSort.h"

RadixSort& RadixSort::operator=(const BaseSorting& obj)
{
		return ((*this) = RadixSort(obj));
}

long long RadixSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		auto t1 = std::chrono::system_clock::now();

		// Find highest value
		int nMax = abs(myArray[0]);
		for (size_t i = 1; i < tempSize; i++)
		{
				if (abs(myArray[i]) > nMax)
						nMax = abs(myArray[i]);
		}
		RadixTlk(tempSize, nMax, 1);

		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}

void RadixSort::RadixTlk(size_t temp_size, const int flag, int n)
{
		vector<int> vCategory[19];

		if (flag / n <= 0)	return;

		// Sort digit <log(n)>th of each number to its matching digits category
		for (size_t i = 0; i < temp_size; i++)
		{
				vCategory[myArray[i] / n % 10 + 9].push_back(myArray[i]);
		}

		// Sort array acording to vCategory
		int i = 0;
		for (const auto& digit : vCategory)
		{
				if (!digit.empty())
				{
						for (const auto& n : digit)
						{
								myArray[i++] = n;
						}

				}
		}
		RadixTlk(temp_size, flag, n * 10);
}

string RadixSort::name() const
{
		return string("RadixSort");
}