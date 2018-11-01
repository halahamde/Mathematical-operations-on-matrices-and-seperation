#include "Matrix.h"
#include<iostream>
using namespace std;
//purpose: print matrix
ostream& operator<<(ostream& os, Matrix mat1)
{
    int counter=0;
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            if(mat1.data[i][j]==-1999999){
                counter++;
            }
        }
    }
    if(counter==mat1.row*mat1.col){
        os<<"not vaild "<<endl;
    }
    else{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            os<< mat1.data[i][j];
            os<<" ";
        }
        os<<endl;
    }
    }
    return os;
}
//purpose: input matrix
istream& operator>>(istream& is,Matrix &mat1)
{
    cout<<"number of rows of mat :";
    is >> mat1.row;
    cout<<"number of col of mat :";
    is>> mat1.col;
    mat1.data = new int* [mat1.row];

    for (int i = 0; i < mat1.row; i++)
        mat1.data[i] = new int [mat1.col];


    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            cout<<"enter you number of "<<i<<j<<":";
            is>> mat1.data[i][j];
        }
    }
    return is;
}
// purpose of constructor:defines the constructor to create a new matrix
Matrix::Matrix(int r, int c){
	row = r;
	col = c;
	data = new int*[row];
	for (int i=0; i<row; i++){
		data[i] = new int[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			data[i][j] = 0;
		}
	}
}

/*Matrix::Matrix(Matrix mat){ //defines the copying constructor
	row = mat.row;
	col = mat.col;
	data = new int*[row];
	for (int i=0; i<row; i++){
		data[i] = new int[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			data[i][j] = mat.data[i][j];
		}
	}
}
*/
// operator overloading : ++
// Purpose: this function will increase the data of the matrix by 1
// Author:  Mayada Mohamad

void Matrix :: operator++()
{
    for (int i = 0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            data[i][j]++;
        }
    }

}
// operator overloading : --
// Purpose:  This function will decrease the data of the matrix by 1
// Author:  Mayada Mohamad

void Matrix :: operator--()
{
    for (int i = 0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            data[i][j]--;
        }
    }
}
// operator overloading : += Scalar
// Purpose:  This function will increase the data of the matrix by number and return the output in the same matrix
// Author:  Mayada Mohamad

Matrix& Matrix ::operator+= (int scalar)
{
    for (int i = 0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            data[i][j]=data[i][j]+scalar;
        }
    }
    return *this;

}
// operator overloading : -= scalar
// Purpose: this function will decrease the data of the matrix by number and return the output in the same matrix
// Author:  Mayada Mohamad

Matrix& Matrix :: operator-= (int scalar)
{
    for (int i = 0; i < row ; i++)
    {
        for(int j = 0; j < col; j++)
        {
            data[i][j]=data[i][j]-scalar;
        }
    }
    return *this;
}
// operator overloading : += matrix
// Purpose:  This function will add two matrices
// Author:  Mayada Mohamad

Matrix& Matrix :: operator+= (Matrix &mat2)
{
    if((col!=mat2.col)||(row!=mat2.row))
    {
        cout<<" not valid"<<endl;
    }
    else
    {
        for (int i = 0; i < row ; i++)
        {
            for(int j = 0; j <col; j++)
            {

                data[i][j]=data[i][j]+mat2.data[i][j];
            }

        }
        return *this;
    }
}
// operator overloading : -= matrix
// Purpose:  This function will subtract two matrices
// Author:  Mayada Mohamad

Matrix& Matrix :: operator-= (Matrix& mat2)
    if((col!=mat2.col)||(row!=mat2.row))
    {
        cout<<" not valid"<<endl;
    }
    else
    {
        for (int i = 0; i < row ; i++)
        {
            for(int j = 0; j < col; j++)
            {
                data[i][j]=data[i][j]-mat2.data[i][j];
            }
        }
        return *this;
    }

}
// operator overloading : + matrix
// Purpose: This function will add two matrices and return the output in new matrix
// Author:  Naglaa Essam

Matrix Matrix :: operator+(Matrix mat2)
{
    Matrix mat3(row,col);
if((col!=mat2.col)||(row!=mat2.row))
    {
         for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }
    else
    {
        for (int i = 0; i < mat2.row; i++)
        {
            for(int j = 0; j < mat2.col; j++ )
            {

                mat3.data[i][j]=data[i][j]+mat2.data[i][j];
            }
        }

        return mat3;
    }
}
// operator overloading : - matrix
// Purpose: This function will subtract two matrices and return the output in new matrix
// Author:  Naglaa Essam

Matrix  Matrix :: operator-(Matrix mat2)
{
    Matrix mat3(row,col);
    if((col!=mat2.col)||(row!=mat2.row))
    {
        for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }

    else
    {
        for(int i=0; i<mat2.row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {

                mat3.data [i][j]=data[i][j]-mat2.data[i][j];
            }
        }
        return mat3;
    }
}
// operator overloading : + scalar
// Purpose: this function will increase the data of the matrix by number and return the output in the new matrix
// Author:  Naglaa Essam


Matrix Matrix :: operator+(int scalar)
{
    Matrix mat3(row,col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {

            mat3.data[i][j]=data[i][j]+scalar;
        }
    }
    return mat3;
}
// operator overloading : - scalar
// Purpose: This function will decrease the data of the matrix by number and return the output in the new matrix
// Author:  Naglaa Essam

Matrix Matrix :: operator-(int scalar)
{
    Matrix mat3(row,col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {

            mat3.data[i][j]=data[i][j]-scalar;
        }
    }
    return mat3;
}
// operator overloading : * matrix
// Purpose: this function will multiply two matrices and return the output in the new matrix
//Author :Naglaa Essam

Matrix Matrix :: operator*(Matrix mat2)

{
    Matrix mat3(row,mat2.col);
    if(col!=mat2.row)
    {
        for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }
    else
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {
                for(int k=0; k<col; k++)
                {
                    mat3.data[i][j]+=(data[i][k])*(mat2.data[k][j]);
                }
            }
        }
        return mat3;
    }

}
// operator overloading : * scalar
// Purpose: this function will multiply matrix with a constant number and return the output in the new matrix
// Author:  Naglaa Essam

Matrix Matrix :: operator*(int scalar)

{
    Matrix mat3(row,col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            mat3.data[i][j]=data[i][j]*scalar;
        }
    }

        return mat3;

}
// fuction name: transpose()
// Purpose: this function makes the coloums of a function the rows and the rows become the col
// Author:  Hala Hamdy

Matrix Matrix :: transpose()
{
    Matrix mat3(col,row);
    for(int i = 0 ; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            mat3.data[i][j]=data[j][i];
        }
    }
    return mat3;

}
// operator overloading : ==
// Purpose: this fun return true if the row of matrix1  equal the row of matrix2 and  col of matrix1 equal col of matrix2
// Author:  Hala Hamdy
bool Matrix :: operator== (Matrix mat2) //this fun return true if the row of matrix1  equal the row of matrix2 and  col of matrix1 equal col of matrix2
{
    if ( ( row == mat2.row ) && ( col == mat2.col ) )
    {
        for ( int i = 0 ; i < row ; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ( data[i][j] != mat2.data[i][j] )
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return false ;
}
// operator overloading : !=
// Purpose: this fun return true if the row of matrix1 not equal the row of matrix2 and  col of matrix1 not equal col of matrix2
// Author:  Hala Hamdy
bool Matrix :: operator!= (Matrix mat2) //this fun return true if the row of matrix1 not equal the row of matrix2 and  col of matrix1 not equal col of matrix2

{
    if ( (row == mat2.row ) && ( col == mat2.col ) )
    {
        for ( int i = 0 ; i < row ; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if ( data[i][j] == mat2.data[i][j])
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return true ;
}
//function name: isSquare
// Purpose: return true if row of matrix equal col of this matrix
// Author:  Hala Hamdy
bool Matrix :: isSquare   () //return true if row of matrix equal col of this matrix
{
    if ( row == col )
    {
        return true ;
    }
    else
        return false ;
}
//function name: isSymetric
// Purpose: return true if the content of each col of matrix around the main dimensional is identical.
// Author:  Hala Hamdy

bool Matrix :: isSymetric () //return true if the content of each col of matrix around the main dimensional is identical.
{
    if ( row == col )
    {
        for ( int i = 0 ; i < row ; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ( data[i][j] != data[j][i] )
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return false ;
}
//function name:isIdentity
// Purpose: return true if the content of each col equal.
// Author:  Hala Hamdy
bool  Matrix :: isIdentity ()//return true if the content of each col equal.
{
    if ( row == col )
    {
        for ( int i = 0 ; i < row ; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ( i == j )
                {
                    if ( data[i][j] != 1)
                    {
                        return false;
                    }
                }
                else //if ( i != j )
                {
                    if ( data[i][j] != 0 )
                    {
                        return false ;
                    }
                }
            }
        }
        return true ;
    }
    else
        return false ;
}
// Purpose: Skeleton code for the student to start working
// Author:  team work


Matrix::~Matrix()
{
    for (int i=0; i<row; i++){
		delete[] data[i];
		}
	delete[] data;
}
