/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include "SysEqua.hpp"
#include <iostream>
#include <cmath>

using namespace std;


/******************************************************************************
                           Accesseur et mutateur
*******************************************************************************/
//void acces to values of number of rows 
int SysEqua::getNROWS()
{
    return nRows;
}
//void modify values of number of rows
void SysEqua::setNROWS(int n)
{
    nRows=n;
}

//void acces values of number of colums 
void SysEqua::setNCOLS(int m)
{
    nCols = m;
}

// modify values of number of colums
int SysEqua::getNCOLS()
{
    return nCols;
}


/******************************************************************************
                             Constructors
*******************************************************************************/
// make a new Matrix
void SysEqua::allocSpace(){
    Matrix = new double*[nRows];
    for (int i = 0; i < nRows; ++i) {
     Matrix[i] = new double[nCols];
    }
}

//make a new vector
void SysEqua::allocSpaceV(){
    Vectors = new double[nRows];
}
// initialize the constrctor
SysEqua::SysEqua():nRows(1), nCols(1)
{
    allocSpace();
    Matrix[0][0]=0;
    allocSpaceV();
    Vectors[0]=0;
}
// constrctor of matrix, this allows to make a new object
SysEqua::SysEqua(int n, int m):nRows(n), nCols(m)
{
   allocSpace();
}
// initialize the constrctor of vector 
SysEqua::SysEqua(int n):nRows(n)
{
    allocSpaceV();
}
/******************************************************************************
                             Constructors
*******************************************************************************/
SysEqua::~SysEqua(){
    
    for (int i = 0; i < nRows; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    delete[] Vectors;
}
/******************************************************************************
                           Verifications Methodes
*******************************************************************************/

// verify if matrix is square
bool SysEqua::IsSquare()
{
    if(this->getNCOLS() == this->getNROWS()){
        return true;
    }else{
        return false;
    }
}
// verify if the Matrix is triangularize
/*bool square::Istriangular(sysequa&Mat){
       if(this->getNCOLS() == this->getNROWS()){
        return true;
    }else{
        return false;
    }
}*/

/******************************************************************************
                           fill and display Methodes
*******************************************************************************/
//

void SysEqua::display()
{
    
    for(int y = 0; y < nRows; y++)
        {

            for(int x = 0; x < nCols; x++)

            cout << Matrix[x][y] << '\t';

            cout << endl;

        }
}
    
// 
void SysEqua::displayV()
{
    
    for(int x = 0; x < nRows; x++)
        {

            cout << Vectors[x] << '\t';

            cout << endl;

        }
}
///

void SysEqua::fill()
{
    int i,j;
	for(i=0 ; i<nRows ; i++)
		for(j=0 ; j<nCols ; j++)
		{
			cout << "Tapez la valeur de la ligne " << i << " colonne " << j << " : ";
			cin >> Matrix[i][j];
		}

}
//

void SysEqua::fillV()
{
    int i;
	for(i=0 ; i<nRows ; i++)
			cout << "Tapez la valeur de la ligne " << i <<  " : ";
			cin >> Vectors[i];

}

/******************************************************************************
                           Transposer Methodes
*******************************************************************************/
// transposer
SysEqua SysEqua::transposer() const 
{
     SysEqua ret(nCols, nRows);
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            ret.Matrix[j][i] = Matrix[i][j];
        }
    }
    return ret;
}
/******************************************************************************
                           Determinant Methodes
*******************************************************************************/
//
double SysEqua::DeterMatrix(int nRows) const
{
  double det=0.0; 
  int p, h, k, i, j; 
  SysEqua temp(nRows,nCols);
  if(nRows==1) {
    return Matrix[0][0];
  } else if(nRows==2) {
    det=(Matrix[0][0]*Matrix[1][1]-Matrix[0][1]*Matrix[1][0]);
    return det;
  } else {
    for(p=0;p<nRows;p++) {
      h = 0;
      k = 0;
      for(i=1;i<nRows;i++) {
        for( j=0;j<nRows;j++) {
          if(j==p) {
            continue;
          }
          temp.Matrix[h][k] = Matrix[i][j];
          k++;
          if(k==nRows-1) {
            h++;
            k = 0;
          }
        }
      }
      det=det+Matrix[0][p]*pow(-1,p)*DeterMatrix(nRows-1);
    }
    return det;
  }
}
/******************************************************************************
                           triangularize Methodes
*******************************************************************************/
SysEqua SysEqua::triangularize() const
{
    SysEqua tri(nRows,nCols);
     int i,j,k;
      for (i=0; i<nRows - 1; i++){
        for (k = i + 1; k < nCols; k++) {
            double t = Matrix[k][i] / Matrix[i][i];
            for (int j = 0; j <= nRows; j++)
            {
                tri.Matrix[k][j] = Matrix[k][j] - t * Matrix[i][j];
            }
        }
      }
    return tri;
}

/******************************************************************************
                           triangularize Methodes
*******************************************************************************/
SysEqua SysEqua::solver()
{
    SysEqua q(nRows);
    for (int i = nRows - 1; i >= 0; i--)
        {
            q.Vectors[i] = Matrix[i][nRows];
        for (int j = nRows - 1; j > i; j--)
             {
                 q.Vectors[i] = q.Vectors[i] - Matrix[i][j] * q.Vectors[j];
             }
             q.Vectors[i] = q.Vectors[i] / Matrix[i][i];
        } 
        
        return q;
}

int main()
{
    int n,m;
    
    cout<<"Hello World"<<endl;
    cout << "Tapez la nombre de la ligne :";
    cin >> n;
    cout<< "colonne :";
    cin >> m;
    SysEqua a(n,m);
    a.fill();
    cout<<"**********************************************"<<endl;
    cout<<"****************Matrice simple****************"<<endl;
    cout<<"**********************************************"<<endl;
    a.display();
    cout<<"**********************************************"<<endl;
    cout<<"********************transposer****************"<<endl;
    cout<<"**********************************************"<<endl;
    a.triangularize().display();
   
     cout<<"**********************************************"<<endl;
    cout<<"********************transposer****************"<<endl;
     a.transposer().display();
    cout<<"**********************************************"<<endl;
    a.triangularize().display();
    return 0;
}
 