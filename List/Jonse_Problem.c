#include<stdio.h>
#include<stdlib.h>


typedef struct Jonse
{
	int code;
	struct Jonse *next;
}Jonse;

Jonse *Create(int n){
	Jonse * head,*q,*p;
	head=(Jonse *)malloc(sizeof(Jonse));
	p=head;
	for(int i=1;i<n;i++){
		p->code=i;
		q=(Jonse *)malloc(sizeof(Jonse));
		p->next=q;
		p=p->next;
	}
	p->code=n;
	p->next=head;
	return head;
}
void ShowList(Jonse * head){
	Jonse * p=head;

	do{
		printf("%4d",p->code);
		p=p->next;
	}while(p!=head);
	printf("\n");
}
//剩余n个人，第m个人出去
Jonse * JonseOut(Jonse * head,int out_num,int m){
	Jonse * p=head;
	Jonse * q=head;
	int j=0;
	if(m==1){
		while(q->next!=head){
			q=q->next;
		}
	}
	while(j<out_num){
		int i=0;
		//增加m=1的可能性
		while(i<m-1){
			q=p;
			p=p->next;
			i++;
		}
		q->next=p->next;
		printf("%4d",p->code);
		free(p);
		j++;
		p=q->next;
	}
	return p;
}
int main(){
	int n=30;
	int m=2;
	int alive_num=2;
	Jonse * head=Create(n);
	ShowList(head);
	Jonse * alive=JonseOut(head,n-alive_num,m);
	printf("\n剩下的人：\n");
	ShowList(alive);
	free(alive);
	return 0;
}
