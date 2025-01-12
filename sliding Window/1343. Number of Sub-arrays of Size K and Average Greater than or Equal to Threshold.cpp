class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int windowStart = 0;
        int windowEnd = 0;
        int windowSum = 0;
        int count = 0;
        float average = 0;
        for (windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd];
            if (windowEnd >= (k - 1))
            {
                average = windowSum / (float)k;
                if (average >= threshold)
                {
                    count++;
                }
                windowSum = windowSum - arr[windowStart];
                windowStart++;
            }
        }
        return count;
    }
};