package class207;

// 传递闭包，C++版
// 一共n个点，给定有向图的邻接矩阵a，原图没有自环
// 如果 a[i][j] == 1，表示存在从i到j的有向边
// 如果 a[i][j] == 0，表示不存在从i到j的有向边
// 求有向图的传递闭包，输出关系矩阵b
// 如果i经过至少一条有向边可以到达j，那么b[i][j]为1，否则为0
// 1 <= n <= 100
// 测试链接 : https://www.luogu.com.cn/problem/B3611
// 如下实现是C++的版本，C++版本和java版本逻辑完全一样
// 提交如下代码，可以通过所有测试用例

//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int MAXN = 101;
//int n;
//
//bitset<MAXN> dp[MAXN];
//
//void floyd() {
//    for (int bridge = 1; bridge <= n; bridge++) {
//        for (int i = 1; i <= n; i++) {
//            if (dp[i][bridge]) {
//                dp[i] |= dp[bridge];
//            }
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin >> n;
//    int s;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> s;
//            dp[i][j] = s;
//        }
//    }
//    floyd();
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (dp[i][j]) {
//                cout << "1 ";
//            } else {
//                cout << "0 ";
//            }
//        }
//        cout << '\n';
//    }
//    return 0;
//}