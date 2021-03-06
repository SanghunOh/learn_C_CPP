#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
	int data;
	struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val){
    node *temp = NULL;
    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data){
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree){
    if (tree){
        printf("%d\t",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree){
    if (tree){
        print_inorder(tree->left);
        printf("%d\t",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree){
    if (tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\t",tree->data);
    }
}

void deltree(node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val){
    if(!(*tree)){
        return NULL;
    }

    if(val < (*tree)->data){
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data){
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data){
        return *tree;
    }
	return NULL;
}

int main(){
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    printf("InPut Number 9, 4, 15, 6, 12, 17, 2\n");
    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("\nIn Order Display\n");
    print_inorder(root);

    printf("\nPost Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp){
        printf("\nSearched node=%d\n", tmp->data);
    }
    else{
        printf("\nData Not found in tree.\n");
    }

    /* Deleting all nodes of tree */
    deltree(root);
    
    return 0;
}
