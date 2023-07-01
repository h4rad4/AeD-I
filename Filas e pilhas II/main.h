typedef struct
{
    char expressao[200];
    int tamanho;
} Expressao;

/* Função que cria e retorna uma expressão vazia */
Expressao criar_expressao();

/* Função que apaga o conteúdo de uma expressão, deixando-a vazia */
void apagar_expressao(Expressao *expressao);

/* Função que imprime o conteúdo de uma expressão */
void imprimir_expressao(const Expressao *expressao);

/* Função que adiciona um elemento (número ou operador) a uma expressão existente */
void adicionar_elemento(Expressao *expressao, const char *elemento);

/* Função que avalia o resultado de uma expressão matemática */
float resultado_expressao(const Expressao *expressao);

/* Função que verifica se um caractere é um operador matemático */
int isOperador(char c);

/* Função que retorna a prioridade de um operador matemático*/
int getPrioridade(char c);

/* Função que inverte a ordem dos caracteres em uma string */
void inverter_string(char *str);

/* Função que converte uma expressão da notação posfixa para a notação prefixa */
void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa);

/* Função que converte uma expressão da notação prefixa para a notação posfixa */
void converter_prefixa_para_posfixa(const Expressao *expressao_prefixa, Expressao *expressao_posfixa);