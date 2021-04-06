#include <iostream>
#include <string>

using namespace std;
string convert(string s, int numRows)
{
    int len = s.size();
    if (len == 1 || numRows == 1)
    {
        return s;
    }
    string result(s);
    // 可以分成多少块
    int block_size = numRows * 2 - 2, block_num = len / block_size, last_block_size = len % block_size, index = 0;
    if (block_num * block_size < len)
    {
        block_num++;
    }
    for (size_t start = 0, end = block_size; start <= end; start++, end--)
    {
        for (size_t i = 0; i < block_num; i++)
        {
            if (i == block_num - 1)
            {
                // 最后一个块，特殊处理
                if (start > last_block_size - 1)
                {
                    continue;
                }
                if (end > last_block_size - 1)
                {
                    result[index] = s[i * (block_size) + start];
                    index++;
                    continue;
                }
            }

            // 一般情况
            result[index] = s[i * (block_size) + start];
            index += 1;
            if (start == end)
            {
                continue;
            }
            if (end < block_size)
            {
                result[index] = s[i * (block_size) + end];
                index++;
                continue;
            }
        }
    }
    return result;
}

int main()
{
    cout << convert("A", 1) << endl;
}