### `realloc()` 
`void* realloc(void* ptr, size_t size);`
- resizes an already allocated block of memory.
- defined in <stdlib.h> and allows the size of a
memory block that was previously allocated using
malloc(), calloc(), realloc() itself.

### `memset()` 
`void* memset(void* ptr, int value, size_t size);`
- fills a block of memory with a specific value.
- initializes memory.
- defined in <string.h> 

## Heapify Down/ Sift Down/ Bubble Down
- Used to maintain heap property in a max heap after removing
the root node/max element. 
- In a max heap, the parent node must be >= to its child nodes.
- When the root is removed (typically in heap deletion or heap sort),
the last element is moved to the root, and the heap property is violated.
The heapify down process is used to restore this property.

#### Steps
1. Start at the root: When you remove the root (maximum value in the heap), the last element of the heap is placed at the root.
2. Compare the node with its children: Check if the newly placed node is smaller than any of its children.
3. Swap with the largest child: If the parent node is smaller than the largest of its children, swap it with the largest child.
4. Repeat the process: Move to the child node that was swapped and repeat the comparison with its children.
5. Stop when the heap property is restored: Continue the process until the parent is larger than its children, or you reach a leaf node.