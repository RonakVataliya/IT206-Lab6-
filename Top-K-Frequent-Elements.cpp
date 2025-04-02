class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        map<int,int> m;//<num,freq>

        for (int i:nums) 
        {
            m[i]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for (const auto& i:m) 
        {
            bucket[i.second].push_back(i.first);
        }

        for (int pos=bucket.size()-1;pos>=0 && ans.size()<k;--pos) {
            if (!bucket[pos].empty()) {
                ans.insert(ans.end(), bucket[pos].begin(), bucket[pos].end());
            }
        }

        return ans;
    }
};
