#include"threadingtree.h"

static BitNode* pre = NULL;
static BitNode* tmp;
static int tag = 1;
BitNode* PostThread(Bitree &T) {
    if(!T) {
        return 0;
    }
    if(T) {
        //printf("^%d", T->data);
        //if(pre!=NULL) printf("$%d",pre->data);
        if(T->lchild) {
            PostThread(T->lchild);
        }
        if(T->rchild) {
            PostThread(T->rchild);
        }
        if(pre != NULL) {
            pre->next = T;
            T->prior = pre;
        }
        if(tag && pre == NULL) {
            tag = 0;
            tmp = T;
        }
        pre = T;
        //pre->next=NULL;
    }
    return tmp;
}

BitNode* CreatPostThread(Bitree &T) {
    pre = NULL;
    tag = 1;
    return PostThread(T);
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
