from collections import deque

# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Build tree from level order
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

# Check symmetry
def is_mirror(left, right):
    if not left and not right:
        return True
    if not left or not right:
        return False
    return (left.data == right.data and
            is_mirror(left.left, right.right) and
            is_mirror(left.right, right.left))

def is_symmetric(root):
    if not root:
        return True
    return is_mirror(root.left, root.right)

# Input
n = int(input())
values = list(map(int, input().split()))

root = build_tree(values)

# Output
print("YES" if is_symmetric(root) else "NO")
