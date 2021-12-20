gcc -Wall -Werror -Wextra union.c -o union
./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e > result.txt
./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e >> result.txt
./union "rien" "cette phrase ne cache rien"  | cat -e >> result.txt
./union  | cat -e >> result.txt
./union "rien"  | cat -e >> result.txt
diff result.txt expected.txt
