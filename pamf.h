#ifndef REIDIENS_POLYFUNC_H__
    #define REIDIENS_POLYFUNC_H__ 1

    #ifndef _STDIO_H
        #include <stdio.h>
    #endif

    #ifndef __CLANG_STDINT_H
        #include <stdint.h>
    #endif

    #ifndef _GLIBCXX_STDLIB_H
        #include <stdlib.h>
    #endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    typedef struct SingleVarPolynomial {
        double *coef;
        uint8_t degree;
    } univariate_t;

    typedef struct MultiVarTerm {
        double coef;
        uint8_t var[3];
    } multivar_term_t;

    typedef struct MultiVarPoly {
        multivar_term_t *term;
        uint8_t size;
    } multivariate_t;

    univariate_t* p_createUni(uint8_t degree);
    void p_freeUni(univariate_t *p);

    void p_swapMultiTerms(multivar_term_t *t1, multivar_term_t *t2);
    uint8_t p_getTermDegree(multivariate_t *p, uint8_t index);
    int comp(const void *, const void *);
    void p_sortMulti(multivariate_t *p);
    multivariate_t* p_createMulti(uint8_t terms);
    void p_freeMulti(multivariate_t *p);

    double p_abs(double x);

#endif