#include <iostream>
#include <vector>
#include <map>

using std::vector; using std::cout; using std::endl;
using std::map;

/****************************************************************************
* Given an array nums of size n, return the majority element.
*
* The majority element is the element that appears more than [n / 2] times.
* You may assume that the majority element always exists in the array.
* CONSTRAINTS:
*
*    n == nums.length
*   1 <= n <= 5 * 104
*   -231 <= nums[i] <= 231 - 1
*
******************************************************************************/
int majorityElementBrute(vector<int> & nums);
int majorityElementBetter(vector<int> & nums);
int majorityElementOp(vector<int> & nums);

int main(int argc, char * argv[]){
	//vector<int> nums={2,2,1,1,1,2,2};
    vector<int> nums={3,2,1,1,1,2,2,3,3,1,-1};
    //vector<int> nums={6,6,6,7,7};
    //vector<int> nums={3,2,3};
	cout<<majorityElementBrute(nums)<<endl;
    	cout<<majorityElementBetter(nums)<<endl;
        cout<<majorityElementOp(nums)<<endl;
	return 0;
}
/*
 Brute force solution would be to iterate thru the array
 to find how many times a number repeats this will be done in
 O(n^2) time;
*/
int majorityElementBrute(vector<int> & nums){
    int size=nums.size();
    int counter=0, result=0, majorelem=0;
    int target=-1;
    for(int index=0; index<size; ++index)
    {
        target=nums[index];
        for(int j=0; j< size; ++j)
        {
            if(target==nums[j])
            {
                counter++;
            }
        } 
        if(index==0 || counter>result)
        {
            result=counter;
            majorelem=target;
        }
        counter=0;
    }
    return majorelem;
}

/*
 A sightly better solution would be to add array elements onto a map
 then iterate thru the map to obtain the majority Element in O(n) time;
*/
int majorityElementBetter(vector<int> & nums)
{
    map<int,int> Table;
    int size=nums.size();
    int counter=0, target=0;
    for(int index=0; index<size; ++index)
    {
      Table[nums[index]]++;  
    }
    counter=Table.find(nums[0])->second;
    target=nums[0];
    for(int index=1; index<size;++index)
    {
        int x=Table.find(nums[index])->second;
        if(x > counter)
        {
            counter= x;
            target=nums[index];            
        }
    }
    return target;
}

/*
    An optimal solution would be to use the moores voting algo
    This will give us a solution in linear time O(n) and in O(1) space.
*/
int majorityElementOp(vector<int> & nums)
{ //6 ,6 , 6, 7, 7
   int count=0;
   int element=0;
   int size=nums.size();
   for(int index=0; index<size; ++index)
   {
       if(count==0)
       {
            element=nums[index];
       }
       if(nums[index]==element)
       {
           count++;
       }
       else
           count--;
   }
   return element;
}