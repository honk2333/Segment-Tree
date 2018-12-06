#include"threadingtree.h"
using namespace std;

int main() {
    Bitree T;
    int step1 = BulidTree(T);
    if(step1 == 1)
        printf("The Bitree has been built now\n");

    int depth = TreeDepth(T);
    printf("The tree's depth is %d\n", depth);

    Bitree Thrt = T; //��������ȫ����������,Thrt��Ϊ������������ͷ�ڵ�
    CreatpriorThread(T);
    Travel_prior(T);
    RemoveThread(T); //ȥ������

    Thrt = CreatPostThread(T);   //��������ȫ����������,Thrt��Ϊ������������ͷ�ڵ�
    Travel_post(Thrt);
    RemoveThread(T);

    Thrt = CreatMiddleThread(T); //��������ȫ����������,Thrt��Ϊ������������ͷ�ڵ�
    Travel_middle(Thrt);

    Type x, y;
    FindPriorAndNext(Thrt, x, y);    //����Ԫ�ص�ǰ���ͺ��

    Bitree parent = NULL;
    FindParentOfX(T, parent);             //�������������Ѱ��Ԫ�صĸ��׽ڵ㲢�õ���Ӧλ��

    Delete(T, Thrt);          //ɾ��һ���ڵ�
    Travel_middle(Thrt);


    RemoveThread(T);
    Destory(T);

    return 0;
}
