// SumItUp

#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;
int B;
set<vector<int> > mp;
vector<vector<int> > ans;
void Helper(vector<int> &arr,int i,int rq,vector<int> Cmb){
//base case
	if(arr.size()<i&&rq<0) return;
    if(i==arr.size()-1) return;
    if(rq==0){
    	if(!Cmb.empty()&&mp.find(Cmb)==mp.end()){
    		mp.insert(Cmb);
    		ans.push_back(Cmb);
    	}
    }
    //Case 1 array element is Involve in combination
    Cmb.push_back(arr[i]);
    Helper(arr,i+1,rq-arr[i],Cmb);
    Cmb.pop_back();//backtraceint
    //case 2  array element is ignore for combination
    Helper(arr,i+1,rq,Cmb);
    //case 3 New combination is now start from current element
    vector<int> Cmb2;
    Cmb2.push_back(arr[i]);
    Helper(arr,i+1,B-arr[i],Cmb2);
    return;
}
vector<vector<int> > FindSumDistinct(vector<int> &arr,int trgt ,vector<int> &Cmb){
 if(arr.size()==0||trgt==0) return ans;
 Helper(arr,0,trgt,Cmb);
 return ans;
}

int main(){
	ans.clear();
    mp.clear();
  	int n;
  	cin>>n;
  	vector<int> arr(n);
  	for(int i=0;i<n;i++) cin>>arr[i];
  		sort(arr.begin(),arr.end());
    int trgt;
    cin>>trgt;
    ::B=trgt;
    vector<int> Cmb;
  	vector<vector<int> > ans=FindSumDistinct(arr,trgt,Cmb);
  	    sort(ans.begin(),ans.end());

  	for(auto v:ans){
  		for(int p:v){
  			cout<<p<<" ";
  		}
  		cout<<endl;
  	}
}