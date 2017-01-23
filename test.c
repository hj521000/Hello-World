#include<stdio.h>
#include<stdlib.h>
#define ROWS 6
#define COLS 8 

//保存小人当前在地图上的行坐标
int personRow = 1;

// 保存小人当前在地图上的列坐标

int personCol = 1;

char map[ROWS][COLS]={
{'#','#','#','#','#','#','#','#'},
{'#','O','#','#',' ',' ',' ','#'},
{'#',' ','#','#',' ','#',' ','#'},
{'#',' ',' ','#',' ','#',' ','#'},
{'#','#',' ',' ',' ','#',' ','#'},
{'#','#','#','#','#','#',' ','#'},
};


/*
1.应该将游戏地图上的每一个格子的类型保存起来 
只有保存起来，我们后面再动的时候才可以知道下一个格子是什么
使用一个二维数组来保存游戏格子的类型最合适。

第一步：用一个二维数组将地图上的每一个格子的类型保存起来 
2.游戏流程：
	1）显示游戏地图 
	while(1) 
	{
		2)接收用户输入小人的方向
		3）根据用户输入的小人前进方向来移动小人
	}
	

*/ 
//打印地图 
void PrintMap()
{
	int i,j;
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}	
}
//接收用户输入小人的前进方向 
char enterDirection()
{
	char dir;
	printf("请输入小人前进的方向  w.上  s.下  a.左  d.右  q.退出\n");
	rewind(stdin);
	scanf("%c",&dir);
	return dir;
}
//判断用户输入的小人前进方向，根据方向来移动小人
 //将小人向上移动
 
void moveUp()
{
	/*
	    一开始小人的坐标是1行1列，并且小人的坐标随时都在变化
		所以我们用2个变量来保存小人当前的坐标
			 
	*/	
	//小人上一个格子的行坐标和列坐标 
	int personNextRow = personRow - 1;
	int personNextCol = personCol;
	//判断小人的上一个格子的类型是不是路。
	if(map[personNextRow][personNextCol] == ' ')
	{
		map[personNextRow][personNextCol] = 'O';
		map[personRow][personCol] = ' ';
		personRow = personNextRow;
		personCol = personNextCol;
	}
}

void moveDown()
{
	int personNextRow = personRow + 1;
	int personNextCol = personCol;
	//判断小人的下一个格子的类型是不是路。
	if(map[personNextRow][personNextCol] == ' ')
	{
		map[personNextRow][personNextCol] = 'O';
		map[personRow][personCol] = ' ';
		personRow = personNextRow;
		personCol = personNextCol;
	}
	
}

void moveLeft()
{
	int personNextRow = personRow;
	int personNextCol = personCol - 1;
	//判断小人的下一个格子的类型是不是路。
	if(map[personNextRow][personNextCol] == ' ')
	{
		map[personNextRow][personNextCol] = 'O';
		map[personRow][personCol] = ' ';
		personRow = personNextRow;
		personCol = personNextCol;
	}
}

void moveRight()
{ 
	int personNextRow = personRow;
	int personNextCol = personCol + 1;
	//判断小人的下一个格子的类型是不是路。
	if(map[personNextRow][personNextCol] == ' ')
	{
		map[personNextRow][personNextCol] = 'O';
		map[personRow][personCol] = ' ';
		personRow = personNextRow;
		personCol = personNextCol;
	}
}
  
int main()
{

	//map数组，二维数组，char类型，用来保存地图上每一个格子的类型。 
	//#代表墙，空格代表路，O代表小人。 
	while(1)
	{
		system("cls");
		
		PrintMap();
		 
		char dir = enterDirection();
		switch(dir)
		{
			case 'a':
			case 'A':
			//将小人向做移动
				moveLeft();
				break;
			case 'w':
			case 'W':
			//将小人向上移动 
				moveUp();
				break;
			case 's':
			case 'S':
			//将小人向下移动 
				moveDown();
				break;
			case 'd':
			case 'D':
			//将小人向右移动 
				moveRight();
				break;
			case 'q':
			case 'Q':
			//结束游戏 
				printf("你的智商真低！\n");
				return 0;
				break;
		}
		if(personRow == 5 && personCol == 6)
		{
			printf("你的智商真的是太高了。恭喜你！游戏结束。\n");
			return 0;
		}	
	}
	

	return 0;
}

//FunTest1(int rows,int cols,int arr[][cols])
//{
//	int i,j;
//	for(i=0;i<rows;i++)
//	{
//		for(j=0;j<cols;j++)
//		{
//			arr[i][j]=(i*j)+10;
//		}
//	}
//}
//
//FunTest2(int rows,int cols,int arr[][cols])
//{
//	int i,j;
//	for(i=0;i<rows;i++)
//	{
//		for(j=0;j<cols;j++)
//		{
//			printf("%d\t",arr[i][j]);
//		}- 
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int rows=0,cols=0;
//	//int arr[rows][cols];
//	printf("请输入这个二维数组的行数和列数：\n");
//	scanf("%d%d",&rows,&cols);
//	int arr[rows][cols];
//	FunTest1(rows,cols,arr);
//	FunTest2(rows,cols,arr);
//	return 0;
//}

//int main()
//{
//	int arr[] = {13,7,95,45,12,22};
//	int i,j,k,temp=0;
//	int len = sizeof(arr)/sizeof(arr[0]);
//	for(i = 0; i < len-1; i++)
//	{
//		for(j = 0; j < len-1-i; j++)
//		{
//			if(arr[j] > arr[j+1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//	
//	for(k = 0; k < len; k++)
//	{
//		printf("%d\n",arr[k]);
//	}
//	
//	return 0;
//}

