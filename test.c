#include "entropy.h"
#include "stdio.h"

int f(double in){
	return (int) in % 10;
}


int main(){
	entropy_t e;
	entropy_transcation_init(&e, 10);
	int i;
	for (i = 0; i < 10; i++){
		entropy_transcation_sample(e,f(i));
	}
	
	double h = entropy_transcation_get(e);
	printf("%f\n", h);
	entropy_transcation_abort(&e);
}
