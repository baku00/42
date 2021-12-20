gcc -Wall -Werror -Wextra get_next_line.c -o get_next_line
./get_next_line > result.txt
diff result.txt test.txt
