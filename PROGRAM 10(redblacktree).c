#include<stdio.h>
#include<stdlib.h>

struct rbtNode{ 
    int key;
    char color;
    struct rbtNode *left, *right,*parent;
}; 

struct rbtNode* root = NULL;

void leftRotate(struct rbtNode *x){ 
    struct rbtNode *y;
    y = x->right; x->right = y->left;
    if( y->left != NULL)
    { 
        y->left->parent = x;
    }
    y->parent = x->parent;
    if( x->parent == NULL){ 
        root = y;
    }
    else if((x->parent->left!=NULL) && (x->key == x->parent->left->key))
    { 
        x->parent->left = y;
    }
    else x->parent->right = y;
    y->left = x; x->parent = y; return;
}

void rightRotate(struct rbtNode *y){ 
    struct rbtNode *x;
    x = y->left; 
    y->left = x->right;
    if ( x->right != NULL)
    { 
        x->right->parent = y;   
    }
    x->parent = y->parent;
    if( y->parent == NULL)
    { 
        root = x;
    }
    else if((y->parent->left!=NULL)&& (y->key == y->parent->left->key))
    { 
        y->parent->left = x;
    }   
    else
    y->parent->right = x;
    x->right = y; y->parent = x;
    return;
}
void colorinsert(struct rbtNode *z){ 
    struct rbtNode *y=NULL;
    while ((z->parent != NULL) && (z->parent->color == 'r'))
    {
        if ((z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key))
        { 
            if(z->parent->parent->right!=NULL)
                y = z->parent->parent->right;
            if ((y!=NULL) && (y->color == 'r'))
            { 
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->right != NULL) && (z->key == z->parent->right->key))
                { 
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            if(z->parent->parent->left!=NULL)
                y = z->parent->parent->left;
            if ((y!=NULL) && (y->color == 'r'))
            { 
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->left != NULL) && (z->key == z->parent->left->key))
                { 
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(z->parent->parent);
            }
        }
    } 
    root->color = 'b';
}

void inorderTree(struct rbtNode* root){ 
    struct rbtNode* temp = root;
    if (temp != NULL)
    { 
        inorderTree(temp->left);
        printf(" %d-%c ",temp->key,temp->color);
        inorderTree(temp->right);
    }
    return;
}

void postorderTree(struct rbtNode* root){ 
    struct rbtNode* temp = root;
    if (temp != NULL)
    { 
        postorderTree(temp->left);
        postorderTree(temp->right);
        printf(" %d-%c ",temp->key,temp->color);
    }
    return;
}

void traversal(struct rbtNode* root){ 
    if (root != NULL)
    { 
        printf("root is %d- %c",root->key,root->color);
        printf("\nInorder tree traversal\n");
        inorderTree(root);
        printf("\npostorder tree traversal\n");
        postorderTree(root);
    }
    return;
}

int search(int val){ 
    struct rbtNode* temp = root;
    int diff;
    while (temp != NULL)
    { 
        diff = val - temp->key;
        if (diff > 0)
        { 
            temp = temp->right;
        }
        else if (diff < 0)
        { 
            temp = temp->left;
        }
        else
        { 
            printf("Search Element Found!!\n");
            return 1;
        }
    } 
     return 0;
}
void insert(int val){ 
    struct rbtNode *x, *y;
    struct rbtNode *z = (struct rbtNode*)malloc(sizeof(struct rbtNode));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    z->color = 'r';
    x=root;
    if(search(val)==1)
    { 
        printf("\nEntered element already exists in the tree\n");
        return;
    }
    if ( root == NULL )
    { 
        root = z;
        root->color = 'b';
        return;
    }
    while ( x != NULL)
    { 
        y = x;
        if ( z->key < x->key)
        { 
            x = x->left;
        }
        else 
            x = x->right;
    }
    z->parent = y;
    if ( y == NULL)
    { 
        root = z;
    }
    else if( z->key < y->key )
    { 
        y->left = z;
    }
    else{
        y->right = z;
    } 

    colorinsert(z);
    return;
}

struct rbtNode* min(struct rbtNode *x){ 
    while (x->left)
    { 
        x = x->left;
    } 
    return x;
}

struct rbtNode* successor(struct rbtNode *x){ 
    struct rbtNode *y=NULL;
     if(x->left!=NULL)
     {
         y=x->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else
     {
         y=x->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
}

void colordelete(struct rbtNode *x){ 
    while (x != root && x->color == 'b')
    { 
        struct rbtNode *w = NULL;
        if ((x->parent->left!=NULL) && (x == x->parent->left))
        { 
            w = x->parent->right;
            if ((w!=NULL) && (w->color == 'r'))
            { 
                w->color = 'b';
                x->parent->color = 'r';
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->color == 'b') && (w->right->color == 'b'))
            {
                w->color = 'r';
                x = x->parent;
            }
            else if((w!=NULL) && (w->right->color == 'b'))
            { 
                w->left->color = 'b';
                w->color = 'r';
                rightRotate(w);
                w = x->parent->right;
            }
            if(w!=NULL)
            { 
                w->color = x->parent->color;
                x->parent->color = 'b';
                w->right->color = 'b';
                leftRotate(x->parent);
                x = root;
            }
        }
        else if(x->parent!=NULL)
        { 
            w = x->parent->left;
            if ((w!=NULL) && (w->color == 'r'))
            {
                w->color = 'b';
                x->parent->color = 'r';
                leftRotate(x->parent);
                if(x->parent!=NULL){
                    w = x->parent->left;
                }
            }
            if ((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->right->color == 'b') && (w->left->color == 'b'))
            {
                x = x->parent;
            }
            else if((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->color == 'b'))
            {
                w->right->color = 'b';
                w->color = 'r';
                rightRotate(w);
                w = x->parent->left;
            }
            if(x->parent!=NULL)
            { 
                w->color = x->parent->color;
                x->parent->color = 'b';
            }
            if(w->left!=NULL)
                w->left->color = 'b';
            if(x->parent !=NULL){
                leftRotate(x->parent);
            }
            x = root;
        }
    }
    x->color = 'b';
}

struct rbtNode* deleteNode(int var){ 
    struct rbtNode *x = NULL, *y = NULL, *z;
    z=root;

    if((z->left ==NULL ) &&(z->right==NULL) && (z->key==var))
    { 
        root=NULL;
        printf("\nRBTREE is empty\n");
        return 0;
    }
    while(z->key !=var && z!=NULL)
    { 
        if(var < z->key){
            z=z->left;
        }
        else{
            z=z->right;
        }
        if(z== NULL)
            return 0;
    }
    if((z->left==NULL)||(z->right==NULL))
    { 
        y = z;
    }
    else
    { 
        y = successor(z);
    }
    if (y->left!=NULL)
    { 
        x = y->left;
    }
    else
    { 
        if(y->right !=NULL)
            x = y->right;
    }
    if((x!=NULL) && (y->parent !=NULL))
        x->parent = y->parent;
    if ((y !=NULL) && (x!=NULL) && (y->parent==NULL))
    { 
        root=x; 
    }
    else if (y == y->parent->left)
    { 
        y->parent->left = x;
    }
    else
    { 
        y->parent->right = x;
    }
    if (y != z)
    { 
        z->key = y->key;
    }
    if ((y!=NULL) && (x!=NULL) && (y->color == 'b'))
    { 
        colordelete(x);
    }
    return y;
}

void printTree(struct rbtNode *root, int space) 
{ 
    if (root == NULL) 
    {
        return;
    }

    else
    {
        space += 8; 
    printTree(root->right, space); 
    printf("\n"); 
    for (int i = 8; i < space; i++) 
        printf(" "); 
    printf("%d(%c)", root->key,root->color); 
    printTree(root->left, space);
    }
} 

void print(struct rbtNode *root) 
{ 
if(root==NULL)
{
    printf("No Data");
}
else
{
    printTree(root, 0); 
}
}
int main(){
    int choice,val,data,var,fl=0;
    while(1)
    { 
        system("cls");
        print(root);
        printf("\nRed Black Tree Menu - \nEnter your choice :\n1:Insert \n2:Delete \n3:Search \n4:Traversal \n5:Exit\n");
        scanf("%d",&choice);fflush(stdin);
        switch(choice)
        { 
            case 1:
                printf("Enter the integer you want to add : ");
                scanf("%d",&val);fflush(stdin);
                insert(val);
            break;
            case 2:
                printf("Enter the integer you want to delete : ");
                scanf("%d",&val);fflush(stdin);
                deleteNode(val);
            break;
            case 3:
                printf("Enter search element \n");
                scanf("%d",&val);fflush(stdin);
                search(val);
            break;
            case 4:
                traversal(root);
                getchar();
            break;
            case 5:
                fl=1;
            break;
            default:
                printf("\nInvalid Choice\n");
        }
        if(fl==1){ 
            break;}
        }
    return 0;
}
