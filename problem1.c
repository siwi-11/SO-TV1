#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int TreeProcess1(){

    printf("\nTree Process 1:\n");

    pid_t process1, process2, process3, process4;

    process1 = fork();
    if(process1 == 0)
    {
        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(),getppid());
        process2 = fork();
        process3 = fork();

        if(process2 == 0 && process3 != 0) {
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }

        if(process3 == 0 && process2 != 0){
            process4 = fork();

            if(process4 == 0)
            {
                printf("Child process4 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }else{
                printf("Child process3 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }
        }

        if(process2 != 0 && process3 != 0)
            while (wait(NULL) > 0) ;

    } else {
        while (wait(NULL) > 0) ;
    }
}

int TreeProcess2(){
    printf("\n\Tree Process 2:\n");

    pid_t process1, process2, process3, process4, process5;

    process1 = fork();

    if(process1 == 0){

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        process2 = fork();
        process3 = fork();
        process4 = fork();

        if(process2 == 0 && process3 != 0 && process4 != 0)
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        if(process2 != 0 && process3 == 0 && process4 != 0)
        {
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process5 = fork();
            if(process5 == 0)
                printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;

        }
        if(process2 != 0 && process3 != 0 && process4 == 0)
            printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());

        if(process2 != 0 && process3 != 0)
            while (wait(NULL) > 0) ;

    }else{
        while (wait(NULL) > 0) ;
    }
}

int TreeProcess3(){
    printf("\nTree Process 3:\n");

    pid_t process1, process2, process3, process4, process5, process6, process7;

    process1 = fork();

    if(process1 == 0){

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        process2 = fork();
        process3 = fork();
        process5 = fork();

        if(process2 == 0 && process3 != 0 && process5 != 0)
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        if(process2 != 0 && process3 == 0 && process5 != 0){
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process4 = fork();
            if(process4 == 0)
                printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;

        }
        if(process2 != 0 && process3 != 0 && process5 == 0) {
            printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process6 = fork();
            if (process6 == 0){
                printf("Child process6 with id: %d and its Parent id: %d \n", getpid(), getppid());
                process7 = fork();
                if(process7 == 0)
                    printf("Child process7 with id: %d and its Parent id: %d \n", getpid(), getppid());
                else
                    while (wait(NULL) > 0) ;

            }else
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 != 0 && process5 != 0)
            while (wait(NULL) > 0) ;

    }else{
        while (wait(NULL) > 0) ;
    }

}

int TreeProcess4(){
    printf("\nTree Process 4:\n");
    pid_t process1, process2, process3, process4, process5, process6, process7, process8;

    process1 = fork();
    if(process1 == 0){

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());

        process2 = fork();
        process3 = fork();
        process4 = fork();
        process5 = fork();

        if(process2 == 0 && process3 != 0 && process4 != 0 && process5 != 0){
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process6 = fork();
            if(process6 == 0)
                printf("Child process6 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 == 0 && process4 != 0 && process5 != 0){
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process7 = fork();
            if(process7 == 0)
                printf("Child process7 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 != 0 && process4 == 0 && process5 != 0){
            printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            process8 = fork();
            if(process8 == 0)
                printf("Child process8 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 != 0 && process4 != 0 && process5 == 0){
            printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }
        if(process2 != 0 && process3 != 0 && process4 != 0 && process5 != 0){
            while (wait(NULL) > 0) ;
        }

    }else{
        while (wait(NULL) > 0) ;
    }
}
