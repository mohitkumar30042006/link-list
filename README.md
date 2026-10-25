# linked list
DSA Lab Program
Program 1: Singly Linked List in C++
Aim:To implement a singly linked list in C++ and perform various linked list operations.

### Algorithm

1. Define a node structure containing data and a pointer to the next node.
2. Initialize the head pointer to "nullptr".
3. Perform the linked list operations as required.
4. Display the linked list after performing the operations.

### Time Complexity

- Insertion at the beginning: O(1)
- Insertion at the end: O(n)
- Deletion: Depends on the position and implementation.
- Traversal and display: O(n)
- Searching: O(n)

### Test Cases

| Test Case | Operation | Expected Result |
|---|---|---|
| 1 | Insert 10, 20, 30 at end | 10 -> 20 -> 30 -> NULL |
| 2 | Insert 5 at beginning | 5 -> 10 -> 20 -> 30 -> NULL |
| 3 | Search for 20 | 20 found at position 3 |
| 4 | Search for 50 | 50 not found in the list |
| 5 | Delete 20 | 20 deleted successfully |
| 6 | Display the list | 5 -> 10 -> 30 -> NULL |

### Source Code
Program: Singly Linked List in C++
[Click here to view the source code](./linked_list.cpp)

**### Output

```text
Linked List: 5 -> 10 -> 20 -> 30 -> NULL
20 found at position 3.
50 not found in the list.
20 deleted successfully.
Linked List: 5 -> 10 -> 30 -> NULL**
```
---

---

## Program 2: Doubly Linked List in C++

### Aim
To implement a doubly linked list in C++ and perform insertion and traversal operations.

### Description
A doubly linked list is a linear data structure in which each node contains data, a pointer to the previous node, and a pointer to the next node. It allows traversal in both forward and backward directions.

### Algorithm
1. Create a node structure containing data, a previous pointer, and a next pointer.
2. Initialize the head and tail pointers to NULL.
3. Insert elements at the end or beginning of the list.
4. Traverse from head to tail to display the list in forward order.
5. Traverse from tail to head to display the list in backward order.

### Time Complexity

| Operation | Time Complexity |
|---|---|
| Insert at beginning | O(1) |
| Insert at end | O(1) |
| Display forward | O(n) |
| Display backward | O(n) |

### Space Complexity
O(n), where n is the number of nodes in the list.

### Test Cases

| Test Case | Operation | Expected Result |
|---|---|---|
| 1 | Insert 10 at end | 10 |
| 2 | Insert 20 at end | 10 20 |
| 3 | Insert 30 at end | 10 20 30 |
| 4 | Display forward | 10 20 30 |
| 5 | Display backward | 30 20 10 |

### Source Code
Program: Singly Linked List in C++
[Click here to view the source code](./doubly_ll.cpp)

### Output

```text
Forward: 10 20 30
Backward: 30 20 10
```
---

## Program 3: Circular Linked List in C++

### Aim
To implement a circular linked list in C++ and perform insertion and traversal operations.

### Description
A circular linked list is a data structure in which the last node points back to the first node instead of pointing to NULL. This creates a circular structure.

### Algorithm
1. Create a Node class containing data and a pointer to the next node.
2. Initialize the head pointer to NULL.
3. Create a new node for each element.
4. If the list is empty, make the new node point to itself and set it as the head.
5. Otherwise, traverse to the last node and connect it to the new node.
6. Make the new node point to the head.
7. Display the elements using a do-while loop until the head is reached again.

### Time Complexity

| Operation | Time Complexity |
|---|---|
| Insert into an empty list | O(1) |
| Insert a node into a non-empty list | O(n) |
| Display the list | O(n) |

### Space Complexity
O(n), where n is the number of nodes in the list.

### Test Cases

| Test Case | Operation | Expected Result |
|---|---|---|
| 1 | Insert 10 | 10 |
| 2 | Insert 20 | 10 20 |
| 3 | Insert 30 | 10 20 30 |
| 4 | Display the list | All elements displayed in insertion order |

### Output

```text
Circular Linked List: 10 20 30
```

### Source Code

[Click here to view the source code](./circular_ll.cpp)
---

## Program 4: Stack Using Array in C++

### Aim
To implement a stack using an array in C++ and perform push, pop, and display operations.

### Description
A stack is a linear data structure that follows the LIFO (Last In, First Out) principle. The element inserted last is removed first.

The main operations are:
- Push: Inserts an element into the stack.
- Pop: Removes the top element from the stack.
- Display: Displays the stack elements from top to bottom.

### Algorithm
1. Declare an array of fixed size MAX.
3. For push, check whether the stack is full. If not, increment top and insert the element.
4. For pop, check whether the stack is empty. If not, display and remove the top element.
5. For display, print the elements from top to bottom.
### Time Complexity

| Operation | Time Complexity |
|---|---|
| Push | O(1) |
| Pop | O(1) |
| Display | O(n) |

### Space Complexity
O(n), where n is the maximum capacity of the array.

### Test Cases

| Test Case | Operation | Expected Result |
|---|---|---|
| 1 | Push 10 | 10 pushed into stack |
| 2 | Push 20 | 20 pushed into stack |
| 3 | Push 30 | 30 pushed into stack |
| 4 | Display | 30 20 10 |
| 5 | Pop | 30 popped from stack |
| 6 | Display | 20 10 |

### Output

```text
10 pushed into stack
20 pushed into stack
30 pushed into stack
Stack elements: 30 20 10
30 popped from stack
Stack elements: 20 10
```
### Source Code

[Click here to view the source code](./stacks_arr.cpp)

