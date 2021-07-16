#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(),n = matrix[0].size();
        int i,j;
        for(int index = 0;index<ceil((float)min(m,n)/2.0);index++){
            i = index;
            for(j=index;j<=n-index-1;j++){
                result.push_back(matrix[i][j]);
            }
            j = n-index-1;
            for(i=index+1;i<=m-index-1;i++){
                result.push_back(matrix[i][j]);
            }
            i = m-index-1;
            if(i==index) break;
            for(j=n-index-2;j>=index;j--){
                result.push_back(matrix[i][j]);
            }
            j = index;
            if(j==n-index-1) break;
            for(i=m-index-2;i>=index+1;i--){
                result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
