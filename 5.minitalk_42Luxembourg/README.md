
<h1 align=center>
	<b>Minitalk</b>
</h1>

<p align=center>
	The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use signal functions.

---
<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/minitalkm.png?raw=true" alt="cado-car's 42Project Badge"/>
</div>

---

<h2 align=center>
Mandatory
</h2>

<br/>
<div align="center">
<p>You must create a communication program in the form of a client and a server.</p>
</div>
<p>- The server must be started first. After its launch, it has to print its PID.</p>
<p>- The client takes two parameters: 1) The server PID 2) The string to send.</p>
<p>- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.</p>
<p>- The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.</p>
<p>- Your server should be able to receive strings from several clients in a row without needing to restart.</p>
<p>- The communication between your client and your server has to be done only using UNIX signals.
You can only use these two signals: SIGUSR1 and SIGUSR2.</p>

<br/>
<br/>

<div align="center">
<h2> How it Works </h2>
</div>
<br/>
<div align="center">
<h3>Server:</h3>
</div>
<p>Initializes and waits for signals. It sets up a process to listen for signals.</p>
<p>Uses sigaction or signal to define a signal handler that reacts to specific signals.</p>
<p>Receives signals from the client and translates them into bits, which are then grouped to form complete messages.</p>
<p>Displays the received messages on standard output.</p>
<div align="center">
<h3>Client:</h3>
</div>
<p>Converts the message to be sent into a series of bits.</p>
<p>Sends signals to the server process to represent these bits. For example, for each bit in the <p>message, the client sends a SIGUSR1 or SIGUSR2 signal.</p>
<p>Uses the kill function to send signals to the server's process ID.</p>
