/*
 *
 * */
#include "A2xTest.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                          F R E Q U E N C Y  T E S T
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int // void
Frequency(int n, BitSequence *epsilon)
{
	int		i;
    double	f, s_obs, p_value, sum, sqrt2 = 1.4142135623730950488016887242097;
	
	sum = 0.0;
	for ( i=0; i<n; i++ )
		sum += 2*(int)epsilon[i]-1;
	s_obs = fabs(sum)/sqrt(n);
	f = s_obs/sqrt2;
    p_value = erfc(f);

    //
    results[TEST_FREQUENCY] = stats[TEST_FREQUENCY] = stdout;

	fprintf(stats[TEST_FREQUENCY], "\t\t\t      FREQUENCY TEST\n");
	fprintf(stats[TEST_FREQUENCY], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_FREQUENCY], "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(stats[TEST_FREQUENCY], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_FREQUENCY], "\t\t(a) The nth partial sum = %d\n", (int)sum);
	fprintf(stats[TEST_FREQUENCY], "\t\t(b) S_n/n               = %f\n", sum/n);
    fprintf(stats[TEST_FREQUENCY], "\t\t---------------------------------------------\n");

	fprintf(stats[TEST_FREQUENCY], "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value); fflush(stats[TEST_FREQUENCY]);
	fprintf(results[TEST_FREQUENCY], "%f\n", p_value); fflush(results[TEST_FREQUENCY]);

    //
    if(p_value < ALPHA)
    {
        return FLAG_FAILURE;
    }
    return FLAG_SUCCESS;
}
