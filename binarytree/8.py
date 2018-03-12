from binarytree import Node

def inorder(root):
    if root.left is None and root.right is None:
        return root.value

    if root.left is not None:
        output = inorder(root.left) + root.value + inorder(root.right)

    if root.value in ['+', '-']:
        return "({})".format(output)
    else:
        return output


if __name__ == "__main__":
    root = Node('+')
    root.left = Node('x')
    root.right = Node('x')
    root.left.left = Node('3')
    root.left.right = Node('+')
    root.left.right.left = Node('1')
    root.left.right.right = Node('2')
    root.right.left = Node('+')
    root.right.left.right = Node('4')
    root.right.left.left = Node('7')
    root.right.right = Node('2')
    print(root)
    print(inorder(root))

