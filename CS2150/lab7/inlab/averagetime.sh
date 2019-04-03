#Amber Liu
#al7bf
#11/01/2018
#averagetime.sh
#!/bin/bash

echo "Enter the exponent for counter: "
read input

numCount = 5
result = 0

if [[ $input == "quit" ]] ; then
    exit 0
fi

for((i = 0; i<= numCount; i++))
do
	echo "Running iteration ${i}..."
    time=`./a.out ${input}`
    echo "time taken:" ${time} ms
    result=`expr $result + $time`
done

avg=`expr $result / $numCount`

echo ${numCount} "iterations took" ${result} "ms"
echo "Average time was" ${avg} "ms"