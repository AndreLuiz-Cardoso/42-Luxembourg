<h1 align=center>
	<b>Get_Next_Line</b>
</h1>

<p align=center>
	It is a function that reads a file and allows you to read a line ending with a newline character from a file descriptor. When you call the function again on the same file, it grabs the next line. This project deals with memory allocation and when to free and allocate memory to prevent leaks.

	A (-1) is returned if an error occurred. A (0) is returned if the file is finished reading. And a (1) is returned if a line is read.

---
<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/get_next_linem.png?raw=true"/>
</div>

---

<h2> How it Works </h2>
</div>
<br/>

This project is focused on writing our own function to get a line from a file descriptor, without knowing its size beforehand
<br/>
* We must implement a buffer. We can't neither come back nor move in the file descriptor.
* We can't use lseek, only read, malloc, free, nor the libft
* We can't use globals variables nor FILE structure, but static variables are allowed
* The buffer size used by read can be changed
* Call the function in a loop will then allow to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines
* Be able to read multiple file descriptors at the same time
* Only use one static variable.
