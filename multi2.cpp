#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

#define matrizA 100
#define matrizB 100
#define matrizC 100

int blockSize;
double **A, **B, **C;

void initialize();
void print_();

void initialize(){

	A = new double*[matrizA];
	for(int i = 0; i<matrizA; ++i){
		A[i] = new double[matrizB];
	}
	int numero_aleatorio;
	for(int i = 0; i<matrizA; ++i){
		for(int j = 0; j<matrizB; ++j){
			numero_aleatorio = 1 + rand() % (101 - 1);  ///numeros entre 1-100
			A[i][j] = numero_aleatorio;
		}
	}
	
	B = new double*[matrizB];
	for(int i = 0; i<matrizB; ++i){
		B[i] = new double[matrizC];
	}
	for(int i = 0; i<matrizB; ++i){
		for(int j =0; j<matrizC; ++j){
			numero_aleatorio = 1 + rand() % (101 - 1);  ///numeros entre 1-100	
			B[i][j] = numero_aleatorio;
		}
	}
	
	C = new double*[matrizA];
	for(int i = 0; i<matrizA; ++i){
		C[i] = new double[matrizC];
	}
}
	
void print_(){
	cout<<"MATRIZ A"<<endl;
	for(int i = 0; i<matrizA; ++i){
		for(int j = 0; j<matrizB; ++j){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"ARRAY B"<<endl;
	for(int i = 0; i<matrizB; ++i){
		for(int j = 0; j<matrizC; ++j){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"ARRAY RES"<<endl;
	for(int i = 0; i<matrizA; ++i){
		for(int j = 0; j<matrizC; ++j){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
	
int main(int argc, char *argv[]) {
	srand (time(NULL));
	initialize();
	blockSize = 10;
	for(int i = 0; i<matrizA; ++i){
		for(int j = 0; j<matrizC; ++j){
			C[i][j] = 0;
		}
	}
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i<matrizA; i+=blockSize){
		for(int j = 0; j<matrizC; j+=blockSize){
			for(int k =0; k<matrizB; k+=blockSize){
				for(int ii = i; ii<min(i+blockSize,matrizA); ++ii){
					for(int jj = j; jj<min(j+blockSize,matrizC); ++jj){
						for(int kk = k; kk<min(k+blockSize,matrizB); ++kk){
							C[ii][jj] += A[ii][kk] * B[kk][jj];
						}
					}
				}
			}
		}
	}
	end = std::chrono::high_resolution_clock::now();
	int64_t duration =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
		.count();
	std::cout << duration <<" nanoseconds"<<endl;
	std::cout << (double)duration/1000000000 <<endl;
	
	return 0;
}
