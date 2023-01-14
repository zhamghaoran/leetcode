package main

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func gcdd(a, b int) int {
	if b > a {
		a, b = b, a
	}
	if b == 0 {
		return a
	} else {
		return gcdd(b, a%b)
	}
}
func countDifferentSubsequenceGCDs(nums []int) int {
	maxx := 0
	ans := 0
	for _, num := range nums {
		maxx = max(num, maxx)

	}
	vis := make([]int, maxx+1)
	for _, num := range nums {
		vis[num] = 1
	}
	for i := 1; i <= maxx; i++ {
		gcd := 0
		for j := i; j <= maxx; j += i {
			if vis[j] == 1 {
				if gcd == 0 {
					gcd = j
				} else {
					gcd = gcdd(gcd, j)
				}
				if gcd == i {
					ans++
					break
				}
			}
		}
	}
	return ans
}
func main() {
	val := []int{6, 10, 3}
	println(countDifferentSubsequenceGCDs(val))
}
