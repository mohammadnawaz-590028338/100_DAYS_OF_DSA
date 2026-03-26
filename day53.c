from collections import defaultdict, deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Build tree
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

# Vertical Order Traversal
def vertical_order(root):
    if not root:
        return
    
    hd_map = defaultdict(list)
    q = deque([(root, 0)])  # (node, horizontal distance)
    
    while q:
        node, hd = q.popleft()
        hd_map[hd].append(node.val)
        
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    
    # Print from leftmost to rightmost
    for hd in sorted(hd_map):
        print(*hd_map[hd])

# Input
n = int(input())
arr = list(map(int, input().split()))

# Build tree
root = build_tree(arr)

# Output
vertical_order(root)
