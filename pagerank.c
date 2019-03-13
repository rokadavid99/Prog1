#include <stdio.h>
#include <math.h>

void kiir (double tomb[], int db)
{
		for (int i=0; i<db; i++) {
		printf("PageRank [%d]: %lf\n", i, tomb[i]);
	}
}
	
double tavolsag (double PR[], double PRv[], int n){
double tav = 0.0;

	for(int i=0; i<n; i++) {
		tav += (PR[i] - PRv[i]) * (PR[i] - PRv[i]);
	}

return sqrt(tav);
}

int main (void){
double L[4][4]={
	       {0.0, 0.0, 1.0 / 3.0, 0.0},
               {1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
	       {0.0, 1.0 / 2.0, 0.0, 0.0},
	       {0.0, 0.0, 1.0 / 3.0, 0.0}
};

	double PR[4] = { 0.0, 0.0, 0.0, 0.0};
	double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0 };
	
	int i, j;

	for (;;) {
		for(int i=0; i<4; i++) {
			PR[i] = PRv[i];
		}

		for (int i=0; i<4; i++) {
			double tmp = 0.0;

			for (int j=0; j<4; j++) {
				tmp += L[i][j] * PR[j];
				PRv[i] = tmp;
			}
		}

		
if (tavolsag (PR, PRv, 4) < 0.0000000001){
	break;
	}
		}

	kiir(PR, 4);

	return 0;
}

