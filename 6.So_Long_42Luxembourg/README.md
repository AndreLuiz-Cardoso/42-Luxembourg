<h1 align=center>
	<b>So_Long</b>
</h1>

<p align=center>
	This is a 2D game where the player navigates through a maze-like environment to reach a goal, avoiding obstacles and enemies. It is created using the MiniLibX library and I had to implement game mechanics, file input/output, and basic graphics.

---
<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/so_longm.png?raw=true"/>
</div>

---
<h2> Mandatory </h2>
<br/>
<p>1. Must use MiniLibX.</p>
<p>2. Makefile must compile source files and should not relink.</p>
<p>3. The program has to take as a parameter a map description file ending with the .ber extension.</p>
<h2> GAME </h2> 
<p>Goal: Collect every collectable and escape choosing the shortest route.</p>
<p>W, A, S and D keys must be used to move the main character up, down, left and right.</p>
<p>Can't move into walls.</p>
<p>Number of movements must be displayed in the shell.</p>
<p>Must be a 2D view (top-down or profile).</p>
<p>Doesn't need to be real-time.</p>
<h2> GRAPHIC MANAGEMENT</h2> 
<p>Display the image in a window and must remain smooth (changing windows, minimizing, ...).</p>
<p>Pressing ESC must close the window and cleanly quit the program.</p>
<p>Clicking on the window cross must also close and quit the program cleanly.</p>
<p>The use of the images of the MiniLibx is mandatory.</p>
<h2> MAP COMPONENTS</h2> 
<p>The map should include 3 components to be constructed: walls, collectables and free space.</p>
<p>Should be composed of only these 5 characters:</p>
<p>Characters	Description</p>
<p>0	Empty space.</p>
<p>1	Wall.</p>
<p>C	Collectible.</p>
<p>E	Map exit.</p>
<p>P	Player starting position.</p>
<h2> MAP VALIDATION</h2> 
<p>The map must contain 1 exit, at least 1 collectable, and 1 starting position to be valid.</p>
<p>Map must be rectangular.</p>
<p>Map must be closed/surrounded by walls. If not, the program should return an error.</p>
<p>Check if there is a valid path in the map.</p>
<p>The program must be able to parse any kind of map, as long it respects the rules.</p>
<p>If an error/misconfiguration is encountered, it should return Error\n followed by an explicit message.</p>

