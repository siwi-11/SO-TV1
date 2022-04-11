#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int processTree1(){

    printf("\n\nPROCESS TREE 1:\n");

    pid_t P1, P2, P3, P4;

    P1 = fork();
    if(P1 == 0)
    {
        printf("Child P1 with id: %d and its Parent id: %d \n", getpid(),getppid());
        P2 = fork();
        P3 = fork();

        if(P2 == 0 && P3 != 0) {
            printf("Child P2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }

        if(P3 == 0 && P2 != 0){
            P4 = fork();

            if(P4 == 0)
            {
                printf("Child P4 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }else{
                printf("Child P3 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }
        }

        if(P2 != 0 && P3 != 0)
            while (wait(NULL) > 0) ;

    } else {
        while (wait(NULL) > 0) ;
    }
}

int processTree2(){
    printf("\n\nPROCESS TREE 2:\n");

    pid_t P1, P2, P3, P4, P5;

    P1 = fork();

    if(P1 == 0){

        printf("Child P1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        P2 = fork();
        P3 = fork();
        P4 = fork();

        if(P2 == 0 && P3 != 0 && P4 != 0)
            printf("Child P2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        if(P2 != 0 && P3 == 0 && P4 != 0)
        {
            printf("Child P3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P5 = fork();
            if(P5 == 0)
                printf("Child P5 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;

        }
        if(P2 != 0 && P3 != 0 && P4 == 0)
            printf("Child P4 with id: %d and its Parent id: %d \n", getpid(), getppid());

        if(P2 != 0 && P3 != 0)
            while (wait(NULL) > 0) ;

    }else{
        while (wait(NULL) > 0) ;
    }
}

int processTree3(){
    printf("\n\nPROCESS TREE 3:\n");

    pid_t P1, P2, P3, P4, P5, P6, P7;

    P1 = fork();

    if(P1 == 0){

        printf("Child P1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        P2 = fork();
        P3 = fork();
        P5 = fork();

        if(P2 == 0 && P3 != 0 && P5 != 0)
            printf("Child P2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        if(P2 != 0 && P3 == 0 && P5 != 0){
            printf("Child P3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P4 = fork();
            if(P4 == 0)
                printf("Child P4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;

        }
        if(P2 != 0 && P3 != 0 && P5 == 0) {
            printf("Child P5 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P6 = fork();
            if (P6 == 0){
                printf("Child P6 with id: %d and its Parent id: %d \n", getpid(), getppid());
                P7 = fork();
                if(P7 == 0)
                    printf("Child P7 with id: %d and its Parent id: %d \n", getpid(), getppid());
                else
                    while (wait(NULL) > 0) ;

            }else
                while (wait(NULL) > 0) ;
        }
        if(P2 != 0 && P3 != 0 && P5 != 0)
            while (wait(NULL) > 0) ;

    }else{
        while (wait(NULL) > 0) ;
    }

}

int processTree4(){
    printf("\n\nPROCESS TREE 4:\n");
    pid_t P1,P2, P3, P4, P5, P6, P7, P8;

    P1 = fork();
    if(P1 == 0){

        printf("Child P1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        P2 = fork();
        P3 = fork();
        P4 = fork();
        P5 = fork();

        if(P2 == 0 && P3 != 0 && P4 != 0 && P5 != 0){
            printf("Child P2 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P6 = fork();
            if(P6 == 0)
                printf("Child P6 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(P2 != 0 && P3 == 0 && P4 != 0 && P5 != 0){
            printf("Child P3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P7 = fork();
            if(P7 == 0)
                printf("Child P7 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(P2 != 0 && P3 != 0 && P4 == 0 && P5 != 0){
            printf("Child P4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            P8 = fork();
            if(P8 == 0)
                printf("Child P8 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(P2 != 0 && P3 != 0 && P4 != 0 && P5 == 0){
            printf("Child P5 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }
        if(P2 != 0 && P3 != 0 && P4 != 0 && P5 != 0){
            while (wait(NULL) > 0) ;
        }

    }else{
        while (wait(NULL) > 0) ;
    }
}
