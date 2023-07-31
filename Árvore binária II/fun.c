#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Pilha *criar_pilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha *pilha, NoArvore *dado)
{
    NoPilha *novo_no = (NoPilha *)malloc(sizeof(NoPilha));
    novo_no->dado = dado;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

NoArvore *desempilhar(Pilha *pilha)
{
    if (pilha->topo == NULL)
        return NULL;

    NoArvore *dado = pilha->topo->dado;
    NoPilha *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);

    return dado;
}

NoArvore *topo(Pilha *pilha)
{
    return pilha->topo != NULL ? pilha->topo->dado : NULL;
}

bool vazia(Pilha *pilha)
{
    return pilha->topo == NULL;
}

void infixa_para_posfixa(char *infixa, char *posfixa)
{
    Pilha *pilha = criar_pilha();
    int i = 0, j = 0;

    while (infixa[i] != '\0')
    {
        char caractere_atual = infixa[i];

        if (caractere_atual == ' ')
        {
            i++;
            continue;
        }

        if (caractere_atual >= 'a' && caractere_atual <= 'z')
            posfixa[j++] = caractere_atual;

        else if (caractere_atual == '(')

            empilhar(pilha, criar_no(caractere_atual));

        else if (caractere_atual == ')')
        {
            while (!vazia(pilha) && topo(pilha)->dado != '(')
            {
                NoArvore *temp = desempilhar(pilha);
                posfixa[j++] = temp->dado;
                free(temp);
            }

            desempilhar(pilha);
        }
        else
        {
            while (!vazia(pilha) && prioridade(topo(pilha)->dado) >= prioridade(caractere_atual))
            {
                NoArvore *temp = desempilhar(pilha);
                posfixa[j++] = temp->dado;
                free(temp);
            }

            empilhar(pilha, criar_no(caractere_atual));
        }

        i++;
    }

    while (!vazia(pilha))
    {
        NoArvore *temp = desempilhar(pilha);
        posfixa[j++] = temp->dado;
        free(temp);
    }

    posfixa[j] = '\0';
}

NoArvore *criar_no(char dado)
{
    NoArvore *novo_no = (NoArvore *)malloc(sizeof(NoArvore));
    novo_no->dado = dado;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;

    return novo_no;
}

void inserir(Arvore *a, char dado)
{
    if (a->raiz == NULL)
        a->raiz = criar_no(dado);
    else
    {
        NoArvore *atual = a->raiz;
        while (true)
        {
            if (dado < atual->dado)
            {
                if (atual->esquerda == NULL)
                {
                    atual->esquerda = criar_no(dado);
                    break;
                }
                atual = atual->esquerda;
            }
            else if (dado > atual->dado)
            {
                if (atual->direita == NULL)
                {
                    atual->direita = criar_no(dado);
                    break;
                }
                atual = atual->direita;
            }
            else
                break;
        }
    }
}

NoArvore *construir_arvore(char *posfixa)
{
    Pilha *pilha = criar_pilha();
    int i = 0;

    while (posfixa[i] != '\0')
    {
        char caractere_atual = posfixa[i];

        NoArvore *novo_no = criar_no(caractere_atual);
        if (caractere_atual >= 'a' && caractere_atual <= 'z')
            empilhar(pilha, novo_no);

        else
        {
            novo_no->direita = desempilhar(pilha);
            novo_no->esquerda = desempilhar(pilha);
            empilhar(pilha, novo_no);
        }

        i++;
    }

    NoArvore *raiz = desempilhar(pilha);
    free(pilha);
    return raiz;
}

void liberar_arvore(NoArvore *no)
{
    if (no != NULL)
    {
        liberar_arvore(no->esquerda);
        liberar_arvore(no->direita);
        free(no);
    }
}

int avaliar(NoArvore *no)
{
    if (no->dado >= 'a' && no->dado <= 'z')
    {
        switch (no->dado)
        {
        case 'a':
            return 97; // Valor numérico de 'a'
        case 'b':
            return 98; // Valor numérico de 'b'
        case 'c':
            return 99; // Valor numérico de 'c'
        case 'd':
            return 100; // Valor numérico de 'd'
        default:
            return 0;
        }
    }

    int valor_esquerda = avaliar(no->esquerda);
    int valor_direita = avaliar(no->direita);

    switch (no->dado)
    {
    case '+':
        return valor_esquerda + valor_direita;
    case '-':
        return valor_esquerda - valor_direita;
    case '*':
        return valor_esquerda * valor_direita;
    case '/':
        return valor_esquerda / valor_direita;
    default:
        return 0;
    }
}

int prioridade(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

void inverter(char *str)
{
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim)
    {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inicio++;
        fim--;
    }
}

void infixa_para_prefixa(char *infixa, char *prefixa)
{
    char posfixa[100];
    infixa_para_posfixa(infixa, posfixa);

    inverter(posfixa);

    strcpy(prefixa, posfixa);
}
