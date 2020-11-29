package divideConquer_Tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil{
		return nil
	}
	if key < root.Val{
		root.Left = deleteNode(root.Left, key)
	}else if key > root.Val{
		root.Right = deleteNode(root.Right, key)
	}else{
		if root.Left == nil{
			return root.Right
		}
		if root.Right == nil{
			return root.Left
		}

		leftBig := root.Left
		for;leftBig.Right != nil;{
			leftBig = leftBig.Right
		}
		leftBig.Right = root.Right
		return root.Left
	}
	return root
}
