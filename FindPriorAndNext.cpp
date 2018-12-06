#include"threadingtree.h"

int FindPriorAndNext(Bitree T, Type &priorelem, Type &nextelem) {   //��������Ѱ��ĳ��Ԫ�ؽ��б���ʱ��ǰ���ͺ��
                                                                      //��Ԫ�ص�ǰ���ͺ�̴����priorelem��nextelem��
    Bitree B = T;
    printf("please input a number to be searched and print its prior and next:\n");
    Type e;
    scanf("%d", &e);
    while(B != NULL) {
        if(B->data == e) {
            if(B->prior == NULL) {
                nextelem = B->next->data;
                printf("The next element of %d is %d.\nand its prior element is not exist\n", e, nextelem);
                return 2;
            } else if(B->next == NULL) {
                priorelem = B->prior->data;
                printf("The prior element of %d is %d.\nand its next element is not exist\n", e, priorelem);
                return 3;
            } else {
                priorelem = B->prior->data;
                nextelem = B->next->data;
                printf("The prior element of %d is %d.\nand its next element is %d\n", e, priorelem, nextelem);
                return 1;
            }
        }
        B = B->next;
    }
    return 0;
}
