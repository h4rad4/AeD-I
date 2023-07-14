typedef struct AVIAO
{
    char nome[20];
    int codigo;

} AVIAO;

typedef struct NODE
{
    AVIAO aviao;
    struct NODE *proximo;

} NODE;

typedef struct HANGAR
{
    NODE *inicio;
    NODE *fim;
    int tamanho;

} HANGAR;

void imprimirAviao(HANGAR *hangar);
int inserirAviao(HANGAR *hangar, AVIAO novo_aviao);
void inicializarHangar(HANGAR *hangar);
void liberaAviao(HANGAR *hangar, int pos);
void pop(HANGAR *hangar);