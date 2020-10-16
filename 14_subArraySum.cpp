#include <bits/stdc++.h>

using namespace std;

int subArraySum(vector<int> v, int k)
{
	/**
	 * This is brute force approach
	 * check each subarray sum is equal to k or not
	 * Complexity O(n^2)
	 * */
	int len=v.size();
	int ans=0,sum;
	
	for(int i=0;i<len;i++)
	{
		sum=0;
		for(int j=i;j<len;j++)
		{
			sum+=v[j];
			if(sum==k) ans++;
		}
	}
	
	return ans;
}

int subArraySumOptimal(vector<int> v, int k)
{
	/**
	 * Store qumulative sum and check is there any sum-k present
	 * in previous any qumulative sum
	 * Complexity O(n)
	 * */
	
	int len=v.size();
	int ans=0,sum=0;
	unordered_map<int,int> mp;
	
	for(int i=0;i<len;i++)
	{
		mp[sum]++;
		sum+=v[i];
		ans+=mp[sum-k];
	}
	
	return ans;
}

int main()
{
	vector<int> v={1,5,-6,8,-2,3,7,-3};
	
	cout << subArraySum(v,5) << endl;
	cout << subArraySumOptimal(v,5) << endl;
	
	return 0;
}

