
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // unordered_map<string, vector<string>> dict;
        // for (string &str : strs)
        // {
        //     string key(26, '0');
        //     for (char &c : str)
        //     {
        //         key[c - 'a']++;
        //     }
        //     if (dict.count(key) == 0)
        //     {
        //         dict.insert(make_pair(key, vector<string>()));
        //     }
        //     dict[key].push_back(str);
        // }
        // vector<vector<string>> result;
        // for (auto iter = dict.begin(); iter != dict.end(); iter++)
        // {
        //     result.push_back(iter->second);
        // }
        // return result;
        unordered_map<string, vector<string>> dict;
        for (string &str : strs)
        {
            string key(str);
            sort(key.begin(),key.end());
            if (dict.count(key) == 0)
            {
                dict.insert(make_pair(key, vector<string>()));
            }
            dict[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            result.push_back(iter->second);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = solu.groupAnagrams(strs);
    return 0;
}
