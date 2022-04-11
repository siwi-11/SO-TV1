#include <stdio.h>
#include <string.h>
#include <pthread.h>

// aquest es el programa q mes tindras que adaptar. esta fet amb threads.
// falta el main. el main crida a selector() i au. tu pots ficar que el selector sigui el main, per exemple.

char order[8192];
double prepCost;
int prepTime;

void optionInsertMeal() {
    char choiceMain[2];
    char choiceEntrant[2];
    char out;
    char choices[8192];
    int keepOrdering = 1;
    int orderMore = 0;
    do {
        printf("\tEntrant choices:\n");
        printf("\t1. Crispy baked falafel\n");
        printf("\t2. Peanut Slaw in soba Noodles\n");
        printf("\t3. Bio Hummus\n");
        printf("\tInput entrant choice: ");
        scanf(" %c", choiceEntrant);
        strcat(choices, choiceEntrant);

        printf("\tMain dish choices:\n");
        printf("\ta. Minimal Eggplant Lasagna\n");
        printf("\tb. Spicy Veggie Tacos\n");
        printf("\tc. Plant Based XXL Burger\n");
        printf("\tInput main dish choice: ");
        scanf(" %c", choiceMain);
        strcat(choices, choiceMain);

        //CANVIA AIXO D'AQUI BAIX SI O SI, ES MOLT 'PARTICULAR'
        printf("\tOrder more meals? [y/n]\n");
        scanf(" %c", &out);
        if(out == 'n') {
            keepOrdering = 0;
        }
    } while(keepOrdering);

    (void)strcpy(order, choices);
    printf("Received order: %s\n", order);
    pthread_exit(NULL);
}

void optionCalculateMeal() {
    printf("Calculate cost of %s \n", order);

    double cost = 0;

    for(int i = 0; i < strlen(order); i++) {

        if(order[i] == '1') {
            cost += 3.5;
        } else if (order[i] == '2') {
            cost += 2.5;
        } else if (order[i] == '3') {
            cost += 3;
        } else if (order[i] == 'a') {
            cost += 4;
        } else if (order[i] == 'b') {
            cost += 4.5;
        } else if (order[i] == 'c') {
            cost += 5;
        } else {
            //pass
        }
    }

    prepCost = cost;
    printf("Received order cost of  %s order is %f EUR \n", order, cost);
    pthread_exit(NULL);
}

void optionCalculateTime() {

    printf("Calculate time of %s \n", order);

    int time = 0;
    prepTime = 0;

    for(int i = 0; i < strlen(order); i++) {
        
        // idea: SEPARA '1' I 'a' ens dos elses diferents
        if(order[i] == '1' || order[i] == 'a') {
            time += 3;
        }else if (order[i] == '2'){
            time += 1;
        }else if (order[i] == '3'){
            time += 2;
        }else if (order[i] == 'b'){
            time += 4;
        }else if (order[i] == 'c'){
            time += 5;
        }else{
            //pass
        }
    }

    prepTime = time;
    printf("Received order required time for preparation of  %s order is %d minutes \n", order, time);
    pthread_exit(NULL);
}


void selector(){

    pthread_t threads[0];

    int inputOption = 0;
    printf("\t1. Order meals \n");
    printf("\t2. Calculate price \n");
    printf("\t3. Calculate time \n");
    printf("\t4. Exit \n");
    printf("\tInput option: \n");
    scanf("%i", &inputOption);
    printf("\tInput option:  %i \n", inputOption);
    if(inputOption == 1) {
        pthread_create(&threads[0],NULL, optionInsertMeal, NULL);
        pthread_join(threads[0], NULL);
    } else if(inputOption == 2) {
        pthread_create(&threads[0],NULL, optionCalculateMeal, NULL);
        pthread_join(threads[0], NULL);
    } else if(inputOption == 3) {
        pthread_create(&threads[0],NULL, optionCalculateTime, NULL);
        pthread_join(threads[0], NULL);
    } else if(inputOption == 4) {
        return;
    } else {
        printf("Invalid option \n");
    }
    selector();
}
