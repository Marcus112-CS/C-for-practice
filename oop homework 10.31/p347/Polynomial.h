//
// Created by DELL on 2020/10/18.
//

#ifndef P347_POLYNOMIAL_H
#define P347_POLYNOMIAL_H


class Polynomial {
public:
    int size_n;
    int p_max;
    double *p_data;
private:
    void Init();
    void Free();
    inline bool InvalidateIndex(int nIndex);
public:
    Polynomial();
    Polynomial(int psize,double* narray);
    Polynomial(const Polynomial& symbol);
    double getValue(int x);
    bool operator== (const Polynomial& temp);
    bool operator!= (const Polynomial& temp);
    Polynomial operator+ (const Polynomial& temp);
    Polynomial operator- (const Polynomial& temp);
    Polynomial operator* (const Polynomial& temp);
    Polynomial operator* (double j);
};


#endif //P347_POLYNOMIAL_H
