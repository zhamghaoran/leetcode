package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var move int

func distributeCoins(root *TreeNode) int {
	ch := make(chan int)
	defer close(ch)
	move = 0
	go dfs(root, ch)
	<-ch
	return move
}

func dfs(root *TreeNode, ch chan int) {
	movel := make(chan int)
	mover := make(chan int)
	defer close(movel)
	defer close(mover)
	if root == nil {
		ch <- 0
		return
	}
	if root.Left != nil {
		go dfs(root.Left, movel)
	}
	if root.Right != nil {
		go dfs(root.Right, mover)
	}
	tem := 0
	if root.Left != nil {
		moveleft := <-movel
		move += abs(moveleft)
		tem += moveleft
	}
	if root.Right != nil {
		moveright := <-mover
		move += abs(moveright)
		tem += moveright
	}
	ch <- tem + root.Val - 1
}

func abs(a int) int {
	if a < 0 {
		a = -a
	}
	return a
}

func main() {
	tree := new(TreeNode)
	tree.Val = 3
	treeL := new(TreeNode)
	treeR := new(TreeNode)
	tree.Right = treeR
	tree.Left = treeL
	fmt.Println(distributeCoins(tree))
}
