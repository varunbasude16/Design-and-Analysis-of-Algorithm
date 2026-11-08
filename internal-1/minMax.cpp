#include<iostream>
using namespace std;
void minmax(int a[],int l,int h ,int &min,int &max){
    if(l==h) {
        min=max=a[0];
    }
    else if (h-1==l){
        if(a[l]<a[h]){
            min = a[l];
            max = a[h];
        }
        else{
            min = a[h];
            max = a[l];
        }
    }
    else{
        int mid = (l+h)/2;
        int min1,max1;
        minmax(a,l,mid,min,max);
        minmax(a,mid+1,h,min1,max1);
        if(min1<min)
            min = min1;
        if(max1>max)
            max =max1 ;

    }

}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter elements:";
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];

        int min, max;
    minmax(a,0,n-1,min,max);
    cout<<"Max:"<<min<<" Min:"<<max<<endl;
    return 0;
}