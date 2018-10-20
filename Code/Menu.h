#ifndef MENU_H_
#define MENU_H_

#include "BaseSorting.h"
#include <iomanip>
#include <sstream>

template<typename T>
int CacLenh(const vector<T>&);

template<typename T>
int CacLenh<T>(const std::vector<T>& cacLenh)
{
		using std::string;

		if (cacLenh.empty())
				return -1;

		string strChoice;
		int choice;
		size_t i;
		while (1)
		{
				system("cls");
				std::stringstream ss;
				for (i = 1; i <= cacLenh.size(); i++)
				{
						std::cout << std::setw(3) << ' ' << i << ". " << cacLenh[i - 1] << std::endl;
				}
				std::cout << std::setw(3) << ' ' << i << ". " << "Thoat" << std::endl;

				std::cout << "Nhap lenh: ";
				std::getline(std::cin, strChoice);

				ss << strChoice;
				if (ss >> choice)
				{
						if (choice >= 1 && choice <= i)
								return choice;
				}

		}
}

void sort(BaseSorting* algrm, string state, size_t size);

void run();
#endif
