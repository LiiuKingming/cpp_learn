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

        // ���һ��һ�У��������ó�ʼ����
        // ��ʼ������λ��Ϊ0����һ�к͵�һ�ж�Ϊ0����ʼ����
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // dp[i][j]��ʾi����Ʒ����ռ�Ϊj�ı����е�����ֵ
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                //�����i����Ʒ����j,˵���Ų��£� ����dp[i][j]������ֵ��dp[i - 1][j]��ͬ
                if (A[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // �����װ����Ϊdp[i - 1][j]
                    // ���װ,��Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ�:[j - A[i - 1]],
                    // װ��֮�������ֵ��Ϊdp[i - 1][j - A[i - 1]] + V[i - 1] + ��i����Ʒ�ļ�ֵV[i - 1]
                    int newVal = dp[i - 1][j - A[i - 1]] + V[i - 1];
                    dp[i][j] = max(newVal, dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};



/*
�Ż��㷨��
������㷨�ڼ����i��Ԫ��ʱ��ֻ�õ���i-1�е�Ԫ�أ����Զ�ά�Ŀռ�����Ż�Ϊһά�ռ�
���������һά��������Ҫ�Ӻ���ǰ���㣬��Ϊ�����Ԫ�ظ�����Ҫ����ǰ���Ԫ��δ���£�ģ���ά�������һ�е�
ֵ����ֵ
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
        
        //���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
        //��ʼ������λ��Ϊ0����һ�ж�Ϊ0����ʼ����
        const int M = m + 1;
        vector<int> dp(m + 1, 0);
        //������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
        //�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
        for (int i = 0; i != N; ++i) {
            for (int j = M - 1; j > 0; --j) {
                //�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
                if (A[i] > j) {
                    dp[j] = dp[j];
                }
                // �������װ�£������������װ���߲�װ
                // �����װ����Ϊ(i-1, j)
                // ���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i],
                // װ��֮�������ֵ��Ϊ(i - 1, j - A[i-1]) + ��i����Ʒ�ļ�ֵV[i]
                // �����װ�벻װ��ѡ�����ļ�ֵ
                else {
                    int newValue = dp[j - A[i]] + V[i];
                    dp[j] = max(newValue, result[j]);
                }
            }
        }
        //����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
        return result[m];
    }
};