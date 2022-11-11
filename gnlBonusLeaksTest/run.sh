gcc -o prog -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h main.c
echo "\n!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!\n"
valgrind ./prog > result_with_buffersize_1.txt
gcc -o prog -D BUFFER_SIZE=42 ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h main.c
echo "\n!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!\n"
valgrind ./prog > result_with_buffersize_42.txt
gcc -o prog -D BUFFER_SIZE=1000000 ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h main.c
echo "\n!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!"
echo "!-- PLEASE TYPE SOMETHING NOW --!\n"
valgrind ./prog > result_with_buffersize_1000000.txt
rm -f prog
