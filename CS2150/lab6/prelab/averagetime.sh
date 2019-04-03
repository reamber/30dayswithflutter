#Amber Liu
#al7bf
#10/23/2018
#averagetime.sh

#!/bin/bash

#prompt the user for the dictionary and grid file names used by your word puzzle executable
echo 'your dictionary file: '
read dictFile

echo 'your grid file: '
read gridFile

RUNNING_TIME1=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME2=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME3=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME4=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME5=`./a.out $dictFile $gridFile | tail -1`

echo 'Average time: ' $(((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5)/5))


