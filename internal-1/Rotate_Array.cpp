
#include<iostream>
#include<vector>
using namespace std;

void swap(int& a,int& b){
        int t=a;
        a=b;
        b=t;
#include<iostream>
#include<vector>
using namespace std;

void swap(int& a,int& b){
        int t=a;
        a=b;
        b=t;
}
void rev(vector<int>& nums,int l,int h){
        while(l<h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
        
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);        
  
}
int main() {
    
    int  k ;
    vector<int> nums ;
    cout<<"Enter arraysize:";
    int n;
    cin>>n;
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);  
    }
    cout<<"Enter rotation value(k):";
    cin>>k;
    
   rotate(nums,k);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    // INPUT: 1 2 3 4 5 6 7 
    // OUTPUT:  5 6 7 1 2 3 4 S
    return 0;
}
}
void rev(vector<int>& nums,int l,int h){
        while(l<h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
        
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);        
  
}
int main() {
    
    int  k ;
    vector<int> nums ;
    cout<<"Enter arraysize:";
    int n;
    cin>>n;
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);  
    }
    cout<<"Enter rotation value(k):";
    cin>>k;
    
   rotate(nums,k);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    // INPUT: 1 2 3 4 5 6 7 
    // OUTPUT:  5 6 7 1 2 3 4 S
    return 0;
}
