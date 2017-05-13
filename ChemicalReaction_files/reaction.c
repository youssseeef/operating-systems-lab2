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
    reaction->hCount = 0;

    // init the mutex
    pthread_mutex_init(&reaction->lock, 0);

    // init the condition variables
    pthread_cond_init(&reaction->react, 0);
    pthread_cond_init(&reaction->newH, 0);
}

void reaction_h(struct reaction *reaction)
{
    // lock the critical section
    pthread_mutex_lock(&reaction->lock);

    ++reaction->hCount;
    // signal the creation of a new H
    // up by one
    pthread_cond_signal(&reaction->newH);
    // block the reaction
    // down by one
    pthread_cond_wait(&reaction->react, &reaction->lock);

    // realease access to the critical section
    pthread_mutex_unlock(&reaction->lock);
}

void reaction_o(struct reaction *reaction)
{
    pthread_mutex_lock(&reaction->lock);

    // block until there are 2 H atoms
    // down by one
    while (reaction->hCount < 2) pthread_cond_wait(&reaction->newH, &reaction->lock);

    // when ready create water
    make_water();
    // reset the counter
    reaction->hCount -= 2;

    // unblock the reaction
    // up by two
    pthread_cond_signal(&reaction->react);
    pthread_cond_signal(&reaction->react);

    // release access to the critical section
    pthread_mutex_unlock(&reaction->lock);
}
