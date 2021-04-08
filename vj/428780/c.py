inf = 50 * (10 ** 27)
n = int(input())
w = list(map(int, input().split()))
dp = []
for i in range(n):
    dp.append([])
    for j in range(n):
        dp[i].append(0)
for l in range(2, n + 1):
    for i in range(n - l):
        j = i + l
        dp[i][j] = inf
        for k in range(i + 1, j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + w[i] * w[k] * w[j])
print(dp[0][n - 1])