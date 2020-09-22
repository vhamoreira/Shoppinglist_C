
#include <stdio.h>
#include <stdlib.h>

#define TAMANHOstock 20
#define TAMANHOCATALOGO 21

/**
    Descreve cada 'material' tratado pelo programa, como item de stock ou
    como item de uma lista de compras.
**/
struct Material{
       int cod;          // código do material (deve ser único)
       float valorUnit;  // valor unitário
       char* descr;      // descrição do material
};

/**
     O vetor abaixo representa o catálogo de materiais comercializados pela empresa.
     (versão preliminar, com dados criados diretamente pelo programa - a idéia é
      que no futuro essa lista seja lida de um arquivo texto).
     A lista está propositadamente ordenada em ordem crescente pelo código.
**/
struct Material catalogo[] = {
                         {101,5.1,"colher"},
                         {102,8.2,"faca"},
                         {103,9.1,"garfo"},
                         {104,20.0,"panela"},
                         {105,25.0,"frigideira"},
                         {106,18.0,"bacia"},
                         {107,10.0,"tesoura"},
                         {108,12.2,"sacarrolhas"},
                         {109,12.4,"canecao"},
                         {110,16.5,"martelo"},
                         {120,21.5,"serrote"},
                         {121,20.2,"formao"},
                         {122,12.3,"verruma"},
                         {123,25.5,"arco de pua"},
                         {124,24.4,"plaina"},
                         {125,32.3,"esquadro"},
                         {126,39.2,"paquimetro"},
                         {127,23.2,"goiva"},
                         {128,23.0,"lima"},
                         {129,23.0,"groza"},
                         {130,20.0,"rebolo"}
                      };

/**
     Descreve um item do stock ou de uma lista de compras.
**/
struct Item{
       int cod;    // código do item (identificação única relativa ao catálogo)
       int quant;  // quantidade (em stock, sendo adquirida ou sendo vendida)
       };

/**
     Lista que representa o stock da empresa (de novo, criada diretamente em
     memória - a idéia é que no futuro seja lida de um arquivo texto).
     Os itens estão propositadamente ordenados em ordem crescente pelo código.
**/
struct Item stock[] = {
                         {102, 53},
                         {103, 60},
                         {104, 45},
                         {105, 30},
                         {106, 12},
                         {107, 21},
                         {108, 34},
                         {109, 12},
                         {110, 22},
                         {120, 24},
                         {121, 33},
                         {122, 13},
                         {123, 9},
                         {124, 14},
                         {125, 18},
                         {126, 14},
                         {127, 21},
                         {128, 23},
                         {129, 30},
                         {130, 21}
                       };

/**
     Exemplo de um pedido feito por um cliente
     (assim como o stock, usa a estrutura Item).
**/
struct Item pedido1[] = {
                         {127, 5},
                         {102, 15},
                         {110, 12},
                         {103, 20},
                         {126, 8},
                         {106, 7}
                        };

/**
     Exemplo de uma lista de itens adquiridos que deve
     ser agragada ao stock.
**/
struct Item compra[] = {
                         {128, 12},
                         {120, 15},
                         {102, 22},
                         {126, 10},
                         {103, 20},
                         {128, 23}
                       };

/**
     Busca por um item no catálogo a partir do código.
     Como no catálogo, os códigos estão em ordem crescente,
     foi usada a técnica de 'busca binária':

**/
struct Material * buscaNoCatalogo(int cod){
    int i = 0, j = TAMANHOCATALOGO-1;
    while(j >= i){
            int k = (i+j)/2;
            if(cod > catalogo[k].cod) i = k + 1; else
            if(cod < catalogo[k].cod) j = k - 1; else
            return &catalogo[k];
    }
    return NULL;
}

/**
    Busca por um item no stock, usando a técnica de
    busca sequencial. A busca binária pode ser usada aqui
    e fica como exercício.
**/
struct Item * buscaNostock(int cod){
    int i;
    for(i = 0; i < TAMANHOstock; i++)
      if(stock[i].cod == cod) return &(stock[i]);
    return NULL;
}

/**
     Verifica se é possivel atender a uma lista de compra
     com o stock atual. Retorna TRUE se possível ou FALSE
     em caso contrário.
     A implementação desta função fica como exercício.
**/
int verificastock ( struct Item[], int n);

/**
     Imprime uma lista (de compras, de aquisição ou a que representa
     o stock). Os detalhes (valor unitário e descrição são
     buscados no catálogo.
**/
void imprimeLista (struct Item lista[], int n){
    int i;
    float total = 0;
    for(i = 0; i < n; i++){
        struct Material * p = buscaNoCatalogo(lista[i].cod);
        if(p == NULL) printf("cod:%d Item desconhecido\n",lista[i].cod);
        else {
            printf("cod:%d descr:%s v.Unit:%8.2f quant: %d valor:%8.2f\n",
                    lista[i].cod, (*p).descr, (*p).valorUnit,
                    lista[i].quant, (*p).valorUnit*lista[i].quant);
            total += (*p).valorUnit*lista[i].quant;
        }
    }
    printf("Valor Total: %8.2f\n",total);
}

/**
     Calcula o valor de uma lista (de compras, de aquisição o a que
     representa o stock). Os detalhes são buscados no catálogo.
**/
float calculaValor(struct Item lista[], int n){
    int i; float valor = 0;
    for(i = 0; i < n; i++){
        struct Material *p = buscaNoCatalogo(lista[i].cod);
        if(p != NULL) valor += (*p).valorUnit*lista[i].quant;
    }
    return valor;
}

/**
     Baixa no stock dos itens que constam numa lista de compras.
**/
int baixastock(struct Item lista[], int n){
    int i;
    for(i = 0; i < n; i++){
        struct Item *p = buscaNostock(lista[i].cod);
        if(p != NULL) (*p).quant -= lista[i].quant;
    }
}

/**
     Agrega ao stock os itens que constam de uma lista de aquisição.
     A implementação deve ser feita como exercício.
**/
int recebeLista(struct Item lista[], int n);

/**
     Programa principal: alguns testes simples.
**/
int main()
{
    FILE * fp;
    int ch;


    while(1){

    system("cls");


    printf("\n");
    printf("LISTA DE COMPRAS \n");
    printf("\n\n\n");



        printf("Escolha a opcao a que se adequa a acao pretendida []:\n");
        printf("\n");
        printf(" [1]Criar categoria\n");
        printf(" [2]Stock\n");
        printf(" [3]Escolher produtos para adicionar na lista temporaria\n");
        printf(" [4]Gerir lista temporaria\n");
        printf(" [0]Sair\n");

        scanf("%d", &ch);

        switch (ch)
        {
            case 1:

                //criar_categorias ();  - Por criar
                break;

            case 2:
                imprimeLista(stock,22); //Falta adicionar relaçao com as categorias já criadas
                break;

            case 3:
              ; //São os produtos a adicionar à lista temporaria,a partir dos já existentes
                break;

            case 4:
                ;
                break;

            case 0: exit(0);
        }

    }
return 0;
}
