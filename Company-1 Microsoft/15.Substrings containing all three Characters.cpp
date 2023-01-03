// LeetCode: 1358. Number of Substrings Containing All Three Characters

int numberOfSubstrings(string s)
{
    int i = 0, j = 0, ans = 0, count = 0, n = s.size();
    unordered_map<char, int> m;
    while (j < n)
    {
        m[s[j]]++;
        count = m.size();
        if (count < 3)
        {
            j++;
        }
        else if (count == 3)
        {
            ans += (n - j);
            while (count == 3)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                else
                {
                    ans += (n - j);
                }
                i++;
                count = m.size();
            }
            j++;
        }
    }
    return ans;
}