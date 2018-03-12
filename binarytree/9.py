from binarytree import Node


def levelorder(root):
    currentNodes = [root]
    maxWidth = 0
    while len(currentNodes) > 0:
        if len(currentNodes) > maxWidth:
            maxWidth = len(currentNodes)
        nextNodes = []
        for node in currentNodes:
            if node.left is not None:
                nextNodes.append(node.left)
            if node.right is not None:
                nextNodes.append(node.right)
        currentNodes = nextNodes

    return {'maxWidth', maxWidth}


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
    print(levelorder(root))

