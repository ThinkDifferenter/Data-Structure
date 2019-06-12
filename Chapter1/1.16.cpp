#include<stdio.h>


void swap(int *p,int *q);
void sort();


int main(){
	sort();
	for(int i=0;i<10;i++){
		printf("%d\t",i);
	} 
	return 0;
} 

void swap(int *p,int *q){
	int tmp=*p;
	*p=*q;
	*q=tmp;
}

void sort(){
	int x=6;
	int y=3;
	int z=9;
	int tmp;
	
	if(x<y){
		swap(&x,&y);
	} 
	
	if(y<z){
		swap(&y,&z);
	}
	
	if(x<y){
		swap(&x,&y);
	}
	
	printf("%d\t%d\t%d\n",x,y,z);
}







