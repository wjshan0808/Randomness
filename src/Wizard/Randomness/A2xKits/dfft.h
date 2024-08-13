
#ifndef _H_DFFT_H_
#define _H_DFFT_H_

void __ogg_fdrffti(int n, double *wsave, int *ifac);
void __ogg_fdrfftf(int n, double *X, double *wsave, int *ifac);
void __ogg_fdrfftb(int n, double *r, double *wsave, int *ifac);

void __ogg_fdcosqi(int n, double *wsave, int *ifac);
void __ogg_fdcosqf(int n, double *x, double *wsave, int *ifac);
void __ogg_fdcosqb(int n, double *x, double *wsave, int *ifac);

#endif /* !_H_DFFT_H_  */
