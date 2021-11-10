#include <iostream>
#include <vector>
#include <map>

using std::vector; using std::map; using std::cout;
using std::cin; using std::endl;

vector<int> twoSum(vector<int> & nums, int target);

int main(int argc, char * argv[]){
   // vector<int> nums={2,7,11,15};
    vector<int> nums={1,3,4,2};
    vector<int> result=twoSum(nums,6);
    for(int index=0; index<2;++index){
        cout<<result[index];
    }        
    cout<<endl;
       return 0;
}

vector<int> twoSum(vector<int> & nums, int target){
        if(!nums.empty()){
            map<int,int> myMap;
            int size=nums.size();
            for(int index=0; index<size; ++index)
            {
                //find=target-nums[index];
                if(myMap.find(target-nums[index]) != myMap.end())
                {
                    return{index, myMap[target-nums[index]]};     
                }
                myMap[nums[index]]=index;
            }
        }
        return {};
}
