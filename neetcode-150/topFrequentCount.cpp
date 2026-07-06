#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namepace std;

class solution{
	public: 
		vector<int> topFrequent(vector<int>&nums,int k){
			unorderd_map<int,int>freq;

			//count frequencies
			for(int num:nums) {
				freq[num]++;
			}

			//Min heap:(frequency,number)
			priority_queue<
				pair<int,int>,
				vector<pair<int,int>>,
				greater<pair<int,int>>
				>minHeap;

			//keep only the k largest frequencies
			for(auto pair : freq){
				minHeap.push({pair.second,pair.first});

				if(minHeap.push({pair.second,pair.first}));

				if(minHeap.size()>k){
					minHeap.pop();
				}
			}

			vector<int>ans;

			while(!minHeap.empty()){
				ans.pushback(minHeap.top().second);
			}

			return ans;
		}
};
