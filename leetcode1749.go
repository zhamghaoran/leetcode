package main

func maxAbsoluteSum(nums []int) int {
	ans := 0
	a := len(nums)
	var dp int
	dp = Abs(nums[0])
	maxsum := nums[0]
	minsum := nums[0]
	ans = Abs(nums[0])
	for i := 1; i < a; i++ {
		maxsum = max(maxsum+nums[i], nums[i])
		minsum = min(minsum+nums[i], nums[i])
		dp = max(Abs(maxsum), Abs(minsum))
		ans = max(ans, dp)
	}
	return ans
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func Abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	qaq := []int{2, -5, 1, -4, 3, -2}
	println(maxAbsoluteSum(qaq))
}
