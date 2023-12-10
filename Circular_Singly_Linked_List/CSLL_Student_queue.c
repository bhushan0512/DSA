#include<stdio.h>
#include<stdlib.h>
struct node{
    int reg;
    char name[50];
    int sem;
    int total;
    char grade;
    struct node *next;
};

typedef struct node *nodeptr;
nodeptr p,list=NULL,temp;

nodeptr getnode();
void insert_l();
void delete_b();
void display();

void main(){
    int c;
    char ch;
    do{
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:insert_l();
                    break;
            case 2:delete_b();
                    break;
            case 3:display();
                    break;
            case 4:printf("Thankyou!");
                    break;
            default:printf("Invalid choice");
        }
    }while(c!=4);
}

nodeptr getnode(){
    return ((struct node*)malloc(sizeof(struct node)));
}

void insert_l(){
    temp=getnode();
    printf("Enter the Student RegNo, Name, Semester, Total marks : \n");
    scanf("%d",&temp->reg);
    scanf("%s",temp->name);
    scanf("%d",&temp->sem);
    scanf("%d",&temp->total);
    if(temp->total >= 75)
        temp->grade='A';
    else if(temp->total > 60)
        temp->grade='B';
    else if(temp->total > 50)
        temp->grade='C';
    else if(temp->total >= 35)
        temp->grade='D';
    else
        temp->grade='F';
    if(list==NULL){
        list=temp;
        list->next=list;
        return;
    }
    temp->next=list->next;
    list->next=temp;
    list=temp;
}

void delete_b(){
    if(list==NULL){
        printf("No Students in the list");
        return;
    }
    p=list->next;
    if(list->next==list){
        printf("Reg\t Name\t Semester\t Total\t Grade\n");
        printf("%d\t %s\t %d\t %d\t %c\nRemoved from list",p->reg,p->name,p->sem,p->total,p->grade);
        list=NULL;
        p->next=NULL;
        free(p);
        return;
    }
    printf("Reg\t Name\t Semester\t Total\t Grade\n");
    printf("%d\t %s\t %d\t %d\t %\c\nRemoved from list",p->reg,p->name,p->sem,p->total,p->grade);
    list->next=p->next;
    p->next=NULL;
    free(p);
}

void display(){
    if(list==NULL){
        printf("No Students in the list");
    }
    else{
        p=list->next;
        printf("Reg\t Name\t Semester\t Total\t Grade\n");
        do{
            printf("%d\t %s\t %d\t %d\t %c\n",p->reg,p->name,p->sem,p->total,p->grade);
            p=p->next;
        }while(p!=list->next);
    }
}
