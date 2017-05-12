#include <stdio.h>
#include <pthread.h>

struct reaction {
	// FILL ME IN - OKAY
	pthread_mutex_t ourMutex;
	pthread_cond_t condO,condP;
	int countO;
	int countH;

};

void reaction_init(struct reaction *reaction);

void reaction_h(struct reaction *reaction);

void reaction_o(struct reaction *reaction);
