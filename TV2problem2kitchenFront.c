#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum {false,true} bool;

int displayMenu();
int numMenus();
void errorOption(int type);

int main(){
  bool exitApp = false;
  int fd;
  
  char * myfifo = "/tmp/myfifo/"
    
  mkfifo(myfifo, 0666);
  char arr1[150];
  int menu, nMenu, nOrder = 100, totalMenus = 0;
  do{
    menu = displayMenu();
    if (menu==0)
      exitApp = true;
    else{
      system("clear");
      nMenu=numMenus();
      if (menu >= 1 && menu <= 5){
        if (nMenu != 0){
          fd = open(myfifo, O_WRONLY);
          write(fd, &menu, 2);
          write(fd, &nMenu, 2);
          write(fd, &nOrder, 4);
          close(fd);
          
          fd = open(myfifo, O_RDONLY);
          
          read(fd, &totalMenus, 2);
          
          printf("Pending time menus:\n");
          for(int i=0; i<totalMenus; i++){
            read(fd, arr1, sizeof(arr1+1);
            printf("%s", arr1);
          }
          close(fd);
          nOrder = nOrder+1;
                 
          printf("press any key to continue\n");
          getchar();getchar();
          system("clear");               
        }
      }else{
        errorOption(0);
      }
    }
  }while(!exitApp);
  return 0;
}
                 
int displayMenu(){
  int inputChoice;
  
  printf("DELIVEROO MENU\n");
  printf("1: Fatty American Menu\n");
  printf("2: Vegetarian Slim Poke Menu\n");
  printf("3: Bio Italian Pizza Menu\n");
  printf("4: Mexican Tacos Special\n");
  printf("5: Japanese Spicy Bento\n");
  printf("0: Exit Menu\n");
  scanf("%d%", &inputChoice);
  
  return inputChoice;
}
        
int numMenus(){
  int inputChoice;
  
  printf("DELIVEROO MENU\n");
  printf("How many choices?\n");
  printf("0: Exit Menu\n");
  scanf("%d", &inputChoice);
  
  return inputChoice;
}
                 
void errorOPtion(int type){
  switch (type){
    case 1:
      printf("Kitchen is not open\n");
      break;
    default:
      printf("No valid option\n");
  }
  printf("Press any key to continue\n");
  getchar(); getchar();
  system("clear");
}
                   
        
        
        
    
