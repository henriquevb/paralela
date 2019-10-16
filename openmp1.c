#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void openMP1() {
    #pragma omp parallel
    {
        printf("Oi mundo! Sou a thread %d \n", omp_get_thread_num());
    }
}

void openMP2() {
    #pragma omp parallel
    {
        printf("Sou a thread %d \n", omp_get_thread_num());
        for (int i = 0; i < 3; i++)
          printf("i = %d \n", i);
    }
}

int main (){

    printf("Região sequencial 1. Thread master.  Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Entrando na primeira região paralela...\n");

    openMP1();

    printf("Fim da primeira região paralela...\n");

    printf("\nRegião sequencial 2. Thread master. Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Entrando na segunda região paralela...\n");

    openMP2();

    printf("Fim da segunda região paralela...\n");
    printf("\nRegião sequencial 3. Thread master. Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Terminando o programa...\n");

}
