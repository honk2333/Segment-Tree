#include"threadingtree.h"
int BulidTree(Bitree& T)
{
    int n;
    printf("How many numbers to input?\n");
    scanf("%d", &n);
    printf("Please input the root Node\n");
    Type e;
    scanf("%d", &e);
    Initree(T, e);  //创建头节点
    for(int i = 2; i <= n; i++) {
        printf("Please input %d th Node\n", i);
        scanf("%d", &e);
        Insert(e, T);
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
        return true;
    } else {
        printf("The number has been existed\n");
        return false;
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
