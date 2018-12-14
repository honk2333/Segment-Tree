#include"threadingtree.h"

static BitNode* pre = NULL;
static BitNode* tmp;
static int tag = 1;
BitNode* MiddleThread(Bitree &T) {
    Bitree t = T;
    if(!t)
        return 0;
    if(t) {
        if(t->lchild != NULL) {
            MiddleThread(t->lchild);
        }
        if(pre != NULL) {
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
    }
    return tmp;
}

BitNode* CreatMiddleThread(Bitree &T) {
    pre = NULL;
    tag = 1;
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
