#include<stdio.h>
#include<stdlib.h>

int front=0,rear=0;

typedef struct BiNode{
	int val;
	struct BiNode * rchild;
	struct BiNode * lchild;
}BiNode;

//人工创建二叉树
void CreateTree(BiNode **T)  //传入一个Btree的指针的地址
{
    int  data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (BiNode *)malloc(sizeof(struct BiNode));  
        (*T)->val = data;
        printf("Please input %d lchild:", data);
        CreateTree(&((*T)->lchild));
        printf("Please input %d rchild:", data);
        CreateTree(&((*T)->rchild));
    }
}
/*
此二叉树形状
                1
			2		3
		  4	  5   6   7	
*/
void CreateTreeAuto(BiNode **T){
    *T=(BiNode*)malloc(sizeof(BiNode));
    (*T)->val=1;
    (*T)->lchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->rchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->lchild->val=2;
    (*T)->lchild->lchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->lchild->rchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->lchild->rchild->val=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=NULL;
    (*T)->rchild->val=3;
    (*T)->rchild->lchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->rchild->lchild->val=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiNode*)malloc(sizeof(BiNode));
    (*T)->rchild->rchild->val=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->val=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
}
// 回收内存
void distroyTree(BiNode **T)
{
    BiNode *pl, *pr;
    if((*T) == NULL) {
        return ;
    } else {
        pl = (*T)->lchild;  //保存左孩子的地址
        pr = (*T)->rchild;  //保存右孩子的地址
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        free(*T);   //释放根节点
        (*T) = NULL;
        distroyTree(&pl);   //递归销毁
        distroyTree(&pr);
    }
}
///////////////////////////////////////////////////////////
// 前序遍历
void Traverse_PreOrder(BiNode* root) {
	if (root != NULL) {
		printf("%d ", root->val);
		Traverse_PreOrder(root->lchild);
		Traverse_PreOrder(root->rchild);
	}
}

/*
非递归前序遍历
对于任一结点P：
     1)访问结点P，并将结点P入栈;
     2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当前的结点P;
     3)直到P为NULL并且栈为空，则遍历结束。
*/
void Traverse_PreOrder1(BinTree *root)     
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())//出口
    {
        while(p!=NULL)
        {
            cout<<p->data<<"";
            s.push(p);  //出栈
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}
//////////////////////////////////////////////////////////
// 中序遍历
void Traverse_InOrder(BiNode* root) {
	if (root != NULL) {
		Traverse_InOrder(root->lchild);
		printf("%d ", root->val);
		Traverse_InOrder(root->rchild);
	}
}
/*
非递归中序遍历
对于任一结点P，
  1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P再进行相同的处理；
  2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子；
  3)直到P为NULL并且栈为空则遍历结束
*/
void Traverse_InOrder1(BinTree *root)      
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data<<"";
            s.pop();
            p=p->rchild;
        }
    }    
} 
///////////////////////////////////////////////////////////
// 后序遍历
void Traverse_PostOrder(BiNode* root) {
	if (root != NULL) {
		Traverse_PostOrder(root->lchild);
		Traverse_PostOrder(root->rchild);
		printf("%d ", root->val);
	}
}


//入队函数
void EnQueue(BiNode **a,BiNode *node){
    a[rear++]=node;
}
//出队函数
BiNode* DeQueue(BiNode** a){
    return a[front++];
}
//层序遍历
void Traverse_LeverOrder(BiNode * root){
	BiNode * p;
    //采用顺序队列，初始化创建队列数组
    BiNode * a[20];
    //根结点入队
    EnQueue(a, root);
    //当队头和队尾相等时，表示队列为空
    while(front < rear) {
        //队头结点出队
        p=DeQueue(a);
        printf("%d ", p->val);
        //将队头结点的左右孩子依次入队
        if (p->lchild!=NULL) {
            EnQueue(a, p->lchild);
        }
        if (p->rchild!=NULL) {
            EnQueue(a, p->rchild);
        }
    }

}

// 求树的节点
int CountBiNode(BiNode * root){
	if(root==NULL) return 0;
	else
		return 1+CountBiNode(root->rchild)+CountBiNode(root->lchild);
}

// 求叶子节点
int CountLeaf(BiNode * root){
	if(root==NULL) return 0;
	if(root->lchild==NULL&&root->rchild==NULL)  return 1;
	else{
		return CountLeaf(root->lchild)+CountLeaf(root->rchild);
	}
}

// 求数的深度
int Depth(BiNode * root){
	if(root==NULL) return 0;
	else {
        int lenl = Depth(root->lchild);
        int lenr = Depth(root->rchild);
        return lenl > lenr ? lenl+1:lenr+1;
    }
}
// 左右子树交换
void Exchange(BiNode *root){
	if(root==NULL) return ;
	else{
		BiNode * p;
		p=root->lchild;
		root->lchild=root->rchild;
		root->rchild=p;
		Exchange(root->rchild);
		Exchange(root->lchild);
	}
}

void BSTInsert(BiNode ** root,BiNode ** node )
{
	if(*root==NULL) // 空树
	{
		*root=*node;
		return ;
	}

	if((*node)->val == (*root)->val) // BST中不能有相等的值
		printf("不能有相同值\n");
		return ;
 
	if((*node)->val < (*root)->val){  // 递归
		BSTInsert(&((*root)->lchild), (node));
	}
 	else{
 		BSTInsert(&((*root)->rchild), (node)); // 递归
 	}
}



int main(){
	BiNode * root=(BiNode *)malloc(sizeof(BiNode));
	CreateTreeAuto(&root);
	printf("前序遍历：\n");
	Traverse_PreOrder(root);
	printf("\n中序遍历：\n");
	Traverse_InOrder(root);
	printf("\n后序遍历:\n");
	Traverse_PostOrder(root);
	printf("\n层序遍历：\n");
	Traverse_LeverOrder(root);
	printf("\n求叶子节点：");
	printf("\t%d\n",CountLeaf(root));
	printf("求节点数：");
	printf("\t%d\n",CountBiNode(root));
	printf("求树的深度：");
	printf("\t%d\n",Depth(root));
	Exchange(root);
	printf("层序遍历：\n");
	Traverse_LeverOrder(root);
	BiNode * bst=(BiNode *)malloc(sizeof(BiNode));
	bst->val=4;
	bst->rchild=NULL;
	bst->lchild=NULL;

	int i;
	for(i = 0; i < 10; i++)
	{
		BiNode * node=( BiNode *)malloc(sizeof(BiNode));
		node->val=i;
		node->rchild=NULL;
		node->lchild=NULL;
		BSTInsert(&bst, &node);
	}
	printf("层序遍历：\n");
	Traverse_LeverOrder(bst);


	distroyTree(&root);
	return 0;

}