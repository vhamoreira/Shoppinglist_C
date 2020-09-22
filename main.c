/* Nome: Vitor Moreira, Numero: 33953
Data: 20/11/2016
Nome do Trabalho: Lista de Compras Digital*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 50


struct produto
{
    int id;
    char nome[50];
    char categoria [50];
    float kcal;
    char lactose[1]; //Lactose: S || N
    int quantidade;
};

struct produtos_lista
{
    int pid;
    char pnome[50];
    char pcategoria [50];
    float pkcal;
    char plactose[1]; //Lactose: S || N
};





int criar_ID();
int Numero_lista_compras();


void criar_categoria();
void criar_produtos();
void criar_listas_compras();
void atualizarProduto (int id,int qtd);
struct produto encontrarProduto(int id);



char fproduto[]= {"produto.txt"};
char fcategorias[]= {"categorias.txt"};
char fprodutos_lista[]= {"lista_temporaria.txt"};





int main()
{
    FILE * fp;
    int ch, op, n, i, l;

    int num_produtos=0, num_categorias=1, num_listas=0;


    while(1)
    {

        system("cls");

        printf("SE PRETENDE 1. CRIAR CATEGORIAS \n 2. CRIAR PRODUTOS \n 3. CRIAR LISTA DE COMPRAS \n 4. INSERIR/ELIMINAR/EDITAR OS PRODUTOS DA LISTA DE COMPRAS \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("QUANTAS CATEGORIAS PRETENDE CRIAR ? \n");
            scanf ("%d", &n);
            for (i=0; i<n; i++)
            {
                criar_categoria(&categorias[num_categorias], n);
                num_categorias++;
            }
            break;
        case 2:
            printf("QUANTOS PRODUTOS PRETENDE ADICIONAR ? \n");
            scanf("%d", &n);
            for (i=0; i<n; i++)
            {
                criar_produtos(&Lista->produtos[num_produtos], categorias, num_categorias);
                num_produtos++;
            }
            break;
        case 3:
            printf("QUANTAS LISTAS DE COMPRAS PRETENDE INSERIR ? \n");
            scanf("%d", &l);
            for (i=0; i<l; i++)
            {
                criar_lista_de_compras(&Lista->nome);
                num_listas++;
            }
            break;
        case 4:
            printf("1. INSERIR \n 2. ELIMINAR \n 3. EDITAR \n");
            scanf("%d", &n);
            if (n==1)
            {
                int m, j;
                printf("QUANTOS PRODUTOS PRETENDE INSERIR ? \n");
                scanf("%d", &m);
                for (j=0; j<m; j++)
                {
                    inserir_produtos(&Lista->produtos);
                }
                return main();
            }
            if (n==2)
            {
                int e, j;
                exibir_produtos(&Lista, strlen(Lista->produtos));
                printf("QUAL A POSICAO QUE PRETENDE ELIMINAR? \n");
                scanf("%d", &e);
                eliminar_produtos(e, &Lista->produtos);
                return main();
            }
            if (n==3)
            {
                int i;
                exibir_produtos(&Lista, strlen(Lista->produtos));
                printf("QUAL A POSICAO DO PRODUTO QUE PRETENDE EDITAR? \n");
                editar_produtos(&Lista);
                return main();
            }
        }

        return 0;
    }


    int criar_ID()
    {
        FILE * fp;
        int valor=0;
        fp=fopen("id_produto.txt","r");

        if(fp==NULL)
        {
            fp=fopen("id_produto.txt","w");
            fprintf(fp,"%d",0);
            fclose(fp);
            fp=fopen("id_produto.txt","r");
        }

        fscanf(fp,"%d",&valor);

        fclose(fp);

        fp=fopen("id_produto.txt","w");

        fprintf(fp,"%d",valor+1);

        fclose(fp);

        return valor+1;
    }


    void criar_produtos()
    {
        int ch;
        int voltar = 0;
        system("cls");
        while (1)
        {

            printf("1. Adicionar novo produto\n\n");
            printf("2. Mostrar todos os produtos\n\n");

            printf("0. Voltar\n\n");

            printf("Insira a sua escolha:");
            scanf("%d",&ch);

            switch(ch)
            {
            case 1:
                adicionar_produto();
                break;

            case 2:
                mostrar_produtos();
                break;

            case 0:
                voltar = 1;
                break;
            }

            if (voltar==1)
            {
                break;
            }
            else
            {

            }
        }
    }


    void adicionar_produto()
    {
        FILE * fp;
        struct produto t1;



        fp=fopen(fproduto,"ab");

        t1.id=criar_ID();

        printf("\nInsira o nome do produto:");
        scanf("%s",t1.nome);
        printf("\nInsira a categoria do produto:");
        scanf("%s",t1.categoria);
        printf("\nInsira a quantidade de calorias do produto:");
        scanf("%f",&t1.kcal);
        printf("\nO produto tem lactose? (s/n):");
        scanf("%s",t1.lactose);
        printf("\nInsira a quantidade existente deste produto:");
        scanf("%d",&t1.qtd);

        fwrite(&t1,sizeof(t1),1,fp);

        fclose(fp);

    }

    void mostrar_produtos()
    {
        FILE * fp;
        struct produto t;
        int id, encontrado=0;

        fp = fopen(fproduto,"rb");
        printf("\t\t Detalhes dos Produtos \n\n");
        printf("ID\tNome\tCategoria\tCalorias(kcal)\tLactose(Sim/Nao)  Quantidade\n\n");

        while(1)
        {
            fread(&t,sizeof(t),1,fp);

            if (feof(fp))
            {
                break;
            }

            printf("%d\t",t.id);
            printf("%s\t",t.nome);
            printf("%s\t\t",t.categoria);
            printf("%f\t",t.kcal);
            printf("%s\t\t",t.lactose);
            printf("  %d\n",t.qtd);
        }
        fclose(fp);
    }

    void gerir_listas()
    {

        int ch;
        int voltar = 0;
        system("cls");
        while (1)
        {

            printf("\t\tGerir Listas \n\n");

            printf("1. Criar nova lista\n\n");
            printf("2. Apagar Lista\n\n");

            printf("0. Voltar\n\n");

            printf("Insira a sua escolha:");
            scanf("%d",&ch);

            switch(ch)
            {
            case 1:
                printf("NOME DA LISTA DE COMPRAS PRETENDE INSERIR ? \n");
                scanf("%s", &nome);
                for (i=0; i<l; i++)
                {
                    criar_lista_de_compras(&Lista->nome);
                    num_listas++;
                }//criar_listas_compras();
                break;

            case 2:
                printf("Remover lista igual a: \n");
                scanf("%s",&removelista);

                for(i=0; i<ultimo; i++)
                {

                    if(vet[i].lista == removelista)
                    {
                        vet[i].lista= vet[i+1].lista;
                        vet[ultimo-1].lista = 0;
                    }
                    printf("lista = %s\n",vet[i].lista);
                } //apagar lista();
                break;

            case 0:
                voltar = 1;
                break;
            }

            if (voltar==1)
            {
                break;
            }
            else
            {

            }
        }
    }



    void comprar_produtos()
    {
        char ch1,ch2;
        int id;
        system("cls");

        while(1)
        {

            mostrar_produtos();
            fflush(stdin);

            printf("\n\n\nPretende adicionar na lista algum destes produtos? (s/n):");
            scanf("%c",&ch1);

            if(ch1=='s')
            {
                FILE * fp;
                struct produtos_lista t1;
                struct produto t2;

                fp=fopen(fprodutos_lista,"ab");

                printf("\n\nInsira o ID do produto que pretende adicionar na lista:");
                scanf("%d",&id);

                t2=encontrarProduto(id);

                t1.pid=t2.id;
                strcpy(t1.pnome,t2.nome);
                strcpy(t1.pcategoria,t2.categoria);
                t1.pkcal = t2.kcal;
                strcpy(t1.plactose,t2.lactose);


                fwrite(&t1,sizeof(t1),1,fp);

                fclose(fp);
            }
            fflush(stdin);
            printf("\n\n\nDeseja adicionar mais algum produto na lista? (s/n):");
            scanf("%c",&ch2);

            if (ch2=='n')
            {
                break;
            }
        }
    }

    struct produto encontrarProduto(int id)
    {
        FILE * fp;
        struct produto t;

        fp=fopen(fproduto,"rb");

        while(1)
        {

            fread(&t,sizeof(t),1,fp);

            if(feof(fp))
            {
                break;
            }

            if(t.id==id)
            {
                atualizarProduto(id,t.qtd-1);
                break;
            }
        }
        fclose(fp);
        return t;
    }

    void atualizarProduto (int id,int qtd)
    {
        FILE * fp, *fp1;
        struct produto t,t1;
        int encontrado=0;

        fp=fopen(fproduto,"rb");
        fp1=fopen("temporario.txt","wb");

        while(1)
        {
            fread(&t,sizeof(t),1,fp);

            if(feof(fp))
            {
                break;
            }

            if(t.id==id)
            {
                encontrado=1;
                t.qtd=qtd;
                fwrite(&t,sizeof(t),1,fp1);

            }
            else
            {
                fwrite(&t,sizeof(t),1,fp1);
            }
        }
        fclose(fp);
        fclose(fp1);

        if (encontrado==0)
        {
            printf("Ficheiro não encontrado\n\n"); //No caso da gravação não ser encontrada

        }
        else
        {
            fp=fopen(fproduto,"wb");
            fp1=fopen("temporario.txt","rb");

            while(1)
            {
                fread(&t,sizeof(t),1,fp1);

                if(feof(fp1))
                {
                    break;
                }
                fwrite(&t,sizeof(t),1,fp);
            }
        }
        fclose(fp);
        fclose(fp1);

        void criar_listas_compras()
        {

            char nlista[50];
            printf("Qual o nome da lista nova que pretende criar?\n");
            scanf("%s\n",nlista);
            nficheiro = ("%s.txt", nlista);

            FILE * fp;

            fp = fopen (nficheiro,"w");
            fp1=fopen("temporario.txt","r");

            while(1)
            {
                fread(&t,sizeof(t),1,fp1);

                if(feof(fp1))
                {
                    break;
                }
                fwrite(&t,sizeof(t),1,fp);
            }
        }

        printf("\n\nQual pretende que seja o nome dessa lista definitiva?:");
        scanf("%s",nomelistapretendido);
        nomelista =("%s.txt",nomelistapretendido); /*-- Como se definie o nome do ficheiro,
                                                      segundo a palavra dada pelo utilizador? */


        ltemprel=numerolistadefinitiva();
        sprintf(nomelista,"%s%d","",ltemprel);
        strcat(nomelista,".txt");

        fp=fopen(fprodutos_lista,"rb");
        fp1=fopen(nomelista,"wb");

        while(1)
        {
            fread(&t,sizeof(t),1,fp);

            if(feof(fp))
            {
                break;
            }
            fwrite(&t,sizeof(t),1,fp1);
        }
        fclose(fp);
        fclose(fp1);

        fp=fopen(fprodutos_lista,"wb");
        fclose(fp);
    }
}

int numerolistadefinitiva()
{
    FILE * fp;
    int valor=0;
    fp=fopen("numero_lista_definitiva.txt","r");

    if(fp==NULL)
    {
        fp=fopen("numero_lista_definitiva.txt","w");
        fprintf(fp,"%d",0);
        fclose(fp);
        fp=fopen("numero_lista_definitiva.txt","r");
    }
    fscanf(fp,"%d",&valor);

    fclose(fp);

    fp=fopen("numero_lista_definitiva.txt","w");
    fprintf(fp,"%d",valor+1);
    fclose(fp);

    return valor+1;
}



/*void criar_listas ()
{
    char nomelis,nomprod;
    int nlista,i,j,nprod;
    printf("Quantas listas deseja criar?\n");
    scanf("%d",&nlista);
    fflush(stdin);
    for (i=0;i<nlista;i++)
    {
        printf("Que nome deseja dar a sua lista de compras?\n");
        scanf("%s",&nomelis);
        fflush(stdin);
        printf("Quantos produtos deseja inserir nesta lista?\n");
        scanf("%d",&nprod);
        fflush(stdin);
        if (nprod>1)
        {
            for (j=0;j<nprod;j++)
            {
                printf("Insira o nome do produto");
                scanf("%s",&nomprod);
            }
        }
    }


}

 */
