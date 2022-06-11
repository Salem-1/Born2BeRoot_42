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
(check) 2-Create at least 2 encrypted partitions
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

Note: check the testing commands at the end of the project file.
----------------------------------------------------------------
The commandline_bank.enum():
$ apt-get update -y
$ apt-get upgrade -y
$ apt install sudo
$ su -
$ usermod -aG sudo your_username
 getent group sudo
sudo visudo
your_username    ALL=(ALL) ALL
$ apt-get install git -y
	sudo apt-get install wget
	 sudo apt-get install vim
	 $ sudo apt-get install zsh
$ zsh --version
$ sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
	$ sudo apt-get update
$ sudo apt install openssh-server
	sudo systemctl status ssh
	 service ssh restart
	 sudo nano /etc/ssh/sshd_config
	 #Port 22
	 Port 4242
	 sudo grep Port /etc/ssh/sshd_config
	 sudo service ssh restart
	 apt-get install ufw
	 sudo ufw enable
	 sudo ufw status numbered
	 sudo ufw allow ssh
	 sudo ufw allow 4242
	 sudo ufw status numbered
$ sudo ufw delete (that number, for example 5 or 6)
	modify the port from the vm
	sudo systemctl restart ssh
	$ sudo service sshd status
	----from the host machine
	ssh your_username@127.0.0.1 -p 4242
	exit =-------> to quit the connection
	------------------
	Password policy:
	--------------
	$ sudo apt-get install libpam-pwquality
	 sudo nano /etc/pam.d/common-password
	 password [success=2 default=ignore] pam_unix.so obscure sha512
	 password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10
	 password    requisite         pam_pwquality.so retry=3
	 password    requisite         pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7 enforce_for_root
	 $ sudo nano /etc/login.defs
	 PASS_MAX_DAYS 9999
PASS_MIN_DAYS 0
PASS_WARN_AGE 7

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
Defaults	logfile="/var/log/sudo/sudo.log"
Defaults	log_input,log_output
Defaults        requiretty
Defaults   secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
$ hostnamectl
$ hostnamectl set-hostname new_hostname
$ sudo nano /etc/hosts
127.0.0.1       localhost
127.0.0.1       new_hostname
 sudo reboot
 $ sudo crontab -u root -e
 */10 * * * * /usr/local/bin/monitoring.sh
  drm:vmw_host_log *ERROR* Failed to send host log message.
