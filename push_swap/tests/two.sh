#!/bin/bash
for i in {0..9}
do
	for j in {0..9}
	do
		echo "./push_swap '$i $j'"
		./push_swap "$i $j"
	done
done
