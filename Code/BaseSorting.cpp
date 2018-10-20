
#include "BaseSorting.h"
#include <fstream>
#include <cmath>
#include <iomanip>

BaseSorting::BaseSorting(const vector<int>& vec) : size(vec.size()), myArray(vec) {}

BaseSorting::BaseSorting(const string &file_name) : size(0)
{
		using std::ifstream;
		string fn;
		size_t pos = file_name.rfind(".txt");
		(pos != string::npos) ? fn = file_name : fn = file_name + string(".txt");
		ifstream rf(fn);
		if (!rf.is_open())
		{
				std::cout << "Can't open file\nFile may not exist.\n";
				return;
		}
		//	WARNING!!!! Viet theo cau truc file cau de bai
		string ignore;
		std::getline(rf, ignore);
		//
		while(rf.good())
		{
				int num;
				if (rf >> num)
				{
						myArray.push_back(num);
						size++;
				}
		}
		if (!rf.eof())
		{
				std::cout << "An error happened while reading file.\nOnly some data have been read.\n";
		}
}
BaseSorting::BaseSorting(const int* arr, size_t n) : size(n)
{
		for (size_t i = 0; i < n; i++)
				myArray.push_back(arr[i]);
}
void BaseSorting::random(int min, int max)
{
		if (size == 0) return;
		for (size_t i = 0; i < size; i++)
		{
				myArray[i] = rand() % (max - min + 1) + min;
		}
}
void BaseSorting::increase(int start, int step)
{
		if (myArray.empty())	return;
		for (size_t i = 0; i < size; i++)
		{
				myArray[i] = start;
				start += step;
		}
}
void BaseSorting::decrease(int start, int step)
{
		increase(start, -step);
}
void BaseSorting::reverse()
{
		if (myArray.empty())	return;
		for (size_t i = 0; i <= (size-1) / 2; i++)
		{
				std::swap(myArray[i], myArray[size - 1 - i]);
		}
}
void BaseSorting::reset()
{
		myArray.clear();
		size = 0;
}
std::ostream& operator<<(std::ostream& os, const BaseSorting& obj)
{
		if (obj.myArray.empty())
		{
				os << "Empty Array!\n";
				return os;
		}

		// Find max value
		size_t max = 0;
		for (size_t i = 1; i < obj.size; i++)
		{
				if (std::abs(obj.myArray[i]) > std::abs(obj.myArray[max]))
						max = i;
		}
		int maxValue = abs(obj.myArray[max]);
		int offset = log10l((long)maxValue) + 1 + 1;		//for minus character

		int initState = os.setf(std::ios_base::right, offset);

		int i = 1;
		int nCols = 25;
		for (size_t k = 0; k < obj.size; k++)
		{
				os << std::setw(offset);
				os << obj.myArray[k] << ' ';
				if (i % nCols == 0)
						os << std::endl;
				i++;
		}
		os << std::endl;

		// return to normal state
		os.setf(initState);
		return os;
}