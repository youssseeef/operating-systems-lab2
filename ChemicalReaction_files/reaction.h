#include <stdio.h>
#include <pthread.h>

struct reaction {
	// FILL ME IN - OKAY
	pthread_mutex_t lock;
	pthread_cond_t react, newH;
	int hCount;
};

void reaction_init(struct reaction *reaction);

void reaction_h(struct reaction *reaction);

void reaction_o(struct reaction *reaction);
