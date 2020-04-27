class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        if (A.empty() || V.empty() || m <= 0) {
            return 0;
        }

        // 多加一行一列，用于设置初始条件
        // 初始化所有位置为0，第一行和第一列都为0，初始条件
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // dp[i][j]表示i个物品放入空间为j的背包中的最大价值
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                //如果第i个商品大于j,说明放不下， 所以dp[i][j]的最大价值和dp[i - 1][j]相同
                if (A[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // 如果不装，则即为dp[i - 1][j]
                    // 如果装,需要腾出放第i个物品大小的空间:[j - A[i - 1]],
                    // 装入之后的最大价值即为dp[i - 1][j - A[i - 1]] + V[i - 1] + 第i个商品的价值V[i - 1]
                    int newVal = dp[i - 1][j - A[i - 1]] + V[i - 1];
                    dp[i][j] = max(newVal, dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};



/*
优化算法：
上面的算法在计算第i行元素时，只用到第i-1行的元素，所以二维的空间可以优化为一维空间
但是如果是一维向量，需要从后向前计算，因为后面的元素更新需要依靠前面的元素未更新（模拟二维矩阵的上一行的
值）的值
*/
class Solution {
public:
/**
* @param m: An integer m denotes the size of a backpack
* @param A: Given n items with size A[i]
* @param V: Given n items with value V[i]
* @return: The maximum value
*/
    int backPackII(int m, vector<int> A, vector<int> V) {
        if (A.empty() || V.empty() || m < 1) {
            return 0;
        }
        
        //多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
        //初始化所有位置为0，第一行都为0，初始条件
        const int M = m + 1;
        vector<int> dp(m + 1, 0);
        //这里商品的索引位置不需要偏移，要和未优化的方法区分开
        //这里的i-1理解为上一行，或者未更新的一维数组值
        for (int i = 0; i != N; ++i) {
            for (int j = M - 1; j > 0; --j) {
                //如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
                if (A[i] > j) {
                    dp[j] = dp[j];
                }
                // 如果可以装下，分两种情况，装或者不装
                // 如果不装，则即为(i-1, j)
                // 如果装，需要腾出放第i个物品大小的空间： j - A[i],
                // 装入之后的最大价值即为(i - 1, j - A[i-1]) + 第i个商品的价值V[i]
                // 最后在装与不装中选出最大的价值
                else {
                    int newValue = dp[j - A[i]] + V[i];
                    dp[j] = max(newValue, result[j]);
                }
            }
        }
        //返回装入前N个商品，物品大小为m的最大价值
        return result[m];
    }
};