#include<iostream>
#include<vector>
#include<unorderd_set>
using namespace std;

bool contain duplicate(vector<int>&nums){
     unorderd_set<int> seen;
	for(int num:nums){
	   if(seen.find(num)!=seen.end(num))
		return true;
		seen.insert(num);
	}
     return false;
}
