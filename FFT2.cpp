#include <complex>
#include <iostream>
#include <valarray>

const double PI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;


void FFT(CArray x, int start, int size, int stride, CArray w){
	if (size <=1) return;
	
//	FFT(x, start, size/2, 2*stride,w);
//	FFT(x, start+1, size/2, 2*stride,w);

	Complex t = 0.0;
	int allk = start;
	int oddk = start + 1;
	int evenk = start;
	int ks = 0;
	
	stride = 2*stride;
	size = size/2;

        FFT(x, start, size, stride,w);
        FFT(x, start+1, size, stride,w);


	for(int k=0; k < size/2; k++){
		ks = k* stride;
		oddk = oddk + 2*ks;
		evenk = evenk + oddk -1;
		allk = allk + ks;
		t = x[oddk]*w[allk];
	std::cout << "x[even]k: " << x[evenk] << "  t: " << t << std::endl;
		x[allk] = x[evenk] + t;
		int sallk = allk + size/2;
		x[sallk] = x[evenk] - t;
	}


    for (int i = 0; i < size; ++i)
    {
        std::cout << x[i] << std::endl;
    }
	std::cout << "new run" << std::endl;


}

int main(){
	const Complex test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};
    	int N = 8;
	CArray data(test, N);
	CArray w(test,N);

	for(int j = 0; j<N; j++){
        	w[j]= std::polar(1.0,-2*PI*j/N);
	}	
	
	FFT(data,0,N,1,w);

	std::cout << "fft" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        std::cout << data[i] << std::endl;
    }	


}



