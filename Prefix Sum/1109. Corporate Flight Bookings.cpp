class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> answer(n);
        vector<int> prefixSum(n + 2, 0);
        for (int i = 0; i < bookings.size(); i++)
        {
            int start = bookings[i][0];
            int end = bookings[i][1];
            int seats = bookings[i][2];
            prefixSum[start] += seats;
            prefixSum[end + 1] -= seats;
        }
        for (int i = 1; i < prefixSum.size(); i++)
        {
            prefixSum[i] += prefixSum[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            answer[i] = prefixSum[i + 1];
        }
        return answer;
    }
};