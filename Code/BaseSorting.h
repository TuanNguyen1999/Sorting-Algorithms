#ifndef CL_BaseSorting_H_
#define CL_BaseSorting_H_

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

class BaseSorting
{
public:
		BaseSorting(size_t n = 0) : size(n) { myArray = std::vector<int>(size, 0); }
		BaseSorting(const std::vector<int>&);
		BaseSorting(const int*, size_t);
		BaseSorting(const std::string&);
		virtual ~BaseSorting() {}

		// elements assigment
		void increase(int start = -100, int step = 1);
		void decrease(int start = 100, int step = 1);
		void random(int min = -100, int max = 100);

		// modify array order
		void reverse();
		virtual long long sort(size_t = 100) = 0;
		void reset();
		friend std::ostream& operator<<(std::ostream&, const BaseSorting&);
		inline size_t length() const { return size; }
		virtual std::string name() const = 0;

protected:
		std::vector<int> myArray;
		size_t size;
};


#endif
