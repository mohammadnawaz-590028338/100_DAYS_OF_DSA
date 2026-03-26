class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Build tree from level-order input
def build_tree(arr):
    if not arr or arr[0] == -1:
        return None
    
    root = Node(arr[0])
    queue = [root]
    i = 1
    
    while queue and i < len(arr):
        curr = queue.pop(0)
        
        if arr[i] != -1:
            curr.left = Node(arr[i])
            queue.append(curr.left)
        i += 1
        
        if i < len(arr) and arr[i] != -1:
            curr.right = Node(arr[i])
            queue.append(curr.right)
        i += 1
    
    return root

# Find LCA
def lca(root, n1, n2):
    if root is None:
        return None
    
    if root.val == n1 or root.val == n2:
        return root
    
    left = lca(root.left, n1, n2)
    right = lca(root.right, n1, n2)
    
    if left and right:
        return root
    
    return left if left else right

# Input
n = int(input())
arr = list(map(int, input().split()))
n1, n2 = map(int, input().split())

# Build tree
root = build_tree(arr)

# Get LCA
ancestor = lca(root, n1, n2)

# Output
print(ancestor.val)
