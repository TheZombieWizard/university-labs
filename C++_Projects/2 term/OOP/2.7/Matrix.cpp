#include "Matrix.h"


Matrix:: Matrix(unsigned int desired_rows, unsigned int desired_columns)
{
    rows_count = desired_rows;
    columns_count = desired_columns;
    rows = new Vector[rows_count];

    for (int i = 0; i < rows_count; ++i)
        rows[i] = Vector(columns_count);

    self_id_number = id_number;
    ++id_number;
}

Matrix:: Matrix() : Matrix(5, 5) {}

Matrix:: ~Matrix()
{
    for (int i = 0; i < rows_count; ++i)
        rows[i].~Vector();
    
    rows_count = 0;
    columns_count = 0;
}

Matrix:: Matrix(const Matrix &copying_matrix)
{
    rows_count = copying_matrix.rows_count;
    columns_count = copying_matrix.columns_count;
    rows = new Vector[rows_count];

    for (int i = 0; i < rows_count; ++i)
        rows[i] = copying_matrix.rows[i];
    
    self_id_number = id_number;
    ++id_number;
}

Matrix:: Matrix(Matrix&& moving_matrix)
{
    rows_count = moving_matrix.rows_count;
    columns_count = moving_matrix.columns_count;
    rows = new Vector[rows_count];

    for (int i = 0; i < rows_count; ++i)
        rows[i] = move(moving_matrix.rows[i]);
    
    self_id_number = id_number;
    ++id_number;
}

Matrix& Matrix:: operator= (const Matrix& copying_matrix)
{
    for (int i = 0; i < rows_count; ++i)
        rows[i].~Vector();
    
    rows_count = copying_matrix.rows_count;
    columns_count = copying_matrix.columns_count;
    rows = new Vector[rows_count];

    for (int i = 0; i < rows_count; ++i)
        rows[i] = copying_matrix.rows[i];

    return *this;
}

Matrix& Matrix:: operator=(Matrix&& moving_matrix)
{
    for (int i = 0; i < rows_count; ++i)
        rows[i].~Vector();
        
    rows_count = moving_matrix.rows_count;
    columns_count = moving_matrix.columns_count;
    rows = new Vector[rows_count];

    for (int i = 0; i < rows_count; ++i)
        rows[i] = move(moving_matrix.rows[i]);

    return *this;
}

Vector& Matrix:: operator[] (unsigned int index)
{
    if (index >= rows_count)
        throw out_of_range("Exceded the borders of the matrix");
    return rows[index];
}       

Matrix Matrix:: operator+ (Matrix& summing_matrix)
{
    if ((rows_count != summing_matrix.rows_count) || (columns_count != summing_matrix.columns_count))
        throw out_of_range("Summing matrixes must be the same size");
    
    Matrix sum(rows_count, columns_count);
    for (int i = 0; i < rows_count; ++i)
        for (int q = 0; q < columns_count; ++q)
            sum[i][q] = rows[i][q] + summing_matrix.rows[i][q];

    return sum;
}

Matrix Matrix:: operator* (Matrix& multiplying_matrix)
{
    if (columns_count != multiplying_matrix.rows_count)
        throw out_of_range("Multyplying matrixes requires the number of columns of the 1st matrix to be equal to the number of rows of the 2nd matrix");

    Matrix multiplication(rows_count, multiplying_matrix.columns_count);
    for (int i = 0; i < rows_count; ++i)
        for (int q = 0; q < multiplying_matrix.columns_count; ++q)
        {
            int subtotal = 0;
            for (int column = 0, row = 0; column < columns_count; ++column, ++row)
                    subtotal += rows[i][column] * multiplying_matrix[row][q];

            multiplication[i][q] = subtotal;
        }
    return multiplication;
}

void Matrix:: print()
{
    cout << "Matrix " << self_id_number << endl;
    for (int i = 0; i < rows_count; ++i)
        rows[i].print_values();
}

void Matrix:: fill_random()
{
    for (int i = 0; i < rows_count; ++i)
        rows[i].fill_random();
}

void Matrix:: change_rows(unsigned int desired_rows)
{
    if (desired_rows < rows_count)
    {
        for (int i = desired_rows; i < rows_count; ++i)
            rows[i].~Vector();

        rows_count = desired_rows;
        Vector* new_rows = new Vector[rows_count];
        for (int i = 0; i < rows_count; ++i)
            new_rows[i] = rows[i];
        rows = new_rows;
    }
    else if (desired_rows > rows_count)
    {
        Vector* new_rows = new Vector[desired_rows];
        for (int i = 0; i < rows_count; ++i)
            new_rows[i] = rows[i];
        rows = new_rows;

        for (int i = rows_count; i < desired_rows; ++i)
            rows[i] = Vector(columns_count);

        rows_count = desired_rows;
    }
}

void Matrix:: change_columns(unsigned int desired_columns)
{
    if (desired_columns < columns_count)
    {
        for (int i = 0; i < rows_count; ++i)
            for (int pops_number = 0; pops_number < (columns_count - desired_columns); ++pops_number)
                rows[i].pop();
        columns_count = desired_columns;
    }
    else if (desired_columns > columns_count)
    {
        for (int i = 0; i < rows_count; ++i)
            for (int appends_number = 0; appends_number < (desired_columns - columns_count); ++appends_number)
                rows[i].append();
        columns_count = desired_columns;
    }
}
