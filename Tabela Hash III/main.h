#ifndef main_h
#define main_h

#define M 11

typedef struct Hash
{
    int key;

} Hash;

typedef Hash *TB_HASH[M];

void inicializaHash(TB_HASH tabela);
int sLinear(TB_HASH tabela, Hash elemento);
int sQuadratica1(TB_HASH tabela, Hash elemento);
int sQuadratica2(TB_HASH tabela, Hash elemento);
int hash01(TB_HASH tabela, Hash elemento);
int hash02(TB_HASH tabela, Hash elemento);
void imprimirTabela(TB_HASH tabela);

#endif
