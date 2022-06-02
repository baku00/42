#!/bin/bash
for i in {-9. .9}
do
	for j in {-9. .9}
	do
	  for k in {-9. .9}
	  do
		  for l in {-9. .9}
		  do
			  ./push_swap "$i $j $l" | shasum
		  done
	  done
	done
done
