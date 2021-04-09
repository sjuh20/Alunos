//
// Created by Estudos on 07/04/2021.
//

#ifndef TAREFAESTRUTURA_LISTADINENCAD_H
#define TAREFAESTRUTURA_LISTADINENCAD_H

//Arquivo ListaDinEncad.h

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento *Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

int insere_lista_final(Lista *li, struct aluno al);

int insere_lista_inicio(Lista *li, struct aluno al);

int remove_lista(Lista *li, int mat);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int lista_cheia(Lista *li);

void imprime_lista(Lista *li);

int consulta_lista_pos(Lista *li, int pos, struct aluno *al);

void showMenu();

int removeInicioLista(Lista *li);

int removeFinalDaLista(Lista *li);

void buscaListaPorNome(Lista *li, char *nome);


#endif //TAREFAESTRUTURA_LISTADINENCAD_H

