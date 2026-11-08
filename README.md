# DSE LAB WORKS

Student's Data Structures and Algorithms (DSA) laboratory programs written in C.

## 01. Basic C Programs
- `01_print_dsa.c`: Program to print "DSA" 5 times
- `02_for_loop.c`: Simple `for` loop demonstration (1 to 10)
- `03_pattern_1.c`: Right-angled triangle star pattern
- `04_pattern_2.c`: Inverted right-angled triangle star pattern

## 02. Recursion
- `05_factorial_recursion_iterative.c`: Factorial calculation using Recursion and Iteration

## 03. Array Operations
- `06_array_1d_2d_operations.c`: Input, element access, and traversal of 1D and 2D arrays
- `07_identify_data_structure.c`: Classifies data structure input (Primitive/Non-primitive, Linear/Non-linear, Static/Dynamic)
- `08_array_deletion_function.c`: Array deletion at target index using functions
- `09_array_insertion_function.c`: Array insertion at target position using functions

## 04. Searching
- `10_linear_search_function.c`: Linear search using functions
- `11_binary_search_recursive.c`: Recursive binary search using functions
- `12_binary_search_iterative.c`: Iterative binary search using functions

## 05. Pointers
- `13_play_with_pointers.c`: Pointer basics (variable value, address, pointer dereferencing)
- `14_access_array_using_pointer.c`: Array access using pointer indexing `*(ptr + i)`
- `15_traverse_array_using_pointer.c`: Array traversal using pointer increment `ptr++`
- `16_linear_search_using_pointers.c`: Linear search implementation using pointers
- `17_address_calculation_2d_array.c`: Switch-case address calculation for 2D arrays (Row Major & Column Major)

## 06. Sorting
- `18_bubble_sort.c`: Bubble Sort with step-by-step pass output
- `19_selection_sort.c`: Selection Sort with step-by-step pass output
- `20_insertion_sort.c`: Insertion Sort with step-by-step pass output
- `21_modified_bubble_sort.c`: Modified Bubble Sort using early-exit swap flag
- `22_modified_selection_sort.c`: Modified Selection Sort (Dual Selection Sort using `min_idx` & `max_idx`)
- `23_merge_sort.c`: Merge Sort using divide-and-conquer recursion
- `24_quick_sort.c`: Quick Sort using Lomuto partition scheme

## 07. Combined Sorting Problems
- `25_bubble_quick_combined.c`: Exam exercise executing 1 pass of Bubble Sort followed by Quick Sort

## 08. Stack and Queue
- `26_stack_implementation.c`: Array implementation of Stack (`push`, `pop`, `peek`, `display`, `isEmpty`, `isFull`)
- `27_queue_implementation.c`: Array implementation of Linear Queue (`enqueue`, `dequeue`, `display`, `isEmpty`, `isFull`)
- `28_circular_queue.c`: Array implementation of Circular Queue (`enqueue`, `dequeue`, `display`, `isEmpty`, `isFull`, modulo wrap-around)

## 09. Singly Linked List (SLL)
- `29_sll_node_structure.c`: Definition and memory demonstration of SLL node structure
- `30_sll_creation_3_nodes.c`: Dynamic allocation and manual linking of 3 nodes
- `31_sll_traversal.c`: Linear traversal and element display
- `32_sll_insertion_beginning.c`: Node insertion at the beginning (new head)
- `33_sll_insertion_end.c`: Node insertion at the end
- `34_sll_deletion_beginning.c`: Deletion of the first node
- `35_sll_deletion_end.c`: Deletion of the last node
- `36_sll_insertion_middle.c`: Node insertion at a specific position (1-based index)
- `37_sll_deletion_middle.c`: Node deletion from a specific position (1-based index)
- `38_sll_searching.c`: Linear search for an element returning position
- `39_sll_reverse_list.c`: Iterative 3-pointer reversal of Singly Linked List

## 10. Circular Linked List (CLL)
- `40_cll_node_structure.c`: Definition and self-pointing circular node structure
- `41_cll_creation_3_nodes.c`: Creation and circular linking of 3 nodes
- `42_cll_traversal.c`: Circular traversal using `do-while` loop
- `43_cll_insertion_beginning.c`: Node insertion at the beginning and circular link maintenance
- `44_cll_insertion_end.c`: Node insertion at the end
- `45_cll_deletion_beginning.c`: Deletion of head node in circular list
- `46_cll_deletion_end.c`: Deletion of last node and closing the circle
- `47_cll_insertion_middle.c`: Insertion at a specific position in circular list
- `48_cll_deletion_middle.c`: Deletion from a specific position in circular list
- `49_cll_searching.c`: Circular linear search returning element position

## 11. Doubly Linked List (DLL)
- `50_dll_node_structure.c`: Bidirectional node structure with `prev` and `next` pointers
- `51_dll_creation_3_nodes.c`: Creation and two-way manual linking of 3 nodes
- `52_dll_traversal.c`: Both forward and backward traversals
- `53_dll_insertion_beginning.c`: Insertion at the beginning with `prev` pointer update
- `54_dll_insertion_end.c`: Insertion at the end with bidirectional linking
- `55_dll_deletion_beginning.c`: Deletion of head node in doubly linked list
- `56_dll_deletion_end.c`: Deletion of last node in doubly linked list
- `57_dll_insertion_middle.c`: Insertion at a specific position with two-way pointer updates
- `58_dll_deletion_middle.c`: Deletion from a specific position with neighbor pointer relinking
- `59_dll_searching.c`: Linear search for an element in doubly linked list

