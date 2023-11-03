#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* lnode, *rnode;  
}node;

node* newnode_func(int x)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->lnode=NULL;
    newnode->rnode=NULL;

    return newnode;
}

node* insert(node* root,int k)
{
    if(root==NULL)
        return newnode_func(k);
    else if(k<root->data)
        root->lnode=insert(root->lnode,k);
    else if(k>root->data)
        root->rnode=insert(root->rnode,k);
}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->lnode);
        printf("%d , ",root->data);
        inorder(root->rnode);
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%d , ",root->data);
        inorder(root->lnode);
        inorder(root->rnode);
    }
}

void postorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->lnode);
        inorder(root->rnode);
        printf("%d , ",root->data);
    }
}

node* search_bst(node* root,int key)
{
    if(root == NULL || root->data ==key)
        return root;
    else if(key<root->data)
        return search_bst(root->lnode,key);
    else
        return search_bst(root->rnode,key);
}

node* smallest(node* root)
{
    if(root==NULL || root->lnode == NULL)
        return root;
    else
        return smallest(root->lnode);
}

node* largest(node* root)
{
    if(root==NULL || root->rnode == NULL)
        return root;
    else
        return largest(root->rnode);
}

int height(node* root)
{
    if(root==NULL)
        return -1;
    else
    {
        int left=height(root->lnode);
        int right=height(root->rnode);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
}

int main()
{
    int sel,n,h;

    node *root=NULL;
    node * temp=NULL;
    //head= (struct node*)malloc(sizeof(struct node));
    //printf("%p\n",head);

    printf("\t1.Create Node\n\t2.Pre-order traversal\n\t3.In-order traversal\n\t4.Post-order traversal\n\t5.Search number\n"
            "\t6.Smallest number\n\t7.largest number\n\t8.height of bst\n");

    printf("enter your selection ( enter -1 to exit ) : ");
    scanf("%d",&sel);

    while(sel != -1)
    {
        
        switch(sel)
        {


            case 1:
                printf("Enter new number to add into bst : ");
                scanf("%d",&n);
                root=insert(root,n);
                break;
            
            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                printf("Enter key to search in bst : ");
                scanf("%d",&n);
                temp=search_bst( root, n);
                
                if(temp==NULL)
                    printf("%d not found in BST.\n",n);
                else
                    printf("%d found in BST.\n",n);

                break;

            case 6:
                temp=smallest( root);

                if(temp==NULL)
                    printf(" BST is empty !\n");
                else
                    printf("Smallest number : %d\n",temp->data);                
                break;

            case 7:
                temp=largest( root);

                if(temp==NULL)
                    printf(" BST is empty !\n");
                else
                    printf("Largest number : %d\n",temp->data); 
                break;

            case 8:
                h=height( root);
                if(h==-1)
                    printf(" BST is empty !\n");
                else
                    printf("Height of BST : %d\n",h); 
                break;


            default:
                printf("selection not in range !!!\n");

        }
        printf("Successfully completed operation %d\n\n",sel);
        printf("Enter your selection ( enter -1 to exit ) : ");
        scanf("%d",&sel);
    }
    
    return 0;
}