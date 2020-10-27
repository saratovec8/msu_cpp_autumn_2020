#include<iostream>


class Matrix
{
	private: 
		int32_t n_columns;
		int32_t n_rows;
		int32_t **arr;
	public:
		Matrix();

		Matrix(const int32_t n_rows_, const int32_t n_columns_, int32_t **arr_);

		int32_t GetRowNum() const;

		int32_t GetColumnNum() const;

		Matrix operator *= (int32_t num);

		bool operator == (Matrix &B) const;

		Matrix& operator = (Matrix &B);

		class Row;

		Row  operator [](int32_t i);

		~Matrix();

		class Row
		{
			public:
				int32_t length;
				int32_t *a;
			public:
				Row();

				Row(const int32_t i, const int32_t n_columns_, int32_t **arr_);

				int32_t& operator[] (int32_t j);

				~Row();

		};


};
