# OS assignment 1
commands (ignore #): 
    file creations:
        echo '321' > f1.txt
        echo '1234' > f2.txt
        ln -s f1.txt f1_link.txt
        make

    ./cmp f1.txt f2.txt #2 different files
    ./copy f2.txt f3.txt #copy normal file to nonexistant
    ./cmp f2.txt f3.txt #compare 2 identical files
    ./copy f1.txt f3.txt #copy normal file to normal file
    ./cmp f2.txt f3.txt #now they are not identical
    ./copy f1_link.txt f2.txt #symlink to normal file
    ./copy f1_link.txt f4.txt #symlink to nonexistant file
    ./cmp f1.txt f2.txt #now they should be the same
    ./copy f1_link.txt f2.txt -l #symlink to normal file with -l
    ./copy f1_link.txt f5.txt -l #symlink to nonexistant file with -l
    ./encode codec1 "hELLo 2 yoU!" 
    ./decode codec1 "HellO 2 YOu!"
    ./encode codec2 "hELLo 2 yoU!"
    ./decode codec2 $(./encode codec2 "hELLo 2 yoU!") #should return the same as inputed
    make clean

script:

Script started on 2022-11-26 18:31:54+02:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="80" LINES="24"]
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ echo '321' > f1.txt
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ echo '1234' > f2.txt
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ 
[K[A]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ 
[K]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ln -s f1.txt f1_link.txt
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ make
gcc -Werror  cmp.c -o cmp
gcc -Werror  -c codec1.c -o codec1.o
gcc -shared -o codec1.so codec1.o
gcc -Werror  -c codec2.c -o codec2.o
gcc -shared -o codec2.so codec2.o
gcc -Werror  copy.c -o copy
gcc -Werror  -c decode.c
gcc -Werror  decode.o -ldl -o decode
gcc -Werror  -c encode.c
gcc -Werror  encode.o -ldl -o encode
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./cmp f1.txt f2.txt
Not Identical
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f2.txt f3.txt
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./cmp f2.txt f3.txt
Identical
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./cmp f2.txt f3.txt[K./copy f1.txt f3.txt
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./cmp f3.txt f2.txt
Not Identical
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f1_link.txt f2.txt
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f1_link.txt f4.txt
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f1_link.txt f2.txt -l[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[Kcmp f1.txt f2.txt
Identical
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f1_link.txt f2.txt -l
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./copy f1_link.txt f5.txt -l
file is copied
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./encode codec1 "hELLo 2 yoU!"
HellO 2 YOu!
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./decode codec1 "HellO 2 YOu!"
hELLo 2 yoU!
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./encode codec2 "hELLo 2 yoU!"
������������
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ ./decode codec2 $(./encode codec2 "hELLo 2 yoU!")
hELLo 2 yoU!
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ make clean
rm -f *.o cmp codec1.so codec2.so copy decode encode f1.txt f2.txt f3.txt f1_link.txt f4.txt f5.txt
]0;zivm20@MainServer: ~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[01;32mzivm20@MainServer[00m:[01;34m~/Desktop/codes/University/Year 3/Semester 1/OS/OS-assignment-1[00m$ exit
exit

Script done on 2022-11-26 18:35:31+02:00 [COMMAND_EXIT_CODE="0"]
