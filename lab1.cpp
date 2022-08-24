#include <iostream>
#define MAX 30000
#include <ctime>
using namespace std;

unsigned t0, t1;
double A[MAX][MAX], x[MAX], y[MAX];

int main()
{
  t0=clock();
  int i,j;
    for (i = 0; i < MAX; i++)
      for (j = 0; j < MAX; j++)
        y[i] += A[i][j]*x[j];
  t1 = clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: " << time << endl;
}
