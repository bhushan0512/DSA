#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};

typedef struct node *nodeptr;
nodeptr p,list=NULL,temp;

nodeptr getnode();
void insert_b();
void insert_l();
void insert_before();
void insert_after();
void delete_b();
void delete_l();
void delete_middle();
void display();

void main(){
    int c;
    char ch;
    do{
        printf("\n\n1.Insert at beginning\n2.Insert at last\n3.Insert Before\n4.Insert After\n5.Delete beginning\n6.Delete Last\n7.Delete Middle\n8.Display\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:insert_b();
                    break;
            case 2:insert_l();
                    break;
            case 3:insert_before();
                    break;
            case 4:insert_after();
                    break;
            case 5:delete_b();
                    break;
            case 6:delete_l();
                    break;
            case 7:delete_middle();
                    break;
            case 8:display();
                    break;
            case 9:printf("Thankyou!");
                    break;
            default:printf("Invalid choice");
        }
    }while(c!=9);
}

nodeptr getnode(){
    return ((struct node*)malloc(sizeof(struct node)));
}

void insert_b(){
    int x;
    printf("Enter the element : ");
    scanf("%d",&x);
    temp=getnode();
    temp->info=x;
    if(list==NULL){
        list=temp;
        list->next=list;
    }
    else{
        temp->next=list->next;
        list->next=temp;
    }
}

void insert_l(){
    if(list==NULL){
        insert_b();
        return;
    }
    int x;
    printf("Enter the element : ");
    scanf("%d",&x);
    temp=getnode();
    temp->info=x;
    temp->next=list->next;
    list->next=temp;
    list=temp;
}

void insert_before(){
    int x,pos;
    nodeptr q;
    if(list==NULL){
        insert_b();
        return;
    }
    p=list->next;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==0){
        insert_b();
        return;
    }
    int i=0;
    while(i!=pos){
        q=p;
        p=p->next;
        if(p==list->next){                // if you enter a position that is beyond the position of last node
            printf("Cannot Insert");
            return;
        }
        i++;
    }
        printf("Enter the element : ");
        scanf("%d",&x);
        temp=getnode();
        temp->info=x;
        q->next=temp;
        temp->next=p;
}

void insert_after(){
    int x,pos;
    if(list==NULL){
        insert_b();
        return;
    }
    p=list->next;
    printf("Enter the position : ");
    scanf("%d",&pos);
    int i=0;
    while(i!=pos){
        p=p->next;
        if(p==list->next){
            printf("Cannot Insert");
            return;
        }
        i++;
    }
    if(p->next==list->next){
        insert_l();
        return;
    }
    printf("Enter the element : ");
    scanf("%d",&x);
    temp=getnode();
    temp->info=x;
    temp->next=p->next;
    p->next=temp;
}

void delete_b(){
    if(list==NULL){
        printf("No elements");
        return;
    }
    p=list->next;
    if(list->next==list){
        printf("%d Deleted from the list",p->info);
        list=NULL;
        p->next=NULL;
        free(p);
        return;
    }
    printf("%d Deleted from the list",p->info);
    list->next=p->next;
    p->next=NULL;
    free(p);
}

void delete_l(){
    if(list==NULL){
        printf("No elements");
        return;
    }   
    p=list->next;
    if(list->next==list){
        printf("%d Deleted from the list",p->info);
        list=NULL;
        p->next=NULL;
        free(p);
        return;
    }
    while(p->next!=list->next){
        temp=p;
        p=p->next;
    }
    printf("%d Deleted from the list",p->info);
    temp->next=p->next;
    list=temp;
    p->next=NULL;
    free(p);
}

void delete_middle(){
    int pos,i=0;
    if(list==NULL){
        printf("No Elements");
        return;
    }
    temp=p=list->next;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==0){
        delete_b();
        return;
    }
    while(i!=pos){
        temp=p;
        p=p->next;
        if(p==list->next){
            printf("Cannot Delete");
            return;
        }
        i++;
    }
    if(p->next==list->next){
        delete_l();
        return;
    }
    printf("%d Deleted from the list",p->info);
    temp->next=p->next;
    p->next=NULL;
    free(p);
}

void display(){
    if(list==NULL){
        printf("No elemenets");
    }
    else{
        p=list->next;
        printf("List elements are : ");
        do{
            printf("%d ",p->info);
            p=p->next;
        }while(p!=list->next);
    }
}
