#include<stdio.h>

#define STACKSIZE 100

typedef struct BothStack{
	int data[STACKSIZE];
	int top1;
	int top2;

}BothStack;
//值传递。。。。
void InitBothStack(BothStack *S){
	S->top1=-1;
	S->top2=STACKSIZE;
}

void PuschBothStack(BothStack *S,int i, int intnumber){
	if(S->top1+1==S->top2) {}//判断是否满栈
	else{
		if(i==1){
			S->top1=S->top1+1;
			S->data[S->top1]=intnumber;
		}
		else{
			S->top2=S->top2-1;
			S->data[S->top2]=intnumber;
		}
	}
}

int PopBothStack(BothStack *S, int i)
{
	if(i==1&&S->top1>=0){
		int temp=S->data[S->top1];
		S->top1=S->top1-1;
		return temp;
	}
	else if(i==2&&(S->top2<STACKSIZE)){
		int temp=S->data[S->top2];
		S->top2=S->top2+1;
		return temp;
	}
	return 0;
}

int main(){
	BothStack S;
	InitBothStack(&S);
	printf("Hello\n");
	PuschBothStack(&S,1,10);
	printf("%d ",S.top1);
	printf("Hello\n");
	PuschBothStack(&S,1,11);
	PuschBothStack(&S,1,12);
	PuschBothStack(&S,1,13);


	PuschBothStack(&S,2,14);
	PuschBothStack(&S,2,15);
	PuschBothStack(&S,2,16);
	PuschBothStack(&S,2,17);
	printf("%d ",PopBothStack(&S,1));
	printf("%d ",PopBothStack(&S,1));
	printf("%d ",PopBothStack(&S,1));

	printf("%d ",PopBothStack(&S,2));

	printf("%d ",PopBothStack(&S,1));
printf("%d ",PopBothStack(&S,1));
	printf("%d ",PopBothStack(&S,2));
	printf("%d ",PopBothStack(&S,2));
	printf("%d ",PopBothStack(&S,2));
}