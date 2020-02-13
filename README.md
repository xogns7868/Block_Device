# LBA
1. blkparser.cpp는 특정 파일이 어떤 LBA에 있는지 파악하는 코드이다. 
   sudo hdparm --fibmap 명령어를 실행한 결과와 비교하여 확인한다.

2. blktrace.c는 특정 공간(/dev/sda, sda1, sda2...)에서 원하는 LBA주소와 Size를 입력해 파일을 읽는 코드이다.
   blktrace -d /dev/sda -a complete -a issue -o - | blkparse -f "%M %m %d %a %N %S %5T.%9t\n" -i -
   명령어를 통해 확인할 수 있다.
