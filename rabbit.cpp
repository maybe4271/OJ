#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int m, n;
    int a[1001];
    int dp[2][1001];
    //memset(dp, 1, sizeof(dp));
    //初始化记录数组
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 1001; j++) {
            dp[i][j] = 1;
        }
    }


    scanf("%d %d", &m, &n); //m是洞的编号，n是天数
    //第i+1天检查的洞的编号
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    //填表
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == a[i])
                dp[i%2][j] = 0;
            if (dp[(i-1)%2][2] == 0 && i > 0)
                dp[i%2][1] = 0;
            if (dp[(i-1)%2][m-1] == 0 && i > 0)
                dp[i%2][m] = 0;
            if (dp[(i-1)%2][j-1] == 0 && dp[(i-1)%2][j+1] == 0 && i > 0)
                dp[i%2][j] = 0;
        }
    }

    int index = 0;
    for (int j = 1; j <= m; j++) {
        if (dp[(n-1)%2][j] == 1) {
            index = 1;
            break;
        }
    }

    if (index == 1)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}
