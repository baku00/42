#!/bin/bash
for i in {-9. .9}
do
	for j in {-9. .9}
	do
	  for k in {-9. .9}
	  do
		  ./push_swap "$i $j $k" | shasum
	  done
	done
done
