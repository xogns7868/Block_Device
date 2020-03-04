# LBA
0. blktrace를 이용한 Block I/O Layer에서 발생하는 이벤트를 CPU 단위로 분석한 결과
   순서: blktrace -> blkparse -> btt -> seekwatcher로 진행하면서 분석
   btt는 blktrace 추적 도구의 사후 처리 도구. seekwatcher은 blktrace내용을 그림으로 분석해주는 도구

1. blktrace2.c는 특정 공간(/dev/sda, sda1, sda2...)에서 원하는 LBA주소와 Size를 입력해 파일을 읽는 코드이다.
   blktrace -d /dev/sda -a complete -a issue -o - | blkparse -f "%M %m %d %a %N %S %5T.%9t\n" -i -
   명령어를 통해 확인할 수 있다.
   
![initial](https://user-images.githubusercontent.com/43363576/75087592-9eb69a80-5585-11ea-882c-b537d9539c08.png)

   다음 화면은 4GB이상의 영역에 read I/O를 요청한 화면입니다.

![initial](https://user-images.githubusercontent.com/43363576/75654787-d3240800-5ca3-11ea-9b82-c12ab9267210.png)

2. blktrace3.c와 blkparser.cpp는 특정 파일이 어떤 LBA에 있는지 파악하는 코드이다. 먼저 blktrace3.c를 실행하고              
   blktrace -d /dev/sda -a      complete -a issue -o - | blkparse -f "%M %m %d %a %N %S %5T.%9t\n"  
   -i - -o ./blktrace.output 명령어를 실행하여 특정 파일을 read    하는 과정이 찍힌 output 파일을 생성한다. 그
   리고 blkparser.cpp를 실행해 해당 output 파일에서 원하는 것만 추출한 것을 출력한다.
   sudo hdparm --fibmap 명령어를 실행한 결과와 비교하여 확인한다.
 
![initial](https://user-images.githubusercontent.com/43363576/75087525-ceb16e00-5584-11ea-8e4f-97022db7dea9.png)

   다음 화면은 4.6GB에 해당되는 고용량 파일을 parser한 화면입니다.
   
![initial](https://user-images.githubusercontent.com/43363576/75652168-bab0ef00-5c9d-11ea-92fb-6328ef08f159.png)
