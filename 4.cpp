#include <stdio.h>
#include <string.h>

void ReplaceBlank(char str[],int length){
	if(str == NULL || length <= 0){
		return;
	}
	int blankNums = 0;
	int originLength = 0;
	int i = 0;
	while(str[i] != '\0'){
		originLength++;
		if(str[i] == ' '){
			blankNums++;
		}
		i++;
	}
	
	int newLength = 2*blankNums  + originLength;
	if(newLength > length){
		return ;
	}
	
	int indexNew = newLength - 1;
	int indexOld = originLength - 1;
	while(indexOld >= 0){
		if(str[indexOld] != ' '){
			str[indexNew] = str[indexOld];
			indexNew--;
			indexOld--;
		}else{
			str[indexNew] = '0';
			str[indexNew-1] = '2';
			str[indexNew-2] = '%';
			indexNew -= 3;
			indexOld--;
		}
	}
}

void Test1(){
	char str[50] = "hello world";
	char expected[50] = "hello%20world";
	ReplaceBlank(str,50);
	if(strcmp(str,expected) == 0){
		printf("Test1 Success!\n");
	}else{
		printf("Test1 Failed!\n");
	}
}

void Test2(){
	char str[50] = "we are happy";
	char expected[50] = "we%20are%20happy";
	ReplaceBlank(str,50);
	if(strcmp(str,expected) == 0){
		printf("Test2 Success!\n");
	}else{
		printf("Test2 Failed!\n");
	}
}

void Test3(){
	char str[50] = " hello ";
	char expected[50] = "%20hello%20";
	ReplaceBlank(str,50);
	if(strcmp(str,expected) == 0){
		printf("Test3 Success!\n");
	}else{
		printf("Test3 Failed!\n");
	}
}

int main(){
	Test1();
	Test2();
	Test3();
	return 0;
}