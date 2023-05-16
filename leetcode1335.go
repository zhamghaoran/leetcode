package main

import "math"

func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

func minDifficulty(jobDifficulty []int, d int) int {
	n := len(jobDifficulty)
	if n < d {
		return -1
	}

	dp := make([][]int, d)
	dp[0] = make([]int, len(jobDifficulty))
	dp[0][0] = jobDifficulty[0]
	for i := 1; i < len(jobDifficulty); i++ {
		dp[0][i] = max(dp[0][i-1], jobDifficulty[i])
	}

	for i := 1; i < d; i++ {
		dp[i] = make([]int, len(jobDifficulty))
		for j := len(jobDifficulty) - 1; j >= i; j-- {
			dp[i][j] = math.MaxInt
			maxx := 0
			for z := j; z >= i; z-- {
				maxx = max(maxx, jobDifficulty[z])
				dp[i][j] = min(dp[i][j], dp[i-1][z-1]+maxx)
			}
		}
	}
	return dp[d-1][len(jobDifficulty)-1]
}
func main() {

}
