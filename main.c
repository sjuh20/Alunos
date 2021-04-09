#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main() {
    struct aluno *al;

    int removematricula;
    int opcao;
    char nome[30];

    Lista *li;

    do {
        showMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                li = cria_lista();
                break;
            case 2:
                al = (struct aluno *) malloc(sizeof(struct aluno));
                printf("\nDigite um nome:");
                fflush(stdin);
                gets(al->nome);
                printf("\nDigite o numero da matricula:");
                scanf("%d", &al->matricula);
                printf("\nDigite a primeira nota:");
                scanf("%f", &al->n1);
                printf("\nDigite a segunda nota:");
                scanf("%f", &al->n2);
                printf("\nDigite a terceira nota:");
                scanf("%f", &al->n3);
                insere_lista_inicio(li, *al);
                break;
            case 3:
                printf("Tamanho: %d\n", tamanho_lista(li));
                break;
            case 4:
                imprime_lista(li);
                break;
            case 5:
                printf("\nDigite o numero de matricula para ser removido:");
                scanf("%d", &removematricula);
                if (remove_lista(li, removematricula)) {
                    printf("\n");
                    imprime_lista(li);
                } else
                    printf("Nao foi possivel remover o item da lista");
                break;
            case 6:
                removeFinalDaLista(li);
                break;
            case 7:
                removeInicioLista(li);
                break;
            case 8:
                fflush(stdin);
                gets(nome);
                buscaListaPorNome(li, nome);
                break;
            default:
                printf("Opcao incorreta, digite novamente\n");
                break;
        }
    } while (opcao != 0);

    libera_lista(li);
    system("pause");
    return 0;
}