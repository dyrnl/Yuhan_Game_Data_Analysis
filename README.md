# 게임데이터분석 private game code
    * 멤버 : 202327021 송영진
             202327029 송재원
             202327035 정회성
             202327071 노단비


             러시안 룰렛

1. 유니티로 만드는 이유는 쉬워서가 아니라 그림을 넣기 편해서
2. 근데 러시안 룰렛은 돌아가는거를 안넣는다 해도 리볼버를 그려야함
3. 코드는 쉽당.
4. 여기에 ui를 넣는다면 일단

코드 내용

랜덤에 불릿을 넣는다
상대가 있어야함
상대 한번 나한번?
왼쪽에 나라는 큐브를 만들고
오른쪽에 적이라고 큐브를 만들고
총을 가운데에다가 놓고
한턴에 한번씩 왼쪽 오른쪽에 번갈아 가면서 쏠수 있게 만들수 있다


게임 내용

하트는 3개씩
6발중 총알 6발 이하로 넣기 랜덤으로
총을 쏘면 위치가 바뀜
애니메이션을 넣자 가운데에서 쏘는 위치로 총알이 나감
큐브를 맞으면 하트가 사라짐
내가 하트가 사라지면 -100 
상대가 하트가 사라지면 +100
만약 상대방 하트가 다 사라지면 +500점
내 하트가 다 사라지면 게임 오버 화면이 나오면서 코인을 더 넣겠습니까?라고 나오기
나온 다음에 코인을 넣겠다고 하면 (로그 bu) 데이터 넣기
끝
