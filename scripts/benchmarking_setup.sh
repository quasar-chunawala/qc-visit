#!/usr/bin/bash

echo -e "Performing bencmarking setup...\n"

# 1. Disable Turbo boost
echo -e "Disable Turbo boost\t"

# Intel
echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo

echo -e "Complete.\n"

#3. Set scaling_governor to performance
echo -e "Set scaling_governor to performance\t"

for i in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
do
  echo -e "Setting $i"
  echo performance > $i
done

echo -e "Complete.\n"

#4. Lock the frequency of CPU
echo -e "Lock the frequency of core-3 to 2.3GHz\t"

sudo cpupower --cpu 3 frequency-set -d 2.3GHz -u 2.3GHz

echo -e "Complete.\n"

#5. Disable ASLR
echo -e "Disable ASLR\t"
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
echo -e "Complete." 

#2. Disable hyper-threading
echo "Checking SMT(simultaneous multithreading) setup"
cat /sys/devices/system/cpu/cpu*/topology/thread_siblings_list

echo -e "Disabling hyper-threading on core-4\t"

echo 0 | sudo tee /sys/devices/system/cpu/cpu4/online

echo -e "Complete.\n"