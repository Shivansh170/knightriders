class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        vector<int> prefixSum(102, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int start = nums[i][0];
            int end = nums[i][1];
            prefixSum[start] += 1;
            prefixSum[end + 1] -= 1;
        }
        int count = 0;
        for (int i = 1; i < prefixSum.size(); i++)
        {
            prefixSum[i] += prefixSum[i - 1];
            if (prefixSum[i] > 0)
            {
                count++;
            }
        }
        return count;
    }
};