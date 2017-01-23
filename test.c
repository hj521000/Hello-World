#include<stdio.h>
#include<stdlib.h>
#define ROWS 6
#define COLS 8 

//����С�˵�ǰ�ڵ�ͼ�ϵ�������
int personRow = 1;

// ����С�˵�ǰ�ڵ�ͼ�ϵ�������

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
1.Ӧ�ý���Ϸ��ͼ�ϵ�ÿһ�����ӵ����ͱ������� 
ֻ�б������������Ǻ����ٶ���ʱ��ſ���֪����һ��������ʲô
ʹ��һ����ά������������Ϸ���ӵ���������ʡ�

��һ������һ����ά���齫��ͼ�ϵ�ÿһ�����ӵ����ͱ������� 
2.��Ϸ���̣�
	1����ʾ��Ϸ��ͼ 
	while(1) 
	{
		2)�����û�����С�˵ķ���
		3�������û������С��ǰ���������ƶ�С��
	}
	

*/ 
//��ӡ��ͼ 
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
//�����û�����С�˵�ǰ������ 
char enterDirection()
{
	char dir;
	printf("������С��ǰ���ķ���  w.��  s.��  a.��  d.��  q.�˳�\n");
	rewind(stdin);
	scanf("%c",&dir);
	return dir;
}
//�ж��û������С��ǰ�����򣬸��ݷ������ƶ�С��
 //��С�������ƶ�
 
void moveUp()
{
	/*
	    һ��ʼС�˵�������1��1�У�����С�˵�������ʱ���ڱ仯
		����������2������������С�˵�ǰ������
			 
	*/	
	//С����һ�����ӵ�������������� 
	int personNextRow = personRow - 1;
	int personNextCol = personCol;
	//�ж�С�˵���һ�����ӵ������ǲ���·��
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
	//�ж�С�˵���һ�����ӵ������ǲ���·��
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
	//�ж�С�˵���һ�����ӵ������ǲ���·��
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
	//�ж�С�˵���һ�����ӵ������ǲ���·��
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

	//map���飬��ά���飬char���ͣ����������ͼ��ÿһ�����ӵ����͡� 
	//#����ǽ���ո����·��O����С�ˡ� 
	while(1)
	{
		system("cls");
		
		PrintMap();
		 
		char dir = enterDirection();
		switch(dir)
		{
			case 'a':
			case 'A':
			//��С�������ƶ�
				moveLeft();
				break;
			case 'w':
			case 'W':
			//��С�������ƶ� 
				moveUp();
				break;
			case 's':
			case 'S':
			//��С�������ƶ� 
				moveDown();
				break;
			case 'd':
			case 'D':
			//��С�������ƶ� 
				moveRight();
				break;
			case 'q':
			case 'Q':
			//������Ϸ 
				printf("���������ͣ�\n");
				return 0;
				break;
		}
		if(personRow == 5 && personCol == 6)
		{
			printf("������������̫���ˡ���ϲ�㣡��Ϸ������\n");
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
//	printf("�����������ά�����������������\n");
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

