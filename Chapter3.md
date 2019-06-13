1. 从数据结构的角度看，栈和队列属于线性表，但是其由于存取受到的限制，故称为受限的线性表

2. **栈（stack）**指限定在表尾进行插入或删除操作的线性表。相应的表尾称为栈顶（top），表头称为栈底（bottom），由栈的读取特性可知栈是一种先进后出的数据结构（FILO）

3. 栈与线性表一样，具有顺序存储结构和链式存储结构，顺序栈是利用一组地址连续的存储单元依次存放栈底到栈顶的数据。对于栈的大小一种合理的想法是先为栈分配一个初始大小，当栈满时再**逐段扩大**栈的大小。

4. 栈的顺序存储实现
```C
#define STACK_INIT_SIZE 100
#define STACK_INCRESENT_SIZE 10
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;
```

5. 栈的初始化操作
```C
Status InitStack(SqStack &S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base){
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
```

6. 获取栈顶元素
```C
Status GetTop(SqStack S,SElemType &e){
    if(S.top == S.base){
        return ERROR;
    }

    e = * (--S.top);
    return OK;
}
```

7. 入栈操作
```C
Status Push(SqStack &S,SElemType e){
    if(S.top - S.base >= s.stacksize){
        S.base  = (SElemType*)realloc(S.base,(S.stacksize+STACK_INCRESENT_SIZE)*sizeof(SElemType));

        if(!S.base){
            exit(OVERFLOW);
        }
        
        S.top  = S.base + S.stacksize;
        S.stacksize += STACK_INCRESENT_SIZE;
    }

    S.top++ = e;
    return OK;
}

```

8. 出栈操作
```C

Status Pop(SqStack &S,SElemType &e){
    if(S.base == S.top){
        return ERROR;
    }
    e = *(--S.top);
    return OK;
}
```

```C

```

```C

```

```C

```

```C

```

```C

```

```C

```

```C

```

```C

```
