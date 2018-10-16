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

		// Find highest value
		int nMax = myArray[0];
		for (size_t i = 1; i < tempSize; i++)
		{
				if (myArray[i] > nMax)
						nMax = myArray[i];
		}

		auto t1 = std::chrono::system_clock::now();
		CoutingTlk(tempSize, nMax, 1);
		auto t2 = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return elapsed.count();
}
void CoutingSort::CoutingTlk(size_t temp_size, const int flag, int n)
{
		static int aDigits[19]{ -9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9 };
		std::vector<int> output(temp_size, 0);

		std::vector<size_t> vCount(19,0);

		if (flag / n <= 0) {
				return;
		}

		// Count number of occurrences of each digit
		for (size_t i = 0; i < temp_size; i++)
		{
				vCount[myArray[i] / n % 10 + 9]++;
		}

		// modify vCount so that each element is the sum of previous element
		for (size_t i = 1; i < 19; i++)
		{
				vCount[i] += vCount[i - 1];
		}

		// Sort array acording to vCount
		for (int i = temp_size - 1; i >= 0; i--)
		{
				size_t &nCount = vCount[myArray[i] / n % 10 + 9];
				output[nCount - 1] = myArray[i];
				nCount--;
		}

		// copy values from output to myArray
		for (size_t i = 0; i < temp_size; i++)
		{
				myArray[i] = output[i];
		}

		CoutingTlk(temp_size, flag, n * 10);
}
std::string CoutingSort::name() const
{
		return std::string("CoutingSort");
}