#include <stdio.h>

typedef enum {false, true} bool;

int hole[]  = {0,3,3,3,3,3,3,0,3,3,3,3,3,3};  // 0, 7は墓場

void show(void) {
    int k;
    printf("     ");
    for ( k = 1; k < 7; k++ ) {
        printf(" %2d  ", k);
    }
    printf("\n");
    printf("[%2d] ", hole[0]);
    for ( k = 1; k <= 6 ; k++ ) {
        printf("(%2d) ", hole[k]);
    }
    printf("\n     ");
    for ( k = 13; k > 7; k-- ) {
        printf("(%2d) ", hole[k]);
    }
    printf("[%2d]\n     ", hole[k]);
    for ( k = 6; k >= 1; k-- ) {
        printf(" %2d  ", k);
    }
    printf("\n");
}
int input(int min, int max, int add) {
    int p;

    while (1) {
        printf("%d～%dの数字を入力\n", min, max);
        printf("> ");
        scanf("%d", &p);
        if ( p <=  max && p >= min && hole[p+add] != 0 ) { break; }
        printf("不正な入力\n");
    }
    return p+add;
}

bool move(int p) {
    int k;
    int num = hole[p];
    hole[p] = 0;
    for ( k = 1; k <= num; k++ ) {
        p--;
        if ( p < 0 ) { p = 13; }
        hole[p]++;
    }

    if ( p == 0 || p == 7 ) { return true; }   // 墓場で終わればもう一回
    return false;
}

bool end(void) {
    int k;
    int numA = 0;
    int numB = 0;
    for ( k = 1; k <= 6; k++ ) {
        numA += hole[k];
        numB += hole[k+7];
    }
    if ( numA == 0 || numB == 0 ) { return true; }
    return false;
}
int main(void) {
    printf("mancala START\n");

    while ( 1 ) {
        while (1) {
            show();
            printf("先手のターン\n");
            if ( move(input(1,6,0)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }
        while (1) {
            show();
            printf("後手のターン\n");
            if ( move(input(1,6,7)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }
    }
    show();
    return 0;
}
