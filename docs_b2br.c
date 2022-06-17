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
-Virtulaization:
	using the resources of the os virtualized for another os on top of the main os
-turn in signature.txt at the root repo., paste in it the signature fo your VMachine
-Server:
	Computer that provide service to other computers.
-Debian Vs CentOS:
	Both are Linux destro, for CentOS more to enterprise, more stable release new version every 5 years, not easy to update, 
	for Debian release every 2 years more easy to update both used as server, debian more easier to use.
-KDump:
	Export Memory Image if the Kernel crashed, to be used for debugging
-SELinux:
	Security enhanced linux,, that control who can access the system, more complex technology
	Developed by NSA and released as opensource in 2000
-AppArmor
	Security application that protect against external and internal threats, Debain has it by default, less complex
	more easy to learn that SElinux
-How to create encrypted partitions in Debian?
		all data on this partition will be erased, then you can encrypt it after that
-Apt vs aptget?
	apt-get more to the lower level(For system users ), both almost do the same fuctionality, apt more user friendly
	REF:https://linuxconfig.org/apt-vs-apt-get-advanced-package-tool
-Apptitude Vs Apt:
	Aptitude for package management more higher level and has better UI, apt more to lower level and uses command line only
	Aptitude can ease the package searching as well,
	Ref:https://www.fosslinux.com/43884/apt-vs-aptitude.htm#:~:text=The%20first%20difference%20you%20will,by%20both%20of%20the%20tools.
-SSH:
	Secured shell, make it secure to remotly access another computer, connect securly 2 computers connected to unsecured network through
	encryption, secure file transfer and data transfer ....ect.
-Port
	Virtual place within OS where the connection start and end, On software level identify Logical operation that specifiy specific process
	or type of network service
-SSH configuration port and not to run as root:
	this is from the configuration of the ufw
-ufw  firewall?
	Uncomplicated Fire wall is the network security device teh at monitors and filters incoming and outgoing network traffic based 
	on organisations based security policy, firewall is the barrier living bettween internal network and public networks,
	Firewall main purpose to allow non threatning traffic and keep threatning traffic away,
	Ref: https://www.checkpoint.com/cyber-hub/network-security/what-is-firewall/#:~:text=A%20Firewall%20is%20a%20network,network%20and%20the%20public%20Internet.

-How to configure ufw?
	in the comands below
-How to modify hostname?
	in commands below
-How to configure password policy?
	using passwd quality library to change password specifications
-sudo
	allow you execute commands as root, super user
-how to configure sudo
	visudors file 
-groups
	number of users has same privilage
-how to create groups, add users, delete users, chmod groups?
	see commands below.
-How to create new user and assign him to a group?
	see code below.
-TTY mode
	teletype writer, print the name of the terminal, 
	for example if you have more than virtual terminal, users use same veirtual terminal, then you can type
	$tty to know which virtual terminal you are in

SSH will be tested during defence by setting up new account?

----------------------------------------------------------------------------------
Specifications:
(check)1-AppArmor must be running at startup
(check) 2-Create at least 2 encrypted partitions
(check)3-SSH run on port 4242 only 
(check)4-Must not be able to connect SSH as root
5-Setting up new account during defense
(check)6-Firewall has only port 4242 open
(check)7-Firewall must be activated when launching the VM
(check)8-Host name ahsalem42, another user ahsalem ----->  belong to user42 group
9-Modify hostname during evaluation
(check)10-Implement strong password policy:
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
(check)12-sudo group specs:
	incorrect passwd attempt = 3 
	wrong passwd message need to be displayed "this is wrong password"
	archive all sudo actions in /var/log/sudo/  all inputs and outputs 
	enable TTY mode
	sudo path restricted to "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
13-monitoring.sh !/bash/sh ,,,, man wall:
	Displayed at startup
	Displayed evey 10 minutes 
	contains following:
		1-archticture  of my OS and Kernel version uname
		2-Number of physical processpor  lscpu
		3-Number of virtual processors    lscpu
		4-Available RAM on my server , and utilization percentage rate
		5-Date and time of last reboot
		6-LVM active or not
		7-Number of active connections 
		8-Number of users using the server
		9-IPv4 address of my server and MAC address
		10-Number of commands executed with sudo program

Note: check the testing commands at the end of the project file.
----------------------------------------------------------------
The commandline_bank.enum():
//advanced package tools managment that install remove upgrade manage thousands of packages on debian and other distro
	$ apt-get update -y
	$ apt-get upgrade -y
//Super user giving commands as the root, similar to windows admin
	$ apt install sudo
	$ su -
//Adding user to the sudo group usermod -aG groupname username
	$ usermod -aG sudo your_username
//Check if the user part of the sudo group?
	$getent group sudo
//opening the sudo config file	
	$sudo visudo
//adding username privilage to the sudo group in the sudo_config file	
	$your_username    ALL=(ALL) ALL
//Installing git version control	
	$ apt-get install git -y
//wget is free opentool to download files from the web, using those protocols( HTTP, HTTPS, FTP and FTPS,)	
	$sudo apt-get install wget
//isntalling vim
	$sudo apt-get install vim
installing the zsh because it's more handy in dealing with the terminal (not part of the project)
	  $ sudo apt-get install zsh
	$ zsh --version
	//do this later
	 $ sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
	$ sudo apt-get update
	
---------------------------------->>>>>>>>>>>>>>>continue studying this part in the campus inshalla 15th June 2022<<<<<<<<<<<<<<<<----------------
//secure shell use for file transfer and remote controlling other mashines for security purpose , openssh is cloned from the ssh project and it's opensource
	  $ sudo apt install openssh-server
//cehcking the status of ssh you have one of 2 commands
	 $sudo service ssh status	  $sudo systemctl status ssh
//do what it said
	 $service ssh restart
//opening the ssh configuration file to edit the configs like: ports ..ect
	 $sudo nano /etc/ssh/sshd_config
	 #Port 22
	 Port 4242
//checking the port 4242 via grep command
	 $sudo grep Port /etc/ssh/sshd_config
	 $sudo service ssh restart
//installing the firewall
	 $apt-get install ufw
//enable the firewall on the system startup
	 $sudo ufw enable
//list the ufw rules, then you can delete or deal with the role depending on it's number
	 $sudo ufw status numbered
//firewall allowing the ssh 
	 $sudo ufw allow ssh
//allowing the port of 4242
	 $sudo ufw allow 4242
//checking the ufw added rules
	 $sudo ufw status numbered
//delete sprecific rule
	$sudo ufw delete (that number, for example 5 or 6)
//modify the port from the virtual machine
	sudo systemctl restart ssh
	$ sudo service sshd status
	----from the host machine
	ssh your_username@127.0.0.1 -p 4242
	exit =-------> to quit the connection
	------------------
	Password policy:
	--------------
//This is a library to specify debian password configuration
//ref : https://ostechnix.com/how-to-set-password-policies-in-linux/	
	$ sudo apt-get install libpam-pwquality
//openining the password configuration file on the system
	 $sudo nano /etc/pam.d/common-password
//modifying what is inside the file
	 password [success=2 default=ignore] pam_unix.so obscure sha512
	 password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10
	 password    requisite         pam_pwquality.so retry=3
	 password    requisite         pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7 enforce_for_root
	 $ sudo nano /etc/login.defs
PASS_MAX_DAYS 9999
PASS_MIN_DAYS 0
PASS_WARN_AGE 7
//change it to be 
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7

$ sudo reboot

$ sudo groupadd user42
$ sudo groupadd evaluating
groups

$ chage -l your_new_username
$ sudo nano /etc/sudoers
Defaults     secure_path="..."
Defaults     passwd_tries=3
Defaults     badpass_message="Password is wrong, please try again!"
Defaults	logfile="/var/log/sudo.log"
Defaults	log_input,log_output
Defaults        requiretty
Defaults   secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
"
//to know the name of the host
$ hostnamectl
//assigning new host name
$ hostnamectl set-hostname new_hostname
$ sudo nano /etc/hosts
127.0.0.1       localhost
127.0.0.1       new_hostname
 sudo reboot
//configuring the crontab
 $ sudo crontab -u root -e
 */10 * * * * /usr/local/bin/monitoring.sh

monitoring.sh script draft, other people draft that I idn't 
  #!/bin/bash
wall $'#Architecture: ' `hostnamectl | grep "Operating System" | cut -d ' ' -f5- ` `awk -F':' '/^model name/ {print $2}' /proc/cpuinfo | uniq | sed -e 's/^[ \t]*//'` `arch` \
$'\n#CPU physical: '`cat /proc/cpuinfo | grep processor | wc -l` \
$'\n#vCPU:  '`cat /proc/cpuinfo | grep processor | wc -l` \
$'\n'`free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }'` \
$'\n'`df -h | awk '$NF=="/"{printf "#Disk Usage: %d/%dGB (%s)", $3,$2,$5}'` \
$'\n'`top -bn1 | grep load | awk '{printf "#CPU Load: %.2f\n", $(NF-2)}'` \
$'\n#Last boot: ' `who -b | awk '{print $3" "$4" "$5}'` \
$'\n#LVM use: ' `lsblk |grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"} }'` \
$'\n#Connection TCP:' `netstat -an | grep ESTABLISHED |  wc -l` \
$'\n#User log: ' `who | cut -d " " -f 1 | sort -u | wc -l` \
$'\nNetwork: IP ' `hostname -I`"("`ip a | grep link/ether | awk '{print $2}'`")" \
$'\n#Sudo:  ' `grep 'sudo ' /var/log/auth.log | wc -l`
----------------------------------------------------------------------
my bash script
//It took me 4 days to write this scrip, because II needed to understand many new concept before execting each tasks
//next step to calibrate it vs the script above using diff,
//15th June 2022 (from home)
#!/bin/bash

echo "#Architecture: $(uname -a)"
echo "#Physical proccessor: $(lscpu | grep "CPU(s)" | head -1 | awk '{print $2}')"
echo "#Vcpu: $(cat /proc/cpuinfo | grep "processor" | wc -l)" 

#$4 is the free space, $3 utilized space, $2 total space
free | head --line=2 | tail --line=1 | awk '{print "#Memory usage:  " $4 "/" $2 "MB ("  $3/$2 * 100 "%)"}'

df -h | head -4 | tail -1 | awk '{print "#Disk usage: "$3"/" $2 " (" $4 ")"}'
lsblk |grep lvm | wc -l | awk '{if ($1 < 1 ) {print "#LVM use: no";exit;} else {print "#LVM use: yes"}}'
netstat -an | grep "ESTABLISHED" |grep "tcp" | wc -l  | awk '{print "#Connections TCP: " $1 " ESTABLISHED"}'
w |head -1 | awk '{print "#User log: " $4 }'
echo "#Network: IP $(ip route list | grep "default" | cut -d " " -f 3) ($(ifconfig -a | grep "ether" | head -1 | cut -d " " -f 10))"
cat /var/log/sudo/sudo.log | wc -l | awk'{print "#Sudo: " $1 "cmd"}'
----------------------------------
	
$Who
list info about all the logged in users

//left tasks 
1-Close root acces from remote machine
2-Test your script vs others
3-Direct the err to /dev/null
4-revise and test all specifications all over again



n = n * 100000 /100000; 
-----------
passwds:
root=Asdfjkl;1
ahsalem=Born2BeRoot
encryption="asdfjkl; asdfjkl; "
test_user=Test_user1

----------------------------------------
yesterday 16th June, I finished the project, then took snapshot before submission, I tried to delete the old snapshots, but I deleted the whole project by mistake, here I am redoing it all over again, let's see the work that took me 8 days to finish how much time will it take me now to do it again.
17th June 6:00 am



Done with the project 8:16 am :) 

Ahmed Salem
17th June 2022
42_Abu Dhabi
