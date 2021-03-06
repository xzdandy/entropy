#ifndef ENTROPY_H
#define ENTROPY_H

typedef struct _entropy_transcation* entropy_t;

int entropy_transcation_init(entropy_t *e, int _n);
int entropy_transcation_sample(entropy_t e, int state);
double entropy_transcation_get(entropy_t e);
int entropy_transcation_abort(entropy_t *e);


#endif
