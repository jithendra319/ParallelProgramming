#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<asm/unistd.h>
#include<stdlib.h>
void readFile(char fileName[1000]);
void checkpatternerror(char fileName[1000]);
int n=0;
int count=0,countn;
struct complex{
int real,imag;
};

struct complex multiply(struct complex a , struct complex b );
void *runner(int* a);
struct complex *comp;
int main(int argc,char *argv[])
{

	char *fileName=argv[1];
	checkpatternerror(fileName);
    	readFile(fileName);
    	pthread_t tid[n+1];   
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int x=n,i;
	
	while(x>0){
		for( i=0;i<x/2;i++){
			pthread_create(&tid[i],&attr,(void *)runner, &i );
			pthread_join(tid[i],NULL);	
		}
	
		if(x%2==1 && x!=1){
			struct complex z;
			int b=x;
			x=x/2+1;
			comp[x-1].real = comp[b-1].real;
			comp[x-1].imag = comp[b-1].imag;
		}
		else{
			x=x/2;
		}
		count+=1;			
		}
	return 0;

}


void *runner (int* a )
{
	struct complex z;
		z = multiply(comp[2*(*a)],comp[2*(*a)+1]);
		printf("\nThread%d%d multiplication value is : %d+i%d \n",count,*a, z.real, z.imag);	
		comp[*a].real = z.real;
		comp[*a].imag = z.imag;
	
	pthread_exit(0);

}

void checkpatternerror(char fileName[1000]){

    FILE *filePtr;
    char str,str1,str2;
    int real,imag;
    filePtr= fopen(fileName,"r");
    fscanf(filePtr, "%d",&n);
    while (fscanf(filePtr, " %d%c%c%d", &real,&str,&str1,&imag) != EOF)   
    {
    if(str=='-'){
    	printf("Please enter in the form of a+ib in the text file ");
    	exit(0);
    }   
    
    if(str1!='i'){
    	printf("Please enter in the form of a+ib in the text file ,you have entered some number in the other form");
    	exit(0);
    }
    
	countn+=1;	
    }
    
    if(countn>n || countn<n)
    {
    	printf("You Defined n as %d ,But You declared %d numbers. Please check",n,countn);
    	exit(0);
    }
    
    fclose(filePtr);


}
void readFile(char fileName[1000])

{
    FILE *filePtr;
    int real=0;
    int imag=0,status;
    int position = 0;
    filePtr= fopen(fileName,"r");
    fscanf(filePtr, "%d",&n);
    comp = (struct complex*)malloc(10000*sizeof(struct complex));
    while (fscanf(filePtr, " %d+i%d", &real, &imag) != EOF)   
    {
        comp[position].real = real;
        comp[position].imag = imag;
        position++;
	
    }
    comp = realloc(comp,n*sizeof(struct complex));
    fclose(filePtr);
}



