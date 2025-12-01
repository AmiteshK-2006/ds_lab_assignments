#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int>&nums){
    int n=nums.size();
    for(int i=0 ; i<n-1; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j] , nums[j+1]);
            }
        }
    }
}

void insertion(vector<int>&nums){
    int n=nums.size();
    for(int i=1 ; i<n ; i++){
        int key=nums[i];
        int j=i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}

void selection(vector<int>&nums){
    int n=nums.size();
    for(int i=0 ; i<n ; i++){
        int flag=i;
        for(int j=i+1 ; j<n ; j++){
            if(nums[j]<nums[flag]) flag=j;
        }
        swap(nums[flag] , nums[i]);
    }
}


//MERGE
void f1(vector<int>&nums , int l , int mid , int r){
    vector<int>ans;
    int a=l , b=mid+1;
    while(a<=mid && b<=r){
        if(nums[a]<=nums[b]){
            ans.push_back(nums[a]);
            a++;
        }else{
            ans.push_back(nums[b]);
            b++;
        }
    }
    while(a<=mid){
        ans.push_back(nums[a]);
        a++;
    }
    while(b<=r){
        ans.push_back(nums[b]);
        b++;
    }
    for(int i=l ; i<=r ; i++){
        nums[i]=ans[i-l];
    }
}

void merge(vector<int>&nums , int l , int r){
    if(l==r) return;
    int mid=l+(r-l)/2;
    merge(nums , l , mid);
    merge(nums , mid+1 , r);
    f1(nums , l , mid , r);
}



//QUICK

int f2(vector<int>&nums , int l , int r){
    int pivot=nums[l];
    int a=l , b=r;
    while(a<b){
        while(a<=r && nums[a]<=pivot) a++;
        while(b>=0 && nums[b]>pivot) b--;
        if(a<b){
            swap(nums[a] , nums[b]);
        }
    }
    swap(nums[l] , nums[b]);
    return b;
}

void quick(vector<int>&nums , int l , int r){
    if(l<r){
        int pivot=nums[l];
        int idx=f2(nums , l , r);
        quick(nums , l , idx-1);
        quick(nums , idx+1 , r);
    }
}




int main(){
    vector<int>nums={9,9,9,1,9,2,1,8,3,7,8,943,8,8,4,6,5};
    merge(nums , 0 , nums.size()-1);
    for(int i:nums) cout<<i<<" ";
}