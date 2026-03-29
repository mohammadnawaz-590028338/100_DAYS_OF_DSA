from collections import deque

# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Build tree
def build_tree(values):
    if not values or values[0] == -1:
        return None
    
    root = Node(values[0])
    queue = deque([root])
    i = 1
    
    while queue and i < len(values):
        current = queue.popleft()
        
        if values[i] != -1:
            current.left = Node(values[i])
            queue.append(current.left)
        i += 1
        
        if i >= len(values):
            break
        
        if values[i] != -1:
            current.right = Node(values[i])
            queue.append(current.right)
        i += 1
    
    return root

# Mirror function
def mirror_tree(root):
    if not root:
        return
    
    # Swap left and right
    root.left, root.right = root.right, root.left
    
    # Recur for children
    mirror_tree(root.left)
    mirror_tree(root.right)

# Inorder traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

# Input
n = int(input())
values = list(map(int, input().split()))

root = build_tree(values)

# Convert to mirror
mirror_tree(root)

# Output inorder traversal
inorder(root)
