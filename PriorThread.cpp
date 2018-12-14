#include"threadingtree.h"

static Bitree pre = NULL; //��¼��һ��λ��
int CreatpriorThread(Bitree &T) { //����������
    if(!T) {
        return 0;
    }
    if(T) {
        if(T->lchild == NULL && T->rchild == NULL) {
            T->next = NULL;
        }
        if(pre != NULL) {
            pre->next = T;
            T->prior = pre;
        }
        pre = T;
        if(T->lchild) {
            CreatpriorThread(T->lchild);   //�ݹ�
        }
        if(T->rchild) {
            CreatpriorThread(T->rchild);   //�ݹ�
        }
    }
    return 1;
}

static void Travel(Bitree T) {
    if(T != NULL) {
        printf("%d ", T->data);
        if(T->next) {
            Travel(T->next);
        }
    }

}

void Travel_prior(Bitree T) {
    printf("The preorder sequence is\n");
    Travel(T);
    printf("\n");
}
