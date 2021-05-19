#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;

        int word_count = words.size();
        int one_word = words[0].size();
        int all_words = word_count * one_word;
        int string_size = s.size();

        unordered_map<string, int> word_map;
        for (auto word : words)
        {
            word_map[word]+=1;
        }

        for (int i = 0; i < one_word; i++)
        {
            int l = i, r = i, count = 0;
            unordered_map<string, int> tem_map;
            while (r + one_word <= string_size && l + all_words <= string_size)
            {
                string tem = s.substr(r, one_word);
                r += one_word;
                if (word_map[tem] == 0)
                {
                    // 匹配失败，全部右移
                    l = r;
                    count = 0;
                    tem_map.clear();
                }
                else
                {
                    tem_map[tem]++;
                    count++;
                    // l右移
                    while (tem_map[tem] > word_map[tem])
                    {
                        string remove_tem = s.substr(l, one_word);
                        tem_map[remove_tem]--;
                        l += one_word;
                        count--;
                    }
                    if (count == word_count)
                    {
                        result.push_back(l);
                        string remove_tem = s.substr(l, one_word);
                        tem_map[remove_tem]--;
                        l += one_word;
                        count--;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solu;
    string str[] = {"word","good","best","good"};
    vector<string> strs(str, str + str->size());
    vector<int> result = solu.findSubstring("wordgoodgoodgoodbestword", strs);
    cout << "result:" << endl;
    for (auto res : result)
    {
        cout << res << endl;
    }
    cout << "end" << endl;
}