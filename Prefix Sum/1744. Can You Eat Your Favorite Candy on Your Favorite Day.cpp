class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<long> prefixSum(candiesCount.size());
        vector<bool> answer;
        prefixSum[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + candiesCount[i];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            long favtype = queries[i][0];
            long favday = queries[i][1];
            long dailycap = queries[i][2];
            long totalcandiesbefore;
            if (favtype == 0)
            {
                totalcandiesbefore = 0;
            }
            else
            {
                totalcandiesbefore = prefixSum[favtype - 1];
            }
            if (totalcandiesbefore >= ((favday + 1) * dailycap))
            {
                answer.push_back(false);
            }
            else if (favday + 1 > prefixSum[favtype])
            {
                answer.push_back(false);
            }
            else
            {
                answer.push_back(true);
            }
        }
        return answer;
    }
};