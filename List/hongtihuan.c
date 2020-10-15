#include<stdio.h>

#define PRIN_INT(i)      \
printf("%8s():&%-5s=0x%-6x,%-5s=0x%-6x\n",__FUNCTION__,#i,&(i),#i,i)
/*
宏替换
#define 标识符(替换元素)  替换列表
注：
	用 #元素  来使用已经宏替换的元素
	标识符与（替换元素）  这里不能有空格
	宏替换一般在第一个行换符结束
		如果替换列表过长，可以用  “\”  来表示下一行继续
*/
int main()
{
	int iNum1,iNum2,temp;
	iNum1=12;
	iNum2=9;
	PRIN_INT(iNum1);
	PRIN_INT(iNum2);
	temp=iNum1;
	iNum1=iNum2;
	iNum2=temp;
	PRIN_INT(iNum1);
	PRIN_INT(iNum2);
	return 0;
}