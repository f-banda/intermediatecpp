#include "matrix.h"

/// <summary>
/// Matrix constructor. Initialize a [[1, 0], [0, 1]] matrix
/// </summary>
/// 
matrix::matrix()
{
	matrix_arr[0][0] = 1;
	matrix_arr[0][1] = 0;
	matrix_arr[1][0] = 0;
	matrix_arr[1][1] = 1;
};

/// <summary>
/// Matrix constructor. Initialize the matrix with one provided
/// </summary>
/// <param name="arr"></param>

matrix::matrix(int arr[2][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			matrix_arr[i][j] = arr[i][j];
	}
}


/// <summary>
/// Calculate the determinant of the matrix
/// Returns the determinant of the class object matrix
/// </summary>
/// <returns></returns>
int matrix::determinant() const
{
	return (matrix_arr[0][0] * matrix_arr[1][1]) - (matrix_arr[0][1] * matrix_arr[1][0]);
}

/// <summary>
/// operator+ overload, gives the object "matrix" the ability of doing additions within another "matrix" object
/// 
/// /// Returns a new "matrix" object containing the result of the operation
/// </summary>
/// <param name="T2"></param>
/// <returns></returns>
matrix matrix::operator+ (const matrix& T2) const
{
	matrix result;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			result.matrix_arr[i][j] = this->matrix_arr[i][j] + T2.matrix_arr[i][j];
	}

	return result;
}

/// <summary>
/// operator* overload: gives the object "matrix" the ability of scalar multiplication
/// /// Returns a new "matrix" object containing the result of the operation
/// </summary>
/// <param name="T2"></param>
/// <returns></returns>
matrix matrix::operator*(const int T2) const
{
	matrix result;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			result.matrix_arr[i][j] = this->matrix_arr[i][j] * T2;
	}

	return result;
}


/// <summary>
/// operator* overload: gives the object "matrix" the ability of multiply itself with another "matrix" object
/// Returns a new "matrix" object containing the result of the operation
/// </summary>
/// <param name="T2"></param>
/// <returns></returns>
matrix matrix::operator*(const matrix& T2) const
{
	matrix result;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result.matrix_arr[i][j] = 0;
			for (int k = 0; k < 2; k++)
				result.matrix_arr[i][j] += this->matrix_arr[i][k] * T2.matrix_arr[k][j];
		}
	}

	return result;
}

/// <summary>
/// operator== overload: gives the object "matrix" the ability of compare itself with another "matrix" object
/// Returns true if class object is equal to comparand "matrix" object
/// </summary>
/// <param name="T2"></param>
/// <returns></returns>
bool matrix::operator==(const matrix& T2) const
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (this->matrix_arr[i][j] != T2.matrix_arr[i][j])
				return false;
		}
	}

	return true;
}

/// <summary>
/// operator== overload: gives the object "matrix" the ability to compare itself with another "matrix" object
/// Returns true if class object is different from the comparand "matrix" object
/// </summary>
/// <param name="T2"></param>
/// <returns></returns>
bool matrix::operator!=(const matrix& T2) const
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (this->matrix_arr[i][j] != T2.matrix_arr[i][j])
				return true;
		}
	}

	return false;
}

/// <summary>
/// operator<< friend overload for class matrix: gives the object "matrix" the ability to print in a standard format [[a, b], [c, d]] its 2*2 matrix 
/// </summary>
/// <param name="os"></param>
/// <param name="T1"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const matrix& T1)
{
	os << "[";

	for (int i = 0; i < 2; i++)
	{
		os << "[";
		for (int j = 0; j < 2; j++)
		{
			os << T1.matrix_arr[i][j];

			if (j == 0)
				os << ", ";
		}
		os << "]";

		if (i == 0)
			os << ", ";
	}

	os << "]";
	return os;
}

/// <summary>
/// operator* friend overload for class matrix: given a scalar multiplier and a "matrix" object, performs a scalar multiplication
/// Returns a new "matrix" object containing the result of the operation
/// </summary>
/// <param name="multiplier"></param>
/// <param name="T2"></param>
/// <returns></returns>
matrix operator*(int multiplier, const matrix& T2)
{
	matrix result;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			result.matrix_arr[i][j] = multiplier * T2.matrix_arr[i][j];
	}

	return result;
}