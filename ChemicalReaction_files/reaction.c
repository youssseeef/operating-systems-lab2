#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();

// Initialize the reaction object
void reaction_init(struct reaction *reaction)
{
  // clear the counters
  reaction->countO = 0;
  reaction->countH = 0;

  // init the mutex
  pthread_mutex_init(&reaction->ourMutex, 0);

  // init the condition variables
  pthread_cond_init(&reaction->condO, 0);
  pthread_cond_init(&reaction->condP, 0);
}


void reaction_h(struct reaction *reaction)
{
	// FILL ME IN
}


void reaction_o(struct reaction *reaction)
{
	// FILL ME IN
}
