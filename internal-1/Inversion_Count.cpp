
#include<iostream>
using namespace std;
int merge(int a[],int l,int mid,int h){
	int n1=mid-l+1;
	int n2=h-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
		left[i]=a[l+i];
	for(int i=0;i<n2;i++)
		right[i]=a[mid+1+i];
		
	int i=0,j=0,k=l,count=0;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			a[k++]=left[i++];
		}
		else{
			a[k++]=right[j++];
			count+=(n1-i);
		}
	}
	while(i<n1)
		a[k++]=left[i++];
	while(j<n2)
		a[k++]=right[j++];
	return count;
}
int mergesort(int a[],int l,int h){
	if(l<h){
		int mid=l+(h-l)/2;
		int leftcount=mergesort(a,l,mid);
		int rightcount=mergesort(a,mid+1,h);
		
		int count=merge(a,l,mid,h);
		return leftcount+rightcount+count;
	}
	return 0;
}

int inversionCount(int a[],int n){
	return mergesort(a,0,n-1);
}

int main(){
	int a[100],n;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"Count:"<<inversionCount(a,n)<<endl;	
	
	return 0;
}
