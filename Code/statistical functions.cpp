#include "statistical functions.h"
#include "RadixSort.h"

static string resultFolder = "ThongKe";
static string dataFolder = "DataBase";

void ghi_du_lieu(const BaseSorting& algorithm, size_t size, const string &state)
{
		string arrSize = std::to_string(size);
		string file = state + string("_") + arrSize;
		std::ofstream fWrite(dataFolder + string("\\") + file + string(".txt"));
		fWrite << state << ", " << algorithm.length() << std::endl << std::endl;
		fWrite << algorithm << std::endl;
}


void ghi_ket_qua(const BaseSorting& algorithm, const string& state, const long long &thoi_gian)
{
		string arrSize = std::to_string(algorithm.length());
		string out = algorithm.name() + string("_") + state + string("_") + arrSize;
		string path = resultFolder + string("\\") + algorithm.name() + string("\\") + out + string(".txt");

		std::ofstream fWrite(path);

		fWrite << algorithm.name() << ", " << state << ", " << algorithm.length() << ", " << thoi_gian << std::endl << std::endl;
		fWrite << algorithm << std::endl;

		return;
}

void xay_dung_csdl(const vector<string> &states, const vector<std::size_t> &sizes)
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
						}
						else if (states[j] == states[1])
						{
								sample.decrease(size / 2);
						}
						else if (states[j] == states[2])
						{
								sample.random(-(int)((float)size*2.0f), (int)((float)size*2.0f));
						}
						else
						{
								sample.random(-(int)((float)size*2.0f), (int)((float)size*2.0f));
								sample.sort(78);
						}
						ghi_du_lieu(sample, size, states[j]);
				}

		}
		//-----------------------------------------------------------
}

void thong_ke(const vector<BaseSorting*>& vecAlgorithm, const vector<string>& vecStates, const vector<std::size_t>& vecSizes)
{
		using std::getline;

		//----------------- WARNING!!! HARDCODED PART---------------------
		if (vecAlgorithm.empty() || vecSizes.empty() || vecStates.empty())
				throw std::invalid_argument("thong_ke()");

		string header = string("Input State, Input Size, ");

		for (const auto& algorithm : vecAlgorithm)
		{
				header += algorithm->name() + string(",");
		}

		std::ofstream fWrite(resultFolder + string("\\") + string("Result.csv"));
		fWrite << header << std::endl;

		for (const auto &size : vecSizes)
		{
				for (const auto &state : vecStates)
				{
						fWrite << state << ", " << size << ", ";
						for (const auto &algorithm : vecAlgorithm)
						{
								string file = algorithm->name() + string("_") +
										state + string("_") +
										std::to_string(size);
								string path = resultFolder + string("\\") +
										algorithm->name() + string("\\") +
										file + string(".txt");

								std::ifstream fRead(path);
								if (!fRead.is_open())
										throw std::runtime_error("Invalid path");

								// Đọc dữ liệu từ các file kết quả
								// chỉ đọc dòng đầu tiên
								// cấu trúc file đọc
								// tên_thuật_toán, tình_trạng, kích_thước, thời_gian_xử_lí

								string name;
								getline(fRead, name, ',');

								string state;
								getline(fRead, state, ',');

								string size;
								getline(fRead, size, ',');

								string elapsed;
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

void chay_thuat_toan(const vector<BaseSorting*>& vecAlgorithm, const vector<string>& vecStates, const vector<std::size_t>& vecSizes)
{
		for (const auto& size : vecSizes)
		{
				std::cout << "size = " << size << std::endl;
				for (const auto& state : vecStates)
				{
						std::cout << "\tstate = " << state << std::endl;
						string dataFile = state + string("_") + std::to_string(size);
						string path = dataFolder + string("\\") + dataFile;
						for (const auto& algorithm : vecAlgorithm)
						{
								*algorithm = RadixSort(path);
								long long elapsed = algorithm->sort();
								std::cout << "\t\tAlgorithm = " << algorithm->name() << std::endl;
								algorithm->reset();
						}
				}
		}
}