func diagonalSum(mat [][]int) int {
	ans := 0
	a := len(mat)
	for i := 0; i < a; i++ {
		ans += mat[i][i]
	}
	for i := 0; i < a; i++ {
		ans += mat[i][a-i-1]
	}
	if a&1 == 1 {
		ans -= mat[a/2][a/2]
	}
	return ans
}