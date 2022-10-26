# 아두이노 보드 정리
참조 : https://www.circuito.io/

> PIN
>> A0~A4
>> D0~D13

>

# 센서 정리
(센서 : 데이터 수집/출력, 모듈 : 부가기능(또는 센서 사용을 편하게 해준 api같은 존재))



> LED 센서
>> +, -극, 저항(정격이 1.85V임)

> 물 수위 감지 센서
>> VCC(5V), GND(GROUND), S(출력값 : 아날로그)


>

# 코드 정리

## 클래스
>Serial
>>if()
>>available()
>>begin(보드레이트) : 초당 몇번 송/수신할건지 설정하는 보드레이트 값 설정(보통 9600으로 설정 : 1초에 9600번 통신한다는 뜻)
>>


+아두이노 함수 정의 정리

> define : 매크로
>>"#define" "매크로명" "값" 으로 정의(변수 정의랑 같음)
>>ex: #define ANALOGY_PIN A5 //ANALOGY_PIN을 A5값으로 설정

> void setup : 시작 전 설정 함수
>> 

> loop : 