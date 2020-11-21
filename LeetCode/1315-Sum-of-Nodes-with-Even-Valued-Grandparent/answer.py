class Solution:
    def dfs(self, node: TreeNode):
        total = 0
        if node.val % 2 == 0:
            childs = []
            if node.left:
                childs.append(node.left.left)
                childs.append(node.left.right)
            if node.right:
                childs.append(node.right.left)
                childs.append(node.right.right)
                
            for child in childs:
                if child:
                    total += child.val
        
        if node.left:
            total += self.dfs(node.left)
        if node.right:
            total += self.dfs(node.right)
        
        return total        
        
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        return self.dfs(root)
