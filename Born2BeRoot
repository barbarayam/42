Born2beroot: A Retrospective on Secure System Admin
📌 Project Overview
I originally validated my project in August 2025; this project involved configuring a secure Debian server on a Virtual Machine. It emphasizes system hardening, strict partitioning using LVM (Logical Volume Management), and automated system monitoring.

Why revisit this?
I recently had the opportunity to revisit this project as an evaluator. This dual perspective—as both the implementer and the auditor—allowed me to identify common pitfalls and architectural "best practices" that I’ve documented here for future reference.

🛠 Technical Specifications
Operating System: Debian.
Hypervisor: VirtualBox.
Partitioning: LVM for dynamic scaling, allowing volumes to be resized without unmounting—a critical business continuity feature.
Security: Strict Sudoers policy (logging, TTY requirement) and UFW firewall configuration.
Automation: Bash script for real-time telemetry via cron.

📊 Monitoring Logic (monitoring.sh)
The custom script broadcasts telemetry to all terminals using the wall command.

Key Command Learning Points
awk: Used to extract specific columns (like RAM usage) and perform real-time math for percentages.
journalctl _COMM=sudo: The most reliable way to count successful sudo actions by filtering system logs.
top -bn1: Running top in "batch mode" for exactly one iteration to grab clean CPU load data.

📈 Technical Trade-offs & Evaluation Insights
Scalability vs. Complexity: LVM adds an abstraction layer but is the "Technical PM" choice for scalability. It allows for adding disk space to a live database partition without downtime.
Security vs. User Experience: A strict sudo policy (limited retries, custom errors) reduces brute-force risks but requires clear documentation so users don't feel "locked out".
The "Startup" Gap: A common mistake I saw as an evaluator was the cron job that only ran every 10 minutes. By adding @reboot, we ensure the first data point is captured immediately upon deployment.

🚀 Critical Setup Steps (Crontab)
To avoid the "missing data on boot" error, ensure these two triggers are in the root crontab:
Bash

# Edit crontab with: sudo crontab -e
# 1. Run every 10 minutes
*/10 * * * * /usr/local/bin/monitoring.sh

# 2. Run at system startup
@reboot /usr/local/bin/monitoring.sh
📄 The Final Script
Bash

#!/bin/bash

# Extracting Architecture, CPU (Physical/Virtual), RAM, Disk, Load, and Network status.
# The use of 'wall' ensures all active users are alerted to system status.

arch=$(uname -a)
cpuf=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
cpuv=$(grep "^processor" /proc/cpuinfo | wc -l)
ram_total=$(free -m | awk '$1 == "Mem:" {print $2}')
ram_use=$(free -m | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')
cpu_load=$(top -bn1 | grep "^%Cpu" | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
tcpc=$(ss -ta | grep ESTAB | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	#Architecture: $arch
	#CPU physical: $cpuf
	#vCPU: $cpuv
	#Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	#Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	#CPU load: $cpu_load
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $tcpc ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmnd cmd"
