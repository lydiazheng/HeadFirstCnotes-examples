//COMMAND-LINE OPTIONS

//man [command] //show the manual for other command

//ps -ae
//display all the processes, including their environments
//ie
//1836 ??         0:00.17 /System/Library/Frameworks/Foundation.framework/Versio
//757 ttys000    0:00.02 login -pf Mint
//758 ttys000    0:00.03 -bash
//1855 ttys000    0:00.00 ps -ae

//head foo.txt   //
//display the first 10 lines of the file

//tail foo.txt
//display the last 10 lines

//tail -n 3 foo.txt  // the last 3 lines
//head -n 4 foo.txt  // the first 4 lines

//tail -n +10 foo.txt  // start from the 10th line til the last
//head -n -10 foo.txt  // print all, except the last 10 lines

//head -n10 foo.txt | tail -n+4  // 4th line to 10th line

//head[命令参数][选择参数][文件]
//tail[命令参数][选择参数][文件]

//命令参数 //check using man for appropriate mode usage
//-f //循环读取；display the end of the file, but wait for new data to be added to the end of the file
//-q //不显示处理信息
//-v //显示详细的处理信息
//-c<数目> //显示的bytes
//-n<行数> //显示行数
//--pid=PID //与-f合用,表示在进程ID,PID死掉之后结束.
//-q, --quiet, --silent //从不输出给出文件名的首部
//-s, --sleep-interval=S //与-f合用,表示在每次反复的间隔休眠S秒


#include <stdio.h>
#include <unistd.h>   //to use getopt() for command-line options
//unistd.h header is not part of the standard C library; it is from the POSIX libraries
//getopt(): get option character from command-line argument list
//getopt(int argc, char * const argv[], const char *optstring);

//***argv[0]will instead point to the first command-line argument that follows the options
//   rocket_to -e 4 -a Brasilia Tokyo London
//                     argv[0] argv[1] argv[2]


//./order_pizza -d now -t Anchovies Pineapple....can be used combined -td;
//in order to avoid ambiguity use set_temp -c -- -4 instead of set-temo -c -4 where the 4 is for getof()
//but the -c is system mode
int main(int argc, char * argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;  //the command-linee argument list; type can be integer
    
    //":" means that the option takes an additional argument
    while((ch = getopt(argc, argv, "d:t")) != EOF){  //setting d option valid & needs an argument; e option valid
        switch (ch) {
            case 'd':
                delivery = optarg; //optarg: argument supplied with the 'd' option
                break;
            case 't':
                thick = 1; //setting 1 is equivalent to setting it to true
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    
    argc -= optind;  //optind stores the number of strings read from the command line to get pst the options
    argv += optind;  //make sure we skip past the options we read; argv is a pointer to address
    
    if(thick)
        puts("Thick crust.");
    if(delivery[0])
        printf("To be delivered %s.\n", delivery);
    puts("Ingredients:");
    for (count = 0; count < argc; count++) {
        puts(argv[count]);
    }
    return 0;
}