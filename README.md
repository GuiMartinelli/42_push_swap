# PUSH_SWAP

This project consists of ordering a stack, using a limited set of operations, with as few instructions as possible. 
It is only allowed to use two stacks and at the end, stack A must be sorted, from top to bottom.

## USAGE

Run `make` to compile. Execute it with a list of integers, and it will return which instructions, based on the allowed stack operations, you need to sort it.  
Run `./push_swap 3 5 1`, to sort a stack with 3, 5 and 1.  
If you try to sort duplicated numbers, some data that isn't a numerical or a int overflow, it will return **Error**

You can also see the algorithm sorting with the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer).  
Execute it with ```python3 pyviz.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"``` to sort a stack of 100 numbers between -50 and 50. You can change the values to use with a bigger or smaller stack.

Run `make bonus` to compile the **checker** program. It will check the instructions delivered by **push_swap** and check if they sort the stack.  
To use it run `./push_swap 3 5 1 | ./checker 3 5 1`. It should display **OK** if the instructions are correct, if the stack still unsorted, it will display **KO**.  
If you give it duplicated numbers, some data that isn't a numerical or a int overflow, it will return **Error**. The arguments must be the same to **push_swap** and the **checker**

## SMALL SORT

With 3 elements, it must sort with no more than 3 instructions. Since you have only 6 possible order with 3 elements, 
it just find out which one it is, and make execute the sorting.

With 5 elements, it must sorte with no more than 12 instructions. This program push the smallest int at Stack A to B, then the next smallest int, 
sort the remaining 3 elements, and push the 2 elements at B to A. 5 elements are sorted average on 7 instructions.

## BIG SORT

Here the fun begins. I test several algorithms before coding this one. The main problem is that algorithms aren't so easy to implement using 
stacks and these very specifics instructions. Then, after studing some other projects, i developed an algorithm that will **search for the least number of moves**
to sort an elements, until the Stack A is sorted. I called it **Lightning Sort**(quite presumptuous) since it always search for the easiest path to act.

- First, it **pulls** every element to **B**, except for smallest and biggest elements, and those that are already sorted.
- Then, It goes through every element at **B** and calculates what would be its index at Stack **A** to make it sorted, and whats its index at **B**.
- It calculates how many moves i need to do to sort every element, then i choose the one with less moves, and **pull** back to Stack **A** at the right index.
- It also check if i can **rotate** or **reverse rotate** both stack, making 2 instructions into one.
- Repeat this until Stack **B** is empty, then put the smallest element at Stack **A** at the top, and is sorted.

With this algorithm, it can sort 100 elements in average ~610 instructions, and 500 in average ~5450 instructions.

## RESOURCES

[Push_Swap](https://github.com/paulahemsi/push_swap) by [paulahensi](https://github.com/paulahemsi);  
[Push_Swap](https://github.com/laisarena/push_swap) by [laisarena](https://github.com/laisarena);  
[Push_Swap](https://github.com/alchrist42/push_swap_v2) by [alchrist42](https://github.com/alchrist42)**(The Wheel Algorithm)**;  
[Wheel Algorithm Video](https://www.youtube.com/watch?v=JnbILLTLhOk&t=208s);  
[VBranznik Explanation about Wheel Algorithm](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm);  
[Push_Swap Guide for small sort](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a);  

## TOOLS

[Push_Swap Tester](https://github.com/laisarena/push_swap_tester) by [laisarena](https://github.com/laisarena);  
[Push_Swap Simulator](https://github.com/o-reo/push_swap_visualizer) by [o-reo](https://github.com/o-reo);  
