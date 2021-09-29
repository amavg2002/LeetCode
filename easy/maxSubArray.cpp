#include <iostream>
#include <vector>
#include <algorithm>

using std::vector; using std::max; using std::cout; using std::endl;

int maxSubArray(vector<int> & nums){
	int size=nums.size();
	if(size==0){
		return 0;
	}
	int maxSum=nums[0];
	int sum_plus_curr=nums[0];
	for(int index=1; index<size; ++index){
	   int n=nums[index];
	   sum_plus_curr=max(sum_plus_curr+n,n);
	   maxSum=max(maxSum,sum_plus_curr);

	}
	return maxSum;
}

int main(int argc, char * argv[]){
	vector<int> nums={5,4,-1,7,8};
	cout<<maxSubArray(nums)<<endl;
	return 0;
}
