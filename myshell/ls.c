#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


int cmp(const void *a, const void *b) 
{
    return strcmp(*(const char **)a, *(const char **)b);
}


void print_file_info(const char *path, long long max_size) {
    struct stat file_stat;

    // 获取文件状态信息
    if (stat(path, &file_stat) == -1) {
        perror("stat");
        return;
    }

    // 输出文件类型和权限
    printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf(" %ld", file_stat.st_nlink); // 链接数

    // 输出所有者和组
    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group  *gr = getgrgid(file_stat.st_gid);
    printf(" %s %s", pw->pw_name, gr->gr_name);

    // 输出文件大小
    printf(" %*lld", (int)max_size, (long long)file_stat.st_size);

    // 输出最后修改时间
    char timebuf[80];
    struct tm *tm_info = localtime(&file_stat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M", tm_info);
    printf(" %s", timebuf);


}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    bool _L = 0;
    char *tmp = NULL;
    char **file_name = NULL;

    if(argc > 1 && !strcmp(argv[1], "-l"))
    {
        _L = 1;
        tmp = argc > 2 ? argv[2] : ".";
    }
    else
    {
        tmp = argc > 1 ? argv[1] : ".";
        //puts(tmp);
    }

    long long max_size = 0;
    // 如果没有传入目录，则使用当前目录
    const char *path = tmp;


    // 打开目录
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // 读取目录内容
    //获取最大的文件
    int file_count = 0;

    //存储文件名和找到最长的文件大小
    while ((entry = readdir(dir)) != NULL)
    {
        file_name = realloc(file_name, (file_count + 1) * sizeof(char *));
        file_name[file_count] = strdup(entry->d_name); // 存储文件名 复制字符串，自动管理内存
        file_count ++;

        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        
        
        struct stat files;
        if(stat(fullpath, &files) == 0)
        {
            if(files.st_size > max_size)
                max_size = files.st_size;
        }
    }

    closedir(dir);

    qsort(file_name, file_count, sizeof(char *), cmp);

    //执行ls
    if(_L)
    {
        for(int i = 0; i < file_count; i ++)
        {
            char fullpath[1024];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, file_name[i]);
        
            print_file_info(fullpath, snprintf(NULL, 0, "%lld", (long long)max_size)); // 输出文件详细信息
                // 输出文件名
            printf(" %s\n", file_name[i]);
        }
    }
    else
    {
        for(int i = 0; i < file_count; i ++)
        {   
            if(!strcmp(file_name[i], ".") || !strcmp(file_name[i], "..")) continue;
            
            printf("%s  ", file_name[i]);
        }
        puts("");
    }

    return EXIT_SUCCESS;
}
