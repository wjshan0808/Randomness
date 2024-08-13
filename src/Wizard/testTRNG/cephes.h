#ifndef __CEPHES_H_
#define __CEPHES_H_

#if defined(__cplusplus)
extern "C" {
#endif

double cephes_igamc(double a, double x);
double cephes_igam(double a, double x);
double cephes_lgam(double x);
double cephes_p1evl(double x, double *coef, int N);
double cephes_polevl(double x, double *coef, int N);
double cephes_erf(double x);
double cephes_erfc(double x);
double cephes_normal(double x);

#if defined(__cplusplus)
}
#endif

#endif /* !__CEPHES_H_ */
