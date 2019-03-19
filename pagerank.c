#include <stdio.h>
#include <math.h>

void kiir (double tomb[], int db)
  {
  
  int i;
  for (i=0; i<db; i++)
  printf("PageRank [%d]: %lf\n", i, tomb[i]);
  
  }

double tavolsag(double pagerank[],double pagerank_temp[],int db)
{
double tav = 0.0;
int i;
for(i=0;i<db;i++)
tav +=abs(pagerank[i] - pagerank_temp[i]);
return tav;
}

int main(void)
{
  double L[4][4] = {
  {0.0, 0.0, 1.0 / 3.0, 0.0},
  {1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
  {0.0, 1.0 / 2.0, 0.0, 0.0},
  {0.0, 0.0, 1.0 / 3.0, 0.0}
  };

  double PR[4] = {0.0, 0.0, 0.0, 0.0};
  double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

  int i,j;


  for (;;)
  {

  for (i=0;i<4;i++)
    {
    PR[i]=0.0;
    for (j=0;j<4;j++)
      PR[i]+=L[i][j]*PRv[j];
    }

    if ( tavolsag(PR,PRv, 4) < 0.0000001)
    break;
  
    for(i=0;i<4;i++)
      PRv[i] = PR[i];
  
  }
  kiir (PR,4);
  return 0;

} 
