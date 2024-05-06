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

    #ifndef __STDARG_H
        #include <stdarg.h>
    #endif

    typedef struct SingleVarPolynomial {
        double *coef;
        uint8_t degree;
    } single_var_poly_t;

    typedef struct MultiVarTerm {
        double coef;
        uint8_t vars[3];
    } multi_var_term_t;

    typedef struct MultiVarPoly {
        struct MultiVarTerm *poly;
        uint8_t terms;
    } multi_var_poly_t;

    /*
        p_CreateSingleVarPoly - create a simple polygon with only 1 variable (x)
        degree - the degree of the polynomial, or its highest exponent.
        Returns a pointer to a polynomial of size (degree + 1)
    */
    single_var_poly_t* p_CreateSingleVarPoly(uint8_t degree);
    
    /*
        p_FreeSingleVar - destroy a single-variable polynomial
    */
    void p_FreeSingleVar(single_var_poly_t *p);
    
    /*
        p_CreateMultiVarPoly - create a polygon that has maximum of 3 variables
        terms = the total number of terms in the polynomial, including non-variable constants
        term1 = a struct containing the coefficient and variable data of the first (highest degree)

        each following (optional) argument is another pointer to a multi_var_term_t struct containing the
        information for the next term. The first term is mandatory, while others are optional.

        the order of terms in the polynomial is alphabetical order by the highest degree.
        For example, the polynomial 2x^3 + 5x^5y^3 - 4y^4z would be re-written as
        5x^5y^3 + 2x^3 - 4y^4z
    */
    multi_var_poly_t* p_CreateMultiVarPoly(uint8_t terms, multi_var_term_t *term1, ...);
                                        

#endif