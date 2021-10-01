#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using std::vector; using std::cout; using std::endl;
using std::map;    using std::sort; using std::string;
using std::unordered_map;
/*
 Given two integer arrays nums1 and nums2, 
 return an array of their intersection.
 Each element in the result mush appear as many times as it shows in both arrays
 and you may return the result in any order
*/
vector<int> result;
vector<int> intersect(vector<int>& nums1, vector<int> & nums2);
void fillTable(unordered_map<int,int>  & Table, const vector<int> & Arr);
void findT(unordered_map<int,int> & Table, vector<int> & Arr1, vector<int> & Arr2);


int main(int argc, char * argv[])
{
    vector<int> nums1={1,2};//{1,2,2,1};//{4,9,5};
    vector<int> nums2={1,1};//{2,2};//{9,4,9,8,4};
    vector<int> result;
    result=intersect(nums1,nums2);
    for(int index=0; index< result.size(); ++index)
    {
        cout<<result[index]<<endl;
    }

	return 0;
}



vector<int> intersect(vector<int> & nums1, vector<int> & nums2){
    unordered_map<int,int> Table;
    int size1=nums1.size();
    int size2=nums2.size();
    if(size1>=size2)
    {
       // sort(nums1.begin(),nums1.end());
        fillTable(Table,nums1);
        findT(Table, nums1,nums2);
    }
    else{
        //sort(nums2.begin(),nums2,end());
       fillTable(Table,nums2);
       findT(Table, nums2,nums1);
    }
    return result;
}	

void findT(unordered_map<int,int> & Table, vector<int> & Arr1, vector<int> & Arr2)
{
       int size1=Arr1.size();
       int size2=Arr2.size();
       int prev=-100;
       for(int index=0; index<size1; ++index)
       {
       if(index<size2 && ((Table.find(Arr2[index])!=Table.end()) && Table[Arr2[index]] > 0))
           {
                result.push_back(Arr2[index]);   
                Table[Arr2[index]]--;
           }
       }       
}

void fillTable(unordered_map<int,int>  & Table, const vector<int> & Arr)
{
    int size1=Arr.size();
    for(int index=0; index<size1; ++index){
       
       Table[Arr[index]]++;
   }
}
