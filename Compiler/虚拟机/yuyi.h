#include "cifa.h"
using namespace std;
const int maxvartablep = 500;
map<string, int> mp;
char token[20], token1[40];
char yuyi_in[300] = "D:\\devc_workspace\\ci_fa_output.txt";
char yuyi_out[300] = "D:\\devc_workspace\\yu_yi_output.txt";
char case_id[300];
bool flag;
FILE *fin, *fout;
int program();
int declaration_list();
int declaration_stat();
int statement_list();
int statement();
int if_stat();
int while_stat();
int do_while_stat();
int for_stat();
int switch_case_stat();
int case_stat();
int case_list();
int read_stat();
int write_stat();
int compound_stat();
int expression_stat();
int expression();
int bool_expr();
int additive_expr();
int term();
int factor();
int fun_declaration();
int fun_body();
int main_declaration();
int call_stat();
int name_def(char *name);
struct Node
{
	char name[8];
	int address;
	bool is_fun;
	Node() : is_fun(false) {}
} vartable[maxvartablep];
int vartablep = 0, labelp = 1, datap = 0;
int name_def(char *name, bool flag)
{
	int i, es = 0;
	if (vartablep >= maxvartablep)
		return 21;
	for (i = vartablep - 1; i >= 0; i--)
	{
		if (strcmp(vartable[i].name, name) == 0)
		{
			if (flag != vartable[i].is_fun)
				break;
			es = 22;
			break;
		}
	}
	if (es > 0)
		return es;
	strcpy(vartable[vartablep].name, name);
	vartable[vartablep].address = datap;
	if (flag)
		vartable[vartablep].is_fun = true;
	datap++;
	vartablep++;
	return es;
}
int lookup(char *name, int *paddress, bool flag)
{
	int i, es = 0, vis = 0;
	for (i = 0; i < vartablep; i++)
	{
		if (strcmp(vartable[i].name, name) == 0)
		{
			*paddress = vartable[i].address;
			vis = 1;
			if (flag == vartable[i].is_fun)
				return es;
		}
	}
	if (flag && vis)
		return es = 18;
	return es = 23;
}
int TESTparse()
{
	int es = 0;
	if ((fin = fopen(yuyi_in, "r")) == NULL)
	{
		printf("打开%s文件错误\n", yuyi_in);
		es = 10;
	}
	if ((fout = fopen(yuyi_out, "w")) == NULL)
	{
		printf("打开%s文件错误\n", yuyi_out);
		es = 10;
	}

	if (es == 0)
		es = program();
	printf("-------------------------语义分析结果-------------------------\n");
	switch (es)
	{
	case 0:
		printf("语义分析成功!\n语义分析文件已保存\n");
		break;
	case 1:
		cout << "第" << Line << "行缺少{!" << endl;
		break;
	case 2:
		cout << "第" << Line << "行缺少}!" << endl;
		break;
	case 3:
		cout << "第" << Line << "行缺少标识符!" << endl;
		break;
	case 4:
		cout << "第" << Line << "行缺少分号!" << endl;
		break;
	case 5:
		cout << "第" << Line << "行缺少(!" << endl;
		break;
	case 6:
		cout << "第" << Line << "行缺少)!" << endl;
		break;
	case 8:
		cout << "第" << Line << "行缺少,!" << endl;
		break;
	case 7:
		cout << "第" << Line << "行缺少操作数!" << endl;
		break;
	case 9:
		cout << "第" << Line << "行缺少main函数" << endl;
		break;
	case 10:
		cout << "文件无法打开" << endl;
		break;
	case 11:
		cout << "第" << Line << "行非法声明,缺少函数名称fun/main" << endl;
		break;
	case 13:
		cout << "第" << Line << "行do-while语句中缺少while" << endl;
		break;
	case 14:
		cout << "第" << Line << "行do-while语句的while中缺少右括号)" << endl;
		break;
	case 15:
		cout << "第" << Line << "行call语句后面缺少函数名称" << endl;
		break;
	case 16:
		cout << "第" << Line << "行switch-case语句中缺少:" << endl;
		break;
	case 17:
		cout << "第" << Line << "行switch-case语句中缺少break" << endl;
		break;
	case 18:
		cout << "第" << Line << "行call语句后面标识符不是函数名" << endl;
		break;
	case 21:
		cout << "第" << Line << "行错误，符号表溢出" << endl;
		break;
	case 22:
		cout << "第" << Line << "行标识符重复定义！" << endl;
		break;
	case 23:
		cout << "第" << Line << "行变量缺少声明类型int" << endl;
		break;
	default:
		cout << es << endl;
	}
	return es;
}

int program()
{
	int es = 0;
	fprintf(fout, "\tBR LABEL0\n");
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "function") && strcmp(token, "main"))
	{
		return es = 11;
	}
	while (strcmp(token, "function") == 0)
	{
		es = fun_declaration();
		if (es > 0)
			return es;
	}
	if (strcmp(token, "main"))
		return es = 9;
	es = main_declaration();
	fprintf(fout, "STOP\n");
	if (es > 0)
		return es;
	for (int i = 0; i < vartablep; i++)
	{
		if (vartable[i].is_fun == false)
			printf("\t变量名： %s\t变量地址： %d\n", vartable[i].name, vartable[i].address);
		else
			printf("\t函数名： %s\t函数地址： %d\n", vartable[i].name, vartable[i].address);
	}
	return es;
}
int fun_declaration()
{
	int es = 0;
	string str;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "ID"))
		return es = 3;
	es = name_def(token1, true);
	for (int i = 0; i < strlen(token1); i++)
		str += token1[i];
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	while (strcmp("int", token) == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		if (strcmp(token, "ID"))
			return es = 3;
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		if (strcmp(token, ","))
			break;
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
	}
	if (strcmp(token, ")"))
		return es = 5;
	//	cout<<str<<endl;
	mp[str] = labelp;
	fprintf(fout, "LABEL%d:\n", labelp++);
	es = fun_body();
	fprintf(fout, "\tRETURN\n");
	if (es > 0)
		return es;

	return es;
}
int main_declaration()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ")"))
		return es = 6;
	fprintf(fout, "LABEL0:\n");
	es = fun_body();
	if (es > 0)
		return es;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);

	return es;
}
int fun_body()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "{"))
		return es = 1;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = declaration_list();
	if (es > 0)
		return es;
	es = statement_list();
	if (es > 0)
		return es;
	if (strcmp(token, "}"))
		return es = 2;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int declaration_list()
{
	int es = 0;
	while (strcmp(token, "int") == 0)
	{
		es = declaration_stat();
		if (es > 0)
			return es;
	}
	return es;
}
int declaration_stat()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "ID"))
		return es = 3;
	es = name_def(token1, false);
	if (es > 0)
		return es;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	//	printf("%s %s\n",token,token1);
	if (strcmp(token, ";") == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		return es;
	}
	else if (strcmp(token, ",") && strcmp(token, ";"))
		return es = 4;
	else
	{
		while (strcmp(token, ",") == 0)
		{
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
			if (strcmp("ID", token))
				return es = 3;
			es = name_def(token1, false);
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
		}
		if (strcmp(token, ";") == 0)
		{
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
			return es;
		}
	}
	return es;
}
int statement_list()
{
	int es = 0;
	while (strcmp(token, "}"))
	{
		es = statement();
		if (es > 0)
			return es;
	}
	return es;
}
int statement()
{
	int es = 0;
	if (es == 0 && strcmp(token, "if") == 0)
		es = if_stat();
	if (es == 0 && strcmp(token, "while") == 0)
		es = while_stat();
	if (es == 0 && strcmp(token, "for") == 0)
		es = for_stat();
	if (es == 0 && strcmp(token, "read") == 0)
		es = read_stat();
	if (es == 0 && strcmp(token, "write") == 0)
		es = write_stat();
	if (es == 0 && strcmp(token, "{") == 0)
		es = compound_stat();
	if (es == 0 && strcmp(token, "call") == 0)
		es = call_stat();
	if (es == 0 && strcmp(token, "do") == 0)
		es = do_while_stat();
	if (es == 0 && strcmp(token, "switch") == 0)
		es = switch_case_stat();
	if (es == 0 && (strcmp(token, "ID") == 0 || strcmp(token, "NUM") == 0 || strcmp(token, "(") == 0))
		es = expression_stat();

	return es;
}
int if_stat()
{
	int es = 0, label1, label2;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	if (strcmp(token, ")"))
		return es = 6;
	label1 = labelp++;
	fprintf(fout, "\tBRF LABEL%d\n", label1);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	//	printf("%s %s\n",token,token1);
	es = statement();
	//	printf("%s %s\n",token,token1);
	if (es > 0)
		return es;
	label2 = labelp++;
	fprintf(fout, "\tBR LABEL%d\n", label2);
	fprintf(fout, "LABEL%d:\n", label1);
	if (strcmp(token, "else") == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		es = statement();
		if (es > 0)
			return es;
	}
	fprintf(fout, "LABEL%d:\n", label2);
	//	printf("%s %s\n",token,token1);
	return es;
}
int while_stat()
{
	int es = 0, label1, label2;
	label1 = labelp++;
	fprintf(fout, "LABEL%d:\n", label1);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	if (strcmp(token, ")"))
		return es = 6;
	label2 = labelp++;
	fprintf(fout, "\tBRF LABEL%d\n", label2);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = statement();
	if (es > 0)
		return es;
	fprintf(fout, "\tBR LABEL%d\n", label1);
	fprintf(fout, "LABEL%d:\n", label2);
	return es;
}
int do_while_stat()
{
	int es = 0, label1, label2;
	label1 = labelp++;
	fprintf(fout, "LABEL%d:\n", label1);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "{"))
		return es = 1;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = statement();
	label2 = labelp++;
	if (es > 0)
		return es;
	if (strcmp(token, "}"))
		return es = 2;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "while"))
		return es = 13;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	if (strcmp(token, ")"))
		return es = 6;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ";"))
		return es = 4;
	fprintf(fout, "\tBRF LABEL%d\n", label2);
	fprintf(fout, "\tBR LABEL%d\n", label1);
	fprintf(fout, "LABEL%d:\n", label2);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int switch_case_stat()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "ID"))
		return es = 3;
	strcpy(case_id, token1);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ")"))
		return es = 6;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "{"))
		return es = 1;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	flag = false;
	es = case_list();
	if (es > 0)
		return es;
	if (strcmp(token, "}"))
		return es = 2;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int case_list()
{
	int es = 0;
	while (strcmp(token, "case") == 0)
	{
		es = case_stat();
		if (es > 0)
			return es;
	}
	return es;
}
int case_stat()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	fprintf(fout, "LABEL%d:\n", labelp++);
	if (strcmp(token, "ID"))
		return es = 3;
	if (strcmp(token1, case_id) != 0 && !flag)
	{
		fprintf(fout, "\tBR LABEL%d\n", labelp);
	}
	else if (strcmp(token1, case_id) == 0)
		flag = true;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ":"))
		return es = 16;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	fprintf(fout, "\tPOP\n");
	if (strcmp(token, ";"))
		return es = 4;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int for_stat()
{
	int es = 0, label1, label2, label3, label4;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	fprintf(fout, "\tPOP\n");
	if (strcmp(token, ";"))
		return es = 4;
	label1 = labelp++;
	fprintf(fout, "LABEL%d:\n", label1);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	label2 = labelp++;
	fprintf(fout, "\tBRF LABEL%d\n", label2);
	label3 = labelp++;
	fprintf(fout, "\tBR LABEL%d\n", label3);
	if (strcmp(token, ";"))
		return es = 4;
	label4 = labelp++;
	fprintf(fout, "LABEL%d:\n", label4);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	fprintf(fout, "\tPOP\n");
	fprintf(fout, "\tBR LABEL%d\n", label1);
	if (strcmp(token, ")"))
		return es = 6;
	fprintf(fout, "LABEL%d:\n", label3);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = statement();
	if (es > 0)
		return es;
	fprintf(fout, "\tBR LABEL%d\n", label4);
	fprintf(fout, "LABEL%d:\n", label2);
	return es;
}
int write_stat()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = expression();
	if (es > 0)
		return es;
	if (strcmp(token, ";"))
		return es = 4;
	fprintf(fout, "\tOUT\n");
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int read_stat()
{
	int address;
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "ID"))
		return es = 3;
	es = lookup(token1, &address, false);
	if (es > 0)
		return es;
	fprintf(fout, "\tIN  \n");
	fprintf(fout, "\tSTO %d\n", address);
	fprintf(fout, "\tPOP\n");

	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ";"))
		return es = 4;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int compound_stat()
{
	int es = 0;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	es = statement_list();
	if (strcmp(token, "}"))
		return es = 2;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int expression_stat()
{
	int es = 0;
	if (strcmp(token, ";") == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		return es;
	}
	es = expression();
	if (es > 0)
		return es;
	fprintf(fout, "\tPOP\n");
	if (es == 0 && strcmp(token, ";") == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		return es;
	}
	else
	{
		return es = 4;
	}
}
int call_stat()
{
	int es = 0, address;
	string str;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "ID"))
		return es = 3;
	es = lookup(token1, &address, true);
	for (int i = 0; i < strlen(token1); i++)
		str += token1[i];
	if (es > 0)
		return es;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, "("))
		return es = 5;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ")"))
		return es = 6;
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	if (strcmp(token, ";"))
		return 4;
	fprintf(fout, "\tBR LABEL%d\n", mp[str]);
	fscanf(fin, "%s %s %d\n", token, token1, &Line);
	return es;
}
int expression()
{
	int es = 0, fileadd;
	char token2[20], token3[40];
	if (strcmp(token, "ID") == 0)
	{
		fileadd = ftell(fin);
		fscanf(fin, "%s %s %d\n", token2, token3, &Line);
		if (strcmp(token2, "=") == 0)
		{
			int address;
			es = lookup(token1, &address, false);
			if (es > 0)
				return es;
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
			es = bool_expr();
			if (es > 0)
				return es;
			fprintf(fout, "\tSTO   %d\n", address);
		}
		else
		{
			fseek(fin, fileadd, 0);
			es = bool_expr();
			if (es > 0)
				return es;
		}
	}
	else
		es = bool_expr();
	return es;
}
int bool_expr()
{
	int es = 0;
	es = additive_expr();
	if (es > 0)
		return es;
	if (strcmp(token, ">") == 0 || strcmp(token, ">=") == 0 || strcmp(token, "<") == 0 || strcmp(token, "<=") == 0 || strcmp(token, "==") == 0 || strcmp(token, "!=") == 0)
	{
		char token2[20];
		strcpy(token2, token);
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		es = additive_expr();
		if (es > 0)
			return es;
		if (strcmp(token2, ">") == 0)
			fprintf(fout, "\tGT\n");
		if (strcmp(token2, ">=") == 0)
			fprintf(fout, "\tGE\n");
		if (strcmp(token2, "<") == 0)
			fprintf(fout, "\tLES\n");
		if (strcmp(token2, "<=") == 0)
			fprintf(fout, "\tLE\n");
		if (strcmp(token2, "==") == 0)
			fprintf(fout, "\tEQ\n");
		if (strcmp(token2, "!=") == 0)
			fprintf(fout, "\tNOTEQ\n");
	}
	return es;
}
int additive_expr()
{
	int es = 0;
	es = term();
	if (es > 0)
		return es;
	while (strcmp(token, "+") == 0 || strcmp(token, "-") == 0)
	{
		char token2[20];
		strcpy(token2, token);
		fscanf(fin, "%s %s %d", token, token1, &Line);
		//		printf("%s %s\n",token,token1);
		es = term();
		if (es > 0)
			return es;
		if (strcmp(token2, "+") == 0)
			fprintf(fout, "\tADD\n");
		if (strcmp(token2, "-") == 0)
			fprintf(fout, "\tSUB\n");
	}
	return es;
}
int term()
{
	int es = 0;
	es = factor();
	if (es > 0)
		return es;
	while (strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
	{
		char token2[20];
		strcpy(token2, token);
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		es = factor();
		if (es > 0)
			return es;
		if (strcmp(token2, "*") == 0)
			fprintf(fout, "\tMULT\n");
		if (strcmp(token2, "/") == 0)
			fprintf(fout, "\tDIV\n");
	}
	return es;
}
int factor()
{
	int es = 0;

	if (strcmp(token, "(") == 0)
	{
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
		es = expression();
		if (es > 0)
			return es;
		if (strcmp(token, ")"))
			return es = 6;
		fscanf(fin, "%s %s %d\n", token, token1, &Line);
	}
	else
	{

		if (strcmp(token, "ID") == 0)
		{
			int address;
			es = lookup(token1, &address, false);
			if (es > 0)
				return es;
			fprintf(fout, "\tLOAD %d\n", address);
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
			return es;
		}
		if (strcmp(token, "NUM") == 0)
		{
			fprintf(fout, "\tLOADI %s\n", token1);
			fscanf(fin, "%s %s %d\n", token, token1, &Line);
			return es;
		}
		else
		{
			es = 7;
			return es;
		}
	}
	return es;
}

bool yuyi_program()
{
	if (!cifa_program())
	{
		cout << "词法分析错误" << endl;
		printf("-------------------------谢谢使用-------------------------\n");
		return 0;
	}
	printf("-------------------------词法分析成功-------------------------\n");
	int es = 0;
	es = TESTparse();
	if (es != 0)
	{
		printf("语义分析失败\n");
	}
	fclose(fin);
	fclose(fout);
}

int main()
{
	
}