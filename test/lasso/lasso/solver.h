/* stuff about open source license
 * ....
 * The problem specification for this solver is: 
 *
 *     parameter A(2,3)
 *     
 *     parameter b(2)
 *     
 *     parameter lambda positive
 *     
 *     parameter u
 *     parameter l
 *     
 *     variable x(3)
 *     
 *     minimize square(norm(A*x - b)) + lambda*norm1(x)
 *     subject to
 *         l <= x
 *         x <= u
 *     
 *
 * For now, parameters are *dense*, and we don't respect sparsity. The sparsity
 * structure has to be specified during code generation time. We could do the more
 * generic thing and allow sparse matrices, but as a first cut, we won't.
 * Version 0.0.1
 * Eric Chu, Alex Domahidi, Neal Parikh, Stephen Boyd (c) 2012 or something...
 */

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "ecos.h"

/*
 * struct params_t (or `params`)
 * =============================
 * This structure contains the data for all parameters in your problem.
 *
 */
typedef struct params_t {
  double A[2][3];
  double b[2];
  double l;
  double lambda;
  double u;
} params;

/*
 * struct vars_t (or `vars`)
 * =========================
 * This structure stores the solution variables for your problem.
 *
 */
typedef struct vars_t {
  double x[3];
} vars;

pwork *setup(params *p);        /* setting up workspace (assumes params already declared) */
int solve(pwork *w, vars *sol); /* solve the problem (assumes vars already declared) */
void cleanup(pwork *w);         /* clean up workspace */

#endif    /* solver.h */
