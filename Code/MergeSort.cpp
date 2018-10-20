#include "MergeSort.h"

MergeSort& MergeSort::operator=(const BaseSorting& obj)
{
		return ((*this) = MergeSort(obj));
}
long long MergeSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		int tempSize = (int)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		auto t1 = std::chrono::system_clock::now();
		MergeSortTlk(tempSize);
		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}
void MergeSort::MergeSortTlk(int temp_size)
{
		int mid = (temp_size - 1) / 2;

		partition(0, mid);
		partition(mid + 1, temp_size - 1);
		merging(0, mid, temp_size - 1);

		return;
}

void MergeSort::partition(int low,int high)
{
		// Split array into 2 child ones until they have only 1 element
		// then start merging them
		// process terminates when merging 2 arrays to initial one

		if (high <= low)   return;

		int mid = (high + low) / 2;
		partition(low, mid);
		partition(mid + 1, high);
		merging(low, mid, high);

		return;
}

void MergeSort::merging(int low, int mid, int high)
{
		if (myArray[mid + 1] >= myArray[mid])  return;  // No need to sort anything

		// Create a temp array, use it to contain sorted elements
		// Then properly copy this array to arr

		vector<int> temp(high - low + 1);
		int i = low;
		int j = mid + 1;
		int iNow = 0;

		while (i <= mid && j <= high)
		{
				if (myArray[i] == myArray[j])
				{
						temp[iNow] = temp[iNow + 1] = myArray[i];
						iNow += 2; j++; i++;
				}
				else if (myArray[i] < myArray[j])
				{
						temp[iNow++] = myArray[i++];
				}
				else  temp[iNow++] = myArray[j++];
		}

		while (i <= mid)
				temp[iNow++] = myArray[i++];
		while (j <= high)
				temp[iNow++] = myArray[j++];

		// Copy temp
		for (size_t i = 0; i < temp.size(); i++)
		{
				myArray[low + i] = temp[i];
		}

		return;
}
