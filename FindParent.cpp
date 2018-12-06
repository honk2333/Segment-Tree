#include"threadingtree.h"

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
