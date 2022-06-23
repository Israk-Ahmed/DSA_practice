// Traversing a tree in pre-order,in-order,post-order


#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void insert(int data){
    struct node* temp, *parent;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    parent = root;

    if(root == NULL){
        root = temp;
        //printf("root here : %d\n",root->data);
    }
    else{
        struct node* currentNode;
        currentNode = root;

        while(currentNode){
            parent = currentNode;

            if(temp->data > currentNode->data){
                currentNode = currentNode->right;
            }
            else{
                currentNode = currentNode->left;
            }

        }

        if(temp->data > parent->data){
            parent->right = temp;
            //printf("right here : %d\n",parent->right->data);
        }
        else{
            parent->left = temp;
            //printf("left here : %d\n",parent->left->data);
        }
    }
}

void traverseInorder(struct node* node)
{
    if (node == NULL)
        return;

    traverseInorder(node->left);

    printf("%d ", node->data);

    traverseInorder(node->right);
}

void main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    printf("Traversing In-Order : ");
    traverseInorder(root);
    printf("\n");
}