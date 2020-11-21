class Solution:
    def dfs(self, node, depth):
        if not node.left and not node.right:
            return depth
        
        ret = 100000
        if node.left:
            ret = min(ret, self.dfs(node.left, depth + 1))
        if node.right:
            ret = min(ret, self.dfs(node.right, depth + 1))
        
        return ret
    
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        
        return self.dfs(root, 1)
