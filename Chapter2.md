1. **线性表**是具有多个数据元素的有限序列，不同的线性表的数据元素的形式可能不同，顺序线性表在数据逻辑结构和存储结构上都是相邻的，而链式线性表在数据逻辑上是相邻的，并且通过指针来体现数据的逻辑结构，但是数据的存储结构上是分散的，这也使得前者在数据读取上是随机读取的，而后者在数据读取上是顺序读取的。

2. 利用线性表实现集合间的并操作：
```C
void Union(List &La,List Lb){
    //将链表b中不在链表a中出现的元素插入到链表a中
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    for(int i=0;i<lb_len;i++){
        //获取链表b的当前位置元素
        GetElem(Lb,i,e);

        //判断是否在a中存在，若不存在则添加到链表a
        if(!LocateElem(La,e,equal)){
            ListInsert(La,La_len++,e);
        }
    }
}
```

2. 利用线性表实现两有序链表的合并
```c
void MergeList(List La,List Lb,List &Lc){
    
    //将有序的链表La，Lb合并成链表Lc，仍然保持两边的有序性
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    InitList(Lc);
    int i=1;    int j=1;    int k=0;
    
    //当两个量表都不为空的时候
    while((i<= la_len) && (j <= lb_len)){
        GetElem(La,i,ia);
        GetElem(Lb,j,ib);
        if(ia <= ib){
            ListInsert(Lc,k++,ia);  i++;
        }else(
            ListInsert(Lc,k++,ib);  j++;
        )
    }

    //还有元素没有处理完
    while(i<= la_len){
        GetElem(La,i,ia);
        ListInsert(Lc,k++,ia);  i++;
    }
    
    while(j <= lb_len){
         GetElem(Lb,j,ib);
         ListInsert(Lc,k++,ib);  j++;
    }

}
```

3. 线性表的顺序存储结构
```c
#define LIST_INIT_SIZE 100
#define LSITINCREMENT 10

typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

```

4. 顺序线性表的初始化
```C
Status InitList_Sq(Sq_List &L){
    //申请内存空间
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));

    //判断是否申请成功
    if(NULL == L.elem){
        exit(OVERFLOW);
    }

    L.length = 0;
    L.size = LIST_INIT_SIZE;

    return OK;
}
```

5. 顺序线性表插入元素
```C
Status ListInsert(Sq_List &L,int index ,ElemType e){

    if(index<1||index > L.length+1){
        return ERROR;
    }

    if(L.length >=  L.listsize){
        newbase = (ElemType *)realloc( (L.listsize+LSITINCREMENT)*sizeof(ElemType));
        //判断是否申请成功
        if(NULL == newbase){
            exit(OVERFLOW);
        }
        
        L.elem = newbase;
        L.listsize += LSITINCREMENT;
    }

    q = &(L.elem[i-1]);

    for(p = &(L.elem[L.length-1];p>q;p--){
        *(p+1)=*p;
    }

    *q = e;
    L.length++;

    return OK;
}
```

6. 顺序线性表删除一个元素
```C
Status ListDelete_Sq(Sq_List &L,int index ,ElemType &e){
    //在顺序线性表中删除第i各元素，并返回值e
    if(index<1 || i>L.length){
        return ERROR;
    }

    ElemType* p = &(L.elem[index-1]);
    e = *p;
    int q = L.elem + L.length-1;

    for(;p<=q;p++){
        *p=*(p+1);
    }

    L.length--;

    return OK;
}
```

7. 顺序线性表查找元素出现的第一个位置
```C
int LocateEle(Sq_list L,ElemType e,Status (*compare)(ElemType,ElemType)){
    int i=1;
    ElemType *p = L.elem;

    while(i<= L.length && !(*compare)(*p++,e)){
        i++;
    }

    if(i>L.length){
        return NOTFOUND;
    }else{
        return i;
    }
}
```
===

8. 链式线性表的结点结构
```C
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;
//声明第零个结点为岗哨结点，不存储数据
```

9. 链式线性表取某个位置上的元素
```C
Status GetElem_L(LinkList L,int index,ElemType &e){
    LinkList p = L->next;
    int j=1;

    while(p && j<index){
        p = p->next;
        j++;
    }

    if(!p || j >index){
        return NOTFOUD;
    }

    e = p->data;
    
    return OK;
}
```

10. 链式线性表插入元素
```C
Status ListInsert_L(LinkList &L,int index,ElemType e){
    //第index位置之前插入元素
    LinkList p = L->next;
    int j=1;

    while(p && j<index){
        p = p->next;
        j++;
    }

    if(!p || j >index){
        return ERROR;
    }
    
    LinkList s = (LinkList)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}
```

11. 链式线性表删除元素
```C
Status ListDelet_L(LinkList &L,int index,ElemType &e){
    LinkList p = L->next;
    int j=1;

    while(p && j<index){
        p = p->next;
        j++;
    }

    if(!p || j >index){
        return ERROR;
    }
    
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);

    return OK;
}
```

12. 链式线性表的创建
```C
Status CreateList_L(LinkList &L,int n){
    LinkLsit L=(LinkLsit)malloc(sizeof(LNode));
    L->next = NULL;

    for(int i=0;i<n;i++){
        LinkLsit p = (LinkLsit)malloc(sizeof(LNode));
        if(p == NULL){
            return OVERFLOW;
        }
        scanf(&p->data);
        p->next = L->next;
        L->next =p;     
    }
    
    return OK;
}
```

13. 链式线性表实现两有序链表的合并
```C
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
    pa = La ->next;
    pb = Lb ->next;
    pc = Lc = La;   //Lc头结点没有动态申请了

    while(pa && pb){
        if(pa->data >= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;        
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa:pb;

    free(Lb);
}
```

14. 利用链表实现一元多项式的加法
```C
void AddPolyn(polynomial &Pa,polinomial &Pb){
    ha = GetHead(Pa);
    hb = GetHead(Pb);
    qa = NextPos(Pa,ha);
    qb = NextPos(Pb,hb);

    while(qa && qb){
        a = GetElem(qa);
        b = GetElem(qb);

        swith( *cmp(a,b)){
            case -1:
                ha = qa;
                qa = NextPos(Pa,ha);
                break;
            case 0:
                sum = a.cof + b.cof;
                if(sum != 0){
                    SetCurElem(qa,sum);
                    ha = qa;
                }else{
                    DelFirst(ha,qa);
                    Free(qa);
                    DelFirst(hb,qb);
                    Free(qb);
                    qa = NextPos(Pa,ha);
                    qb = NextPos(Pb,hb);
                    break;
                }
            case 1:
                DelFirst(hb,qb);
                InsFirst(ha,qb);
                qa = NextPos(Pa,ha);
                qb = NextPos(Pb,hb);
                break;
        }

    }

    if(!Empty(qb)){
        Append(Pa,qb);
    }

    FreeNode(hb);
}
```


