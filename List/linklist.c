#include<stdio.h>
#include<stdlib.h>//malloc()

typedef struct ListNode{
	int val;
        struct ListNode *next;
}ListNode;
//初始化节点
ListNode * ListInit(int x){
	ListNode *node =(ListNode *)malloc(sizeof(ListNode));
        node->val=x;
        node->next=NULL;
	return node;
}
//在头节点后插入值
void ListAddAtHead(ListNode *head,int val){
	//初始化节点
	ListNode *newNode=ListInit(val);
	
	if(head->next==NULL){
		//头节点为空时，直接插到头节点后
		head->next=newNode;
		return;
	}
	else{
		//不为空时，进行变换
		newNode->next=head->next;
		head->next=newNode;
	}
}
//在链表尾部添加值
void ListAddAtTail(ListNode *head,int val){
	ListNode *newNode =ListInit(val);
	//设置哨兵指针
	ListNode *p=head;
	//遍历到尾节点
	while(p->next!=NULL){
		p=p->next;
	}
	//在尾部节点添加新节点
	p->next=newNode;
}
//链表遍历
void ListTraverse(ListNode *head){
	ListNode *p=head;
	while(p->next!=NULL){
		p=p->next;
		printf("%d  ",p->val);
	}
	printf("\n");
}
//就地逆置
void ListReverse(ListNode *head){
	if(head==NULL||head->next==NULL){}
	else{
		ListNode * pre,*p;
		pre =head->next;
		head->next=NULL;
		while(pre){
			p=pre;
			pre=pre->next;
			p->next=head->next;
			head->next=p;
		}
	}
}
/*
合并两个有序递增的链表(无头结点)，并且新开一个链表来存储，不影响后面的两个链表的使用
	输入：两个有序递增有头结点的链表
	输出：一个带有头节点的链表
*/
ListNode * UnionOrderdList(ListNode * l1,ListNode * l2){
	ListNode * preHead = (ListNode *) malloc(sizeof(ListNode)) ;
	preHead->val=-1;
	preHead->next=NULL;
	ListNode * la=l1->next;
	ListNode * lb=l2->next;
	ListNode * prev=preHead;
	while(la&&lb){
		ListNode * node = (ListNode *) malloc(sizeof(ListNode)) ;
		if(la->val<lb->val){
			node->val=la->val;
			node->next=NULL;
			prev->next=node;
			la=la->next;
		}
		else{
			node->val=lb->val;
			node->next=NULL;
			prev->next=node;
			lb=lb->next;
		}
		prev=prev->next;
	}
	prev->next=la==NULL?lb:la;//将剩下的节点添加上去
	//prev=preHead->next;
	//free(preHead);//回收preHead节点
	return preHead;
}


ListNode * CreateList(){
	int sum_node=0;
	ListNode *head=ListInit(0);
	printf("please input sum of listnode:\t");
	scanf("%d",&sum_node);
	printf("please input node:\t");
	for(sum_node;sum_node>0;sum_node--){
		int temp;
		scanf("%d",&temp);
		ListAddAtTail(head,temp);
	}
	return head;
}

int main(){
	
	ListNode * head=CreateList();
	ListNode * head1=CreateList();

	ListTraverse(head);
	ListTraverse(head1);
	ListNode * l1=UnionOrderdList(head,head1);
	ListTraverse(l1);
	ListReverse(head);
	ListTraverse(head);

	return 0;
}
