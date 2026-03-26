class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

# Insert into BST
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.val:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

# LCA function
def find_lca(root, n1, n2):
    while root:
        if n1 < root.val and n2 < root.val:
            root = root.left
        elif n1 > root.val and n2 > root.val:
            root = root.right
        else:
            return root

# Input
n = int(input())
values = list(map(int, input().split()))
n1, n2 = map(int, input().split())

# Build BST
root = None
for v in values:
    root = insert(root, v)

# Find and print LCA
lca = find_lca(root, n1, n2)
print(lca.val)
