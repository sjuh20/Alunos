//
// Created by Estudos on 07/04/2021.
//

#include "ListaDinEncad.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista() {
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void imprime_lista(Lista *li) {
    if (li == NULL)
        return;
    Elem *no = *li;
    while (no != NULL) {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}


int insere_lista_final(Lista *li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem *no;
    no = (Elem *) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) {//lista vazia: insere início
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem *no;
    no = (Elem *) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}


int remove_lista(Lista *li, int mat) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL)//não encontrado
        return 0;

    if (no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}


int tamanho_lista(Lista *li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem *no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista *li) {
    return 0;
}

int lista_vazia(Lista *li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}


void libera_lista(Lista *li) {
    if (li != NULL) {
        Elem *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void showMenu() {
    printf("Menu de Opcoes\n");
    printf("Opcoes: \n");
    printf("1 - Criar Lista \n");
    printf("2 - Inserir item no inicio da Lista \n");
    printf("3 - Tamanho da Lista  \n");
    printf("4 - Imprime Lista  \n");
    printf("5 - Remova um aluno por matricula \n");
    printf("6 - Remova o primeiro aluno por matricula \n");
    printf("7 - Remova o final aluno por matricula \n");
    printf("8 - Digite o nome do aluno a ser buscado:  \n");
    printf("0 - Para encerrar o programa \n ");
    printf("Digite a opcao: ");
}

int removeInicioLista(Lista *li) {
    if (li == NULL)
        return 0;
    if (*li == NULL)
        return 0;
    Elem *no = *li;
    if (no->prox == NULL)
        *li = NULL;
    else *li = no->prox;
}

int removeFinalDaLista(Lista *li) {
    Elem *no = *li;
    if (no == NULL)
        return 0;
    if (no->prox == NULL)
        return 0;

    Elem *ultimo = no->prox;
    Elem *penultimo = no;

    while (ultimo->prox != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    penultimo->prox = NULL;
    return 1;
}

void buscaListaPorNome(Lista *li, char *nome) {
    if (li == NULL)
        printf("Não foi possivel encontrar o nome procurado");
    if (*li == NULL)
        printf("A lista esta vazia");
    Elem *no = *li;
    while (no != NULL) {
        if (strcmp(no->dados.nome, nome) == 0)
            printf("\nAluno(a): %s encontrado\n", no->dados.nome);
        no = no->prox;
    }

}



