# LBA

1. blktrace2.c는 특정 공간(/dev/sda, sda1, sda2...)에서 원하는 LBA주소와 Size를 입력해 파일을 읽는 코드이다.
   blktrace -d /dev/sda -a complete -a issue -o - | blkparse -f "%M %m %d %a %N %S %5T.%9t\n" -i -
   명령어를 통해 확인할 수 있다.

2. blktrace3.c와 blkparser.cpp는 특정 파일이 어떤 LBA에 있는지 파악하는 코드이다. 먼저 blktrace3.c를 실행하고 blktrace -d /dev/sda -a      complete -a issue -o - | blkparse -f "%M %m %d %a %N %S %5T.%9t\n" -i - -o ./blktrace.output 명령어를 실행하여 특정 파일을 read    하는 과정이 찍힌 output 파일을 생성한다. 그리고 blkparser.cpp를 실행해 해당 output 파일에서 원하는 것만 추출한 것을 출력한다.
   sudo hdparm --fibmap 명령어를 실행한 결과와 비교하여 확인한다.
 
