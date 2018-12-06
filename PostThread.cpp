#include"threadingtree.h"

static BitNode* pre = NULL;
static BitNode* tmp;
static int tag = 1,fag=1;
BitNode* CreatPostThread(Bitree &T) {
     if(fag){
        pre=NULL;
        fag=0;
    }
    if(!T) {
        return 0;
    }
    if(T) {
        if(T->lchild) {
            CreatPostThread(T->lchild);
        }
        if(T->rchild) {
            CreatPostThread(T->rchild);
        }
        if(pre != NULL) {
            pre->next = T;
            T->prior = pre;
        }
        if(tag) {
            tag = 0;
            tmp = T;
        }
        pre = T;
    }
    return tmp;
}

static void Travel(Bitree T) {
    if(T != NULL) {
        printf("%d ", T->data);
        if(T->next) {
            Travel(T->next);
        }
    }
}

void Travel_post(Bitree T) {
    printf("The postorder sequence is\n");
    Travel(T);
    printf("\n");
}
