#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int TreeProcess1(){

    printf("\nTree Process 1:\n");

    pid_t process1, process2, process3, process4;
    //fork the first process
    process1 = fork();
    if(process1 == 0) //if there's child
    {
        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(),getppid());
        //fork the other processes
        process2 = fork();
        process3 = fork();
        //if there's child in process 2
        if(process2 == 0 && process3 != 0) {
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }
        //if there's child in process 3
        if(process3 == 0 && process2 != 0){
            //fork the process 4
            process4 = fork();
            //if there's child in process 4
            if(process4 == 0)
            {
                printf("Child process4 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }else{ //if not, print process 3
                printf("Child process3 with id: %d and its Parent id: %d \n", getpid(),getppid());
            }
        }
        //if there's no more processes, sleep
        if(process2 != 0 && process3 != 0)
            while (wait(NULL) > 0) ;

    } else {
        while (wait(NULL) > 0) ;
    }
}

int TreeProcess2(){
    printf("\nTree Process 2:\n");

    pid_t process1, process2, process3, process4, process5;
    
    //fork the first process
    process1 = fork();

    if(process1 == 0){ //if there's child

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());
        
        //create child processes
        process2 = fork();
        process3 = fork();
        process4 = fork();

        if(process2 == 0 && process3 != 0 && process4 != 0) //if there's child in process 2
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        
        if(process2 != 0 && process3 == 0 && process4 != 0) //if there's child in process 3
        {
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            //create process 5
            process5 = fork();
            
            if(process5 == 0) //if there's child in process 5
                printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else
                while (wait(NULL) > 0) ; //else sleep

        }
        if(process2 != 0 && process3 != 0 && process4 == 0) //if there's child in process 4
            printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());
        
        //if there's no more processes, sleep
        if(process2 != 0 && process3 != 0)
            while (wait(NULL) > 0) ;

    }else{
        while (wait(NULL) > 0) ;
    }
}

int TreeProcess3(){
    printf("\nTree Process 3:\n");

    pid_t process1, process2, process3, process4, process5, process6, process7;
    
    //fork the first process
    process1 = fork();

    if(process1 == 0){ //if there's child in process 1

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());
        //create child processes
        process2 = fork();
        process3 = fork();
        process5 = fork();

        if(process2 == 0 && process3 != 0 && process5 != 0) //if there's child in process 2
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
        
        if(process2 != 0 && process3 == 0 && process5 != 0){ //if there's child in process 3
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());            
            //create process 4
            process4 = fork();
            
            if(process4 == 0) //if there's child in process 4
                printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else //if not, sleep
                while (wait(NULL) > 0) ;

        }
        if(process2 != 0 && process3 != 0 && process5 == 0) { //if there's child in process 5
            printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());            
            //create process 6
            process6 = fork();
            
            if (process6 == 0){ //if there's child in process 6
                printf("Child process6 with id: %d and its Parent id: %d \n", getpid(), getppid());
                //create process 7
                process7 = fork();
                
                if(process7 == 0) //if there's child in process 7
                    printf("Child process7 with id: %d and its Parent id: %d \n", getpid(), getppid());
                else //if not, sleep
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
    
    //fork the first process
    process1 = fork();
    if(process1 == 0){ //if there's child in process 1

        printf("Child process1 with id: %d and its Parent id: %d \n", getpid(), getppid());
        
        //create child processes
        process2 = fork();
        process3 = fork();
        process4 = fork();
        process5 = fork();

        if(process2 == 0 && process3 != 0 && process4 != 0 && process5 != 0){ //if there's child in process 2
            printf("Child process2 with id: %d and its Parent id: %d \n", getpid(), getppid());
            //create process 6
            process6 = fork();
            
            if(process6 == 0) //if there's child in process 6
                printf("Child process6 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else //if not, sleep
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 == 0 && process4 != 0 && process5 != 0){ //if there's child in process 3
            printf("Child process3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            //create process 7
            process7 = fork();
            
            if(process7 == 0) //if there's child in process 7
                printf("Child process7 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else //if not, sleep
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 != 0 && process4 == 0 && process5 != 0){ //if there's child in process 4
            printf("Child process4 with id: %d and its Parent id: %d \n", getpid(), getppid());
            //create process 8
            process8 = fork();
            
            if(process8 == 0) //if there's child in process 8
                printf("Child process8 with id: %d and its Parent id: %d \n", getpid(), getppid());
            else //if not, sleep
                while (wait(NULL) > 0) ;
        }
        if(process2 != 0 && process3 != 0 && process4 != 0 && process5 == 0){ //if there's child in process 5
            printf("Child process5 with id: %d and its Parent id: %d \n", getpid(), getppid());
        }
        if(process2 != 0 && process3 != 0 && process4 != 0 && process5 != 0){
            while (wait(NULL) > 0) ;
        }

    }else{
        while (wait(NULL) > 0) ;
    }
}
