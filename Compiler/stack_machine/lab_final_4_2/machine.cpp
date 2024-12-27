#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

using namespace std;

// 定义操作码
map<string, int> Map;

// 操作码枚举类型
enum Operation {LABEL, LOAD, LOADI, STO, STI, ADD, SUB,
                MULT, DIV, BR, BRF, EQ, NOTEQ, GT,
                LES, GE, LE, AND, OR, NOT, IN, OUT, RETURN, ENTER, CAL, STOP};

// 定义中间代码结构体
typedef struct Code {
    char opt[10];   // 操作码
    int operand;    // 操作数
} Code;

Code codes[1000];    // 存储中间代码的数组

// 初始化操作码映射
void init() {
    Map["LABEL"] = LABEL;
    Map["LOAD"] = LOAD;
    Map["LOADI"] = LOADI;
    Map["STO"] = STO;
    Map["STI"] = STI;
    Map["ADD"] = ADD;
    Map["SUB"] = SUB;
    Map["MULT"] = MULT;
    Map["DIV"] = DIV;
    Map["BR"] = BR;
    Map["BRF"] = BRF;
    Map["EQ"] = EQ;
    Map["NOTEQ"] = NOTEQ;
    Map["GT"] = GT;
    Map["LES"] = LES;
    Map["GE"] = GE;
    Map["LE"] = LE;
    Map["AND"] = AND;
    Map["OR"] = OR;
    Map["NOT"] = NOT;
    Map["IN"] = IN;
    Map["OUT"] = OUT;
    Map["RETURN"] = RETURN;
    Map["ENTER"] = ENTER;
    Map["CAL"] = CAL;
    Map["STOP"] = STOP;
}

// 执行机器码
int executeMachineCode() {
    int errorCode = 0;
    int numCodes = 0;  // 中间代码的条数
    FILE *inputFile;   // 用于读取中间代码文件

    // 栈相关变量
    int stack[100] = {}, top = 0, base = 0;
    int instructionPointer = 0;  // 指令指针
    Code instruction;

    init();

    // 打开中间代码文件
    if((inputFile = fopen("./yuyi_result.txt", "rb")) == NULL) {
        printf("Error opening file: yuyi_result.txt\n");
        errorCode = 10;
        return errorCode;
    }

    int useless = 0;
    // 从文件中读取指令
    while (fscanf(inputFile, "%d %s %d", &useless, instruction.opt, &instruction.operand) == 3) {
        // 检查操作码是否有效
        //printf("%d, %s, %d\n", useless, instruction.opt, instruction.operand);
        codes[numCodes++] = instruction;
        // if (Map.find(instruction.opt) != Map.end()) {
        //     codes[numCodes++] = instruction;
        // }
    }
    //printf("numcodes:%d\n", numCodes-1);

    // 初始化栈和其他变量
    top = 0;
    base = 0;
    instructionPointer = 0;
    stack[0] = 0;
    stack[1] = 0;

    // 执行每条指令
    do {
        instruction = codes[instructionPointer];
        instructionPointer++;

        switch(Map[instruction.opt]) {

            case LOAD:
                stack[top] = stack[base + instruction.operand];  // 将操作数加载到栈顶
                top++;
                break;

            case LOADI:
                stack[top] = instruction.operand;  // 将常量压入栈
                top++;
                break;

            case STO:
                top--;
                stack[base + instruction.operand] = stack[top];  // 将栈顶值存储到指定地址
                break;

            case ADD:
                top--;
                stack[top - 1] = stack[top - 1] + stack[top];  // 栈顶两个值相加
                break;

            case SUB:
                top--;
                stack[top - 1] = stack[top - 1] - stack[top];  // 栈顶两个值相减
                break;

            case MULT:
                top--;
                stack[top - 1] = stack[top - 1] * stack[top];  // 栈顶两个值相乘
                break;

            case DIV:
                top--;
                stack[top - 1] = stack[top - 1] / stack[top];  // 栈顶两个值相除
                break;

            case BR:
                instructionPointer = instruction.operand;  // 无条件跳转
                break;

            case BRF:
                top--;
                if(stack[top] == 0)
                    instructionPointer = instruction.operand;  // 栈顶为0时跳转
                break;

            case EQ:
                top--;
                stack[top - 1] = (stack[top - 1] == stack[top]);  // 栈顶两个值做相等比较
                break;

            case NOTEQ:
                top--;
                stack[top - 1] = (stack[top - 1] != stack[top]);  // 栈顶两个值做不等比较
                break;

            case GT:
                top--;
                stack[top - 1] = stack[top - 1] > stack[top];  // 次栈顶大于栈顶
                break;

            case LES:
                top--;
                stack[top - 1] = stack[top - 1] < stack[top];  // 次栈顶小于栈顶
                break;

            case GE:
                top--;
                stack[top - 1] = stack[top - 1] >= stack[top];  // 次栈顶大于等于栈顶
                break;

            case LE:
                top--;
                stack[top - 1] = stack[top - 1] <= stack[top];  // 次栈顶小于等于栈顶
                break;

            case AND:
                top--;
                stack[top - 1] = stack[top - 1] && stack[top];  // 栈顶两个值做逻辑与运算
                break;

            case OR:
                top--;
                stack[top - 1] = stack[top - 1] || stack[top];  // 栈顶两个值做逻辑或运算
                break;

            case NOT:
                stack[top - 1] = !stack[top - 1];  // 取反栈顶值
                break;

            case IN:
                printf("Please enter a number: ");
                scanf("%d", &stack[top]);  // 从输入获取数据并压栈
                top++;
                break;

            case OUT:
                top--;
                printf("Program output: %d\n", stack[top]);  // 输出栈顶的值
                break;

            case ENTER:
                top += instruction.operand;  // 在栈中为函数分配空间
                break;

            case RETURN:
                top = base;  // 释放函数栈空间
                instructionPointer = stack[top + 1];  // 获取返回地址
                base = stack[top];  // 恢复调用函数的基地址
                break;

            case CAL:
                stack[top] = base;  // 保存调用函数的基地址
                stack[top + 1] = instructionPointer;  // 保存返回地址
                base = top;  // 更新基地址为当前函数的基地址
                instructionPointer = instruction.operand;  // 跳转到被调用函数
                break;
            
            case STOP:
                return 0;
        }

    } while(instructionPointer != 0);  // 当指令指针为0时结束

    return errorCode;
}

int main() {
    // 执行机器码并返回结果
    int result = executeMachineCode();
    return result;
}
