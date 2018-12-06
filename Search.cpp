#include "threadingtree.h"

int Search(Bitree T, Type x, Bitree& Childtree) {
    while (T) {
        if (x == T->data) {
            Childtree = T;
            return 1;
        } else if (x < T->data) {
            Childtree = T;
            T = T->lchild;
        } else {
            Childtree = T;
            T = T->rchild;
        }
    }
    return 0;
}

int FindParentOfX(Bitree T, Bitree& parent) {
    printf("Input a number,and we will find its parent and relatively position\n");
    Type x;
    scanf("%d", &x);
    Bitree child;
    if(Search(T, x, child)) {
        int pos = FindParent(T, parent, child);
        if(pos == 0) {
            printf("The root number doesn't have parent\n");
            return 0;
        }
        if(pos == 1)
            printf("The number input is in the left tree of %d\n", parent->data);
        else
            printf("The number input is in the right tree of %d\n", parent->data);
        return 1;
    } else
        printf("The number is not existed\n");
    return 0;
}
int FindParent(Bitree T, Bitree& parent, BitNode *s) {  //在二叉排序树中查找节点的父亲节点
    BitNode *pre = NULL;
//    while(T != s && T != NULL) {
//        pre = T;
//        T = T->lchild;
//    }
//    while(T != s && T != NULL) {
//        pre = T;
//        T = T->rchild;
//    }
    //printf("%d\n", T->data);
    //printf("%d\n",s->data);

    if(T->data == s->data)
        return 0;   //根节点不存在父亲节点
    while(T->data != s->data && T != NULL) {
        if(T->data < s->data) {
            pre = T;
            T = T->rchild;
        } else {
            pre = T;
            T = T->lchild;
        }
    }
    if(T != NULL) {
        parent = pre;
        //printf("%d", pre->data);
        if(parent->lchild == s)
            return 1;
        if(parent->rchild == s)
            return 2;
    }
    return 0;
}

int FindPriorAndNext(Bitree T, Type &priorelem, Type &nextelem) {   //利用线索寻找某种元素进行遍历时的前驱和后继
                                                                      //将元素的前驱和后继存放在priorelem与nextelem中
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
