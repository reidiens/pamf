#include "pamf.h"

univariate_t* p_createUni(uint8_t degree) {
    univariate_t *p = malloc(sizeof(univariate_t));
    if (!p) return NULL;

    p->degree = degree;
    p->coef = malloc((degree + 1) * sizeof(double));
    if (!p->coef) {
        free(p);
        return NULL;
    } 

    return p;
}

void p_freeUni(univariate_t *p) {
    if (p == NULL) return;
    if (p->coef != NULL) free(p->coef);
    free(p);
    return;
}

uint8_t p_getTermDegree(multivariate_t *p, uint8_t index) {
    uint8_t retval = 0;

    for (int i = 0; i < 3; i++)
        retval += p->term[index].var[i];

    return retval;
}

int comp(const void *t1, const void *t2) {
    int d1 = 0, d2 = 0;

    for (int i = 0; i < 3; i++) {
        d1 += ((multivar_term_t*)t1)->var[i];
        d2 += ((multivar_term_t*)t2)->var[i];
    }

    return d1 - d2;
}

void p_sortMulti(multivariate_t *p) {
    qsort(p->term, p->size, sizeof(multivar_term_t), comp);
}

multivariate_t* p_createMulti(uint8_t terms) {
    multivariate_t *p = malloc(sizeof(multivariate_t));
    if (!p) return NULL;

    p->size = terms;
    p->term = malloc(terms * sizeof(multivar_term_t));
    if (!p->term) {
        free(p);
        return NULL;
    }

    return p;
}

void p_freeMulti(multivariate_t *p) {
    if (p == NULL) return;
    if (p->term != NULL) free(p->term);
    free(p);
    return;
}

double p_abs(double x) {
    if (x > 0) return x;
    if (x == 0) return 0;
    double retval = x * -2;
    return retval / 2;
}