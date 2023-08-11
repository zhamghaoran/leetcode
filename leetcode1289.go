func minFallingPathSum(grid [][]int) int {
    n := len(grid)
    d := make([][]int, n)
    for i := 0; i < n; i++ {
        d[i] = make([]int, n)
        for j := 0; j < n; j++ {
            d[i][j] = math.MaxInt
        }
    }
    for i := 0; i < n; i++ {
        d[0][i] = grid[0][i]
    }
    for i := 1; i < n; i++ {
        for j := 0; j < n; j++ {
            for k := 0; k < n; k++ {
                if j == k {
                    continue
                }
                d[i][j] = min(d[i][j], d[i - 1][k] + grid[i][j])
            }
        }
    }
    res := math.MaxInt
    for i := 0; i < n; i++ {
        res = min(res, d[n - 1][i])
    }
    return res
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
