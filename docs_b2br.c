#Bism Ellah Elra7man Elra7eem 

7th June 2022

This is documentation of my journey with born to be root project:
in this project I will setup a server in virutal box with tight specification, 
   Let the fun begin....

-Operating system : CentOS. Debian ----- dont't setup KDump  SELinux must run at the startup	and config. must be adapted for the project needs
-at Startup:
   SELinux
   AppArmor for Debian
-Firewall must be activated upon launching the virtual box for SCentOS
-Create at least 2 encrypted partitions 
-SSH service will run on 4242 only must not be possible to connect using SSH as root
-Configure your firewall using UFW (this will leave only 4242 open)
	to install it you will need DNF

Terminology(Mind map):
--------------------
-turn in signature.txt at the root repo., paste in it the signature fo your VMachine
-Server
-Debian Vs CentOS
-KDump
-SELinux
-AppArmor
-How to create encrypted partitions in Debian?
-Apptitude Vs Apt
-SSH 
-Port
-SSH configuration port and not to run as root
-ufw  firewall
-How to configure ufw
-How to modify hostname?
-How to configure password policy
-sudo
-how to configure sudo
-groups
-how to create groups, add users, delete users, chmod groups?
-How to create new user and assign him to a group?
-TTY mode
Questions to prepare answer for?
What is the difference bettween aptitude and apt?
What is SELinux?
What is AppArmor?
SSH will be tested during defence by setting up new account?

----------------------------------------------------------------------------------
Specifications:
1-AppArmor must be running at startup
2-Create at least 2 encrypted partitions
3-SSH run on port 4242 only 
4-Must not be able to connect SSH as root
5-Setting up new account during defense
6-Firewall has only port 4242 open
7-Firewall must be activated when launching the VM
8-Host name ahsalem42, another user ahsalem ----->  belong to user42 group
9-Modify hostname during evaluation
10-Implement strong password policy:
expiry every: 30 days
minimum days allowed before modifications: 2 days
user recieve warning message before passwd expiry: 7 days
passwd specs: 
	10 char long,
   	must have uppercase,
   	must have number,
   	must not contain 3 consecutive identical chars,
   	must not include username
root userpass:
	at least 7 chars,
	not part of former passwd (unique) 
	root passwd has to compliy with this policy ???????
11-After setting up and configure sudo group, change all password on the machine including rootuser pass..
12-sudo group specs:
	incorrect passwd attempt = 3 
	wrong passwd message need to be displayed "this is wrong password"
	archive all sudo actions in /var/log/sudo/  all inputs and outputs 
	enable TTY mode
	sudo path restricted to "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
13-monitoring.sh !/bash/sh ,,,, man wall:
	Displayed at startup
	Displayed evey 10 minutes 
	contains following:
		1-archticture  of my OS and Kernel version
		2-Number of physical processprs
		3-Number of virtual processors
		4-Available RAM on my server , and utilization percentage rate
		5-Date and time of last reboot
		6-LVM active or not
		7-Number of active connections
		8-Number of users using the server
		9-IPv4 address of my server and MAC address
		10-Number of commands executed with sudo program





