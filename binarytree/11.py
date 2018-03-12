from binarytree import Node


def inorder(node):
    nodeStack = []
    result = []
    while True:
        if node is not None:
            nodeStack.append(node)
            node = node.left
        elif len(nodeStack) > 0:
            node = nodeStack.pop()
            result.append(node)
            node = node.right
        else:
            break

    return result


if __name__ == "__main__":
    root = Node(2)
    root.left = Node(4)
    root.right = Node(5)
    root.left.left = Node(7)
    root.left.right = Node(8)
    root.left.right.left = Node(12)
    root.left.right.right = Node(14)
    root.right.left = Node(16)
    root.right.left.right = Node(19)
    root.right.left.left = Node(20)
    root.right.right = Node(21)
    print(root)
    print(inorder(root))

