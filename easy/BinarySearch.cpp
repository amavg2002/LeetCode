#include <iostream>
#include <vector>

int search(std::vector<int> & nums, int target);

int main(int argc, char * argv[])
{
	std::vector<int> nums= {-1,0,3,5,9,12};
	int result= search(nums,9);
	std::cout<<result<<std::endl;
	return 0;
}

/* Search function implements a binary search to find a target value
 * algorithm has 0(log n) runtime complexity*/

int search(std::vector<int> & nums, int target){
	int mid, low=0, high=nums.size()-1;
	while(low<=high){
		mid=low+(high-low)/2;
		if(nums[mid]==target) return mid;
		if(nums[mid]>target) high=mid-1;
		else low=mid+1;
	}
	return -1;
}
