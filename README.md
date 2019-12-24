	
	/*
	*	2019/12/6
	*	Yonhoo
			*/


	A simple shell lab implemented with the book


################<br/>
CS:APP Shell Lab<br/>
################<br/>

Files:<br/>
Makefile&ensp;&ensp;# Compiles your shell program and runs the tests<br/>
README&ensp;&ensp;  # This file<br/>
tsh.c&ensp;&ensp;   # The shell program that you will write and hand in<br/>
tshref&ensp;&ensp;  # The reference shell binary.<br/>

\# The remaining files are used to test your shell<br/>
sdriver.pl&ensp;&ensp;# The trace-driven shell driver<br/>
trace*.txt&ensp;&ensp;# The 15 trace files that control the shell driver<br/>
tshref.out&ensp;&ensp;# Example output of the reference shell on all 15 traces<br/>

\# Little C programs that are called by the trace files<br/>
myspin.c&ensp;&ensp;  # Takes argument <n> and spins for <n> seconds<br/>
mysplit.c&ensp;&ensp; # Forks a child that spins for <n> seconds<br/>
mystop.c&ensp;&ensp;  # Spins for <n> seconds and sends SIGTSTP to itself<br/>
myint.c&ensp;&ensp;   # Spins for <n> seconds and sends SIGINT to itself<br/>
