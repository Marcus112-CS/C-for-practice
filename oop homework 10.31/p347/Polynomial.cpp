//
// Created by DELL on 2020/10/18.
//

#include "Polynomial.h"
#include <bits/stdc++.h>
void Polynomial::Init(){
    size_n=0;
    p_max=1;
    p_data=new double [p_max];
}
void Polynomial::Free(){
    delete [] p_data;
}
bool Polynomial::InvalidateIndex(int nIndex) {
    if(nIndex<p_max&&nIndex>=0)
        return true;
    else
        return false;
}
Polynomial::Polynomial(int psize,double* narray){
    if (size_n==0)
        Init();
    else
    {
        size_n=psize;
        p_max=psize;
        p_data=new double[psize];
        for (int i = 0; i < psize; ++i) {
            p_data[i]=narray[i];
        }
        //memset(p_data,pvalue,psize);
    }
}
double Polynomial:: getValue(int x){
    //double result=p_data[] ;
    double result=x;
    for (int i =0; i <p_max-1; ++i) {
        if (i==0)
        result=result*p_data[i]+p_data[i+1];
        if (i!=0)
            result=result*x+p_data[i+1];
    }
    return result;
}
Polynomial::Polynomial(const Polynomial& symbol){
    size_n=symbol.size_n;
    p_max=symbol.p_max;
    p_data=new double [size_n];
    memcpy(p_data,symbol.p_data,sizeof(double)*size_n);
}
bool Polynomial::operator== (const Polynomial& temp){
    bool result=true;
    if(size_n!=temp.size_n)
        return false;
    else
    {
        for (int i = 0; i < size_n; ++i) {
            if(p_data[i]!=temp.p_data[i])
                return false;
        }
    }
    return true;
}
bool Polynomial::operator!= (const Polynomial& temp){
    bool result=true;
    if(size_n!=temp.size_n)
        return result;
    else
    {
        for (int i = 0; i < size_n; ++i) {
            if(p_data[i]!=temp.p_data[i])
                return result;
        }
    }
    return false;
}
Polynomial Polynomial::operator+ (const Polynomial& temp){
    Polynomial temper;
    temper.size_n=size_n>temp.size_n?size_n:temp.size_n;
    temper.p_data=new double [size_n];
    if(size_n==temp.size_n){
        for (int i = 0; i < size_n; ++i)
            temper.p_data[i]=this->p_data[i]+temp.p_data[i];
    }
    else{
        if (size_n==temper.size_n){
            int standard=temper.size_n -temp.size_n;
            for (int i = 0; i < standard; ++i)
                temper.p_data[i]=this->p_data[i];
            for (int i = standard; i < temper.size_n; ++i)
                temper.p_data[i]=this->p_data[i]+temp.p_data[i-standard];
        }
        else{
            int standard=temp.size_n-temper.size_n ;
            for (int i = 0; i < standard; ++i)
                temper.p_data[i]=temp.p_data[i];
            for (int i = standard; i < temper.size_n; ++i)
                temper.p_data[i]=temp.p_data[i]+this->p_data[i-standard];
        }
    }
}
Polynomial Polynomial::operator- (const Polynomial& temp){
    Polynomial temper;
    temper.size_n=size_n>temp.size_n?size_n:temp.size_n;
    temper.p_data=new double [size_n];
    if(size_n==temp.size_n){
        for (int i = 0; i < size_n; ++i)
            temper.p_data[i]=this->p_data[i]-temp.p_data[i];
    }
    else{
        if (size_n==temper.size_n){
            int standard=temper.size_n -temp.size_n;
            for (int i = 0; i < standard; ++i)
                temper.p_data[i]=this->p_data[i];
            for (int i = standard; i < temper.size_n; ++i)
                temper.p_data[i]=this->p_data[i]-temp.p_data[i-standard];
        }
        else{
            int standard=temp.size_n-temper.size_n ;
            for (int i = 0; i < standard; ++i)
                temper.p_data[i]=-temp.p_data[i];
            for (int i = standard; i < temper.size_n; ++i)
                temper.p_data[i]=this->p_data[i-standard]-temp.p_data[i];
        }
    }
}
Polynomial Polynomial::operator* (const Polynomial& temp){

}
Polynomial Polynomial::operator* (double j){
//    Polynomial temp=Polynomial(this)?????明确拷贝构造函数和赋值构造函数的区别，两者的参量一个是对象指针一个是类的引用
    Polynomial temp;
      temp.size_n=size_n;
      temp.p_data=new double [size_n];
      temp.p_max=p_max;
    for (int i = 0; i < size_n; ++i)
        temp.p_data[i]*=j;
    return temp;
}