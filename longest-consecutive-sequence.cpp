class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int longest = 0;
        map<int, bool> m;
        
        for (int i:nums) 
        {
            m[i] = false;
        }
        
        for (int i:nums) 
        {
            if (m[i])
            { 
                continue;
            }

            int length = 1;
            m[i] = true;

            
            int j=i+1;
            while(m.find(j) != m.end()) 
            {
                length++;
                m[j] = true;
                j++;
            }

            j=i-1;
            while(m.find(j) != m.end())
            {
                length++;
                m[j] = true;
                j--;
            }

            longest=max(longest,length);
        }
        
        return longest;
    }
};
