//该方法错误


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
bool dp[MAXN][205]; // dp[i][s+offset], offset=100

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        int offset = n;
        // 初始化全部false
        memset(dp, false, sizeof(dp));
        dp[0][0 + offset] = true;
        
        for(int i = 0; i < n; i++)
        {
            for(int s = -i; s <= i; s++)
            {
                if(dp[i][s + offset]) // 如果前i项和s可达
                {
                    // 方案1：不翻转i位置，处理第i个，走到i+1
                    int ns = s + a[i];
                    dp[i+1][ns + offset] = true;
                    
                    // 方案2：翻转i和i+1（前提i+1存在），直接跳到i+2
                    if(i + 1 < n)
                    {
                        int ns2 = s - a[i] - a[i+1];
                        dp[i+2][ns2 + offset] = true;
                    }
                }
            }
        }
        if(dp[n][0 + offset])//前n个是否可以为0
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
