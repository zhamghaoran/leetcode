package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	var a []int
	for head != nil {
		a = append(a, head.Val)
		head = head.Next
	}
	for i := 0; i < len(a); i += 2 {
		if i+1 < len(a) {
			a[i], a[i+1] = a[i+1], a[i]
		}
	}
	ans := &ListNode{}
	head = ans
	for i := 0; i < len(a); i++ {
		ans.Val = a[i]
		if i < len(a)-1 {
			ans.Next = &ListNode{}
		}
		ans = ans.Next
	}
	if len(a) == 0 {
		return nil
	}
	return head
}
func main() {

}
