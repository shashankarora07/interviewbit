#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


void FileArchType(char *filename)
{
    char *file_name = (char *)malloc(sizeof(char)*160);
    //char *file_name[160];
    strcpy(file_name,filename);
    char str[160] = "readelf -h ";
    char *comm = strcat(str,file_name);
    char *command = strcat(comm, "| grep Machine: 2>&1 > test.txt"); 
    system(command);
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) { perror("failed"); exit(1); }
    memset(file_name,0,160);
    int bytes = read(fd,file_name,160);
    //printf("bytes = %d\n",bytes );
    if (bytes <= 0) {
        printf("%s : Not an ELF file\n",filename);
        return;
    }
    //printf("file_name = %s\n",file_name);
    char *token = strtok(file_name,":");
    while(isspace(*token)) token++;
    //printf("starting token =%s\n",token);
    int i = 0;
    if (strcmp(token,"Machine") == 0) {
        while( token != NULL) {
        while(isspace(*token)) token++;
        //printf("token =%s\n",token);
        int len_of_token = strlen(token);
       // printf("len_of_token = %d\n",len_of_token);
       // printf("AA kehra token =%s\n",token);
       // while(token[i] != '\0')
        //    printf("%d ",token[i++]);
       // printf("\n");
        i = 0;
        if (token == NULL)
            break;

        if (strcmp(token,"ARM\n") == 0) {
            printf("%s : armeabi-v7a\n",filename);
            break;
        }
        if (strcmp(token,"Intel 80386\n") == 0) {
            printf("%s : x86\n",filename);
            break;
        }
        token = strtok(NULL, ":");
        }
     }

    close(fd);
    free(file_name);
}

int main(void)
{
    struct dirent *de;  // Pointer for directory entry
    char *tmp;
    char file_name[160];
    int count = 0;
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir(".");

    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    printf("File Arch Type\n");
    printf("======= =========== =======\n");
    while ((de = readdir(dr)) != NULL)
    {
        //printf("%s\n", de->d_name);
        memset(file_name, 0, sizeof(file_name));
        strcpy(file_name, de->d_name);
        tmp = (char *)strtok(file_name,".");
        //printf("tmp first = %s\n",tmp);
        if (tmp != NULL)
        {
            tmp = (char *)strtok(NULL, ".");
          //  printf("tmp = %s\n",tmp);
            if ((tmp != NULL) && (strncmp(tmp, "so", 2) == 0))
            {
                //printf("This is shared object: %s\n", de->d_name);
                count++;
                FileArchType(de->d_name);
            }
        }
    }
    printf("======= ============ ========\n");
    printf("Total number of libraries: %d\n",count);

    closedir(dr);

    return 0;
}