class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int windowStart = 0;
        int windowEnd = 0;
        map<char, int> frequencyMap;
        for (windowEnd = 0; windowEnd < s.size(); windowEnd++)
        {
            frequencyMap[s[windowEnd]]++;
            while (frequencyMap.size() != windowEnd - windowStart + 1)
            {
                char leftchar = s[windowStart];
                frequencyMap[leftchar]--;
                if (frequencyMap[leftchar] == 0)
                {
                    frequencyMap.erase(leftchar);
                }
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};