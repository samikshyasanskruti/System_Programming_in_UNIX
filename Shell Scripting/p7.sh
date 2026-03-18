#!/bin/bash
i=1
while (( $i <=20 ))
 do  
   if (($i%5==0));then
     echo "The number $i"
   fi
   i=$((i+1))
done
   
