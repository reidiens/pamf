#include "pamf.h"

single_var_poly_t* p_CreateSingleVarPoly(uint8_t degree) {
    single_var_poly_t *p = malloc(sizeof(single_var_poly_t));
    if (!p) return NULL;

    p->degree = degree;
    p->coef = malloc((degree + 1) * sizeof(double));
    if (!p->coef) {
        free(p);
        return NULL;
    } 

    return p;
}

void p_FreeSingleVar(single_var_poly_t *p) {
    if (p == NULL) return;
    if (p->coef != NULL) free(p->coef);
    free(p);
    return;
}