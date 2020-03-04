1. sudo blktrace -d /dev/sda -w 600

   sda.blktrace.0 sda.blktrace.1 sda.blktrace.2 sda.blktrace.3 ... 이 생성된다. 생성 개수는 CPU 개수만큼  
   생성되며 각 파일엔 해당되는 CPU의 이벤트가 출력되어있다.

2. blkparse -i sda.blktrace.* -d sda.bin

   sda.bin이 생성한다. btt에서 사용하기 위해 각 CPU의 이벤트 처리를 binary 파일로 표현한 것이다.

3. btt -i sda.bin -o sda

   sda라는 이름의 avg, dat, msg가 생성된다.
