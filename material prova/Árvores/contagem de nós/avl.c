#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No
{
    char dado[50];
    struct No *esquerda;
    struct No *direita;
    int altura;
} No;

// Função p calcular a altura de um no
int altura(No *no)
{
    if (no == NULL)
    {
        return 0;
    }
    return no->altura;
}

// Função p calcular o fator de balanceamento de um no
int fatorBalanceamento(No *no)
{
    if (no == NULL)
    {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

// Função p atualizar a altura de um nó
void atualizarAltura(No *no)
{
    if (no == NULL)
    {
        return;
    }
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    no->altura = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

// Função p criar um novo nó
No *criarNo(const char *dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->dado, dado);
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

// Função para fazer a rotação simples à esquerda
No *rotacaoEsquerda(No *y)
{
    No *x = y->direita;
    No *T2 = x->esquerda;

    x->esquerda = y;
    y->direita = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

// Função p fazer a rotação simples à direita
No *rotacaoDireita(No *x)
{
    No *y = x->esquerda;
    No *T2 = y->direita;

    y->direita = x;
    x->esquerda = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

// Função p inserir um nó na árvore AVL
No *inserirNo(No *raiz, const char *dado)
{
    if (raiz == NULL)
    {
        return criarNo(dado);
    }

    int compareResult = strcmp(dado, raiz->dado);
    if (compareResult < 0)
    {
        raiz->esquerda = inserirNo(raiz->esquerda, dado);
    }
    else if (compareResult > 0)
    {
        raiz->direita = inserirNo(raiz->direita, dado);
    }
    else
    {
        // Caso a chave já exista, não permita duplicatas
        return raiz;
    }

    // Atualizar altura do nó atual
    atualizarAltura(raiz);

    // Verificar o fator de balanceamento e fazer rotações
    int balanco = fatorBalanceamento(raiz);

    // Casos de rotação para balancear a árvore AVL
    if (balanco > 1 && compareResult < 0)
    {
        return rotacaoDireita(raiz);
    }
    if (balanco < -1 && compareResult > 0)
    {
        return rotacaoEsquerda(raiz);
    }
    if (balanco > 1 && compareResult > 0)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balanco < -1 && compareResult < 0)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função p contar os nós em um nível específico
int contarNosNoNivel(No *raiz, int nivelAlvo, int nivelAtual)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (nivelAtual == nivelAlvo)
    {
        return 1;
    }

    return contarNosNoNivel(raiz->esquerda, nivelAlvo, nivelAtual + 1) +
           contarNosNoNivel(raiz->direita, nivelAlvo, nivelAtual + 1);
}

int alturaArvore(No *raiz)
{
    if (raiz == NULL)
        return 0;

    return raiz->altura;
}

bool buscarNo(No *raiz, const char *alvo, char *caminho)
{
    if (raiz == NULL)
    {
        return false;
    }

    int resultadoComparacao = strcmp(alvo, raiz->dado);
    if (resultadoComparacao == 0)
    {
        strcat(caminho, raiz->dado);
        return true;
    }
    else if (resultadoComparacao < 0)
    {
        strcat(caminho, raiz->dado);
        strcat(caminho, " -> ");
        return buscarNo(raiz->esquerda, alvo, caminho);
    }
    else
    {
        strcat(caminho, raiz->dado);
        strcat(caminho, " -> ");
        return buscarNo(raiz->direita, alvo, caminho);
    }
}

int main(int argc, char const *argv[])
{
    No *raiz = NULL;
    raiz = inserirNo(raiz, "apple");
    raiz = inserirNo(raiz, "banana");
    raiz = inserirNo(raiz, "cherry");
    raiz = inserirNo(raiz, "date");
    raiz = inserirNo(raiz, "grape");
    raiz = inserirNo(raiz, "fig");

    int nivelAlvo = 2;
    int quantidade = contarNosNoNivel(raiz, nivelAlvo, 1);
    int altura = alturaArvore(raiz);

    printf("Numero de nos no nivel %d: %d\n", nivelAlvo, quantidade);
    printf("Altura da arvore: %d\n", altura);

    char *alvo = "cherry";
    char caminho[1000] = "";

    if (buscarNo(raiz, alvo, caminho))
    {
        printf("String '%s' encontrada na arvore AVL.\n", alvo);
        printf("Caminho ate a string: %s\n", caminho);
    }
    else
        printf("String '%s' nao encontrada na arvore AVL.\n", alvo);

    return 0;
}
