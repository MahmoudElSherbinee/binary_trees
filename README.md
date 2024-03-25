# Binary Trees Data Structure in C

## Overview

This repository contains an implementation of the binary tree data structure in C. Binary trees are a fundamental data structure used in computer science for organizing and manipulating hierarchical data.

## Features

- Insertion of nodes
- Deletion of nodes
- Searching for a node
- Traversal (in-order, pre-order, post-order)
- Height calculation
- Counting the number of nodes
- Finding the maximum and minimum values
- Deleting the entire tree

## Getting Started

To use this binary tree implementation, follow these steps:

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/binary-trees-c.git


2. Navigate to the cloned directory:

   ```bash
   cd binary-trees-c
   ```

3. Compile the source code:

   ```bash
   gcc binary_tree.c -o binary_tree
   ```

4. Run the executable:

   ```bash
   ./binary_tree
   ```

## Usage

After running the executable, you will be presented with a menu of options to interact with the binary tree. You can choose options such as insertion, deletion, traversal, height calculation, and more.

Here is a brief explanation of each option:

1. **Insert Node**: Insert a new node into the binary tree.
2. **Delete Node**: Delete a node from the binary tree.
3. **Search Node**: Search for a node with a specific value in the binary tree.
4. **In-order Traversal**: Perform an in-order traversal of the binary tree.
5. **Pre-order Traversal**: Perform a pre-order traversal of the binary tree.
6. **Post-order Traversal**: Perform a post-order traversal of the binary tree.
7. **Calculate Height**: Calculate the height of the binary tree.
8. **Count Nodes**: Count the number of nodes in the binary tree.
9. **Find Maximum Value**: Find the maximum value in the binary tree.
10. **Find Minimum Value**: Find the minimum value in the binary tree.
11. **Delete Tree**: Delete the entire binary tree.
12. **Exit**: Exit the program.

## Example

Here's an example of how you can use this binary tree implementation:

```c
#include <stdio.h>
#include "binary_tree.h"

int main() {
    struct Node *root = NULL;

    // Insert some nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Perform in-order traversal
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Calculate the height of the tree
    printf("Height of the tree: %d\n", calculateHeight(root));

    // Search for a node
    int key = 40;
    struct Node *result = searchNode(root, key);
    if (result != NULL)
        printf("%d is found in the tree.\n", key);
    else
        printf("%d is not found in the tree.\n", key);

    // Delete a node
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting node with value 20: ");
    inOrderTraversal(root);
    printf("\n");

    // Delete the entire tree
    deleteTree(root);

    return 0;
}
```

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

This README provides an overview of the binary tree implementation in C, including features, usage instructions, an example, information about contributing, and licensing details. Adjustments can be made based on specific requirements or additional details you want to include.
