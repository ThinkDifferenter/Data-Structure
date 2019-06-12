#include<stdio.h>

int main(){
	int n = 100;
	int i = 1;
	int j = 0;
	int cnt = 0;
	
	while(i+j <= n){
		if(i>j){
			j++;
			cnt++;
		}else{
			i++;
		}
	}
	
	printf("%d\n",cnt);
	return 0;
} 
