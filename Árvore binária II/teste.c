#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do nó da árvore binária
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Definição da árvore binária
typedef struct BinaryTree
{
    TreeNode *root;
} BinaryTree;

// Função auxiliar para criar um novo nó na árvore
TreeNode *create_node(char data)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para inserir um nó na árvore binária
void insert(BinaryTree *tree, char data)
{
    if (tree->root == NULL)
    {
        tree->root = create_node(data);
    }
    else
    {
        TreeNode *current = tree->root;
        while (true)
        {
            if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = create_node(data);
                    break;
                }
                current = current->left;
            }
            else if (data > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = create_node(data);
                    break;
                }
                current = current->right;
            }
            else
            {
                // Ignorar elementos duplicados (opcional)
                break;
            }
        }
    }
}

// Função auxiliar para liberar a memória da árvore binária
void free_tree(TreeNode *node)
{
    if (node != NULL)
    {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

// Função para imprimir a expressão em notação infixa
void print_infix(TreeNode *node)
{
    if (node != NULL)
    {
        if (node->left != NULL || node->right != NULL)
        {
            printf("(");
        }
        print_infix(node->left);
        printf("%c", node->data);
        print_infix(node->right);
        if (node->left != NULL || node->right != NULL)
        {
            printf(")");
        }
    }
}

// Função para imprimir a expressão em notação posfixa
void print_postfix(TreeNode *node)
{
    if (node != NULL)
    {
        print_postfix(node->left);
        print_postfix(node->right);
        printf("%c", node->data);
    }
}

// Função para imprimir a expressão em notação prefixa
void print_prefix(TreeNode *node)
{
    if (node != NULL)
    {
        printf("%c", node->data);
        print_prefix(node->left);
        print_prefix(node->right);
    }
}

// Função para calcular o valor da expressão aritmética representada pela árvore
int evaluate_expression_tree(TreeNode *node)
{
    if (node->data >= 'a' && node->data <= 'z')
    {
        return node->data;
    }

    int left_value = evaluate_expression_tree(node->left);
    int right_value = evaluate_expression_tree(node->right);
    
    switch (node->data)
    {
    case '+':
        return left_value + right_value;
    case '-':
        return left_value - right_value;
    case '*':
        return left_value * right_value;
    case '/':
        return left_value / right_value;
    default:
        return 0; // Operador inválido (opcional, dependendo dos requisitos)
    }
}

int main()
{
    BinaryTree tree = {.root = NULL};
    char expression[] = "a*((b-c)/d)";

    // Inserir cada elemento da expressão na árvore binária
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] != ' ')
        {
            insert(&tree, expression[i]);
        }
    }

    printf("Expressão em Notação Infixa: ");
    print_infix(tree.root);
    printf("\n");

    printf("Expressão em Notação Posfixa: ");
    print_postfix(tree.root);
    printf("\n");

    printf("Expressão em Notação Prefixa: ");
    print_prefix(tree.root);
    printf("\n");

    int result = evaluate_expression_tree(tree.root);
    printf("Resultado da Expressão: %d\n", result);

    // Liberar a memória alocada pela árvore binária
    free_tree(tree.root);

    return 0;
}
