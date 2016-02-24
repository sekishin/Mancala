// �{�[�h�Q�[���uMancala�v�̍쐬

//=======================�w�b�_�t�@�C��=========================
#include <stdio.h>
//=======================����`==========================
typedef enum {false, true} bool;
//=======================���錾==========================
int hole[]  = {0,3,3,3,3,3,3,0,3,3,3,3,3,3};  // 0, 7�͕��
//=======================�Q�[������==========================

//------------------------------------------�Ֆʕ\��------------------------------------------------
void show(void) {
    int k;

    //-- ���̔Ֆʕ\��
    printf("     ");
    for ( k = 1; k < 7; k++ ) { printf(" %2d  ", k); }
    printf("\n[%2d] ", hole[0]);
    for ( k = 1; k <= 6 ; k++ ) { printf("(%2d) ", hole[k]); }
    printf("\n     ");

    //-- ���̔Ֆʕ\��
    for ( k = 13; k > 7; k-- ) { printf("(%2d) ", hole[k]); }
    printf("[%2d]\n     ", hole[k]);
    for ( k = 6; k >= 1; k-- ) { printf(" %2d  ", k); }
    printf("\n");

}
//-----------------------------------------------���͏���-------------------------------------------
int input(int min, int max, int add) {
    int p;

    //-- ����
    while (1) {
        printf("%d�`%d�̐��������\n", min, max);
        printf("> ");
        scanf("%d", &p);
        if ( p <=  max && p >= min && hole[p+add] != 0 ) { break; }    // �������l�Ȃ甽����E�o
        printf("�s���ȓ���\n");
    }

    return p+add;

}
//-----------------------------------------�΂̈ړ�����---------------------------------------------
bool move(int p) {
    int k;
    int num = hole[p];    // �΂̐����i�[
    hole[p] = 0;    // �w��ʒu�̐΂�0��

    for ( k = 1; k <= num; k++ ) {    // �΂̌����������ԂɍX�V
        p--;    // ���݈ʒu�̍X�V
        if ( p < 0 ) { p = 13; }    // 13�Ԗڂ�0�Ԗڂ��Ȃ���
        hole[p]++;    // �΂�1���₷
    }

    if ( p == 0 || p == 7 ) { return true; }   // ���ŏI���΂������

    return false;

}
//---------------------------------------�Q�[���̏I������-------------------------------------------
bool end(void) {
    int k;
    int numA = 0;
    int numB = 0;

    for ( k = 1; k <= 6; k++ ) {    // �e�}�X�𒲂ׂč��v�����߂�
        numA += hole[k];
        numB += hole[k+7];
    }
    if ( numA == 0 || numB == 0 ) { return true; }    // �ǂ��炩��0�Ȃ�I��

    return false;

}
//========================�{�̏���=========================
int main(void) {
    printf("mancala START\n");

    while ( 1 ) {
        //-- ���
        while (1) {
            show();
            printf("���̃^�[��\n");
            if ( move(input(1,6,0)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }    // �I������������
        //-- ���
        while (1) {
            show();
            printf("���̃^�[��\n");
            if ( move(input(1,6,7)) && ! end()) { continue; }
            break;
        }
        if ( end() ) { break; }    // �I������������
    }

    show();

    return 0;

}
