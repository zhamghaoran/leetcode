package main

import (
	"fmt"
	"strconv"
)

func addStrings(num1 string, num2 string) string {
	num1 = reverseString(num1)
	num2 = reverseString(num2)
	i := 0
	j := 0
	add := 0
	var ans []int
	for i < len(num1) && j < len(num2) {
		val1, _ := strconv.Atoi(num1[i : i+1])
		val2, _ := strconv.Atoi(num2[i : i+1])
		ans = append(ans, val1+val2+add)
		add = ans[i] / 10
		ans[i] %= 10
		i++
		j++
	}
	for i < len(num1) {
		val1, _ := strconv.Atoi(num1[i : i+1])
		ans = append(ans, val1+add)
		add = ans[i] / 10
		ans[i] %= 10
		i++
	}
	for j < len(num2) {
		val2, _ := strconv.Atoi(num2[j : j+1])
		ans = append(ans, val2+add)
		add = ans[j] / 10
		ans[j] %= 10
		j++
	}
	if add > 0 {
		ans = append(ans, add)
	}
	str := ""
	for z := len(ans) - 1; z >= 0; z-- {
		str += strconv.Itoa(ans[z])
	}
	return str
}
func reverseString(str string) string {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func main() {
	str := addStrings("6", "501")
	fmt.Println(str)
}
