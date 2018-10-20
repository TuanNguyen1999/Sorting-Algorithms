#include "Menu.h"

#include <iostream>
#include <sstream>

#include "RadixSort.h"

void sort(BaseSorting* algrm, string state, size_t size)
{
		using std::cout;
		using std::cin;
		using std::endl; 

		const static vector<string> states = { "Sorted", "Reversed", "Random","NearlySorted" };
		algrm->resize(size);

		if (state == states[0])
		{
				algrm->increase(-(int)(size / 2));
		}
		else if (state == states[1])
		{
				algrm->decrease(size / 2);
		}
		else if (state == states[2])
		{
				algrm->random(-(int)((float)size*2.0f), (int)((float)size*2.0f));
		}
		else
		{
				RadixSort temp(size);
				temp.random(-(int)((float)size*2.0f), (int)((float)size*2.0f));
				temp.sort(78);
				*algrm = temp;
		}

		bool bPrint;
		string ch;
		cout << "Ban co muon xuat mang ra man hinh?(y/n): ";
		std::getline(cin, ch);
		if (ch[0] == 'Y' || ch[0] == 'y')
				bPrint = true;
		else
				bPrint = false;

		if (bPrint)
		{
				cout << "Mang ban dau:\n" << *algrm << endl;
				cout << "Dang sap xep....\n";
				long long eslapsed = algrm->sort();
				cout << "Hoan thanh! Mang sau khi sap xep:\n" << *algrm << endl
						<< "Thoi gian sap xep: " << eslapsed << endl;
		}

		algrm->reset();

		string close;
		cout << "Bam Enter de quay ve...";
		std::getline(cin, close);
}

void run()
{

		return;
}