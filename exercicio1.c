#include <stdio.h>
#include <pthread.h>

int soma=0;
pthread_mutex_t ExcMutua=PTHREAD_MUTEX_INITIALIZER;

void *random10(void *par){
	for (int i=0; i<99999; i++);
	for(int i = 0; i<10; i++){
		pthread_mutex_lock(&ExcMutua);
		soma += rand()%100;
		pthread_mutex_unlock(&ExcMutua);	
	}
	printf("\nRandom = %d", soma);
	pthread_exit(0);
}
void *intervalo(void *par){
	for (int i=0; i<99999; i++);
	for(int i = 30; i<35; i++){
		pthread_mutex_lock(&ExcMutua);
		soma += i;
		pthread_mutex_unlock(&ExcMutua);	
	}
	printf("\nIntervalo = %d", soma);
	pthread_exit(0);
}
int main (){
	pthread_t t1, t2;
	pthread_create(&t1, 0, random10, "Thread1");
	pthread_create(&t2, 0, intervalo, "Thread2");
	pthread_join(t1,0);
	pthread_join(t2,0);
	printf("\nSoma %d", soma);
}
