# PAMF 
## Polynomial Arithmetic and Multivariable Functions
## A C library for all sorts of polynomial and multivariable math

### Why?
I wanted to challenge myself by learning about memory allocation, garbage collection, and multivariable calculus, so I made this.

## Implemented Types:

### single_var_poly_t
```
typedef struct SingleVarPolynomial {
    double *coef;   // dynamic array of the list of coefficients
    uint8_t degree; // degree (highest exponent) of polynomial
} single_var_poly_t;
```

This struct acts as a single-variable polynomial, storing its coefficients in the array `coef`. Individual coefficients are accessed via their degree in the polynomial, `coef[degree]`.
For example, in the polynomial $2x^{2}+5x-17$ the value at `coef[2]` would be 2, and the value at `coef[0]` would be -17;

### multivar_exponents_t
```
typedef struct VarExponents {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} multivar_exponents_t;
```

This struct contains exponent data for the term in a multivariable polynomial defined by `multi_var_term_t`. The value of each variable is equal its exponent in the polynomial. A value of zero for a variable means that the variable is not present in the current term of the polynomial.

### multi_var_term_t
```
typedef struct MultiVarTerm {
    double coef;
    multivar_exponents_t exps;
} multi_var_term_t;
```

This struct contains the information for a single term in a multivariable polynomial. `coef` stores the value of the coefficient and `exps`
stores the data for the term's variables. See "multivar_exponents_t"

## Implemented Functions:
 - `single_var_poly_t* p_CreateSingleVarPoly(uint8_t degree)` - Create an empty single-variable polynomial with (degree + 1) terms and return its pointer.
 - `void p_FreeSingleVar(single_var_poly_t *p)` - Destroy the specified single-variable polynomial