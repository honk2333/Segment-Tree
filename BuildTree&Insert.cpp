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

int BulidTree(Bitree& T)
{
    if(T){
        printf("The tree has already been built\n");
        return 0;
    }
    int n;
    printf("How many numbers to input?\n");
    scanf("%d", &n);
    printf("Please input the 1th Node\n");
    Type e;
    scanf("%d", &e);
    Initree(T, e);  //创建头节点
    for(int i = 2; i <= n; i++) {
        printf("Please input the %d th Node\n", i);
        scanf("%d", &e);
        if(Insert(e, T)==0) i--;
    }
    return 1;
}

int Insert(Type e, Bitree& T) {
    Bitree p;
    if (!Search(T, e, p)) {
        Bitree s ;
        s = (BitNode*)malloc(sizeof(BitNode));
        s -> data = e;
        s -> lchild = s -> rchild = NULL;
        s -> prior = s -> next = NULL;
        if (! p) {
            T = s;
        } else if (e < p -> data) {
            p -> lchild = s;
        } else {
            p -> rchild = s;
        }
        return 1;
    } else {
        printf("The number has been existed\n");
        getchar();
        return 0;
    }
}

int TreeDepth(Bitree T) {
    if (!T)
        return 0;
    int u = TreeDepth(T->lchild);
    int v = TreeDepth(T->rchild);
    if (u > v)
        return (u + 1);
    else
        return (v + 1);
}
