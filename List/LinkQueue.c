#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
	int val;
    struct ListNode *next;
}ListNode;

ListNode *Enqueue(ListNode * rear,int x){
	ListNode * p=(ListNode *)malloc(sizeof(ListNode));
	p->val=x;
	if(rear==NULL){
		rear=p;
		rear->next=p;
	}
	else{
		p->next=rear->next;
		rear->next=p;
		rear=p;
	}
	return rear;
}

int Dequeue(ListNode *rear){
	if (rear==NULL) {printf("error"); return 0;}
	else{
		ListNode * p;
		p=rear->next;
		int temp;
		if(p==rear){
			temp=p->val;
			free(rear);
			rear=NULL;
			printf("test");
		}
		else{
			rear->next=p->next;
			temp=p->val;
			free(p);	
		}
		
		return temp;
	}
}

int main(){
	ListNode *rear;
	rear=NULL;
	rear=Enqueue(rear,1);
	rear=Enqueue(rear,2);
	rear=Enqueue(rear,13);
	printf("%d  ",Dequeue(rear));
	printf("%d  ",Dequeue(rear));
	printf("%d  ",Dequeue(rear));
	printf("%d  ",Dequeue( rear));
	printf("%d  ",Dequeue( rear));
	return 0;
}