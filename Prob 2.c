#include <stdio.h>

int hanoi(int disk, int source, int dest, int aux) {
    if (disk == 1) {
        printf("Muta discul %d de pe turnul %d pe turnul %d\n", disk, source, dest);
        return 1;
    }
    else {
        int moves = 0;
        moves += hanoi(disk-1, source, aux, dest);
        printf("Muta discul %d de pe turnul %d pe turnul %d\n", disk, source, dest);
        moves += 1;
        moves += hanoi(disk-1, aux, dest, source);
        return moves;
    }
}

int main() {
    int n = 6;
    int total_moves = hanoi(n, 1, 3, 2);
    printf("Total mutari: %d\n", total_moves);
    return 0;
}