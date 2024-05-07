# PAMF 
## Polynomial Arithmetic and Multivariable Functions
## A C library for all sorts of polynomial and multivariable math

### Why?
I wanted to challenge myself by learning about memory allocation, garbage collection, and multivariable calculus, so I made this.

## Implemented Types:

### univariate_t
```
    typedef struct SingleVarPolynomial {
        double *coef;
        uint8_t degree;
    } univariate_t;
```

This type stores a univariate polynomial. `coef` is a dynamically allocated array storing the coefficients in the polynomial of size $k + 1$. `degree` is the degree, $k$, of the polynomial, or the highest exponent in the polynomial. The coefficients are stored in reverse degree order, so the lowest degree coefficient occupies `coef[0]`. In general, any coefficient can be accessed by using its degree to index the array.

### multivar_term_t
```
    typedef struct MultiVarTerm {
        double coef;
        uint8_t var[3];
    } multivar_term_t;
```

This struct represents a single term in a multivariate polynomial. `coef` is the coefficient of the term. The array `var` stores the exponents for the x, y, and z variables, respectively. A value of 0 in `var[i]` represents the respective variable not being a part of the term.

### multivariate_t
```
    typedef struct MultiVarPoly {
        multivar_term_t *term;
        uint8_t size;
    } multivariate_t;
```

This struct stores a multivariant polynomial. `size` is the total number of terms in the polynomial. `term` is a dynamically allocated array of size `size` and of type `multivar_term_t`. Terms are stored in reverse degree order, so the element with the lowest degree is closest to `term[0]`

## Implemented functions

``` univariate_t* p_createUni(uint8_t degree) ```
- Allocate a univariate polynomial with (degree + 1) terms and return its pointer.

```void p_freeUni(univariate_t *p)```
- Destroy a univariate polynomial

```uint8_t p_getTermDegree(multivariate_t *p, uint8_t index)```
- Find the degree of the multivariate term `p->term[index]`

```void p_sortMulti(multivariate_t *p)```
- Sort a multivariate polynomial. Puts the elements in lowest-to-highest degree order.

```multivariate_t* p_createMulti(uint8_t terms)```
- Allocate a multivariate polynomial with (terms) terms and return its pointer.

```void p_freeMulti(multivariate_t *p)```
- Destroy a multivariate polynomial