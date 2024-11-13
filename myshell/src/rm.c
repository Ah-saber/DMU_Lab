#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>



void rm_file_r(char *file_name)
{
    if(remove(file_name) != 0)
    {
        perror("rm file");
    }
}

void rm_file(char **file_name)
{
    int i = 0;
    while(file_name[i] != NULL)
    {
        rm_file_r(file_name[i]);
        i ++;
    }
}

void rm_dir_r(char *dir_name)
{

    DIR *dir = opendir(dir_name);
    struct dirent *entry;
    char path[1024];

    if(dir == NULL)
    {
        perror("opendir");
        return;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        if(entry->d_type == DT_DIR) //编译后不报错
        {
            rm_dir_r(path);
        }
        else
        {   
            rm_file_r(path);
        }
    }

    closedir(dir);
    rm_file_r(dir_name);
}

void rm_dir(char **dir_name)
{
    int i = 0;
    while(dir_name[i] != NULL)
    {
        rm_dir_r(dir_name[i]);
        
        i ++;
    }
}

int main(int argc, char **argv)
{
    //printf("%d", argc);
    
   
    if(argc < 2)
    {
        puts("No remove object");
        return 1;
    }

    if(!strcmp(argv[1], "-d"))
    {
        //remove dir
        rm_dir(argv + 2);
    }
    else
    {
        //remove file
        rm_file(argv + 1);
    }

    return 1;

}
