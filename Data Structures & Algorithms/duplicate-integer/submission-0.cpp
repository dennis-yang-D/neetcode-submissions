class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dups;

        for(int i : nums)
        {
            if(dups.contains(i)) {return true;}
            dups.insert(i);
        }

        return false;
    }
};