#include"threadingtree.h"

int Delete(Bitree T, Bitree& Thrt) {
    Type e;
    printf("Please input a number to be deleted\n");
    scanf("%d", &e);
    if(Delete_x(e, T) == 1) {    //Ԫ��ɾ��������Ԫ�ص����������ң���Ҫ���½���������
        printf("The number input has been deleted successfully\n");
        //printf("%d\n", T->data);
        RemoveThread(T);

//        Bitree c;
//        Search(T, 6, c);
//        if(c->lchild||c->rchild) {
//            printf("1");
//        }
//        //Travel_middle(Thrt);
        //printf("%d\n", T->data);

        Thrt = CreatMiddleThread(T);

        //printf("%d", Thrt->data);
        //Travel_middle(Thrt);

//        Search(T, 6, c);
//        if(c->next) {
//            printf("%d", c->next->data);
//        }
        return 1;
    } else
        printf("The number input is not existed\n");
    return 0;
}


int DeleteNode(Bitree T, Bitree& p) {  //�ڶ�����������ɾ���ڵ�
    Bitree parent;
    int pos = FindParent(T, parent, p);
    if(!p->lchild && !p->rchild) {   //Ҫɾ���Ľڵ���Ҷ�ӽڵ㣬ֱ���ͷſռ�
        //printf("%d\n",parent->data);
        //parent->next=p->next;
        if(pos == 1) { //Ҫɾ���Ľڵ��Ǹ��ڵ�������
            parent->lchild = NULL;
        } else
            parent->rchild = NULL;
        free(p);
    } else if(!p->lchild && p->rchild) { //Ҫɾ���ڵ㲻��������
        //��Ҫɾ���ڵ���Һ����Ƶ�Ҫɾ���ڵ��λ��
        Bitree tmpl = p->rchild->lchild, tmpr = p->rchild->rchild;
        p->data = p->rchild->data;
        p->lchild = tmpl;   //���Ҷ��ӵ����������ؽ�
        p->rchild = tmpr;
        free(p->rchild);
    } else if(!p->rchild && p->lchild) {
        Bitree tmpl = p->lchild->lchild, tmpr = p->lchild->rchild;
//        if(p->lchild->lchild == NULL && p->lchild->rchild == NULL)
//            printf("%d", p->lchild->data);
        p->data = p->lchild->data;
        p->lchild = tmpl;
        p->rchild = tmpr;
//        if(p->lchild == NULL && p->rchild == NULL)
//            printf("%d", p->lchild->data);
        free(p->lchild);
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
