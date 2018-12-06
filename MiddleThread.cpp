#include"threadingtree.h"

//void InThreading(Bitree &T, Bitree &pre) {
//    if(T) {
//        InThreading(T->lchild, pre);
//        if(T->prior == NULL) {
//            T->prior = pre;
//        }
//        if(pre->next == NULL) {
//            pre->next = T;
//        }
//        pre=T;
//        InThreading(T->rchild,pre);
//    }
//}

static BitNode* pre = NULL;
static BitNode* tmp;
static int tag = 1, fag = 1;
BitNode* MiddleThread(Bitree &T) {
    Bitree t = T;
    if(!t)
        return 0;
    if(t) {
//        if(pre)
//            printf("%d\t", pre->data);
        if(t->lchild != NULL) {
            MiddleThread(t->lchild);
        }
        if(pre != NULL) {
            //printf("%d-%d\n", pre->data, t->data);
            t->prior = pre;
            pre->next = t;
        }
        if(tag) {
            tag = 0;
            tmp = t;
        }
        pre = t;
        if(t->rchild != NULL) {
            MiddleThread(t->rchild);
        }
//        BitNode* pre = T;
//        InThreading(T,pre);
    }
    return tmp;
}

BitNode* CreatMiddleThread(Bitree &T) {
    pre = NULL;
    tag = 1;
    fag = 1;
    return MiddleThread(T);
}


static void Travel(Bitree T) {
    if(T != NULL) {
        printf("%d ", T->data);
        if(T->next) {
            Travel(T->next);
        }
    }
}

void Travel_middle(Bitree T) {
    printf("The middleorder sequence is\n");
    Travel(T);
    printf("\n");
}

//void Travel_middle(Bitree T) {
//    printf("The middleorder sequence is\n");
//    Bitree t = T;
//    while(t != T) {
//        while(t->prior) {
//            t = t->prior;
//        }
//        printf("%d", t->data);
//        while(t->next != NULL && t->next != T) {
//            t = t->next;
//            printf("%d", t->data);
//        }
//        t = t->rchild;
//    }
//}
