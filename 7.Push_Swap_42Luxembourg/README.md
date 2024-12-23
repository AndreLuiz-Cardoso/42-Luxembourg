<h1 align=center>
	<b>Push Swap</b>
</h1>

<p align=center>
	Push_swap is a project that involves sorting a list of integers using a limited set of operations. The goal is to sort the list with the fewest possible number of operations.

---
<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/push_swapm.png?raw=true"/>
</div>

---
<h2> Mandatory </h2>
<br/>
<p>1. We have at our disposal, two stacks named a and b.</p>
<p>2. Create a program that takes as parameters, a random set of numbers (negative or positive),</p> without duplicates. Our program has to handle both types of inputs: as a variable number of command line arguments; a string, i.e. "numbers between quotation marks, seperated by a space".</p>
<p>3. Implement an algorithm, that sorts in ascending order, the input of random numbers.</p>
<p>4. Our algorithm will consist of swap, rotate, reverse rotate and push operations.</p>
<p>5. After taking in an input of numbers, and passing them through our sorting algorithms, our program will output the list of operations (instructions).</p>

<h2> How it Works </h2>
</div>
<br/>

The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you have to manipulate various types of algorithms and choose the one (of many) most appropriate solutions for optimized data sorting.
<br/>

The Push Swap algorithm takes a list as input and outputs a series of operations that sorts the integers in ascending order. The available operations are:

<br/>
<p>* sa: Swap the first two elements of the stack A.</p>
<p>* sb: Swap the first two elements of the stack B.</p>
<p>* ss: Swap the first two elements of both stack A and stack B.</p>
<p>* pa: Push the first element of stack B to stack A.</p>
<p>* pb: Push the first element of stack A to stack B.</p>
<p>* ra: Rotate the stack A (move the first element to the end).</p>
<p>* rb: Rotate the stack B (move the first element to the end).</p>
<p>* rr: Rotate both stack A and stack B.</p>
<p>* rra: Reverse rotate the stack A (move the last element to the beginning).</p>
<p>* rrb: Reverse rotate the stack B (move the last element to the beginning).</p>
<p>* rrr: Reverse rotate both stack A and stack B.</p>
