#include <bits/stdc++.h>
#include "Polynomial.h"
#include "Polynomial.cpp"
using namespace std;
int main() {
    int num,x;
    cout<<"please input the number of array"<<endl;
    cin>>num;
    double *myarray=new double [num];
    cout<<"please input the array from now"<<endl;
    for (int i = 0; i < num; ++i)
        cin>>myarray[i];
    Polynomial myPolynomial = Polynomial(num, myarray);
    cout<<"now the array has been copyed by OOP method,input x to calculate";
    cin>>x;
    double newresult=myPolynomial.getValue(x);
    cout<<"the result is "<<newresult;
    delete []myarray;
    return 0;
}
