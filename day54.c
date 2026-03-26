from collections import deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Build tree from level order
def build_tree(arr):
    if not arr or arr[0] == -1:
        return None
    
    root = Node(arr[0])
    q = deque([root])
    i = 1
    
    while q and i < len(arr):
        curr = q.popleft()
        
        if arr[i] != -1:
            curr.left = Node(arr[i])
            q.append(curr.left)
        i += 1
        
        if i < len(arr) and arr[i] != -1:
            curr.right = Node(arr[i])
            q.append(curr.right)
        i += 1
    
    return root

# Zigzag traversal
def zigzag(root):
    if not root:
        return []
    
    result = []
    q = deque([root])
    left_to_right = True
    
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        
        if not left_to_right:
            level.reverse()
        
        result.extend(level)
        left_to_right = not left_to_right
    
    return result

# Input
n = int(input())
arr = list(map(int, input().split()))

# Build tree
root = build_tree(arr)

# Output
print(*zigzag(root))
