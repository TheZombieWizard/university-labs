#include "Vector.h"

using namespace std;


class Matrix
{
    static inline unsigned int id_number{};
    Vector* rows;
    unsigned int rows_count;
    unsigned int columns_count;
    unsigned int self_id_number;
public:
    Matrix(unsigned int desired_rows, unsigned int desired_columns);
    Matrix();
    ~Matrix();

    Matrix(const Matrix &copying_matrix);
    Matrix(Matrix&& moving_matrix);
    Matrix& operator= (const Matrix& copying_matrix);
    Matrix& operator=(Matrix&& moving_matrix);

    Vector& operator[] (unsigned int index);
    Matrix operator+ (Matrix& summing_matrix);
    Matrix operator* (Matrix& multyplying_matrix);

    void change_rows(unsigned int desired_rows);
    void change_columns(unsigned int desired_columns);
    void print();
    void fill_random();
};