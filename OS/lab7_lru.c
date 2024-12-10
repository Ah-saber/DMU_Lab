
#include <stdio.h>

void max_value(int x, int cc[][2]); // 函数声明，页表处理
int r_algorithm(int cc[5][2]); //函数声明，页面淘汰算法

char cc[13];  //存储页表中断记录
void page_table(int page1, int c[5][2]);

void main()
{
	int i, j, page, row = 0, col = 1;
	int k = 0;
	int a[12] = {4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5}; 

	int b[3][13]; //内存，行为页表数
	int c[5][2] = {{1, 0}, {2, 0}, {3,0}, {4, 0}, {5,0}};  
	
	int d[13], p = 0;
	b[0][0] = 0;
	b[1][0] = 0;
	b[2][0] = 0;
 
	//==========页面调度处理==========
	for(int i = 0; i < 12; i ++)
	{
		if(a[i] == b[0][i] || a[i] == b[1][i] || a[i] == b[2][i])
		{
			b[0][i+1] = b[0][i];
			b[1][i+1] = b[1][i];
			b[2][i+1] = b[2][i];

			max_value(a[i], c);
			page_table(a[i], c);
			cc[i] = 'F';
			col ++;
		}
		else
		{
			if(row > 2)
			{ //当row大于2采用置换算法
				page = r_algorithm(c);
				d[p] = page;
				p ++;
				k ++;
				b[0][i+1] = b[0][i];
				b[1][i+1] = b[1][i];
				b[2][i+1] = b[2][i];

				cc[i] = 'Y';

				//如果是替换的页表，就按调度顺序换页表
				if(b[0][i+1] == page)
					b[0][i+1] = a[i];
				if(b[1][i+1] == page)
					b[1][i+1] = a[i];
				if(b[2][i+1] == page)
					b[2][i+1] = a[i];

				max_value(a[i], c);
				page_table(a[i], c);
			}
			else
			{
				b[0][i+1] = b[0][i];
				b[1][i+1] = b[1][i];
				b[2][i+1] = b[2][i];

				cc[i] = 'Y';
				b[row][col] = a[i];
				max_value(a[i], c);

				col ++;;
				k ++;
				row ++;

				page_table(a[i], c);
			}

		}
	}

	//==================显示处理结果====================
	printf("\n     ");
	for(int i = 0; i < 12; i ++)
		printf("%6d", a[i]);
	puts("\n==================================================================================");
	
	for(int i = 0; i < 13; i ++)
		printf("%6d", b[0][i]);
	puts("\n==================================================================================");

	for(int i = 0; i < 13; i ++)
		printf("%6d", b[1][i]);
	puts("\n==================================================================================");
			
	for(int i = 0; i < 13; i ++)
		printf("%6d", b[2][i]);
	puts("\n==================================================================================");

	printf("     ");

	for(int i = 0; i < 13; i ++)
	{
		printf("     ");
		putchar(cc[i]);
	}

	printf("\n 缺页中断次数： %4d\n", k);
	printf("\n 页面淘汰顺序： ");

	for(int i = 0; i < p; i ++)
	{
		printf("%3d", d[i]);
	}
	puts("\n");
}

//每次赋予最新的页表最大值
void max_value(int x, int cc[][2])
{
	int i, max;
	max = cc[0][1];
	for(i = 0; i < 5; i ++)
	{
		if(max < cc[i][1])
			max = cc[i][1];
	}

	for(i = 0; i < 5; i ++)
	{
		if(cc[i][0] == x)
			cc[i][1] = max + 1;
	}
}


int r_algorithm(int cc[5][2])
{
	//先找一个非0值，作为比较依据
	int i, min, row, p;
	for(i = 0; i < 5; i ++)
	{
		if(cc[i][1] != 0)
		{
			min = cc[i][1];
			p = cc[i][0];
			row = i;
			break;
		}
	}

	for(i = 0; i < 5; i ++)
	{
		if(min > cc[i][1] && cc[i][1] != 0)
		{
			min = cc[i][1];
			p = cc[i][0];
			row = i;
		}
	}

	cc[row][1] = 0;

	return (p);
}


void page_table(int page1, int c[5][2])
{
	int i;
	printf("页面调度顺序 page = %d\n", page1);
	for(i = 0; i < 5; i ++)
		printf("%5d%5d\n", c[i][0], c[i][1]);
}



