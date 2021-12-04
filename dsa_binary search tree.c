//bst

#include <stdio.h>
#include <stdlib.h>

typedef struct binarynode{
    int data;
    struct binarynode *left;
    struct binarynode *right;
}bn;
bn *root = NULL;

bn *create(int x)
{
    bn *ptr = (bn *)malloc(sizeof(bn));
    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void printroot(bn * root)
{
    printf("%d",root->data);
    return;
}

void insert(int x)
{
    bn *temp = create(x);
    if(root == NULL)
    {
        root = temp;
        return;
    }
    bn *hlpptr = root;
    bn *parent = NULL;
    while(hlpptr != NULL)
    {
        parent = hlpptr;
        if(x<hlpptr->data)
        {
            hlpptr = hlpptr->left;
        }
        else if(x>hlpptr->data)
        {
            hlpptr = hlpptr->right;
        }
        else
        {
            printf("Element Already in the tree!\n");
            return;
        }
    }

    if(x>parent->data)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }
}

void inorder(bn *ptr)
{
    if(root == NULL)
    {
        printf("No element in the tree!\n");
    }
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d\n",ptr->data);
        inorder(ptr->right);
    }
}

void postorder(bn *ptr)
{
    if(root == NULL)
    {
        printf("No element in the tree!\n");
    }
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\n",ptr->data);

    }
}

void preorder(bn *ptr)
{
    if(root == NULL)
    {
        printf("No element in the tree!\n");
    }
    if(ptr!=NULL)
    {

        printf("%d\n",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}


void del(bn *node,int x)
{
    if(node == NULL)
    {
        printf("No element in the tree!\n");
        return;
    }

    //to delete. the root element
    if(node->left == NULL && node->right == NULL  && node->data == x)
    {
        root = NULL;
        free(node);
        return;
    }

    //to delete root node
    if(node->left == NULL && node->data == x)
    {
        root = node->right;
        free(node);
        return;
    }
    if(node->right == NULL && node->data == x)
    {
        root = node->left;
        free(node);
        return;
    }

    bn * hlpptr = node;
    bn *parent = NULL;
    while(hlpptr != NULL)
    {
        if(x<hlpptr->data)
        {
            parent = hlpptr;
            hlpptr = hlpptr->left;
        }
        else if(x>hlpptr->data)
        {
            parent = hlpptr;
            hlpptr = hlpptr->right;
        }
        else
        {
            break;
        }
    }

    if(hlpptr == NULL)
    {
        printf("Element not found!\n");
        return;
    }


    if(hlpptr->left==NULL && hlpptr->right == NULL)
    {
        if(parent->right == hlpptr)
        {
            parent->right = NULL;
        }
        else
        {
            parent->left = NULL;
        }
        free(hlpptr);
        return;
    }


    if(hlpptr->left==NULL && hlpptr->right != NULL)
    {
        if(parent->right == hlpptr)
        {
            parent->right = hlpptr->right;
        }
        else
        {
            parent->left = hlpptr->right;
        }
        free(hlpptr);
        return;
    }

    if(hlpptr->left != NULL && hlpptr->right == NULL)
    {
        if(parent->right == hlpptr)
        {
            parent->right = hlpptr->left;
        }
        else
        {
            parent->left = hlpptr->left;
        }
        free(hlpptr);
        return;
    }



    int temp;
    if(hlpptr->left!=NULL && hlpptr->right != NULL)
    {
        bn *pred = hlpptr->left;
        while(pred->right!=NULL)
        {
            pred = pred ->right;
        }
        temp = pred->data;
        del(hlpptr,pred->data);
        hlpptr->data=temp;
        return;
    }

}

void main()
{
    int ch,x,y;
    do
    {
        printf("\nEnter one of the following options: \n");
        printf("1-Insert | 2-Delete | 3-In Order Display | 4- Post Order Display |5-Pre Order Display | 6-Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            printf("Enter the number to insert : ");
            scanf("%d",&x);
            insert(x);
            break;
        }
        case 2:
        {
            printf("Enter the element to delete : ");
            scanf("%d",&y);
            del(root,y);
            break;
        }
        case 3:
        {
            printf("\n");
            inorder(root);
            break;
        }

        case 4:
        {
            printf("\n");
            postorder(root);
            break;
        }

        case 5:
        {
            printf("\n");
            preorder(root);
            break;
        }

        case 6:
            break;
        default:
            printf("Invalid choice");
        }
    }
    while(ch!=6);
}
