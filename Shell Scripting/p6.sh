#!/bin/bash
i=1
while [ $i -le 10 ];do
      if [ $((i%5)) -eq 0 ];then
         echo "The number $i is divisible by 5"
      else
         echo "The number $i is not divisible by 5"
      fi
      i=$((i + 1))
done
