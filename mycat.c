#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char** argv){
  if(argc < 2){
	  while(1){
		 char string[100];
		 int size = read(0,string,100);
		 write(1,string,size);
	  }
  }else{
     int i = 1;
     for(;i<argc;i++){
        int fp = open(argv[i],O_RDONLY);
        if(fp < 0){
		   perror(argv[i]);
		   close(fp);
        }
        else{
			char string[1000];
			int size = read(fp,string,1000);
			write(1,string,size);
			close(fp);
        }
     }
     return 0;
  }
}
