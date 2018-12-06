#include"threadingtree.h"
using namespace std;

int main() {
    Bitree T;
    int step1 = BulidTree(T);
    if(step1 == 1)
        printf("The Bitree has been built now\n");

    int depth = TreeDepth(T);
    printf("The tree's depth is %d\n", depth);

    Bitree Thrt = T; //建立先序全线索二叉树,Thrt作为线索二叉树的头节点
    CreatpriorThread(T);
    Travel_prior(T);
    RemoveThread(T); //去除线索

    Thrt = CreatPostThread(T);   //建立后序全线索二叉树,Thrt作为线索二叉树的头节点
    Travel_post(Thrt);
    RemoveThread(T);

    Thrt = CreatMiddleThread(T); //建立中序全线索二叉树,Thrt作为线索二叉树的头节点
    Travel_middle(Thrt);

    Type x, y;
    FindPriorAndNext(Thrt, x, y);    //查找元素的前驱和后继

    Bitree parent = NULL;
    FindParentOfX(T, parent);             //在排序二叉树中寻找元素的父亲节点并得到相应位置

    Delete(T, Thrt);          //删除一个节点
    Travel_middle(Thrt);


    RemoveThread(T);
    Destory(T);

    return 0;
}
