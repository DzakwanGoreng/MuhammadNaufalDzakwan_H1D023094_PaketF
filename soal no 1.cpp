#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 4

typedef struct {
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;

QUEUE antrean;
void inisialisasi(QUEUE *Q) {
    Q->count = 0;
    Q->front = 0;
    Q->rear = 0;
}
int isEmpty(QUEUE *Q) {
    int hasil = 0;
    if (Q->count == 0) {
        hasil = 1;
    }
    return hasil;
}
int isFull(QUEUE *Q) {
    int hasil = 0;
    if (Q->count == MAXQUEUE) {
        hasil = 1;
    }
    return hasil;
}

void printQueue(QUEUE *Q) {
    if (isEmpty(Q)) {
        printf("Antrian kosong.\n");
        return;
    }
    printf("Isi antrian: ");
    for (int i = 0; i < Q->count; i++) {
        int index = (Q->front + i) % MAXQUEUE;
        printf("%d ", Q->item[index]);
    }
    printf("\n");
}

void insert(QUEUE *Q, int data) {
    if (isFull(Q)) {
        printf("Queue sudah penuh %d\n", data);
        return;
    }
    Q->item[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->count++;
    printf("Masukan %d\n", data);
    printQueue(Q);
}

void hapus(QUEUE *Q) {
    if (isEmpty(Q)) {
        printf("Queue kosong \n");
        return;
    }
    printf("Menghapus antrian %d dari antrian\n", Q->item[Q->front]);
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->count--;
    printQueue(Q);
}



int main() {
    inisialisasi(&antrean);
    insert(&antrean, 108);
    insert(&antrean, 109);
    insert(&antrean, 110);
    insert(&antrean, 111);
    hapus(&antrean);
    insert(&antrean, 112);

    return 0;
}
