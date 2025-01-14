class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int windowStart = 0;
        map<int, int> distinct;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            distinct[nums[windowEnd]]++;
            if (distinct.size() != windowEnd - windowStart + 1)
            {
                return true;
            }
        }
        return false;
    }
};