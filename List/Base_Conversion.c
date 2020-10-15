#include<stdio.h>
#include<stdlib.h>


void Base_Conversion(int num,int r){
	int top,k;
	int S[100];
	top=-1;
	while(num!=0){  //商余法
		k=num%r;
		top=top+1;
		S[top]=k;
		num=num/r;
	}
	while(top!=-1){
		printf("%d  ",S[top]);
		top--;
	}
}
int  main(int argc, char const *argv[])
{
	
	int a=10;
	int b=3;
	Base_Conversion(a,b);
	return 0;
}