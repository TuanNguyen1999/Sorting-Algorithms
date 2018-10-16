#include "HeapSort.h"

HeapSort& HeapSort::operator=(const BaseSorting& obj)
{
		return ((*this) = HeapSort(obj));
}

long long HeapSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		auto t1 = std::chrono::system_clock::now();
		HeapSortTlk(tempSize);
		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}

void HeapSort::HeapSortTlk(size_t temp_size)
{

		// Pull the highest value to root
		// Go from last parent to root
		for (int i = (int)(temp_size / 2 - 1); i >= 0; i--)
		{
				pull(i, temp_size);
		}

		for (int i = (int)temp_size - 1; i >= 0; i--)
		{
				// Swap root and last element
				std::swap(myArray[0], myArray[i]);

				// Repeat with previous size - 1 elements
				pull(0, i);
		}

		return;
}
void HeapSort::pull(size_t parent, size_t temp_size)
{
		size_t max = parent;

		// Find index whose value is the highest
		if (parent * 2 + 1 < temp_size)
		{
				if (myArray[parent * 2 + 1] > myArray[max])
						max = parent * 2 + 1;
		}

		if (parent * 2 + 2 < temp_size)
		{
				if (myArray[parent * 2 + 2] > myArray[max])
						max = parent * 2 + 2;
		}

		if (max != parent)
		{
				std::swap(myArray[parent], myArray[max]);
				pull(max, temp_size);
		}

		return;
}
