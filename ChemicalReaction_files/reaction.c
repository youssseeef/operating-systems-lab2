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
  pthread_cond_init(&reaction->condH, 0);
}


void reaction_h(struct reaction *reaction)
{
  // lock the critical section
  pthread_mutex_lock(&reaction->ourMutex);

  // check the count of H atoms
  if (reaction->countH == 2) {
    // signal the condH
    pthread_cond_wait(&reaction->condH, &reaction->ourMutex);
    // check for the o count
    if (reaction->countO == 1) {
      make_water();
    }
  } else {
    // create a new H atom
    ++reaction->countH;
  }

  // realease access to the critical section
  pthread_mutex_unlock(&reaction->ourMutex);
}


void reaction_o(struct reaction *reaction)
{
	// lock the critical section
  pthread_mutex_lock(&reaction->ourMutex);

  // check the count of O atoms
  if (reaction->countO == 1) {
    // signal the condO
    pthread_cond_wait(&reaction->condO, &reaction->ourMutex);
    // check for the H count
    if (reaction->countH == 2) {
      make_water();
    }
  } else {
    // create a new H atom
    ++reaction->countO;
  }

  // realease access to the critical section
  pthread_mutex_unlock(&reaction->ourMutex);
}
