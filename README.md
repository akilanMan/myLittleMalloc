README: 

Tanvi Kumar tk594
Dheeptha Meruva dm1492

(a) What properties your library must have for you to consider it correct
    For our library to be correct, we had to make sure that the allocation and memory allignment were correct, that there were no memory leaks, and that it was able to reallocate memory, 
(b) How you intend to check that your code has these properties
    To check each property, we have created a variety of tests to ensure that the program mallocs and frees as designed.
(c) The specific method(s) you will use to check each property
    Our tests cases are checking each property.
    1 Our first test malloc()s and immediately free()s a 1-byte chunk, 120 times.
    2 Our second test uses malloc() to get 120 1-byte chunks, storing the pointers in an array, then uses free() to deallocate the chunks.
    3 Our third test randomly chooses between alocating a 1-byte chunk and storing the pointer in an array, deallocating one of the chunks in the array (if any)
    4 Our fourth test calls malloc() repeatedly of increasing size and frees the pointer immediately.
    5 Our fifth test calls malloc() with pointers of various primitive type, assigns them a random value and then prints the values to show that the information is being stored in the array.