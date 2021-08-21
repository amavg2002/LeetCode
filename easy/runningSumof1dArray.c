#include <stdlib.h>
#include <stdio.h>

int * runningSum(int * nums, int numsSize, int * returnSize);
int * runningSumOp(int * nums, int numsSize, int * returnSize);
void printarr(int * num, int size);


int main(int argc, char * argv[])
{ 
  int nums[]={1,2,3,4};
  int nums2[]={1,1,1,1,1};
  int nums3[]={3,1,2,10,1};
  int * result;
  result=runningSum(nums,4,result);
  printarr(result,4);
  free(result);
  result=runningSum(nums2,5,result);
  printarr(result,5);
  free(result);
  result=runningSum(nums3,5,result);
  printarr(result,5);
  free(result);  
    result=runningSumOp(nums,4,result);
  printarr(result,4);
  free(result);
  result=runningSumOp(nums2,5,result);
  printarr(result,5);
  free(result);
  result=runningSumOp(nums3,5,result);
  printarr(result,5);
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

int * runningSum(int * nums, int numsSize, int * returnSize)
{
    int * result=malloc(sizeof(int)*numsSize);
    if(!result)
    {
        return NULL;
    }
     result[0]=nums[0];
    if(numsSize>=2){
        int sum=nums[0]+nums[1];
        result[1]=sum;
        for(int index=2;index<numsSize;index++)
        {
            sum+=nums[index];
            result[index]=sum;
        }
    }
    return result;
}

int * runningSumOp(int * nums, int numsSize, int * returnSize)
{
    int runSum=0;
    *returnSize=numsSize;
    int * resultArr=malloc(sizeof(int)*numsSize);
    for(int index=0; index < numsSize; index++)
    {
        runSum+=nums[index];
        resultArr[index]=runSum;
    } 
    return resultArr;
}