#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct Node  
{  
    int data;//数据域，用来存放数据域；  
    struct Node *pNext;//定义一个结构体指针，指向下一次个与当前节点数据类型相同的节点；  
}NODE,*PNODE;
  //NODE等价于 struct Node; PNODE等价于struct Node *； 
  //此处用大写是为了与变量区分，可以让人容易变出是个数据类型；


 
 
 //创建一个链表
  PNODE Create_List(void)  
{  
    int len;  //存放链表的长度  
    PNODE List;     //尾节点
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//分配一个头节点  
    if(pHead==NULL)  
    {  
        printf("Memory allocation failure");  
        exit(-1);  
    }  
    else  
    {   PNODE pTail=pHead;             //只有一个节点是，头节点就是尾节点
        pHead->pNext=NULL;   
        printf("please input the length of list: ");  //需要一个指针始终指向链表的结尾  
        scanf_s("%d",&len);  
        for(int i=0;i<len;i++)  
        {  
            PNODE p=(PNODE)malloc(sizeof(NODE));    //用来申请内存的p指针
            if(p==NULL)  
            {  
                printf("Memory allocation failure");  
                exit(-1);  
            }  
            else  
            {     
                printf("please input the value of list: ");  
                scanf_s("%d",&(pTail->data));           //输入每个节点的数据  
                pTail->pNext=p;  
                p->pNext=NULL;  
                pTail=p;  
            }  
        }  
    }  
    return pHead;    
} 



 
//链表的第pos有效元素前面插入元素val，首先我们应该找到第pos个元素前面一个元素的位置；  
//当链表有3个元素时，pos=4，将不会进行插入操作  
bool Insert_List(PNODE pHead,int pos,int val)  
{  
    int i=0;  
    PNODE p=pHead;  
    while((NULL!=p)&&(i<pos-1)) //  
    {  
        p=p->pNext;  
        i++;  
    }  
    if(p==NULL||i>pos-1)  //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；  
        return false;  
  
    //程序执行到这之后，i=pos-1；p指针指向链表第pos个有效节点的前驱，即指向第pos-1节点；  
    PNODE q=(PNODE)malloc(sizeof(NODE));  
    q->data=val;  
    q->pNext=p->pNext;  
    p->pNext=q;  
}

//删除一个节点
bool Delete_List(PNODE pHead,int pos)  
{  
    int i=0;  
    PNODE p=pHead;  
    while((NULL!=p)&&(i<pos-1))  
    {  
        p=p->pNext;  
        i++;  
    }  
    if(p==NULL||i>pos-1)  //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；  
        return false;  
  
    //程序执行到这之后，i=pos-1；  
    PNODE q=p->pNext;  //q指向待删除的节点； 
    p->pNext=q->pNext; //修改链表指针指向；  
    free(q);           //释放q所指向节点的内存；  
    q=NULL;//千万不可以忘记，否则会出现野指针；  
} 

//链表有效元素的个数  
int Length_List(PNODE pHead)  
{   int len=0;  //定义变量要记得初始化；  
    PNODE p=pHead->pNext;  
    while(NULL!=p)  
    {  
        len++;  
        p=p->pNext;  
    }  
    return len;  
}  

//对链表中的元素进行排序  
void Sort_List(PNODE pHead)  
{  
    int i,j;  
    int temp;  
    int len=Length_List(pHead);  
    PNODE p,q;//指向链表第一个有效元素  
  
    for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)  
    {  
        for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)  
        {  
            //交换数据  
            if(p->data>q->data)  
            {  
                temp=p->data;  
                p->data=q->data;  
                q->data=temp;  
            }  
        }  
    }  
} 