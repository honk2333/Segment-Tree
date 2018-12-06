#include"threadingtree.h"

int Initree(Bitree &T, Type e) { //创建树
    Bitree Root = (BitNode*)malloc(sizeof(BitNode)); //申请空间
    if(!Root) {
        return 0;
    }
    Root->data = e;
    Root->lchild = NULL;
    Root->rchild = NULL;
    Root->prior = NULL;
    Root->next = NULL;
    T = Root;
    return 1;
}

int Destory(Bitree& T) { //释放树
    BitNode* root = T;
    if(T != NULL) {
        Destory(T->lchild);//递归
        Destory(T->rchild);//递归
        free(root); //当左右子结点都为空时，调用free,释放空间
    }
    return 1;
}
static Bitree pre = NULL; //记录上一个位置
int CreatpriorThread(Bitree &T) { //先序线索化
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
            CreatpriorThread(T->lchild);   //递归
        }
        if(T->rchild) {
            CreatpriorThread(T->rchild);   //递归
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
