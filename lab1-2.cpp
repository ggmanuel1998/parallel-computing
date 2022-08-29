#include <iostream>
#define MAX 20000
#include <ctime>
#include <conio.h>
#include <time.h>
using namespace std;

unsigned t0, t1;
long A[MAX][MAX], x[MAX], y[MAX];

int main()
{
  t0=clock();
  int i,j;
  
  for (int p = 0; p < MAX; p++){
	for (int o = 0; o < MAX; o++){
		A[o][p]=rand();
	}
  }

  for (j = 0; j < MAX; j++){
	for (i = 0; i < MAX; i++){
		y[i] += A[i][j]*x[j];
		t1 = clock();
	}
  }
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: " << time << endl;
}
