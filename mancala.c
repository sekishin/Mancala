// ボードゲーム「Mancala」の作成

//=======================ヘッダファイル=========================
#include <stdio.h>
//=======================大域定義==========================
typedef enum {false, true} bool;
//=======================大域宣言==========================
int hole[]  = {0,3,3,3,3,3,3,0,3,3,3,3,3,3};  // 0, 7は墓場
//=======================ゲーム処理==========================

//------------------------------------------盤面表示------------------------------------------------
void show(void) {
    int k;

    //-- 先手の盤面表示
    printf("     ");
    for ( k = 1; k < 7; k++ ) { printf(" %2d  ", k); }
    printf("\n[%2d] ", hole[0]);
    for ( k = 1; k <= 6 ; k++ ) { printf("(%2d) ", hole[k]); }
    printf("\n     ");

    //-- 後手の盤面表示
    for ( k = 13; k > 7; k-- ) { printf("(%2d) ", hole[k]); }
    printf("[%2d]\n     ", hole[k]);
    for ( k = 6; k >= 1; k-- ) { printf(" %2d  ", k); }
    printf("\n");

}
//-----------------------------------------------入力処理-------------------------------------------
int input(int min, int max, int add) {
    int p;

    //-- 入力
    while (1) {
        printf("%d～%dの数字を入力\n", min, max);
        printf("> ");
        scanf("%d", &p);
        if ( p <=  max && p >= min && hole[p+add] != 0 ) { break; }    // 正しい値なら反復を脱出
        printf("不正な入力\n");
    }

    return p+add;

}
//-----------------------------------------石の移動処理---------------------------------------------
bool move(int p) {
    int k;
    int num = hole[p];    // 石の数を格納
    hole[p] = 0;    // 指定位置の石を0個に

    for ( k = 1; k <= num; k++ ) {    // 石の個数分だけ順番に更新
        p--;    // 現在位置の更新
        if ( p < 0 ) { p = 13; }    // 13番目と0番目をつなげる
        hole[p]++;    // 石を1個増やす
    }

    if ( p == 0 || p == 7 ) { return true; }   // 墓場で終わればもう一回

    return false;

}
//---------------------------------------ゲームの終了判定-------------------------------------------
bool end(void) {
    int k;
    int numA = 0;
    int numB = 0;

    for ( k = 1; k <= 6; k++ ) {    // 各マスを調べて合計を求める
        numA += hole[k];
        numB += hole[k+7];
    }
    if ( numA == 0 || numB == 0 ) { return true; }    // どちらかが0個なら終了

    return false;

}
//========================本体処理=========================
int main(void) {
    printf("mancala START\n");

    while ( 1 ) {
        //-- 先手
        while (1) {
            show();
            printf("先手のターン\n");
            if ( move(input(1,6,0)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }    // 終了したか判定
        //-- 後手
        while (1) {
            show();
            printf("後手のターン\n");
            if ( move(input(1,6,7)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }    // 終了したか判定
    }

    show();

    return 0;

}
