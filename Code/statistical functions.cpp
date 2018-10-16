#include "statistical functions.h"
#include "RadixSort.h"

static std::string resultFolder = "ThongKe";
static std::string dataFolder = "DataBase";

void ghi_du_lieu(const BaseSorting& algorithm, size_t size, const std::string &state)
{
		std::string arrSize = std::to_string(size);
		std::string file = state + std::string("_") + arrSize;
		std::ofstream fWrite(dataFolder + std::string("\\") + file + std::string(".txt"));
		fWrite << state << ", " << algorithm.length() << std::endl << std::endl;
		fWrite << algorithm << std::endl;
}


void ghi_ket_qua(const BaseSorting& algorithm, const std::string& state, const long long &thoi_gian)
{
		std::string arrSize = std::to_string(algorithm.length());
		std::string out = algorithm.name() + std::string("_") + state + std::string("_") + arrSize;
		std::string path = resultFolder + std::string("\\") + algorithm.name() + std::string("\\") + out + std::string(".txt");

		std::ofstream fWrite(path);

		fWrite << algorithm.name() << ", " << state << ", " << algorithm.length() << ", " << thoi_gian << std::endl << std::endl;
		fWrite << algorithm << std::endl;

		return;
}

void xay_dung_csdl(const std::vector<std::string> &states, const std::vector<std::size_t> &sizes)
{
		if (states.empty() || sizes.empty())
				throw std::invalid_argument("xay_dung_csdl()");

		//----------------- WARNING!!! HARDCODED PART---------------------
		for (size_t i = 0; i < sizes.size(); i++)
		{
				size_t size = sizes[i];
				for (size_t j = 0; j < states.size(); j++)
				{
						RadixSort sample(size);
						if (states[j] == states[0])
						{
								sample.increase(-(int)(size / 2));
								ghi_du_lieu(sample, size, states[j]);
						}
						else if (states[j] == states[1])
						{
								sample.decrease(size / 2);
								ghi_du_lieu(sample, size, states[j]);
						}
						else if (states[j] == states[2])
						{
								sample.random(-(int)((float)size*1.5f), (int)((float)size*1.5f));
								ghi_du_lieu(sample, size, states[j]);
						}
						else
						{
								sample.random(-(int)((float)size*1.5f), (int)((float)size*1.5f));
								sample.sort(78);
								ghi_du_lieu(sample, size, states[j]);
						}
				}

		}
		//-----------------------------------------------------------
}

void thong_ke(const std::vector<BaseSorting*>& vecAlgorithm, const std::vector<std::string>& vecStates, const std::vector<std::size_t>& vecSizes)
{
		using std::getline;

		//----------------- WARNING!!! HARDCODED PART---------------------
		if (vecAlgorithm.empty() || vecSizes.empty() || vecStates.empty())
				throw std::invalid_argument("thong_ke()");

		//std::string header = std::string("Input State, Input Size, SelectionSort, RadixSort, ") +
		//		std::string("CoutingSort, QuickSort, MergeSort, ") +
		//		std::string("HeapSort, InsertionSort, BubbleSort, InterchangeSort, ShakerSort");

		std::string header = std::string("Input State, Input Size, ");

		for (const auto& algorithm : vecAlgorithm)
		{
				header += algorithm->name() + std::string(",");
		}

		std::ofstream fWrite(resultFolder + std::string("\\") + std::string("Result.csv"));
		fWrite << header << std::endl;

		for (const auto &size : vecSizes)
		{
				for (const auto &state : vecStates)
				{
						fWrite << state << ", " << size << ", ";
						for (const auto &algorithm : vecAlgorithm)
						{
								std::string file = algorithm->name() + std::string("_") +
										state + std::string("_") +
										std::to_string(size);
								std::string path = resultFolder + std::string("\\") +
										algorithm->name() + std::string("\\") +
										file + std::string(".txt");

								std::ifstream fRead(path);
								if (!fRead.is_open())
										throw std::runtime_error("Invalid path");

								// Đọc dữ liệu từ các file kết quả
								// chỉ đọc dòng đầu tiên
								// cấu trúc file đọc
								// tên_thuật_toán, tình_trạng, kích_thước, thời_gian_xử_lí

								std::string name;
								getline(fRead, name, ',');

								std::string state;
								getline(fRead, state, ',');

								std::string size;
								getline(fRead, size, ',');

								std::string elapsed;
								getline(fRead, elapsed);

								// cấu trúc file Result.csv
								// tình_trạng, kích_thước, <thời_gian_xử_lí_thuật_toán_1>, [thời_gian_xử_lí_thuật_toán_2],...
								fWrite << elapsed << ", ";
						}
						fWrite << "\n";
				}
		}
		//-----------------------------------------------------------

}

void chay_thuat_toan(const std::vector<BaseSorting*>& vecAlgorithm, const std::vector<std::string>& vecStates, const std::vector<std::size_t>& vecSizes)
{
		for (const auto& size : vecSizes)
		{
				std::cout << "size = " << size << std::endl;
				for (const auto& state : vecStates)
				{
						std::cout << "state = " << state << std::endl;
						std::string dataFile = state + std::string("_") + std::to_string(size);
						std::string path = dataFolder + std::string("\\") + dataFile;
						for (const auto& algorithm : vecAlgorithm)
						{
								*algorithm = RadixSort(path);
								long long elapsed = algorithm->sort();
								ghi_ket_qua(*algorithm, state, elapsed);
								std::cout << "Algorithm = " << algorithm->name() << std::endl;
								algorithm->reset();
						}
				}
		}
}