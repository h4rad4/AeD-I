#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TreeNode
{
    char data[20];
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

struct BinaryTree
{
    TreeNode *root;
};

typedef struct BinaryTree BinaryTree;

TreeNode *createNode(char *data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TreeNode **root, char *data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }

    if ((*root)->left == NULL)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}

void inorderTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        inorderTraversal(node->left);
        printf("%s ", node->data);
        inorderTraversal(node->right);
    }
}

void postfixTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        postfixTraversal(node->left);
        postfixTraversal(node->right);
        printf("%s ", node->data);
    }
}

void prefixTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        printf("%s ", node->data);
        prefixTraversal(node->left);
        prefixTraversal(node->right);
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main()
{
    BinaryTree tree;
    tree.root = NULL;

    char expression[] = "(a*((b-c)/d))";
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isalnum(expression[i]))
        {
            char data[2] = {expression[i], '\0'};
            insert(&(tree.root), data);
        }
        else if (isOperator(expression[i]))
        {
            char data[2] = {expression[i], '\0'};
            insert(&(tree.root), data);
        }
    }

    printf("Infix Expression: ");
    inorderTraversal(tree.root);
    printf("\n");

    printf("Postfix Expression: ");
    postfixTraversal(tree.root);
    printf("\n");

    printf("Prefix Expression: ");
    prefixTraversal(tree.root);
    printf("\n");

    return 0;
}
