#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct dato{
  char type[30];
  int time;
  int nMenu;
  int nOrder;
  int priority;
};

struc list{
  struct dato datos;
  struct list *sig;
};

struct list *createnode(void);
struct list *pop(struct list *l, struct dato *x);
struct list *orderedInser(struct list *l, struct dato x, int (*f)(struct dato a, struct dato b));
int legthl(struct list *l);
struct list *deleteList(struct list *l);
int comparePrior(struct dato x, struct dato y);

int main(){
  int fd1;
  
  char * myfifo = "/tmp/myfifo";
  mkfifo(myfifo, 0666);
  int totalMenus;
  char arr1[150];
  int menu, nMenu, nOrder;
  struct list *l;
  struct dato x;
  
  while(1){
    fd1 = open(myfifo, O_RDONLY);
    read(fd1, &menu, 2);
    read(fd1, &nMenu, 2);
    read(fd1, &nOrder, 4);
    
    switch (menu){
      case 1:
        strcpy(x.type, "Fatty American Menu");
        x.time = 10;
        x.nMenu = nMenu;
        x.nOrder = nOrder;
        x.priority = 5;
      break;
      case 2:
        strcpy(x.type, "Vegetarian Slim Poke Menu);
        x.time = 2;
        x.nMenu = nMenu;
        x.nOrder = nOrder;
        x.priority = 5;
      break;
      case 3:
        strcpy(x.type, "Bio Italian Pizza Menu");
        x.time = 5;
        x.nMenu = nMenu;
        x.nOrder = nOrder;
        x.priority = 3;
      break;
      case 4:
        strcpy(x.type, "Mexican Tacos Special");
        x.time = 7;
        x.nMenu = nMenu;
        x.nOrder = nOrder;
        x.priority = 2;
      break;
      case 5:
        strcpy(x.type, "Japanese Spicy Bento");
        x.time = 12;
        x.nMenu = nMenu;
        x.nOrder = nOrder;
        x.priority = 1;
      break;
    }
    
    l = orderedInsert(l, x, comparePrior);
    printf("KitchenFront new Order: %s, nOrder[%d]\n", x.type, x.nOrder);
    close(fd1);
               
    fd1 = open(myfifo, O_WRONLY);
               
    totalMenus = lengthl(l);
               
    write(fd1, &totalMenus, 2);
               
    struct list *p;
    p = l;
    int calcTime = 0;
    while (p!=NULL){
      calcTime = calcTime + (p->datos.time * p->datos.nMenu);
      snprintf(arr1, sizeof(arr1), "[%d] %s --> %d minutes\n", p->datos.nOrder, p->datos.type, calcTime);
                 
      write(fd1, arr1, sizeof(arr1)+1);
      p = p->sig;
    }
    close(fd1);
  }
  return 0;
}
               
struct list *createnode(void){
  return (struct list *) malloc(sizeof(struct list));
}

struct list *pop(struct list *l, struct dato *x){
  if (l != NULL){
    struct list *p,*q;
    p = l;
    q = p->sig;
    *x = p->datos;
    free(p);
    l = q;
    return l;
  }
}
               
               
               
struct list *orderedInsert(struct list *l, struct dato x, int (*f)(struct dato a, struct dato b)){
  struct list *p, *q, *ant;
  int ind;
  q = createnode();
  q->datos = x;
  q->sig =NULL;
  if (l==NULL){
    l = q;
    return l;
  }
  
  ant = NULL;
  p = l;
  ind = 0;
  while (p!=NULL && ind==0){
    if ((*f)(x,p->datos) < 0)
      ind = 1;
    else{
      ant = p;
      p = p->sig;
    }
  }
  if (ant==NULL){
    q->sig = l;
    l = q;
  }else{
    ant->sig = l;
    q->sig = p;
  }
  return l;
}
int lengthl(struct list *l){
  struct list *p;
  int n;
  n=0;
  p=l;
  while (p!=NULL){
    ++n;
    p = p-<sig;
  }
  return n;
}
               
struct list *deleteList(struct list *l){
  struc list *p, *q;
  p=l;
  while (p!=NULL){
    q=p->sig;
    free(p);
    p=q;
  }
  return NULL;
}
               
int comparePrior(struct dato x, struct dato y){
  int u,v,w,z;
  u = x.priority;
  v = x.priority;
  w = x.nOrder;
  z = y.nOrder;
  
  if (u<v)
    return 1;
  if (u>v)
    return -1;
  if(u==v && w<z)
    return -1;
  return 1;
}
               
               
        
