#include <iostream>
#include <vector>

/*Given a sorted array of distinct intengers and a target value, return the index if the target is found. 
 *If now, return the index where it would be if it were inserted in order.
 * Algorithm has a O(log n) runtime complexity.*/
int searchInsert(std::vector<int>& nums, int target){
	int mid,low=0,high=nums.size()-1;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(nums[mid]==target) return mid;
		if(nums[mid]>target) high=mid-1;
		else low=mid+1;
	}
	return low;
}

int main(int argc, char * argv[])
{
	std::vector<int> nums={1,3,5,6,7};
	int target=5;
	std::cout<<searchInsert(nums,target)<<std::endl;
	return 0;
}
