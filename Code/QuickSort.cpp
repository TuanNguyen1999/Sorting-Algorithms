#include "QuickSort.h"

QuickSort& QuickSort::operator=(const BaseSorting& obj)
{
		return ((*this) = QuickSort(obj));
}

long long QuickSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		int tempSize = (int)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 0) return 0;

		auto t1 = std::chrono::system_clock::now();
		QuickSortTlk(0, tempSize - 1);
		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}
void QuickSort::QuickSortTlk(int low, int high)
{
		if (high <= low)	return;

		// Choose an element as pivot
		size_t pivot = (low + high) / 2;

		// Find the right index
		size_t iIndex = find_pivot_index(pivot, low, high);
		// Recursively performing again with the left and right side
		QuickSortTlk(low, iIndex - 1);			// left side
		QuickSortTlk(iIndex + 1, high);			// right side
		
		return;
}
size_t QuickSort::find_pivot_index(size_t pivot, int low, int high)
{
		// Bring <high> element to its correct position and return that position
		int iSmaller = low - 1;							// When looping this var represents the index whose value bigger then pivot's;
																				// After looping finished it stores the last element whose value is smaller then pivot's
		int key = myArray[pivot];
		for (int i = low; i <= high; i++)
		{
				if (myArray[i] < key)
				{
						// Push bigger values to the end
						// by swapping them with smaller ones
						// everytime encounter an <ith> element whose value is smaller than pivot's

						iSmaller++;
						std::swap(myArray[i], myArray[iSmaller]);

						// pivot may be swapped some where when isSmaller == pivot
						// make sure to keep track pivot
						if (iSmaller == pivot)
								pivot = i;
				}
		}

		std::swap(myArray[iSmaller + 1], myArray[pivot]);
		return iSmaller + 1;
}
