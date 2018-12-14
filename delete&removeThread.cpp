#include"threadingtree.h"

int Delete(Bitree T, Bitree& Thrt) {
    Type e;
    printf("Please input a number to be deleted\n");
    scanf("%d", &e);
    if(Delete_x(e, T) == 1) {    //Ԫ��ɾ��������Ԫ�ص����������ң���Ҫ���½���������
        printf("The number input has been deleted successfully\n");
        printf("1");
        RemoveThread(T);
        return 1;
    } else
        printf("The number input is not existed\n");
    return 0;
}

int DeleteNode(Bitree T, Bitree& p) {  //�ڶ�����������ɾ���ڵ�
    Bitree parent;
    int pos = FindParent(T, parent, p);
    if(!p->lchild && !p->rchild) {   //Ҫɾ���Ľڵ���Ҷ�ӽڵ㣬ֱ���ͷſռ�
        if(pos == 1) { //Ҫɾ���Ľڵ��Ǹ��ڵ�������
            parent->lchild = NULL;
        } else
            parent->rchild = NULL;
        free(p);
    } else if(!p->lchild && p->rchild) { //Ҫɾ���ڵ㲻��������
        //��Ҫɾ���ڵ���Һ����Ƶ�Ҫɾ���ڵ��λ��
        Bitree tem = p->rchild;
        Bitree tmpl = p->rchild->lchild, tmpr = p->rchild->rchild;
        p->data = p->rchild->data;
        p->lchild = tmpl;   //���Ҷ��ӵ����������ؽ�
        p->rchild = tmpr;
        free(tem);
    } else if(!p->rchild && p->lchild) {
        Bitree tem = p->lchild;
        Bitree tmpl = p->lchild->lchild, tmpr = p->lchild->rchild;
        p->data = p->lchild->data;
        p->lchild = tmpl;
        p->rchild = tmpr;
        free(tem);
    } else { //�������Ӷ���
        Bitree tmp = p, s = p->lchild;
        while(s->rchild) {        //ѡ���������е����ұߵĽڵ�
            tmp = s;
            s = s->rchild;
        }
        p->data = s->data;
        if(tmp != p) {            // �ж��Ƿ�ִ������whileѭ��
            tmp->rchild = s->lchild;       //ִ��������ѭ�����ؽ�������
        } else {
            tmp->lchild = s->lchild;       //δִ������ѭ�����ؽ�������
        }
        free(s);
    }
    return 1;
}

int Delete_x(Type x, Bitree T) {
    Bitree child;
    Search(T, x, child);
    DeleteNode(T, child);
    return 1;
}

int RemoveThread(Bitree& T) { //ȥ������
    if(T != NULL) {
        T->next = T->prior = NULL;
        RemoveThread(T->lchild);
        RemoveThread(T->rchild);
    }
    return 1;
}
int Destory(Bitree& T) { //�ͷ���
    BitNode* root = T;
    if(T != NULL) {
        Destory(T->lchild);//�ݹ�
        Destory(T->rchild);//�ݹ�
        T->lchild = T->rchild = NULL;
        T->next = T->prior = NULL;
        T=NULL;
        free(root); //�������ӽ�㶼Ϊ��ʱ������free,�ͷſռ�
    }
    return 1;
}
