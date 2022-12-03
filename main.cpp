#include "matmul.h"
#include <string>

int test(const CalcType ct){
    matrix m1(5, 2), m2(2, 1);
    double reference[5] = {5, 3, 1, -1, -3};
	matrix result(5, 1);
	MatMul::calc(ct, m1, m2, result);
	for(unsigned i = 0; i < 5; ++i){
		if(result.M[i][0] != reference[i]){
			return 1;
		}
	}
    return 0;
}

int main() {
	matrix m1(5, 2), m2(2, 1);
	//std::cout << "M1" << std::endl;
	//m1.print();
	//std::cout << "M2" << std::endl;
	//m2.print();
	matrix result(5, 1);
	MatMul::calc(CalcType::ByRows, m1, m2, result);
	//std::cout << "Result" << std::endl;
	//result.print();
	if(test(CalcType::ByRows) == 1){
		std::cout << "ERROR" << std::endl;
	}else{
		std::cout <<"Correct" << std::endl;
	}
	Metric M("output.txt", 100);
	M.eval();
	return 0;
}
