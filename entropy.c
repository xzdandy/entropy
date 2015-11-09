#include "entropy.h"
#include "stdlib.h"

struct _entropy_transcation{
	int n;
	int m;
	int *c;
	int (*f)(double);
};

int entropy_transcation_init(entropy_t *e, int _n, int (*_f)(double)){
	*e = malloc(sizeof(entropy_t));
	(*e)->n = _n;
	(*e)->f = _f;
	(*e)->m = 0;
	(*e)->c = malloc(sizeof(int) * (*e)->n);
	int i;
	for (i = 0; i < (*e)->n; i++){
		(*e)->c[i] = 0;
	}
	return 1;
}

int entropy_transcation_sample(entropy_t e, double item){
	int state = e->f(item);
	if (state >= 0 && state < e->n){
		e->c[state] += 1;
		e->m += 1;
		return 1;
	}
	else
		return 0;		
}


double entropy_transcation_get(entropy_t e){
	int i;
	double s = 0;
#include "math.h"
	for (i = 0; i < e->n; i++){
		if (e->c[i] != 0)
			s += e->c[i] * log(e->c[i]) / log(2);
	}
	
	return log(e->m) / log(2) - s / e->m;	
}

int entropy_transcation_abort(entropy_t *e){
	free((*e)->c);
	free(*e);
	return 1;
}














