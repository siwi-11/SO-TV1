#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct thread_data{
    unsigned long long start_nr, end_nr;//ex start_nr = 1, end_nr = 20000
};

struct shared_data{
    unsigned long long nr_of_thread;
    unsigned long long input;
    struct thread_data *td;
    unsigned long long sum;
};

int main(int argc, char  **argv) {
    pthread_t threads[5];
    struct shared_data sd;
    int PerfectThread1 (void *Para);
    int PerfectThread2 (void *Para);
    int PerfectThread3 (void *Para);
    int PerfectThread4 (void *Para);
    int PerfectThread5 (void *Para);

    unsigned long i, j, sum, prime;

// now do it with four threads
// setup a semaphore for synchronization of threads with an initial value of 0 (waits on 0)
    prime_count = 0;
    //time_count = GetTickCount();

    struct thread_data td[5];

    sd.input = 0;
    sd.nr_of_thread = 5;
    sd.td = td;
    sd.sum = 0;

    pthread_mutex_t Parameter1;

    pthread_mutex_init(&Parameter1, NULL);

    pthread_create(&threads[0], NULL, PerfectThread1, &sd.td[0]);

    pthread_mutex_t Parameter2;

    pthread_mutex_init(&Parameter2, NULL);

    pthread_create(&threads[1], NULL, PerfectThread2, &sd.td[1]);

    pthread_mutex_t Parameter3;

    pthread_mutex_init(&Parameter3, NULL);

    pthread_create(&threads[2], NULL, PerfectThread3, &sd.td[2]);

    pthread_mutex_t Parameter4;

    pthread_mutex_init(&Parameter4, NULL);

    pthread_create(&threads[3], NULL, PerfectThread4, &sd.td[3]);

    pthread_mutex_t Parameter5;

    pthread_mutex_init(&Parameter5, NULL);

    pthread_create(&threads[4], NULL, PerfectThread5, &sd.td[4]);

    return 0;
}
// code for each of the threads to execute

int PerfectThread1 (void *Para1) {
  
  /* aqui va el codi del link de la llista del readmi per a trobar els perfect numbers*/

    pthread_mutex_unlock(Para1);
    return 0;
}

int PerfectThread2 (void *Para2) {

     int i, Number, Sum = 0 ;   

     printf("\n Please Enter any number \n") ;   
     scanf("%d", &Number) ;   

     for(i = 1 ; i < Number ; i++)   
      {   
       if(Number % i == 0)   
         Sum = Sum + i ;   
      }    

     if (Sum == Number)   
        printf("\n %d is a Perfect Number", Number) ;   
     else   
        printf("\n%d is not the Perfect Number", Number) ;    

    pthread_mutex_unlock (Para2);
    return 0;
}

int PerfectThread3 (void *Para3) {

  int i, Number, Sum = 0 ;   

     printf("\n Please Enter any number \n") ;   
     scanf("%d", &Number) ;   

     for(i = 1 ; i < Number ; i++)   
      {   
       if(Number % i == 0)   
         Sum = Sum + i ;   
      }    

     if (Sum == Number)   
        printf("\n %d is a Perfect Number", Number) ;   
     else   
        printf("\n%d is not the Perfect Number", Number) ;  

    pthread_mutex_unlock (Para3);
    return 0;
}

int PerfectThread4 (void *Para4) {

  int i, Number, Sum = 0 ;   

     printf("\n Please Enter any number \n") ;   
     scanf("%d", &Number) ;   

     for(i = 1 ; i < Number ; i++)   
      {   
       if(Number % i == 0)   
         Sum = Sum + i ;   
      }    

     if (Sum == Number)   
        printf("\n %d is a Perfect Number", Number) ;   
     else   
        printf("\n%d is not the Perfect Number", Number) ;  

    pthread_mutex_unlock(Para4);
    return 0;
}

int PerfectThread5 (void *Para5) {

  int i, Number, Sum = 0 ;   

     printf("\n Please Enter any number \n") ;   
     scanf("%d", &Number) ;   

     for(i = 1 ; i < Number ; i++)   
      {   
       if(Number % i == 0)   
         Sum = Sum + i ;   
      }    

     if (Sum == Number)   
        printf("\n %d is a Perfect Number", Number) ;   
     else   
        printf("\n%d is not the Perfect Number", Number) ;  

    pthread_mutex_unlock(Para5);
    return 0;
} 
