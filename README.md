# 42_Minishell


<BS><div align="center"><br>
  <img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="650" height="300">
</div>
</br>

> *This project is about creating a simple shell, YES, my own little bash. I've learn a lot about processes and file descriptors*

<p> This project is a recreation bash with some limitations</p>

Install if you don't have readline installed

```bash
sudo apt-get install libreadline-dev
```
<p> To use it:</p>

```bash
git@github.com:benmaia/42_Minishell.git
```

```bash
cd 42_Minishell/minishell
```

```bash
make && ./minishell
```
<br>
<li <p>The built-in functions where made by hand:</p>
	<ul> echo && echo -n </ul>
	<ul> env </ul>
	<ul> export </ul>
	<ul> unset </ul>
	<ul> cd </ul>
	<ul> pwd </ul>
	<ul> exit with error code/values</ul>
</li>


<li <p>Do the signals for prompt and block commands:</p>
	<ul> CTRL C </ul>
	<ul> CTRL D</ul>
	<ul> CTRL \</ul>
</li>

As also have to run all the other commands with execve, have to handle multiple pipes an redirections and support running other programs, like the minishell itself.

Have to launch absolute or relative commands, have to handle expansions of variables '$' and parsing the quotes.

More info on the subject itself!!**<a href="https://github.com/benmaia/42_Minishell/blob/master/en.subject.pdf"> HERE</a>**

<p> Here is an example:</p>

<img src="" width="1000" height="450">
</br>
<p> Minishell OK ✅</p>
</br>
<p> Grade: 96% </p>
<div style="display: inline"><br>
   <img src="">
</div>
