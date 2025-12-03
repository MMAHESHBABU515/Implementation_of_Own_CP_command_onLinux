#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define buffer 4096
int main(int argc,char** argv)
{
int fd,dd;
size_t nread;
char b[buffer];

if(argc!=3)
{
printf("USAGE: <sourc_file> <destination_file>\n");
return 0;
}
fd=open(argv[1],O_RDONLY);
if(fd<0)
{
perror("Error opening source file");
return 0;
}

dd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
if(dd<0){
perror("error opening destination file");
close(dd);
return 0;
}

while((nread=read(fd,b,buffer))>0)
{
if(write(dd,b,nread)!=nread){
perror("error writing to destination file");
close(fd);
close(dd);
return 0;
}

}

if(nread<0)
{
perror("error reading from source");
}

close(fd);
close(dd);


printf("file %s successfully copied to %s.\n",argv[1],argv[2]);

return 0;
}
