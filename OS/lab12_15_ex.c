#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct statqueue
{
    char filename[1024];
    struct stat statbuff;
    struct statqueue* next; 
}Qstat;

typedef Qstat* pQstat;

//bfs
static int get_file_size_time_bfs(const char *filename)
{   
    pQstat head, end;
    head = (pQstat)malloc(sizeof(Qstat));

    if(stat(filename, &(head->statbuff)) == -1)
    {
        printf("Get stat on %s Error: %s\n", filename, strerror(errno));
        return -1;
    }
    strcpy(head->filename, filename);
    head->next = NULL;
    end = head;
    while(head != NULL)
    {
        char *filename = head->filename;
        if(stat(filename, &(head->statbuff)) == -1)
        {
            printf("Get stat on %s Error: %s\n", filename, strerror(errno));
            return -1;
        }
        struct stat statbuff = head->statbuff;
        if(S_ISREG(statbuff.st_mode))  //如果是文件，输出
            //printf("filename: %s  size: %1dbytes\t modifiedat %s", filename, statbuff.st_size, ctime(&statbuff.st_mtime));
            printf("Filename: %-30s | Size: %10ld bytes | Modified at: %s", filename, statbuff.st_size, ctime(&statbuff.st_mtime));
        if(S_ISDIR(statbuff.st_mode)) //如果是目录，进队
        {
            DIR *dirp;
            struct dirent *direntp;

            if((dirp = opendir(head->filename)) == NULL)
            {
                printf("Open Directory %s Error:%s\n", head->filename, strerror(errno));
                return 1;
            }
            while((direntp = readdir(dirp)) != NULL)
            {
                if(!strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..")) continue;
                pQstat newNode;
                newNode = (pQstat)malloc(sizeof(Qstat));
                memset(newNode->filename, 0, 1024);
                strcpy(newNode->filename, head->filename);
                strcat(newNode->filename, "/");
                strcat(newNode->filename, direntp -> d_name);
                //进队
                newNode->next = end->next;
                end->next = newNode;
                end = newNode;
            }

            closedir(dirp);
        }
        pQstat oldNode = head;
        head = head->next; //出队
        free(oldNode);
    }
    
    
    return 0;
}

//dfs
static int get_file_size_time_dfs(const char *filename)
{   
    struct stat statbuff;
    if(stat(filename, &statbuff) == -1)
    {
        printf("Get stat on %s Error: %s\n", filename, strerror(errno));
        return -1;
    }
    if(S_ISREG(statbuff.st_mode))
        printf("Filename: %-30s | Size: %10ld bytes | Modified at: %s", filename, statbuff.st_size, ctime(&statbuff.st_mtime));
    if(S_ISDIR(statbuff.st_mode))
    {
        DIR *dirp;
        struct dirent *direntp;

        if((dirp = opendir(filename)) == NULL)
        {
            printf("Open Directory %s Error:%s\n", filename, strerror(errno));
            exit(1);
        }
        while((direntp = readdir(dirp)) != NULL)
        {
            char path[1024];
            if(!strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..")) continue;
            memset(path, 0, 1024);
            strcpy(path, filename);
            strcat(path, "/");
            strcat(path, direntp -> d_name);
            get_file_size_time_dfs(path);
    
        }

        closedir(dirp);
    }
    
    return 0;
}



int main(int argc, char **argv)
{
    DIR *dirp;
    struct dirent *direntp;
    int stats;
    char path[1024];
    if(argc != 2)
    {
        printf("Usage:%s filename\n\a", argv[0]);
        exit(1);
    }

    puts("BFS_result:");
    if(((stats = get_file_size_time_bfs(argv[1])) == 1) || (stats == -1))
        exit(1);

    puts("\nDFS_result:");
    if(((stats = get_file_size_time_dfs(argv[1])) == 1) || (stats == -1))
        exit(1);
    
    return 0;
}