#!bin/bash

echo -e "Enter File Name:"
read filename
echo -e "Extention? :"
read extention

for i in {1..3}; do
	touch $filename"_"$i.$extention
done
