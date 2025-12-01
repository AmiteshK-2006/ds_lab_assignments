#include<bits/stdc++.h>
using namespace std;

void selection(vector<int>&nums){
    int n=nums.size();
    int l=0 , r=n-1;
    while(l<r){
        int f1=l , f2=r;
        for(int j=l ; j<=r ; j++){
            if(nums[j]<nums[f1]) f1=j;
            if(nums[j]>nums[f2]) f2=j;
        }
        swap(nums[l] , nums[f1]);
        if(f2==l) f2=f1;
        swap(nums[r] , nums[f2]);
        l++; r--;
    }
}

int main(){
    vector<int>nums={9,1,8,2,7,3,6,6,6,20,3,3,3,6,343,232,34,3434,34,4,5};
    selection(nums);
    for(int i:nums) cout<<i<<" ";

    return 0;
}