#ifndef SysEquaHEADERDEF
#define SysEquaHEADERDEF
#include <iostream>

using namespace std;

class SysEqua
{
   private :
    int nRows; //number of rows 
    int nCols;// number of colums
    
    double**Matrix; // values of Matrix
    double*Vectors; //values of Vecteur
    void allocSpace();
    void allocSpaceV();
   public :
    SysEqua (); // initialize a the costructor 
    SysEqua (int n, int m); // the constructor which allows to initialize the new Matrix
    SysEqua (int n); //the constructor which allows to initialize the new vector ;
    SysEqua (SysEqua&Mat, SysEqua&v);//the cconstructor whichv allows to initialize the solver equation
    ~SysEqua(); // this is the destructor
    SysEqua transposer() const;//this methode allows  to find the transposed matrix
    double DeterMatrix(int nRows) const;// this methode allows  to calculation the Determinant matrix
    SysEqua triangularize() const;// function who to transform the matrix in triangular matrix
    bool IsSquare();// verify if the Matrix is square 
    bool Istriangular(SysEqua&Mat);// verify if the Matrix is triangularize
    SysEqua solver();//resolves system linéare equation and find x
    int getNROWS(); //void acces to values of number of rows
    void fillV();//
    void fill();// 
    void setNROWS(int n);//void modify values of number of rows 
    int getNCOLS();//void acces values of number of colums 
    void setNCOLS(int m);//void modify values of number of colums
    void display();
    void displayV();//
    
    
};

#endif