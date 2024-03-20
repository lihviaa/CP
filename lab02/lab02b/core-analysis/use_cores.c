#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *thrd_func() { while(1) { continue; } }

int main(int argc, char *argv[]) {
	long num_of_threads = strtol(argv[1], NULL, 10);

	pthread_t *thread_array = malloc(num_of_threads * sizeof(pthread_t));
	
	for(int i = 0; i < num_of_threads; i++) {
		pthread_create(&thread_array[i], NULL, thrd_func, NULL);
	}

	for(int j = 0; j < num_of_threads; j++) {
		pthread_join(thread_array[j], NULL);
	}

	return 0;
}
