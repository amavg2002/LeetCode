#include <iostream>
#include <vector>
#include <algorithm>
/****************************************************************
 *								*
 * Given an integer array (nums), return true if any value	*
 * appears at least twice in the array, and return false if	*
 * every element is distinct.					*
 *								*
 ****************************************************************/
using std::vector; using std::cout; using std::endl;
using std::sort;

bool containsDuplicate(vector<int> & nums);

int main(int argc, char * argv[])
{
	vector<int> nums={1,2,3,1};
	if(containsDuplicate(nums))
	{
		cout<<"Array contains Duplicates!!"<<endl;
	}
	else
	{
		cout<<"Array Does Not Contain Duplicates!!!"<<endl;
	}
	return 0;
}


/*************************************************************************************
 * First sort the array using c++ stl sorting algorithm (NLogN) time
 * Then compare each i index to i+1 index, if the two numbers are the same
 * return true. worse case N comparisons. 
 * If no duplicates found then return false
 * ***********************************************************************************/
bool containsDuplicate(vector<int> & nums){
	sort(nums.begin(),nums.end());
	int size=nums.size();
	for(int index=0; index<size; ++index){
		if( (index+1 < size) && ( nums[index] == nums[index+1]) )
		{
			return true;
		}
	}
	return false;
}
	
	
