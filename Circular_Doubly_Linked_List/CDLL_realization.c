#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node *nodeptr;
nodeptr p,list=NULL,temp;

nodeptr getnode();
void insert_b();
void insert_l();
void delete_b();
void delete_l();
void display();

void main(){
    int c;
    do{
        printf("\n\n1.Insert beginning\n2.Insert last\n3.Delete beginning\n4.Delete last\n5.Display\n6.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:insert_b();
                    break;
            case 2:insert_l();
                    break;
            case 3:delete_b();
                    break;
            case 4:delete_l();
                    break;
            case 5:display();
                    break;
            case 6:printf("Thankyou");
                break;
            default:printf("Invalid choice");
        }
    }while(c!=6);
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
        list->right=temp;
        list->left=temp;
    }
    else{
        temp->right=list->right;
        list->right->left=temp;
        list->right=temp;
        temp->left=list;
    }
}

void insert_l(){
    int x;
    printf("Enter the element : ");
    scanf("%d",&x);
    temp=getnode();
    temp->info=x;
    if(list==NULL){
        list=temp;
        list->right=temp;
        list->left=temp;
    }
    else{
        temp->right=list->right;
        list->right->left=temp;
        list->right=temp;
        temp->left=list;
        list=temp;
    }
}

void delete_b(){
    if(list==NULL){
        printf("No elements\n");
        return;
    }
    if(list->right==list){
        p=list;
        list=NULL;
        printf("\n%d Deleted from list\n",p->info);
        free(p);
        return;
    }
    p=list->right;
    list->right=p->right;
    p->right->left=list;
    printf("\n%d Deleted from list\n",p->info);
    free(p);
}

void delete_l(){
    if(list==NULL){
        printf("No elements\n");
        return;
    }
    if(list->right==list){
        p=list;
        list=NULL;
        printf("\n%d Deleted from list\n",p->info);
        free(p);
        return;
    }
    p=list;
    list->left->right=list->right;
    list->right->left=list->left;
    list=list->left;
    printf("\n%d Deleted from list\n",p->info);
    free(p);
}
void display(){
    if(list==NULL){
        printf("No elemenets");
    }
    else{
        p=list->right;
        printf("List elements are : ");
        do{
            printf("%d ",p->info);
            p=p->right;
        }while(p!=list->right);
    }
}
