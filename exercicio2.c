#include <stdio.h>
#include <pthread.h>

int vet[3];
pthread_mutex_t ExcMutua=PTHREAD_MUTEX_INITIALIZER;

void *soma(void *Numbers){
	pthread_mutex_lock(&ExcMutua);
	vet[0] = Numbers.num1 + Numbers.num2;
	pthread_mutex_unlock(&ExcMutua);
	printf("\nThread1 - Numero1: %d", Numbers.num1);
	printf("\nThread1 - Numero2: %d", Numbers.num2);
	printf("\nThread1 - Soma: %d", vet[0]);
	pthread_exit(0);
}
void *somadobro(void *Numbers){
	pthread_mutex_lock(&ExcMutua);
	vet[1] = (Numbers.num1*2) + (Numbers.num2*2);
	pthread_mutex_unlock(&ExcMutua);
	printf("\nThread2 - Numero anterior 1: %d", Numbers.num1);
	printf("\nThread2 - Numero anterior 2: %d", Numbers.num2);
	printf("\nThread2 - Numero atual: %d", Numbers.num1*2);
	printf("\nThread2 - Numero atual: %d", Numbers.num2*2);
	printf("\nThread2 - Soma: %d", vet[1]);
	pthread_exit(0);
}
int main (){
	int a, b;
	scanf("%d", a);
	scanf("%d", b);
	
	struct Numbers {
		int num1;
		int num2;
	}

	Numbers.num1 = a;
	Numbers.num2 = b;

	pthread_t t1, t2;
	pthread_create(&t1, 0, soma, &Numbers);
	pthread_create(&t2, 0, somadobro, &Numbers);
	pthread_join(t1,0);
	pthread_join(t2,0);
	for(int i=0; i<3;i++)	
		printf("\nVetor %d - Valor: %d", i, vet[i]);
}
