#include<stdio.h>
struct node{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node *NODEPTR;

void inorder(NODEPTR);
NODEPTR maketree(int);
void setleft(NODEPTR,int);
void setright(NODEPTR,int);
NODEPTR getnode();

void main(){
    NODEPTR root,p,q;
    int number;
    scanf("%d",&number);
    root=maketree(number);
    while(scanf("%d",&number)!=EOF){
        p=q=root;
        while(number!=p->info && q!=NULL){
            p=q;
            if(number<p->info)
                q=p->left;
            else
                q=p->right;
        }
        if(number==p->info)
            printf("%d is duplicate\n",number);
        else if(number<p->info)
            setleft(p,number);
        else
            setright(p,number);
    }
    inorder(root);
}

NODEPTR getnode(){
    return ((struct node*)malloc(sizeof(struct node)));
}

void inorder(NODEPTR p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->info);
        inorder(p->right);
    }
}

NODEPTR maketree(int x){
    NODEPTR p;
    p=getnode();
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    return (p);
}

void setleft(NODEPTR p,int x){
    if(p==NULL)
        printf("Cannot Insert\n");
    else if(p->left!=NULL)
        printf("Invalid Insertion\n");
    else
        p->left=maketree(x);
}

void setright(NODEPTR p,int x){
    if(p==NULL)
        printf("Cannot Insert\n");
    else if(p->right!=NULL)
        printf("Invalid Insertion\n");
    else
        p->right=maketree(x);
}
