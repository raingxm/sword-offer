#include <stdio.h>

bool Find(int *matrix,int rows,int columns,int number){
    if(matrix != NULL && rows > 0 && columns > 0){
        int rowIndex = 0;
        int columnIndex = columns - 1;
        while(rowIndex < rows && columnIndex >=0){
            if(matrix[rowIndex*rows + columnIndex] == number){
                return true;
            }else if(matrix[rowIndex*rows + columnIndex] > number){
                columnIndex--;
            }else{
                rowIndex++;
            }
        }
    }
    return false;
}

void Test(char* testname,int *matrix,int rows,int columns,int number,bool expected){
    if(testname != NULL){
        printf("%s Begin: ",testname);
    }
    bool result = Find(matrix,rows,columns,number);
    
    if(result == expected){
        printf("Success!\n");
    }else{
        printf("Failed!\n");
    }
}

void Test_Case_1(){
    int matrix[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    
    Test("Test_Cast_1",(int*)matrix,4,4,7,true);
}

void Test_Case_2(){
    Test("Test_Cast_2",NULL,0,0,19,false);
}

int main(int argc,char* argv[]){
    Test_Case_1();
    Test_Case_2();
    return 0;
}
