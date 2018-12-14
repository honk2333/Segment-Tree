#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>


typedef int Type;
typedef struct BitNode {
    Type data; //结点数据
    struct BitNode *lchild, *rchild, *prior, *next; //左右孩子指针以及前驱后继指针
} BitNode, *Bitree;

int Initree(Bitree& T, Type e);
int BulidTree(Bitree& T);
int Destory(Bitree& T);
int Search(Bitree T, Type x, Bitree& Childtree);
int Deepth(Bitree T, Type x);
int TreeDepth(Bitree T);
int Insert(Type e, Bitree& T);
int Delete(Bitree T, Bitree& Thrt);
int Delete_x(Type x, Bitree T);
int DeleteNode(Bitree T, Bitree& p);
int CreatpriorThread(Bitree &T);
Bitree CreatMiddleThread(Bitree &T);
Bitree CreatPostThread(Bitree &T);
int RemoveThread(Bitree& T);
void Travel_prior(Bitree T);
void Travel_middle(Bitree T);
void Travel_post(Bitree T);
int FindPriorAndNext(Bitree T, Type &priorelem, Type &nextelem);
int FindParent(Bitree T, Bitree& parent, BitNode *s);
int FindParentOfX(Bitree T, Bitree& parent);
