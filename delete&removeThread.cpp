#include"threadingtree.h"

int Delete(Bitree T, Bitree& Thrt) {
    Type e;
    printf("Please input a number to be deleted\n");
    scanf("%d", &e);
    if(Delete_x(e, T) == 1) {    //元素删除后树中元素的线索被打乱，需要重新建立线索树
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


int DeleteNode(Bitree T, Bitree& p) {  //在二叉排序树中删除节点
    Bitree parent;
    int pos = FindParent(T, parent, p);
    if(!p->lchild && !p->rchild) {   //要删除的节点是叶子节点，直接释放空间
        //printf("%d\n",parent->data);
        //parent->next=p->next;
        if(pos == 1) { //要删除的节点是父节点的左儿子
            parent->lchild = NULL;
        } else
            parent->rchild = NULL;
        free(p);
    } else if(!p->lchild && p->rchild) { //要删除节点不存在左孩子
        //将要删除节点的右孩子移到要删除节点的位置
        Bitree tmpl = p->rchild->lchild, tmpr = p->rchild->rchild;
        p->data = p->rchild->data;
        p->lchild = tmpl;   //将右儿子的左右子树重接
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
    } else { //两个孩子都有
        Bitree tmp = p, s = p->lchild;
        while(s->rchild) {        //选择左子树中的最右边的节点
            tmp = s;
            s = s->rchild;
        }
        p->data = s->data;
        if(tmp != p) {            // 判断是否执行上述while循环
            tmp->rchild = s->lchild;       //执行了上述循环，重接右子树
        } else {
            tmp->lchild = s->lchild;       //未执行上述循环，重接左子树
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

int RemoveThread(Bitree& T) { //去线索化
    if(T != NULL) {
        T->next = T->prior = NULL;
        RemoveThread(T->lchild);
        RemoveThread(T->rchild);
    }
    return 1;
}
