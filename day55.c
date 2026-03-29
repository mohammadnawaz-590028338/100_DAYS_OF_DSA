from collections import deque

# Define Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to build tree from level order input
def build_tree(values):
    if not values or values[0] == -1:
        return None
    
    root = Node(values[0])
    queue = deque([root])
    i = 1
    
    while queue and i < len(values):
        current = queue.popleft()
        
        # Left child
        if values[i] != -1:
            current.left = Node(values[i])
            queue.append(current.left)
        i += 1
        
        if i >= len(values):
            break
        
        # Right child
        if values[i] != -1:
            current.right = Node(values[i])
            queue.append(current.right)
        i += 1
    
    return root

# Function to print right view
def right_view(root):
    if not root:
        return
    
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        
        for i in range(level_size):
            node = queue.popleft()
            
            # If last node of this level
            if i == level_size - 1:
                print(node.data, end=" ")
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

# Input
n = int(input())
values = list(map(int, input().split()))

root = build_tree(values)
right_view(root)
