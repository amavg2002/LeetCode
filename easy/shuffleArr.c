#include <stdio.h>
#include <stdlib.h>

int * shuffle(int * nums, int numsSize, int n, int * returnSize);
void printarr(int * num, int size);

int main(int argc, char * argv[]){
    int nums[]={2,5,1,3,4,7};
    int n=3, size=0;
    int * result=shuffle(nums,6,n,&size);
    printarr(result,size);
    free(result);
return 0;
}
void printarr(int * num, int size)
{   
    int index=0;
    printf("array: [ ");
    for(; index<size-1; index++)
    {
        printf("%d, ",num[index]);
    }
    printf("%d ]\n",num[index]);
}
int * shuffle(int * nums, int numsSize, int n, int * returnSize)
{
    int * result=malloc(sizeof(int)* numsSize);
    int count=0;
    for(int index=0; index < numsSize/2; index++)
    {
        result[count++]=nums[index];
        result[count++]=nums[index+n];
        
    }
    *returnSize=numsSize;
    return result;
}

