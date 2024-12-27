#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define MAX 21
#define RES_MAX 10
#define MAXBUF 255
int Line = 1;
char str[MAX][RES_MAX] = {"int", "call", "function", "case", "main", "for", "if", "else", "do", "while", "void", "return", "break", "struct", "const", "switch", "typedef", "enum", "read", "write", "default"};
bool vis = true;
//对关键字进行从小到大的排序
void sort_KY()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				swap(str[i], str[j]);
			}
		}
	}
}

//折半查找对关键字进行搜索
bool Iskeyword(char *s)
{
	int l = 0, r = MAX - 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (strcmp(s, str[mid]) >= 0)
			l = mid;
		else
			r = mid - 1;
	}
	if (strcmp(s, str[l]) == 0)
		return true;
	else
		return false;
}

//判断是否为字母
bool IsLetter(char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return true;
	return false;
}
//判断是否为数字
bool IsDigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
//分析test文件的词法
void analyse(FILE *fpin, FILE *fpout)
{
	char arr[MAXBUF], ch;
	int j = 0;
	while ((ch = fgetc(fpin)) != EOF)
	{
		if (ch == ' ' || ch == '\t' || ch == '\r')
			continue; //碰到空格、tab则跳过
		else if (ch == '\n')
			Line++;
		else if (IsLetter(ch))
		{ //如果首字符是字母，判断是关键字还是普通标识符
			while (IsLetter(ch) || IsDigit(ch))
			{
				if (ch <= 'Z' && ch >= 'A')
					ch = ch + 32; //将大写字母统一为小写字母
				arr[j] = ch;
				j++;
				ch = fgetc(fpin);
			}
			//重定位流上的文件指针，将其回退一位 SEEK_CUR表示从当前位置开始偏移
			fseek(fpin, -1L, SEEK_CUR);
			arr[j] = '\0';
			j = 0;
			if (Iskeyword(arr))
				fprintf(fpout, "%s\t\t%s\t\t%d\n", arr, arr, Line);
			else //普通标识符
				fprintf(fpout, "ID\t\t%s\t\t%d\n", arr, Line);
		}
		//数字的处理
		else if (IsDigit(ch))
		{
			bool flag = false;
			arr[j++] = ch;
			ch = fgetc(fpin);
			while (IsDigit(ch) || IsLetter(ch))
			{
				if (IsLetter(ch))
				{
					arr[j++] = ch;
					flag = true;
					ch = fgetc(fpin);
				}
				else if (IsDigit(ch))
				{
					arr[j++] = ch;
					ch = fgetc(fpin);
				}
			}
			fseek(fpin, -1L, SEEK_CUR);
			arr[j] = '\0';
			j = 0;
			if (!flag)
				fprintf(fpout, "NUM\t\t%s\t\t%d\n", arr, Line);
			else if (flag)
			{
				vis = false;
				fprintf(fpout, "%s\t\t第%d行出错(标识符不能以数字开头)\n", arr, Line);
				printf("%s\t\t第%d行出错(标识符不能以数字开头)\n", arr, Line);
			}
		}
		else
			switch (ch)
			{
			case '+':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "+", "+", Line);
				break;
			case '-':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "-", "-", Line);
				break;
			case '*':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "*", "*", Line);
				break;
			case '(':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "(", "(", Line);
				break;
			case ')':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", ")", ")", Line);
				break;
			case '[':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "[", "[", Line);
				break;
			case ']':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "]", "]", Line);
				break;
			case ';':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", ";", ";", Line);
				break;
			case '.':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", ".", ".", Line);
				break;
			case ',':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", ",", ",", Line);
				break;
			case ':':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", ":", ":", Line);
				break;
			case '{':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "{", "{", Line);
				break;
			case '}':
				fprintf(fpout, "%s\t\t%s\t\t%d\n", "}", "}", Line);
				break;
			case '>':
				ch = fgetc(fpin);
				if (ch == '=')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", ">=", ">=", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", ">", ">", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
			case '<':
				ch = fgetc(fpin);
				if (ch == '=')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "<=", "<=", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "<", "<", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
			case '!':
				ch = fgetc(fpin);
				if (ch == '=')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "!=", "!=", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "!", "!", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
			case '=':
				ch = fgetc(fpin);
				if (ch == '=')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "==", "==", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "=", "=", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
			case '&':
				ch = fgetc(fpin);
				if (ch == '&')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "&&", "&&", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "&", "&", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
			case '|':
				ch = fgetc(fpin);
				if (ch == '|')
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "||", "||", Line);
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "|", "|", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
				//注释部分处理
			case '/':
				ch = fgetc(fpin);
				if (ch == '*')
				{
					ch = fgetc(fpin);
					while (ch != EOF)
					{
						ch = fgetc(fpin);
						if (ch == '*')
						{
							ch = fgetc(fpin);
							if (ch == '/')
								break;
							fseek(fpin, -1L, SEEK_CUR);
						}
					}
					if (ch == EOF)
					{
						vis = false;
						fprintf(fpout, "注释不完整");
						printf("注释不完整\n");
					}
				}
				else
				{
					fprintf(fpout, "%s\t\t%s\t\t%d\n", "/", "/", Line);
					fseek(fpin, -1L, SEEK_CUR);
				}
				break;
				//非法字符
			default:
			{
				vis = false;
				fprintf(fpout, "在第%d行无法识别字符: %c\n", Line, ch);
				printf("在第%d行无法识别字符: %c\n", Line, ch);
				break;
			}
			}
	}
}
bool cifa_program()
{
	char in_fn[65]="./test2.txt", out_fn[65] = "./cifa_result2.txt";
	sort_KY();
	FILE *fpin, *fpout;
	printf("-------------------------WELCOME-------------------------\n");
	printf("-------------------------语义分析程序-------------------------\n");
	printf("\n");
//	printf("请输入需要进行词法分析的文件名:\n");
//	scanf("%s", in_fn);
	fpin = fopen(in_fn, "r");
	fpout = fopen(out_fn, "w");
	analyse(fpin, fpout);
	fclose(fpin);
	fclose(fpout);
	return vis;
}
