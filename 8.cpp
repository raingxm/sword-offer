#include <iostream>
using namespace std;

int Min(int* number,int length){
	int leftIndex = 0;
	int rightIndex = length - 1;
	int midIndex = (leftIndex + rightIndex)/2;
	while(leftIndex < rightIndex){
		midIndex = (leftIndex + rightIndex)/2;
		if(rightIndex - leftIndex == 1){
			if(number[leftIndex] < number[rightIndex]){
				midIndex = leftIndex;
			}else{
				midIndex = rightIndex;
			}
			break;
		}
		
		if(number[leftIndex] < number[midIndex]){
			leftIndex = midIndex + 1;
		}else{
			rightIndex = midIndex;
		}
		midIndex = (leftIndex + rightIndex)/2;
	}
	
	return number[midIndex];
}

	
void Test1(){
	int number[] = {4,5,6,2,3};
	int length = 5;
	cout << Min(number,length) << endl;
}

int main(){	
	Test1();
	return 0;
}