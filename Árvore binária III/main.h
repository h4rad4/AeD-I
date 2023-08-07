#ifndef func_h
#define func_h

typedef struct aux{
    int num;
    struct aux* esquerda;
    struct aux* direita;
    int h;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializar(ARVORE *a);
int altura(NO *raiz);
int maximo(int v1, int v2);
NO* rot_direita(NO *raiz);
NO* rot_esquerda(NO *raiz);
NO* rot_esq_direita(NO *raiz);
NO* rot_dir_esquerda(NO *raiz);
NO* inserir_no(NO *raiz, NO *novo);
void adiciona_no(ARVORE *a, NO *novo);
void cria_no(ARVORE *a, int numero);
void print_pre_ordem(NO *raiz);
void print_in_ordem(NO *raiz);
void print_pos_ordem(NO *raiz);

#endif