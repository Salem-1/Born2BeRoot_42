#!/bin/bash
wall "Architecture: `uname -a`
#CPU physical: `lscpu | grep \"CPU(s)\" | head -1 | awk '{print $2}'`
#Vcpu: `cat /proc/cpuinfo | grep \"processor\" | wc -l`
`free -m | head --line=2 | tail --line=1 | awk '{ORS =\"\";print \"#Memory usage:  \" $3 \"/\" $2 ;ORS=\"\n\";printf\"MB (%.2f%%)\n\", ($3/$2 * 100)}'`
`df --total -h |tail -1| awk '{printf\"#Disk usage: %d/%s (%s)\n\", $3*1000, $2, $5}'`
`top | head -3 |tail -1| awk '{print \"#CPU laod: \" $2\"%\"}' |head -1`
`who -b | awk '{print\"#Last reboot: \" $3 \" \" $4}'`
`lsblk |grep lvm | wc -l | awk '{if ($1 < 1 ) {print \"#LVM use: no\";exit;} else {print \"#LVM use: yes\"}}'`
`netstat -an | grep \"ESTABLISHED\" |grep \"tcp\" | wc -l  | awk '{print \"#Connections TCP: \" $1 \" ESTABLISHED\"}'`
`w  |head -1 | awk '{print \"#User log: \" $4 }'`
#Network: IP `ip route list | tail -1| cut -d \" \" -f 9` (`ip -h address | grep \"ether\" | cut -d \" \" -f 6`)
`journalctl -q _COMM=sudo |grep \"COMMAND\" |wc -l | awk '{print \"#Sudo: \" $1 \" cmd\"}'`" 2>/dev/null
