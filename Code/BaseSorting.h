#ifndef CL_BaseSorting_H_
#define CL_BaseSorting_H_

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using std::string;
using std::vector;

class BaseSorting
{
public:
		BaseSorting(size_t n = 0) : size(n) { myArray = vector<int>(size, 0); }
		BaseSorting(const vector<int>&);
		BaseSorting(const int*, size_t);
		BaseSorting(const string&);
		virtual ~BaseSorting() {}

		// elements assigment
		void increase(int start = -100, int step = 1);
		void decrease(int start = 100, int step = 1);
		void random(int min = -100, int max = 100);

		// modify array order
		void reverse();
		inline void resize(size_t new_size) { size = new_size; myArray.resize(size); }
		virtual long long sort(size_t = 100) = 0;
		void reset();

		friend std::ostream& operator<<(std::ostream&, const BaseSorting&);
		inline size_t length() const { return size; }
		virtual string name() const = 0;

protected:
		vector<int> myArray;
		size_t size;
};


#endif
