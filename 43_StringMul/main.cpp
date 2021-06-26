#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int len1 = num1.length(), len2 = num2.length(), len = len1 + len2;
        char *res = new char[len]();
        char *tem = new char[len]();

        multiply(num1, num2, len1, len2, len, res, tem);

        while (*res == 0 && len > 0)
        {
            res++;
            len--;
        }
        for (int i = 0; i < len; i++)
        {
            res[i] += '0';
        }

        return string(res, len);
    }

    void multiply(string &num1, string &num2, int &len1, int &len2, int &len, char *&res, char *&tem)
    {
        // num1数组
        char *num1_list = new char[len1]();
        for (int i = 0; i < len1; i++)
        {
            num1_list[i] = num1[i] - '0';
        }
        // 遍历num2
        for (int i = len2 - 1; i >= 0; i--)
        {
            int cur_num = num2[i] - '0';
            if (cur_num == 0)
                continue;
            mul(num1_list, tem, cur_num, len1, len, len2 - i - 1);
            add(res, tem, len);
        }
    }

    void mul(char *&num1_list, char *&tem, int cur_num, int &len1, int &len, int digit)
    {
        memset(tem, 0, sizeof(int) * len);
        for (int i = 0; i < len1; i++)
        {
            int index_1 = len1 - 1 - i, index_t = len - digit - 1 - i;
            int cur_res = cur_num * num1_list[index_1] + tem[index_t];
            tem[index_t - 1] = cur_res / 10;
            tem[index_t] = cur_res % 10;
        }
    }

    void add(char *&res, char *&tem, int &len)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            int cur_add = tem[i] + res[i];
            res[i - 1] += cur_add / 10;
            res[i] = cur_add % 10;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    string res = solu.multiply("2", "3");
    cout << res << endl;
    return 0;
}
