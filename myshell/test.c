#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void enable_raw_mode() {
    //设置原始模式，原本为规则模式，即缓冲行等自动执行，维护一些输入输出程序
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);  // 仅关闭行缓冲和回显
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disable_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;  //还原
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// 更新 complete_file 函数，实现文件补全
void complete_file(char *input) {
    DIR *dir;
    struct dirent *entry;
    size_t len = strlen(input);

    //打开当前目录
    if ((dir = opendir(".")) == NULL) {
        perror("opendir() error");
    } else {
        while ((entry = readdir(dir)) != NULL) {
            if (strncmp(entry->d_name, input, len) == 0) {
                // 找到第一个匹配项，将其补全到输入中
                strcpy(input, entry->d_name);
                break;
            }
        }
        closedir(dir);
    }
}

int main() {
    char input[256] = "";
    enable_raw_mode();

    printf("Enter command: ");
    while (1) {
        char c = getchar();
        
        // 检查是否按下 Backspace 键（通常为 127 或 8）
        if ((int)c == 127 || (int)c == 8) {
            if (strlen(input) > 0) {
                input[strlen(input) - 1] = '\0';  // 删除最后一个字符
                printf("\b \b");  // 在终端上退格、清除字符、再退格
                fflush(stdout);
            }
        } 
        else if (c == '\t') {
            complete_file(input); // 文件补全，将匹配结果填入 input
            printf("\rEnter command: %s", input); // 使用 \r 回到行首更新显示
            fflush(stdout);
        } 
        else if (c == '\n') {
            printf("\n执行命令：%s\n", input);
            break;
        } 
        else {
            strncat(input, &c, 1);
            putchar(c);  // 手动回显字符
        }
    }

    disable_raw_mode();
    return 0;
}
