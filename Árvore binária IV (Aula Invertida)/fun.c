#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Arvore *criar_no(int ultimo)
{
    Arvore *novoNo = (Arvore *)malloc(sizeof(Arvore));
    novoNo->valor = (int *)malloc(sizeof(int) * (ordem - 1));
    novoNo->ramo = (Arvore **)malloc(sizeof(Arvore *) * ordem);
    novoNo->quantidade = 0;
    novoNo->ultimo = ultimo;
    return novoNo;
}

// Função para ligar folhas consecutivas
void ligar_folhas(Arvore *folha_atual, Arvore *proximo)
{
    while (folha_atual->proxima_folha != NULL)
    {
        folha_atual = folha_atual->proxima_folha;
    }
    folha_atual->proxima_folha = proximo;
}

// Função para encontrar o índice onde um valor deve ser inserido
int indice(Arvore *no, int key)
{
    int index = 0;
    while (index < no->quantidade && key > no->valor[index])
    {
        index++;
    }
    return index;
}

// Função para dividir um nó quando está cheio
void split(Arvore *pai, int filho_index)
{
    // Obtém o filho que será dividido
    Arvore *filho = pai->ramo[filho_index];

    // Cria um novo nó para ser o novo filho
    Arvore *newfilho = criar_no(filho->ultimo);
    newfilho->quantidade = ordem / 2 - 1;

    // Move metade dos valores do filho original para o novo filho
    for (int i = 0; i < newfilho->quantidade; i++)
    {
        newfilho->valor[i] = filho->valor[i + ordem / 2];
    }

    // Se o filho original não for uma folha, move metade dos ramos para o novo filho
    if (!filho->ultimo)
    {
        for (int i = 0; i < ordem / 2; i++)
            newfilho->ramo[i] = filho->ramo[i + ordem / 2];
    }

    // Atualiza a quantidade de valores no filho original
    filho->quantidade = ordem / 2 - 1;

    // Move os ramos no nó pai para abrir espaço para o novo filho
    for (int i = pai->quantidade; i >= filho_index + 1; i--)
        pai->ramo[i + 1] = pai->ramo[i];

    // Insere o novo filho no nó pai
    pai->ramo[filho_index + 1] = newfilho;

    // Move os valores no nó pai para abrir espaço para o valor do novo filho
    for (int i = pai->quantidade - 1; i >= filho_index; i--)
        pai->valor[i + 1] = pai->valor[i];

    // Insere o valor mediano do filho original no nó pai
    pai->valor[filho_index] = filho->valor[ordem / 2 - 1];
    pai->quantidade++; // Incrementa a quantidade de valores no nó pai
}

// Função para inserir um valor em um nó que não está cheio
void inserir_vago(Arvore *no, int key)
{
    int index = no->quantidade - 1;

    // Verifica se o nó é uma folha
    if (no->ultimo)
    {
        // Encontra a posição correta para inserir a chave no nó folha
        while (index >= 0 && key < no->valor[index])
        {
            no->valor[index + 1] = no->valor[index]; // Move os valores maiores para a direita
            index--;
        }

        no->valor[index + 1] = key; // Insere a chave na posição correta
        no->quantidade++;           // Incrementa a quantidade de chaves no nó
    }
    else
    {
        // Encontra o filho correto para continuar a inserção
        while (index >= 0 && key < no->valor[index])
            index--;

        index++; // Incrementa o índice para obter o filho certo

        // Verifica se o filho está cheio
        if (no->ramo[index]->quantidade == ordem - 1)
        {
            // Realiza a divisão do filho para acomodar a nova chave
            split(no, index);

            // Atualiza o índice se a chave for maior do que a chave recém-inserida no nó pai
            if (key > no->valor[index])
                index++;
        }

        // Se o nó atual for uma folha, liga as folhas adjacentes
        if (no->ultimo)
            ligar_folhas(no->ramo[index], no->ramo[index + 1]);

        // Chama recursivamente a função para continuar a inserção no filho apropriado
        inserir_vago(no->ramo[index], key);
    }
}

// Função para inserir um valor na árvore B
void inserir(Arvore **raiz, int key)
{
    Arvore *rootNode = *raiz;

    // Verifica se a raiz da árvore está vazia
    if (rootNode == NULL)
    {
        // Cria um novo nó raiz
        *raiz = criar_no(1);
        (*raiz)->valor[0] = key;
        (*raiz)->quantidade = 1;
    }
    else
    {
        // Verifica se o nó raiz está cheio
        if (rootNode->quantidade == ordem - 1)
        {
            // Cria um novo nó raiz e coloca o nó atual como seu primeiro filho
            Arvore *novaRaiz = criar_no(0);
            novaRaiz->ramo[0] = rootNode;
            *raiz = novaRaiz;
        }
        // Insere a chave no nó existente (ou no novo nó raiz criado)
        inserir_vago(rootNode, key);
    }
}

// Função para imprimir todos os valores da árvore em ordem
void imprimirArvore(Arvore *no)
{
    if (no != NULL)
    {
        int i;
        for (i = 0; i < no->quantidade; i++)
        {
            if (!no->ultimo)
                imprimirArvore(no->ramo[i]);
            printf("%d ", no->valor[i]);
        }
        if (!no->ultimo)
            imprimirArvore(no->ramo[i]);
    }
}

// Funções para encontrar o maior e o menor valor na árvore
int maior_elemento(Arvore *no)
{
    while (!no->ultimo)
        no = no->ramo[no->quantidade];

    return no->valor[no->quantidade - 1];
}

int menor_elemento(Arvore *no)
{
    while (!no->ultimo)
        no = no->ramo[0];

    return no->valor[0];
}

// Funções para operações de fusão e redistribuição
void junta_ramos(Arvore *pai, int filho_index)
{
    // Obtém os filhos que serão combinados
    Arvore *leftfilho = pai->ramo[filho_index];
    Arvore *rightfilho = pai->ramo[filho_index + 1];

    // Move o valor do nó pai para o final do filho esquerdo
    leftfilho->valor[leftfilho->quantidade] = pai->valor[filho_index];
    leftfilho->quantidade++;

    // Move os valores do filho direito para o filho esquerdo
    for (int i = 0; i < rightfilho->quantidade; i++)
        leftfilho->valor[leftfilho->quantidade + i] = rightfilho->valor[i];

    // Se o filho esquerdo não for uma folha, move os ramos do filho direito para o filho esquerdo
    if (!leftfilho->ultimo)
    {
        for (int i = 0; i <= rightfilho->quantidade; i++)
            leftfilho->ramo[leftfilho->quantidade + i] = rightfilho->ramo[i];
    }

    // Move os valores e ramos no nó pai para preencher o espaço vazio deixado pelo filho direito
    for (int i = filho_index; i < pai->quantidade - 1; i++)
    {
        pai->valor[i] = pai->valor[i + 1];
        pai->ramo[i + 1] = pai->ramo[i + 2];
    }

    // Atualiza a quantidade de valores no nó pai
    pai->quantidade--;

    // Libera a memória do filho direito
    free(rightfilho);
}

void mover_da_direita(Arvore *pai, int filho_index)
{
    // Obtém o filho e o filho da direita do nó pai
    Arvore *filho = pai->ramo[filho_index];
    Arvore *filhoDireito = pai->ramo[filho_index + 1];

    // Move o valor do nó pai para o último índice do filho
    filho->valor[filho->quantidade] = pai->valor[filho_index];
    filho->quantidade++;

    // Substitui o valor no nó pai pelo primeiro valor do filho da direita
    pai->valor[filho_index] = filhoDireito->valor[0];

    // Se o filho não for uma folha, ajusta os ramos do filho
    if (!filho->ultimo)
        filho->ramo[filho->quantidade] = filhoDireito->ramo[0];

    // Move os valores e ramos no filho da direita para a esquerda
    for (int i = 0; i < filhoDireito->quantidade - 1; i++)
    {
        filhoDireito->valor[i] = filhoDireito->valor[i + 1];
        filhoDireito->ramo[i] = filhoDireito->ramo[i + 1];
    }

    // Se o filho da direita não for uma folha, ajusta o último ramo
    if (!filhoDireito->ultimo)
        filhoDireito->ramo[filhoDireito->quantidade - 1] = filhoDireito->ramo[filhoDireito->quantidade];

    // Ajusta as quantidades de valores nos filhos
    filho->quantidade++;
    filhoDireito->quantidade--;
}

void mover_da_esquerda(Arvore *pai, int filho_index)
{
    // Obtém o filho e o filho da esquerda do nó pai
    Arvore *filho = pai->ramo[filho_index];
    Arvore *filhoEsquerdo = pai->ramo[filho_index - 1];

    // Move os valores no filho para a direita
    for (int i = filho->quantidade; i > 0; i--)
    {
        filho->valor[i] = filho->valor[i - 1];
        filho->ramo[i + 1] = filho->ramo[i];
    }

    // Substitui o primeiro valor no filho pelo último valor do filho da esquerda
    filho->valor[0] = filhoEsquerdo->valor[filhoEsquerdo->quantidade - 1];

    // Se o filho não for uma folha, ajusta o primeiro ramo
    if (!filho->ultimo)
        filho->ramo[0] = filhoEsquerdo->ramo[filhoEsquerdo->quantidade];


    // Decrementa a quantidade de valores no filho da esquerda
    filhoEsquerdo->quantidade--;

    // Incrementa a quantidade de valores no filho
    filho->quantidade++;
}

// Função para excluir um valor da árvore
void exclui_elemento(Arvore *no, int key)
{
    // Encontra o índice onde a chave deve estar no nó atual
    int index = indice(no, key);

    // Verifica se o nó é uma folha
    if (no->ultimo)
    {
        // Remove o valor do nó
        for (int i = index; i < no->quantidade - 1; i++)
        {
            no->valor[i] = no->valor[i + 1];
        }
        no->quantidade--;
    }
    else
    {
        // Obtém os filhos do nó
        Arvore *leftfilho = no->ramo[index];
        Arvore *rightfilho = no->ramo[index + 1];

        // Verifica se o filho esquerdo tem pelo menos metade dos valores necessários
        if (leftfilho->quantidade >= ordem / 2)
        {
            // Encontra o predecessor do valor a ser excluído no filho esquerdo
            int predecessorKey = maior_elemento(leftfilho);
            // Substitui o valor a ser excluído pelo predecessor
            no->valor[index] = predecessorKey;
            // Chama recursivamente a exclusão do predecessor
            exclui_elemento(leftfilho, predecessorKey);
        }
        // Verifica se o filho direito tem pelo menos metade dos valores necessários
        else if (rightfilho->quantidade >= ordem / 2)
        {
            // Encontra o sucessor do valor a ser excluído no filho direito
            int successorKey = menor_elemento(rightfilho);
            // Substitui o valor a ser excluído pelo sucessor
            no->valor[index] = successorKey;
            // Chama recursivamente a exclusão do sucessor
            exclui_elemento(rightfilho, successorKey);
        }
        else
        {
            // Caso contrário, junta os filhos e continua a exclusão
            junta_ramos(no, index);
            exclui_elemento(leftfilho, key);
        }
    }
}

void excluir(Arvore **raiz, int key)
{
    // Verifica se a árvore está vazia
    if (*raiz == NULL)
    {
        printf("A chave %d não está presente na árvore.\n", key);
        return;
    }

    // Obtém a raiz da árvore
    Arvore *rootNode = *raiz;
    // Encontra o índice onde a chave deve estar na raiz
    int index = indice(rootNode, key);

    // Verifica se a chave está presente na raiz
    if (index < rootNode->quantidade && key == rootNode->valor[index])
    {
        // Verifica se a raiz é uma folha
        if (rootNode->ultimo)
        {
            // Remove o valor da raiz
            for (int i = index; i < rootNode->quantidade - 1; i++)
            {
                rootNode->valor[i] = rootNode->valor[i + 1];
            }
            rootNode->quantidade--;
        }
        else
        {
            // Obtém os filhos da raiz
            Arvore *leftfilho = rootNode->ramo[index];
            Arvore *rightfilho = rootNode->ramo[index + 1];

            // Verifica se o filho esquerdo tem pelo menos metade dos valores necessários
            if (leftfilho->quantidade >= ordem / 2)
            {
                // Encontra o predecessor do valor a ser excluído no filho esquerdo
                int predecessorKey = maior_elemento(leftfilho);
                // Substitui o valor a ser excluído pelo predecessor
                rootNode->valor[index] = predecessorKey;
                // Chama recursivamente a exclusão do predecessor
                exclui_elemento(leftfilho, predecessorKey);
            }
            // Verifica se o filho direito tem pelo menos metade dos valores necessários
            else if (rightfilho->quantidade >= ordem / 2)
            {
                // Encontra o sucessor do valor a ser excluído no filho direito
                int successorKey = menor_elemento(rightfilho);
                // Substitui o valor a ser excluído pelo sucessor
                rootNode->valor[index] = successorKey;
                // Chama recursivamente a exclusão do sucessor
                exclui_elemento(rightfilho, successorKey);
            }
            else
            {
                // Caso contrário, junta os filhos e continua a exclusão
                junta_ramos(rootNode, index);
                exclui_elemento(rootNode->ramo[index], key);
            }
        }
    }
    else
    {
        // Se a chave não está na raiz
        if (rootNode->ultimo)
        {
            // Mensagem de chave não encontrada
            printf("A chave %d não está presente na árvore.\n", key);
            return;
        }
        // Obtém o nó filho onde a chave deve estar
        Arvore *filhoNode = rootNode->ramo[index];
        // Verifica se o nó filho tem pelo menos metade dos valores necessários
        if (filhoNode->quantidade >= ordem / 2)
        {
            // Chama recursivamente a exclusão no nó filho
            exclui_elemento(filhoNode, key);
        }
        else
        {
            // Verifica se é possível mover um valor da esquerda
            if (index > 0 && rootNode->ramo[index - 1]->quantidade >= ordem / 2)
            {
                // Move um valor do nó pai para o nó filho
                mover_da_direita(rootNode, index);
            }
            // Verifica se é possível mover um valor da direita
            else if (index < rootNode->quantidade && rootNode->ramo[index + 1]->quantidade >= ordem / 2)
            {
                // Move um valor do nó pai para o nó filho
                mover_da_esquerda(rootNode, index);
            }
            else
            {
                // Caso contrário, junta os filhos e continua a exclusão
                junta_ramos(rootNode, index);
                filhoNode = rootNode->ramo[index];
                exclui_elemento(filhoNode, key);
            }
        }
    }

    // Verifica se a raiz ficou vazia e não é uma folha
    if (rootNode->quantidade == 0 && !rootNode->ultimo)
    {
        // Define a nova raiz como o primeiro filho da raiz anterior
        Arvore *novaRaiz = rootNode->ramo[0];
        // Libera a memória da raiz anterior
        free(rootNode);
        // Atualiza o ponteiro da raiz
        *raiz = novaRaiz;
    }
}

// Função para imprimir apenas as folhas da árvore
void imprimirFolhas(Arvore *no)
{
    if (no != NULL)
    {
        if (no->ultimo)
        { // Se for uma folha
            for (int i = 0; i < no->quantidade; i++)
                printf("%d ", no->valor[i]);
        }
        else
        {
            for (int i = 0; i <= no->quantidade; i++)
                imprimirFolhas(no->ramo[i]); // Chamada recursiva para os filhos
        }
    }
}

// Função para buscar um valor na árvore
int buscar(Arvore *no, int key)
{
    int index = 0;
    while (index < no->quantidade && key > no->valor[index])
        index++;


    if (index < no->quantidade && key == no->valor[index])
        return 1;


    if (no->ultimo)
        return 0;


    return buscar(no->ramo[index], key);
}
