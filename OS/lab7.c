#include <stdio.h>

void main()
{
	int i, j, k = 0;
	char cc[13];
	int a[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
	int b[3][13], c[13], p = 0;

	b[0][0] = 0;
	b[1][0] = 0;
	b[2][0] = 0;

	printf("      ");
	for(int i = 0; i < 12; i ++)
		printf("%6d", a[i]);
	printf("\n   ===============================================================================\n");
	for(int i = 0; i < 12; i ++)
	{
		if(a[i] == b[0][i] || a[i] == b[1][i] || a[i] == b[2][i])
		{
			b[0][i+1] = b[0][i];
			b[1][i+1] = b[1][i];
			b[2][i+1] = b[2][i];
			cc[i] = 'N';
		}
		else
		{
			if(i > 2)
			{
				c[p] = b[2][i];
				p ++;
			}
			b[0][i+1] = a[i];
			b[1][i+1] = b[0][i];
			b[2][i+1] = b[1][i];
			cc[i] = 'Y';
			k = k + 1;
		}
	}

	for(int j = 0; j < 13; j ++)
		printf("%6d", b[0][j]);
	printf("\n   -------------------------------------------------------------------------------\n");

	for(int j = 0; j < 13; j ++)
		printf("%6d", b[1][j]);
	printf("\n   -------------------------------------------------------------------------------\n");

	for(int j = 0; j < 13; j ++)
		printf("%6d", b[2][j]);
	printf("\n   -------------------------------------------------------------------------------\n");
	
	
	printf("      ");
	for(int j = 0; j < 13; j ++)
	{
		printf("     ");

		putchar(cc[j]);
	}

	printf("\n缺页中断次数：%3d\n", k);
	printf("页面淘汰顺序： ");
	for(int j = 0; j < p; j ++)
		printf("%3d", c[j]);
	printf("\n\n");
}
