
#include <stdlib.h>
#include<stdio.h>


#define M 4
#define N 4
int minn[M],maxx[N];
void MinMax(int A[M][N])///M行中最小，N列中最大
{
    int i,j;
    int have=0;
    for(i=0; i<M; i++) ///求出每行最小数，存在minn[0,,,M-1]中
    {
        minn[i]=A[i][0];
        for(j=1; j<N; j++)
            if(minn[i]>A[i][j])
                minn[i]=A[i][j];
    }
    for(j=0; j<N; j++) ///求出每列最大数，存在maxx[0,,,N-1]中
    {
        maxx[j]=A[0][j];
        for(i=1; i<M; i++)
            if(maxx[j]<A[i][j])
                maxx[j]=A[i][j];
    }
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            if(minn[i]==maxx[j])///找到马鞍点
            {
                printf("A[%d][%d]=%d",i,j,A[i][j]);
                have=1;
            }
    if(!have)
        printf("没有马鞍点\n");
}
void Andian(int A[M][N])
{
	int j;
	for(int i=0;i<N;i++){
		int d=A[i][0];
		int k=0;
		for(j=1;j<M;j++){
			if(A[i][j]<d){
				d=A[i][j];
				k=j;
			}
		}
		for(j=0;j<N;j++){
			if(A[j][k]>d) break;
		}
		if(j==N) printf("maandian shi %d \n",A[i][k]);
	}
}
int main()
{
    int A[M][N]= {{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}};
    printf("A矩阵:\n");
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
            printf("%4d",A[i][j]);
        printf("\n");
    }
    printf("矩阵中的马鞍点：\n");
    MinMax(A);

    printf("\n");
    Andian(A);
    printf("输出每行中最小的数\n");
    for(int i=0; i<M; i++)
        printf("%4d",minn[i]);
    printf("\n");
    printf("输出每列中最大的数\n");
    for(int i=0; i<N; i++)
        printf("%4d",maxx[i]);
    printf("\n");
    return 0;
}