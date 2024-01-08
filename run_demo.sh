#!/bin/bash

input_file="input_file.txt"
executable_file="sorting_words"

#Creating file with some list
create_list_for_sorting()
{
	list_of_words=(
		"tiger" 
		"bird" 
		"cat" 
		"lion" 
		"pig" 
		"dog" 
		"elephant"
		"mouse"
		"bear"
		)
	
	for element in "${list_of_words[@]}"; do
		echo "$element" >> "$input_file"
	done
}

#Create build directory for cmake
mkdir -p build
cd build

#Generate make files
cmake ..

#If success then build
if [ $? -eq 0 ]; then
	make
else
	echo "Compilation error"
fi

#If file aldready exist delete it
if [ -e "$input_file" ]; then
	rm "$input_file"
fi

#Create new input file
touch "$input_file"

#If success then write some input data into file
if [ $? -eq 0 ]; then
	create_list_for_sorting
else
	echo "Error while creating file"
fi

#Execute builded binary file
./"$executable_file"
