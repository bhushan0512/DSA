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
    do{
        printf("\n\n1.Insert at beginning\n2.Insert at last\n3.Insert Before\n4.Insert After\n5.Delete from beginning\n6.Delete Last\n7.Delete Middle\n8.Display\n9.Exit\n");
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
    temp->next=list;    // if(list==NULL)
    list=temp;
}

void insert_l(){
    p=list;
    if(p==NULL){
        insert_b();     // calling insert_b() funtion because the statements to insert an element if(list==NULL) is already given in that function
    }
    else{
        int x;
        printf("Enter the element : ");
        scanf("%d",&x);
        while(p->next!=NULL){
            p=p->next;
        }
        temp=getnode();
        temp->info=x;
        p->next=temp;
        temp->next=NULL;
    }
}

void insert_before(){
    int x,pos;
    nodeptr q;
    p=list;
    if(p==NULL){
        insert_b();
    }
    else{
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
            if(p==NULL){
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

}

void insert_after(){
    int x,pos;
    p=list;
    if(p==NULL){
        insert_b();
        return;
    }
    else{
        printf("Enter the position : ");
        scanf("%d",&pos);
        int i=0;
        while(i!=pos){
            p=p->next;
            if(p==NULL){
                printf("Cannot Insert");
                return;
            }
            i++;
        }
        if(p->next==NULL){
            insert_l();
            return;
        }
        else{
            printf("Enter the element : ");
            scanf("%d",&x);
            temp=getnode();
            temp->info=x;
            temp->next=p->next;
            p->next=temp;
        }
    }
}

void delete_b(){
    p=list;
    if(p==NULL){
        printf("No Elements");
        return;
    }
    printf("%d Deleted from List",p->info);
    list=p->next;
    p->next=NULL;
    free(p);
}

void delete_l(){
    p=list;
    if(p==NULL){
        printf("No Elements");
        return;
    }
    if(p->next==NULL){
        printf("%d Deleted from List",p->info);
        free(p);
        list=NULL;
        return;
    }
    while(p->next!=NULL){
        temp=p;
        p=p->next;
    }
    printf("%d Deleted from List",p->info);
    p->next=NULL;
    free(p);
    temp->next=NULL;
}

void delete_middle(){
    temp=p=list;
    int pos,i=0;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(p==NULL){
        printf("No Elements");
        return;
    }
    if(pos==0){
        delete_b();
        return;
    }
    while(i!=pos){
        temp=p;
        p=p->next;
        if(p==NULL){
            printf("Cannot Delete");
            return;
        }
        i++;
    }
    if(p->next==NULL){
        delete_l();
        return;
    }
    printf("%d Deleted from List",p->info);
    temp->next=p->next;
    p->next=NULL;
    free(p);
}

void display(){
    if(list==NULL){
        printf("No elemenets in the list");
    }
    else{
        p=list;
        printf("List elements are : ");
        while(p!=NULL){
            printf("%d ",p->info);
            p=p->next;
        }
    }
}
