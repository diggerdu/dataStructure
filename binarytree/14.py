from binarytree import Node


def countLeaf(root):
    if root is None:
        return 0
    else:
        return countLeaf(root.right) + countLeaf(root.left) + 1


if __name__ == "__main__":
    root = Node(2)
    root.left = Node(4)
    root.right = Node(5)
    root.left.left = Node(7)
    root.left.left.left = Node(13)
    root.left.right = Node(8)
    root.left.right.left = Node(12)
    root.left.right.right = Node(14)
    root.right.left = Node(16)
    root.right.left.right = Node(19)
    root.right.left.left = Node(20)
    root.right.right = Node(21)
    print(root)
    print(countLeaf(root))

