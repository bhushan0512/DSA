#include<stdio.h>
#include<stdlib.h>
struct node{
    int eno;
    char ename[50];
    int basic;
    char des[50];
    char doj[11];
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
    printf("Enter the Employee No, Name, Basic, Designation, Date of Joining : \n");
    scanf("%d",&temp->eno);
    scanf("%s",temp->ename);
    scanf("%d",&temp->basic);
    scanf("%s",temp->des);
    scanf("%s",temp->doj);
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
        printf("No Employees in the list");
        return;
    }
    p=list->next;
    if(list->next==list){
        printf("Eno\t Name\t Salary\t Designation\t DOJ\n");
        printf("%d\t %s\t %d\t %s\t %s\nRemoved from list",p->eno,p->ename,p->basic,p->des,p->doj);
        list=NULL;
        p->next=NULL;
        free(p);
        return;
    }
    printf("Eno\t Name\t Salary\t Designation\t DOJ\n");
    printf("%d\t %s\t %d\t %s\t %s\nRemoved from list",p->eno,p->ename,p->basic,p->des,p->doj);
    list->next=p->next;
    p->next=NULL;
    free(p);
}

void display(){
    if(list==NULL){
        printf("No Employees in the list");
    }
    else{
        p=list->next;
        printf("Eno\t Name\t Salary\t Designation\t DOJ\n");
        do{
            printf("%d\t %s\t %d\t %s\t %s\n",p->eno,p->ename,p->basic,p->des,p->doj);
            p=p->next;
        }while(p!=list->next);
    }
}
