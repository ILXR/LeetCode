#include <iostream>
#include <string>

using namespace std;

// 获取掩码 index是2的多少次方
int mask(int &num, int index)
{
    int bitNum = (num >> index) & 1;
    int mask = 0;
    mask |= bitNum;
    mask |= bitNum << 1; //2位
    mask |= mask << 2;   //4位
    mask |= mask << 4;   //8位
    mask |= mask << 8;   //16位
    mask |= mask << 15;  //31位
    return mask;
}

int sumNums(int n)
{
    int temp = n + 1, result = 0;
    result += (temp << 0) & mask(n, 0);
    result += (temp << 1) & mask(n, 1);
    result += (temp << 2) & mask(n, 2);
    result += (temp << 3) & mask(n, 3);
    result += (temp << 4) & mask(n, 4);
    result += (temp << 5) & mask(n, 5);
    result += (temp << 6) & mask(n, 6);
    result += (temp << 7) & mask(n, 7);
    result += (temp << 8) & mask(n, 8);
    result += (temp << 9) & mask(n, 9);
    result += (temp << 10) & mask(n, 10);
    result += (temp << 11) & mask(n, 11);
    result += (temp << 12) & mask(n, 12);
    result += (temp << 13) & mask(n, 13);
    return result >> 1;
}

int main()
{
    cout << sumNums(9) << endl;
}