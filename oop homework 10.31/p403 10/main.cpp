#include <bits/stdc++.h>

template<typename T>
T countc (T a,T b){
    T result,tempup=1,tempbellow=1;
    for (int i = 1; i < b+1; ++i)
        tempbellow*=i;
    for (int i = a; i >=a-b+1; --i)
        tempup*=i;
    result=tempup/tempbellow;
    return result;
}
using namespace std;
int main() {
    cout<<"the result of C(24,4) is"<<countc<long>(24,4);
    return 0;
}
