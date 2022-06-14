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
