#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define n 20

int comparacoes = 0;
int trocas = 0;
int movimentacoes = 0;

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void print_array(int v[], int size){
    if(size==0 || v==NULL){
        return;
    }

    for(int i=0; i<size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubblesort(int v[], int size){
    int i, j;
    if(v==NULL || size==0){
        return;
    }
    
    for(i=0;i<size;i++){

        for(j=0;j<size-1-i;j++){

            if(v[j]>v[j+1]){
                swap(&v[j], &v[j+1]);
            }   
        }
    }
}

void q1_bubblesort_basic(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];

    printf("\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    bubblesort(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    bubblesort(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    bubblesort(random, n);
    printf("Depois: ");
    print_array(random, n);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    bubblesort(empty, 0);
    printf("\n\nDepois: ");
    print_array(empty, 0);
};

void bubblesort_metrics(int v[], int size){
    comparacoes = 0;
    trocas = 0;
    int i, j;
    if(v==NULL || size==0){
        return;
    }
    
    for(i=0;i<size;i++){

        for(j=0;j<size-1-i;j++){
            if(v[j]>v[j+1]){
                swap(&v[j], &v[j+1]);
                trocas++;
            }  
            comparacoes++;
        }
    }
}

void q2_bubblesort_metrics(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];

    printf("\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    bubblesort_metrics(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    bubblesort_metrics(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    bubblesort_metrics(random, n);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    bubblesort_metrics(empty, 0);
    printf("\nDepois: ");
    print_array(empty, 0);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
}

void bubblesort_metrics_es(int v[], int size){
    comparacoes = 0;
    trocas = 0;
    int i, j, houveTroca;
    if(v==NULL || size==0){
        return;
    }
    
    for(i=0;i<size;i++){
        houveTroca=0;
        for(j=0;j<size-1-i;j++){
            if(v[j]>v[j+1]){
                swap(&v[j], &v[j+1]);
                trocas++;
                houveTroca=1;
            }  
            comparacoes++;
        }
        if(!houveTroca){
            break;
        }
    }
}

void q3_bubblesort_metrics_es(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];

    printf("\n\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    bubblesort_metrics_es(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    bubblesort_metrics_es(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    bubblesort_metrics_es(random, n);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    bubblesort_metrics_es(empty, 0);
    printf("\nDepois: ");
    print_array(empty, 0);
    printf("\nComparações: %d  |  Trocas: %d", comparacoes, trocas);
}

void bubblesort_order(int v[], int size, int order){
    comparacoes = 0;
    trocas = 0;
    int i, j, houveTroca;
    if(v==NULL || size==0){
        return;
    }
    
    for(i=0;i<size;i++){
        houveTroca=0;
        for(j=0;j<size-1-i;j++){
            if(order==1 && v[j]>v[j+1]){
                swap(&v[j], &v[j+1]);
                trocas++;
                houveTroca=1;
            }  
            if(order==-1 && v[j]<v[j+1]){
                swap(&v[j], &v[j+1]);
                trocas++;
                houveTroca=1;
            } 

            comparacoes++;
        }
        if(!houveTroca){
            break;
        }
    }
}

void q5_bubblesort_order(){
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int mixed[]={12,-1,2,-9,15,-14,11,-19,7,-16,13,-5,18,-20,10,-6,4,-3,17,-8};
    int unitary[1]={1};
    int empty[n];
    int order;
    
    while(order!=1 && order!=-1){
        printf("Escolha a order:\n1 - order crescente.    -1 - order decrescente.\nSeleção: ");
        scanf("%d", &order);
        printf("\nOrdenando em order: ");
    }
    if(order==1){
        printf("Crescente.\n");
    } else{
        printf("Decrescente.\n");
    }
    
    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    bubblesort_order(random, n, order);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor VARIADO---\n");
    printf("Antes: ");
    print_array(mixed, n);
    bubblesort_order(mixed, n, order);
    printf("Depois: ");
    print_array(mixed, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor UNITÁRIO---\n");
    printf("Antes: ");
    print_array(unitary, 1);
    bubblesort_order(unitary, 1, order);
    printf("Depois: ");
    print_array(unitary, 1);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    bubblesort_order(empty, 0, order);
    printf("\nDepois: ");
    print_array(empty, 0);
    printf("\nComparações: %d  |  Trocas: %d", comparacoes, trocas);
}

void selectionsort(int v[], int size) {
    comparacoes = 0;
    trocas = 0;
    if(size <= 1){
        return;
    }
    int i, j, key_min;
    for(i = 0; i<size-1; i++){
        key_min = i;
        for(j = i+1; j<size; j++){
            if(v[j] < v[key_min]){
                key_min = j;
            }
            comparacoes++;
        }
        if(key_min != i){//ou seja, foi achado um sucessor menor
            swap(&v[i], &v[key_min]);
            trocas++;
        }
    }
}

void q6_selectionsort(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];

    printf("\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    selectionsort(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    selectionsort(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    selectionsort(random, n);
    printf("Depois: ");
    print_array(random, n);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    selectionsort(empty, 0);
    printf("\n\nDepois: ");
    print_array(empty, 0);
}

void q7_tracado(){
    printf("Vetor:[64, 25, 12, 22, 11]      Algoritmo: Selection Sort.\n\n");
    printf("1ª iteração: (i=0) [64->, 25, 12, 22, 11] => [*11*, 25, 12, 22, *64*] => j=n\n");
    printf("2ª iteração: (i=1) [11, 25->, 12, 22, 64] => [11, *12*, *22*, 25, 64] => j=n\n");
    printf("3ª iteração: (i=2) [11, 12, 22->, 25, 64] => key = i\n");
    printf("4ª iteração: (i=3) [11, 12, 22, 25->, 64] => key = i\n");
    printf("5ª iteração: (i=4) i>n-1, fim do laço\n");
}

void q8_selectionsort_metrics(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];
    
    printf("\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    selectionsort(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    selectionsort(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    selectionsort(random, n);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    selectionsort(empty, 0);
    printf("\n\nDepois: ");
    print_array(empty, 0);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
}

void selectionsort_order(int v[], int size, int order){
    comparacoes = 0;
    trocas = 0;
    if(size <= 1){
        return;
    }
    int i, j, key_min;
    for(i = 0; i<size-1; i++){
        key_min = i;
        for(j = i+1; j<size; j++){
            comparacoes++;
            
            if(order == 1 && v[j] < v[key_min]){
                key_min = j;
            }
            if(order == -1 && v[j] > v[key_min]){
                key_min = j;
            }
        }
        if(key_min != i){//ou seja, foi achado um sucessor menor
            swap(&v[i], &v[key_min]);
            trocas++;
        }
    }
}

void q10_insertionsort_order(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];
    int order;

    while(order!=1 && order!=-1){
        printf("Escolha a order:\n1 - order crescente.    -1 - order decrescente.\nSeleção: ");
        scanf("%d", &order);
        printf("\nOrdenando em order: ");
    }
    if(order==1){
        printf("Crescente.\n");
    } else{
        printf("Decrescente.\n");
    }
    
    printf("\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    selectionsort_order(ordered, n, order);
    printf("Depois: ");
    print_array(ordered, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    selectionsort_order(reverse, n, order);
    printf("Depois: ");
    print_array(reverse, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    selectionsort_order(random, n, order);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
    
    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    selectionsort_order(empty, 0, order);
    printf("\n\nDepois: ");
    print_array(empty, 0);
    printf("Comparações: %d  |  Trocas: %d", comparacoes, trocas);
}

void insertionsort(int v[], int size){
    comparacoes = 0;
    trocas = 0;
    movimentacoes = 0;
    int i, j, key;
    for(i=1; i<size; i++){ //começamos do segundo
        key=v[i];
        j = i;

        while(j > 0){//vai indo pra trás até achar um maior que a chave ou chegar no primeiro el.
            comparacoes++;
            if(key < v[j-1]){
                v[j]=v[j-1];
                movimentacoes++;
                j--;
            }
            else{
                break;
            }
        }
        trocas++;
        v[j]=key;
        movimentacoes++;
    }
}

void q11_insertionsort(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};
    int empty[n];

    printf("\n\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    insertionsort(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    insertionsort(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    insertionsort(random, n);
    printf("Depois: ");
    print_array(random, n);

    printf("\n\n---Vetor VAZIO---\n");
    printf("Antes: ");
    print_array(empty, 0);
    insertionsort(empty, 0);
    printf("\nDepois: ");
    print_array(empty, 0);
}

void q12_tracado(){
    printf("Vetor:vetor [5, 3, 4, 1, 2],      Algoritmo: Insertion Sort.\n\n");
    printf("1ª iteração: (i=1)(chave=3)   [5, <-3, 4, 1, 2] => [*3*, *5*, 4, 1, 2] => j=0\n");
    printf("1ª iteração: (i=2)(chave=4)   [3, 5, <-4, 1, 2] => [3, *4*, *5*, 1, 2] => j=0\n");
    printf("1ª iteração: (i=3)(chave=1)   [3, 4, 5, <-1, 2] => [3, 4, *1*, *5*, 2] => [3, *1*, *4*, 5, 2] => [*1*, *3*, 4, 5, 2] => j=0\n");
    printf("1ª iteração: (i=4)(chave=2)   [1, 3, 4, 5, <-2] => [1, 3, 4, *2*, *5*] => [1, 3, *2*, *4*, 5] => [1, *2*, *3*, 4, 5] => chave > v[j-1]\n");
    printf("1ª iteração: (i=5) => i=n");
}

void q13_insertionsort_metrics(){
    int ordered[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverse[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int random[]={12,1,2,9,15,14,11,19,7,16,13,5,18,20,10,6,4,3,17,8};

    printf("\n\n---Vetor ORDENADO---\n");
    printf("Antes: ");
    print_array(ordered, n);
    insertionsort(ordered, n);
    printf("Depois: ");
    print_array(ordered, n);
    printf("Comparações: %d  |  Movimentações: %d |  Trocas: %d", comparacoes, movimentacoes, trocas);

    printf("\n\n---Vetor DECRESCENTE---\n");
    printf("Antes: ");
    print_array(reverse, n);
    insertionsort(reverse, n);
    printf("Depois: ");
    print_array(reverse, n);
    printf("Comparações: %d  |  Movimentações: %d |  Trocas: %d", comparacoes, movimentacoes, trocas);

    printf("\n\n---Vetor ALEATÓRIO---\n");
    printf("Antes: ");
    print_array(random, n);
    insertionsort(random, n);
    printf("Depois: ");
    print_array(random, n);
    printf("Comparações: %d  |  Movimentações: %d |  Trocas: %d", comparacoes, movimentacoes, trocas);

    printf("\nExplicação:\nNo bubble, as iterações do laço interno ocorrem em varreduras que percorrem o vetor completo. Ou seja, mesmo que uma seção já esteja ordenada, aa varredura ainda vai até o fim.\nJá no Insetion, há duas condição de parada no laço interno, ou seja, na maioria das vezes, as comparações param antes de percorrer o vetor completo.");
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int choice;
    printf("Lista de exercícios:\n");
    printf("  1 - bubble sort básico.\n");
    printf("  2 - bubble sort com métricas.\n");
    printf("  3 - bubble sort com métricas e early stop.\n");
    printf("  5 - bubble sort com order.\n");
    printf("  6 - selection sort.\n");
    printf("  7 - passo a passo do selection sort.\n");
    printf("  8 - selection sort com métricas.\n");
    printf("  10 - selection sort com ordem.\n");
    printf("  11 - insertion básico.\n");
    printf("  12 - passo a passo do insertion sort.\n");
    printf("  13 - insertion sort com métricas.\n");
    printf("\nSeleção: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
        printf("\nbubble sort básico.\n\n");
        q1_bubblesort_basic();
        break;
        
        case 2:
        printf("\nbubble sort com métricas.\n\n");
        q2_bubblesort_metrics();
        break;

        case 3:
        printf("\nbubble sort com métricas e early stop.\n\n");
        q3_bubblesort_metrics_es();
        break;

        case 5:
        printf("\nbubble sort com order.\n\n");
        q5_bubblesort_order();
        break;

        case 6:
        printf("\nselection sort.\n\n");
        q6_selectionsort();
        break;

        case 7:
        printf("\nselection sort.\n\n");
        q7_tracado();
        break;

        case 8:
        printf("\nselection sort.\n\n");
        q8_selectionsort_metrics();
        break;

        case 10:
        printf("\nselection sort.\n\n");
        q10_insertionsort_order();
        break;

        case 11:
        printf("\ninsertion sort básico.\n\n");
        q11_insertionsort();
        break;

        case 12:
        printf("\npasso a passo do insertion sort.\n\n");
        q12_tracado();
        break;

        case 13:
        printf("\ninsertion sort com métricas.\n\n");
        q13_insertionsort_metrics();
        break;

        default:
        break;
    }

    return 0;
}