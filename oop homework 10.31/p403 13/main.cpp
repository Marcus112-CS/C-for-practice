#include <bits/stdc++.h>
using namespace std;
struct Fraction{
    int a;//分子
    int b;//分母
};
struct zimu{
    char a;
};
template<typename T>
T* operator++(T& a){
    a++;
};
//template<char>
//T* operator++(T &j) {
//};           //不允许类内重载性定义
void operator++(Fraction& f){
    f.a+=f.b;
};

void operator++(zimu& f){
    if (f.a!='Z')
        f.a+=1;
    else
        f.a='A';
};


//template <>
//char operator++(char &a){
//
//}
template<class T>
class TMatrix {
public:
    int line=1; //行 1位
    int row=1;//列 2位
    T** myMtrix;

    TMatrix();
    TMatrix(int x,int y,T** temp);
    ~TMatrix();
    bool operator== (const TMatrix<T>& temp);
};
int main() {
    float a=1.23;
    ++a;
    Fraction j;
    j.a=1;
    j.b=2;
    ++j;
    zimu k;
    k.a='Z';
    ++k;
    cout<<a<<endl;
    cout<<j.a<<endl;
    cout<<k.a<<endl;
    return 0;
}

template<class T>
TMatrix<T>::TMatrix(int x,int y,T** temp){
    T **k=new T*[x];
    for (int i = 0; i < y; ++i) {
        k[x]=new T[y];
    }
    this->line=x;
    this->row=y;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            k[i][j]=temp[i][j];
        }
    }
    this->myMtrix=k;
}
template<class T>
bool TMatrix<T>::operator== (const TMatrix<T>& temp){
    if (this->row!=temp.row||this->line!=temp.line)
        return false;
    else{
        for (int i = 0; i < temp.line; ++i) {
            for (int j = 0; j < temp.row; ++j) {
                if(this->myMtrix[i][j]!=temp[i][j]) return false;
            }
        }
    }
    return true;
}