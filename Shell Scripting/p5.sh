#!/bin/bash

for i in {1..100};do
  if(($i%5==0));then
    echo "The number $i is divisible by 5"
  else
    echo "The number $i is not divisible by 5"
  
fi
done
