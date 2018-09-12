#!/bin/bash
g++ ./source/main.c -o lab1
point=1
./lab1 < ./tests/file$point.txt
file="./file.txt"
read  d < $file 
if [ $d -eq 25 ]
then echo TEST#$point success output:$d  
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
echo "" > ./source/file.txt
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -326 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -1 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 4888330 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 16 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -100000000 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 480 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 0 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1

rm file.txt
rm ./source/file.txt
