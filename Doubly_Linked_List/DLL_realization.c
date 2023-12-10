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
        printf("\n\n1.Insert at beggning\n2.Insert at last\n3.Insert Before\n4.Insert After\n5.Delete from beginning\n6.Delete Last\n7.Delete Middle\n8.Display\n9.Exit\n");
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
    temp->left=NULL;
    if(list==NULL){
        list=temp;
        temp->right=NULL;
        return;
    }
    temp->right=list;
    list->left=temp;
    list=temp;
}

void insert_l(){
    p=list;
    if(p==NULL){
        insert_b();
        return;
    }
    int x;
    printf("Enter the element : ");
    scanf("%d",&x);
    temp=getnode();
    temp->info=x;
    temp->right=NULL;
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=temp;
    temp->left=p;
}

void insert_before(){
    int x,pos;
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
            p=p->right;
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
            p->left->right=temp;
            temp->left=p->left;
            temp->right=p;
            p->left=temp;
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
            p=p->right;
            if(p==NULL){
                printf("Cannot Insert");
                return;
            }
            i++;
        }
        if(p->right==NULL){
            insert_l();
            return;
        }
        else{
            printf("Enter the element : ");
            scanf("%d",&x);
            temp=getnode();
            temp->info=x;
            p->right->left=temp;
            temp->right=p->right;
            temp->left=p;
            p->right=temp;
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
    if(p->right==NULL){
        free(p);
        list=NULL;
        return;
    }
    list=p->right;
    list->left=NULL;
    p->right=NULL;
    free(p);
}

void delete_l(){
    p=list;
    if(p==NULL){
        printf("No Elements");
        return;
    }
    printf("%d Deleted from List",p->info);
    if(p->right==NULL){
        free(p);
        list=NULL;
        return;
    }
    while(p->right!=NULL){
        p=p->right;
    }
    p->left->right=NULL;
    free(p);
}

void delete_middle(){
    temp=p=list;
    int pos,i=0;
    if(p==NULL){
        printf("No Elements");
        return;
    }
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==0){
        delete_b();
        return;
    }
    while(i!=pos){
        p=p->right;
        if(p==NULL){
            printf("Cannot Delete");
            return;
        }
        i++;
    }
    if(p->right==NULL){
        delete_l();
        return;
    }
    printf("%d Deleted from List",p->info);
    p->left->right=p->right;
    p->right->left=p->left;
    p->right=NULL;
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
            p=p->right;
        }
    }
}
