#!/bin/bash
for i in {-9. .9}
do
  ./push_swap "$i" | shasum
done
