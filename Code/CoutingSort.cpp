#include "CoutingSort.h"


CoutingSort& CoutingSort::operator=(const BaseSorting& obj)
{
		return ((*this) = CoutingSort(obj));
}
long long CoutingSort::sort(size_t percent)
{
		if (myArray.empty()) return 0;
		while (percent > 100) percent -= 100;

		// temporarily modifying size according to percent
		size_t tempSize = (size_t)((float)this->size / 100.0f * (float)percent);
		if (tempSize <= 1) return 0;

		// Find highest and smallest values
		int nMax = myArray[0];
		int nMin = myArray[0];
		for (size_t i = 1; i < tempSize; i++)
		{
				if (myArray[i] > nMax)
						nMax = myArray[i];
				if (myArray[i] < nMin)
						nMin = myArray[i];
		}

		auto t1 = std::chrono::system_clock::now();
		CoutingTlk(tempSize, nMin, nMax);
		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}
void CoutingSort::CoutingTlk(size_t temp_size, int min, int max)
{

		vector<int> output(temp_size);

		int range = max - min + 1;
		vector<int> vCount(range, 0);

		// Count number of occurrences of each key
		for (size_t i = 0; i < temp_size; i++)
		{
				vCount[myArray[i] - min]++;
		}

		// modify vCount so that each element is the sum of previous element
		for (size_t i = 1; i < range; i++)
		{
				vCount[i] += vCount[i - 1];
		}

		// Sort array acording to vCount
		for (auto& value : myArray)
		{
				output[vCount[value - min] - 1] = value;
				vCount[value - min]--;
		}

		myArray = output;
		return;
}
string CoutingSort::name() const
{
		return string("CoutingSort");
}