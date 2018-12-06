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
