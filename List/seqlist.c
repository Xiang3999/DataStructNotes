#include <stdio.h>
#include <stdlib.h>  //malloc()、exit()
#define MaxSize 8
typedef struct Table {
    int * head;
    int length;
    int size;
}table;
table initTable() {
    table t;
    t.head = (int*)malloc(MaxSize * sizeof(int));
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = MaxSize;
    return t;
}
//输出顺序表中元素的函数
void displayTable(table t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}

void Reverse(table L){
	int n=L.length-1;
	int i=0;
	int temp;
	while(i<n){
		temp=L.head[n];
		L.head[n--]=L.head[i];
		L.head[i++]=temp;
	}
}
void Insert(table L,int x,int * len){
	if(L.length>=MaxSize){}
	else{
		int i=0;
		//L.length++;//L.length 这里是形参，并不能改变他的值！！！！！！
		*len=*len+1;
		while(i<L.length&&L.head[i]<x) i++;

		for(int j=L.length;j>i;j--){
			L.head[j]=L.head[j-1];
			}
		L.head[i]=x;
	}
}
void Interest(table A,table B, table C){
	int k=0;
	for(int i=0;i<A.length;i++){
		int j=0;
		while(j<B.length){
			if(A.head[i]==B.head[j])
				break;
			j++;
		}
		if(j<B.length){
			C.head[k]=A.head[i];
			k++;
		}
	}
}
int main() {
    int i;
    table t = initTable();
    //向顺序表中添加元素
    for (i = 1; i <= MaxSize-3; i++) {
        t.head[i - 1] = i;
        t.length++;
    }
    table t1=initTable();
    for (i = 1; i <= MaxSize-5; i++) {
        t1.head[i - 1] = i+1;
        t1.length++;
    }
    table t2=initTable();
    displayTable(t);
    displayTable(t1);
    Interest(t,t1,t2);
    //Insert(t,3,&t.length);
    //t.length++;
    t2.length=5;
    displayTable(t2);
    //Reverse(t);
    //displayTable(t);
    return 0;
}