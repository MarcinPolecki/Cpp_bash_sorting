# Simple program showing usage of C++ and bash script

## What C++ program do?
1. Open input file named input_file.txt.
2. Read all lines from the file to string vector.
3. Print readed values.
3. Sort vector.
4. Print sorted values.
5. Save sorted values into output file named output_file.txt

## How to run program?
1. Go to directory where main.cpp is (/sorting_words).
2. From the terminal run commands:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
3. In directory where executable file was created (in this case in /build folder) create file named input_file.txt and add some lines one by one. For example:
    ```txt
    word
    second word
    other word
    ```
4. Execute command:
    ```bash
    ./sorting_words
    ```
5. You should get in the same folder output file named output_file.txt with sorted lines. In this example you should receive:
    ```txt
    other word
    second word
    word
    ```

## Run program using bash script
### Alternatively you can run bash script that is doing the same things but automtically:
1. Building main.cpp with cmake
2. Creating input_file with some lines
3. Executing program that is sorting this file

To do so just write in the terminal:
```bash
./run_demo.sh
```