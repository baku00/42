#!/bin/bash
for i in {-9. .9}
do
	for j in {-9. .9}
	do
	  for k in {-9. .9}
	  do
		  for l in {-9. .9}
		  do
			  for m in {-9. .9}
			  do
				  for n in {-9. .9}
				  do
					  ./push_swap "$i $j $n" | shasum
				  done
			  done
		  done
	  done
	done
done
