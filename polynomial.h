/* 
 * File:   polynomial.h
 * Author: jawinton
 *
 * Created on 2010年9月17日, 下午10:41
 */

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "datastructure.h"
    typedef struct Term{
        float coef;
        int exp;
        struct Term *link;
    }Term, *Polynomial;
    Polynomial createPoly();
    void insertPoly(Polynomial p);
    void insertPoly_with_value(Polynomial p, float coef, int exp);
    Polynomial multiplePoly(Polynomial a,Polynomial b);
    void printPoly(Polynomial p);


#ifdef	__cplusplus
}
#endif

#endif	/* POLYNOMIAL_H */

