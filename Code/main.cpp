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

#include <ctime>

static std::string resultFolder = "ThongKe";
static std::string dataFolder = "DataBase";

int main()
{

		std::srand(std::time(0));
		const std::vector<std::string> vecStates = { "Sorted", "Reversed", "Random","NearlySorted" };
		const std::vector<std::size_t> vecSizes = { 1000,5000,10000,50000,100000,250000 };

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

		std::vector<BaseSorting*> vecAlgorithm = {
				&select, &radix,&insertion,
				&couting,&shaker, &merge, &heap,
				&quick,&interchange, &bubble,
		};

		bool bBuildData = false;				// change to true if want to rebuild database
		bool bRunAlgorithm = false;			// change to true if want to run sorting algorithms

		if (bBuildData)
				xay_dung_csdl(vecStates, vecSizes);

		if (bRunAlgorithm)
				chay_thuat_toan(vecAlgorithm, vecStates, vecSizes);

		thong_ke(vecAlgorithm, vecStates, vecSizes);
		return 0;
}
