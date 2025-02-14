#pragma once
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <fstream>

#include<iostream>

enum CalcType{
	ByColumns,
	ByRows,
	ByBlocks
};

enum MatrixParam{
	row,
	column,
	cell
};

struct matrix {
	unsigned n, m;
	double **M;
	matrix(const unsigned _n, const unsigned _m);
	matrix(double** _M, unsigned _n, unsigned _m);
	matrix(const matrix& mtrx, const unsigned row, const unsigned column, const MatrixParam mp);
	~matrix();
	//matrix(const matrix&) = delete;
	matrix& operator=(const matrix& mtrx);
	
	// temp
	void print() {
		for (unsigned i = 0; i < n; ++i) {
			for (unsigned j = 0; j < m; ++j) {
				std::cout << M[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

class MatMul {
public:
	static void* mul_by_columns(void* args);
	static void* mul_by_rows(void* args);
	static void* mul_by_blocks(void* args);
	static void calc(const CalcType ct, const matrix& m1, const matrix& m2, matrix& result);
};

class Metric{
	std::ofstream file;
	unsigned iter_num;
public:
	Metric(const std::string metric_file, const unsigned _iter_num);
	~Metric();
	void eval();
};
