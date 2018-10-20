#include "SelectionSort.h"
#include "RadixSort.h"
#include "CoutingSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "InterchangeSort.h"
#include "BubbleSort.h"
#include "ShakerSort.h"

#include "statistical functions.h"
#include "Menu.h"

#include <ctime>

static string resultFolder = "ThongKe";
static string dataFolder = "DataBase";

int main()
{
		std::srand(std::time(0));

		const vector<string> vecStates = { "Sorted", "Reversed", "Random","NearlySorted" };
		const vector<size_t> vecSizes = { 1000,5000,10000,50000,100000,250000 };
		const vector<string> cmdAlgorithms = { 
				"SelectionSort","RadixSort","CoutingSort",
				"QuickSort","MergeSort","HeapSort",
				"InsertionSort","InterchangeSort","BubbleSort","ShakerSort", "Chay yeu cau do an (thoi gian > 30m)"
		};
		const vector<string> vecSmallSizes = { "10", "50", "70", "100", "150", "200","So khac" };

		long long elapsed = 0ll;

		SelectionSort select;
		RadixSort radix;
		CoutingSort couting;
		QuickSort quick;
		MergeSort merge;
		HeapSort heap;
		InsertionSort insertion;
		InterchangeSort interchange;
		BubbleSort bubble;
		ShakerSort shaker;

		vector<BaseSorting*> vecAlgorithm = {
				&select, &radix,&insertion,
				&couting,&shaker, &merge, &heap,
				&quick,&interchange, &bubble,
		};

		bool bBuildData = false;				// change to true if want to rebuild database
		bool bRunAlgorithm = false;			// change to true if want to run sorting algorithms

		int m_thuatToan, m_state, m_size;
		string sState;
		string sSize;
		size_t size;
		BaseSorting* sample = nullptr;

		while (1)
		{
				m_thuatToan = CacLenh(cmdAlgorithms);
				switch (m_thuatToan)
				{
				case 1:
				{
						sample = &select;
						break;
				}
				case 2:
				{
						sample = &radix;
						break;
				}
				case 3:
				{
						sample = &couting;
						break;
				}
				case 4:
				{
						sample = &quick;
						break;
				}
				case 5:
				{
						sample = &merge;
						break;
				}
				case 6:
				{
						sample = &heap;
						break;
				}
				case 7:
				{
						sample = &insertion;
						break;
				}
				case 8:
				{
						sample = &interchange;
						break;
				}
				case 9:
				{
						sample = &bubble;
						break;
				}
				case 10:
				{
						sample = &shaker;
						break;
				}
				case 11:
				{
						string ch;
						std::cout << "Ban co chac chan khong?(y/n): ";
						std::getline(std::cin, ch);
						if (ch[0] == 'Y' || ch[0] == 'y')
						{
								std::cout << "Xay dung co so du lieu....\n";
								xay_dung_csdl(vecStates, vecSizes);

								std::cout << "Hoan Tat!\nChay thuat toan....\n";
								chay_thuat_toan(vecAlgorithm, vecStates, vecSizes);

								std::cout << "Hoan Tat!\nGhi ket qua vao file....\n";
								thong_ke(vecAlgorithm, vecStates, vecSizes);

								std::cout << "Hoan Tat! Vui long xem ket qua trong thu muc DataBase va ThongKe\n";
						}
						continue;
				}
				default:
						exit(0);
				}

				while (1)
				{
						m_state = CacLenh(vecStates);
						if (m_state >= 1 && m_state < vecStates.size() + 1)
						{
								sState = vecStates[m_state - 1];
						}
						else
								break;

						m_size = CacLenh(vecSmallSizes);
						if (m_size >= 1 && m_size < vecSmallSizes.size())
						{
								sSize = vecSmallSizes[m_size - 1];
								size = (size_t)strtol(sSize.c_str(), nullptr, 10);
						}
						else if (m_size == vecSmallSizes.size())
						{
								std::cout << "Nhap kich thuoc: ";
								int len;
								if (std::cin >> len)
								{
										size = (size_t)abs(len);
								}
								else
								{
										std::cout << "Loi! Huy bo lenh.\n";
										std::cin.clear();
										std::cin.ignore(INT_MAX, '\n');
								}
						}
						else
						{
								continue;
						}
						sort(sample, sState, size);
						break;
				}	
		}

		return 0;
}
