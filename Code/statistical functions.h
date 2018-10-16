#ifndef STATISTICAL_FUNCTIONS_H_
#define STATISTICAL_FUNCTIONS_H_

#include "BaseSorting.h"
#include <fstream>

void ghi_du_lieu(const BaseSorting& algorithm, size_t size, const std::string &state);

void ghi_ket_qua(const BaseSorting& algorithm, const std::string& state,const long long &thoi_gian);

void thong_ke(const std::vector<BaseSorting*>&, const std::vector<std::string>&, const std::vector<std::size_t>&);

void xay_dung_csdl(const std::vector<std::string>&, const std::vector<std::size_t>&);

void chay_thuat_toan(const std::vector<BaseSorting*>&, const std::vector<std::string>&, const std::vector<std::size_t>&);
#endif
