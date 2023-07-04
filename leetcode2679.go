package main

import "sort"

func matrixSum(nums [][]int) int {
	ans := 0
	for i := 0; i < len(nums); i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(nums[i])))
	}
	for i := 0; i < len(nums[0]); i++ {
		var list []int
		for j := 0; j < len(nums); j++ {
			list = append(list, nums[j][i])
		}
		sort.Sort(sort.Reverse(sort.IntSlice(list)))
		ans += list[0]
	}
	return ans

}
func main() {

}
