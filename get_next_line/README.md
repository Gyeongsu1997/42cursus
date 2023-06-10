![header](https://capsule-render.vercel.app/api?type=transparent&fontColor=703ee5&height=120&section=header&text=get_next_line&fontSize=70)

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#whatihavelearned">What i have learned</a>
</h3>

---

## 📘 About

파일 디스크립터(file descriptor)로부터 한 줄을 읽어들여 반환하는 함수를 구현하는 과제이다. 정적 변수라는 개념이 등장한다. 동적으로 할당한 메모리 관리의 어려움과 중요성을 느낄 수 있는 과제였다.

## 💡 What i have learned

<details>
<summary><b>file descriptor</b></summary>
 
 - 파일 디스크립터는 프로세스에서 열린 파일의 목록을 관리하는 테이블(file descriptor table)의 인덱스로 파일 디스크립터를 이용해 해당 파일의 주소를 참조하여 접근할 수 있다.
 - File descriptor table은 PCB(Process Control Block)에 저장된다.
 - 파일 디스크립터는 0 이상의 정수값을 가지며 0은 표준 입력, 1은 표준 출력, 2는 표준 에러로 기본적으로 할당된다.
 - 따라서 프로세스에서 파일을 열거나 생성하면 3번부터 차례대로 할당받게 된다.
 > 참고: [get_next_line](https://80000coding.oopy.io/4d3eba5f-5d2d-4bec-b0a2-fa058d67c643#56d19da82b7847a89d0eca867a9a2484)
<br>
</details>

<details>
<summary><b>정적변수(static variable)</b></summary>

 - 정적변수는 전역변수처럼 프로그램이 시작될때 메모리에 생성되고 프로그램이 종료될때 소멸되는 변수이다.
 - 이때 초기값이 있으면 Data 영역에 생성되고 초기값이 없으면 BSS 영역에 생성되어 초기값으로 0이 들어간다고 한다.
 - 정적변수는 다시 정적 지역변수와 정적 전역변수로 나뉘는데 정적 지역변수는 함수의 중괄호 안에서만 사용할 수 있고 정적 전역변수는 해당 소스파일 내부에서만 사용할 수 있다.
 > 따라서 전역변수처럼 extern 키워드를 이용해 외부 파일에서 참조하는 것이 불가능하다.
 - 정적 변수는 초기화가 한번만 진행되므로 함수의 실행이 끝나고 다시 함수를 호출해도 기존에 가지고 있던 값을 그대로 가지고 있다.
 > 참고: [c언어 정적변수, 지역변수, 전역변수 비교 (static, local, global)](https://code4human.tistory.com/128)
 - 이번 과제에서는 위와 같은 정적변수의 특성을 이용해 포인터 변수를 정적변수로 선언하여 사용한다. 그런데 주의할 점이 있다.
 - 아래와 같이 포인터 변수에 동적으로 할당받은 메모리 주소를 대입하면 함수를 다시 호출했을 때 포인터 변수에 주소값이 남아있고 문자열을 출력한 결과도 동일하다.
 ```c
 #include <stdlib.h>
 #include <stdio.h>

 void test(void)
 {
	 static char *ptr;

	 if (!ptr)
	 {
		 ptr = (char *)malloc(sizeof(char) * 3);
		 ptr[0] = '4';
		 ptr[1] = '2';
		 ptr[2] = '\0';
	 }
	 printf("%p: %s\n", ptr, ptr);
 }

 void test2(void)
 {
	 char str[3] = "17";
 }

 int main(void)
 {
	 test();
	 test2();
	 test();
	 return (0);
 }
 ```
 > 실행 결과
 <img width="392" alt="get_next_line_1" src="https://user-images.githubusercontent.com/97381683/230557111-6f644c02-f04a-4498-8e19-cdf46159194e.png">
 
 그러나 아래와 같이 포인터 변수에 정적 배열의 주소를 대입하고 함수를 다시 호출하면 포인터 변수의 주소값은 그대로지만 문자열을 출력했을 때의 결과가 달라진 것을 확인할 수 있다.
 ```c
 #include <stdio.h>

 void test(void)
 {
	 char str[3];
	 static char *ptr;

	 if (!ptr)
	 {
		 ptr = str;
		 ptr[0] = '4';
		 ptr[1] = '2';
		 ptr[2] = '\0';
	 }
	 printf("%p: %s\n", ptr, ptr);
 }

 void test2(void)
 {
	 char str[3] = "17";
 }

 int main(void)
 {
	 test();
	 test2();
	 test();
	 return (0);
 }
 ```
 > 실행 결과
 <img width="348" alt="get_next_line_2" src="https://user-images.githubusercontent.com/97381683/230560023-06691abc-2f33-4881-b3cd-4e4c1970df7b.png">
 
 > <b>💡 포인터 변수는 정적변수로 선언했으므로 가지고 있는 주소가 유지되지만 스택 영역에 생성된 함수의 지역변수는 함수 실행이 끝나면 메모리가 반환된다.<br>따라서 다른 함수를 호출할 때 해당 주소에 다른 값이 덮어씌워질 수 있는 것이다.<br>반면 힙 영역에 동적으로 할당된 변수는 명시적으로 동적 할당을 해제해주지 않는 이상 수명이 유지되므로 주소값을 가지고 있으면 다시 접근할 수 있다.<br>따라서 포인터 변수를 정적변수로 선언할때는 배열이나 구조체를 동적으로 할당해야 한다.</b>
<br>
</details>

<details>
<summary><b>스택 영역 vs 힙 영역</b></summary>

 - 과제를 하면서 처음에는 버퍼를 정적 배열로 만들어 사용하였는데 동기에게 정적 배열을 사용하면 버퍼 크기가 커질때 에러가 발생할 수 있다는 말을 들었고 실제로 그런 것을 확인하였다.
 - 아래의 코드를 실행하면 컴파일은 되지만 segmentation fault가 발생했다.
 ```c
 #define ARR_SIZE 9000000

 int main(void)
 {
	 char arr[ARR_SIZE];

	 arr[0] = 0;
	 return (0);
 }
 ```
 > 실행 결과
 <img width="579" alt="get_next_line_3" src="https://user-images.githubusercontent.com/97381683/230561149-c442fe1b-8d95-4350-a9a9-e1de61ae5bd5.png">
 
 - 환경마다 다르겠지만 클러스터의 아이맥에서는 약 8000000을 넘어서면 에러가 발생했다.
 - 물론 동적 할당을 사용해도 버퍼 크기가 매우 커지면 에러가 발생했지만 정적 배열에 비해 상대적으로 매우 큰 크기까지 할당할 수 있었다.
 - 스택 영역에 할당할 수 있는 크기에 비해 힙 영역에 할당할 수 있는 크기가 더 큰 이유는 무엇일까?
 > <b>💡 가상 메모리에서의 총 스택 할당 크기는 기본값으로 지정되어 있으며 윈도우에서는 1MB, 리눅스에서는 8MB라고 한다.<br>기본값을 더 크게 하는것도 가능하지만 스택 크기가 커지면 그만큼 생성할 수 있는 스레드의 수가 줄어든다고 한다.<br>힙 공간도 가상 메모리에서의 초기 할당 크기가 정해져 있지만 그 이상의 공간이 필요하다면 가용한 물리적 메모리 크기 내에서 늘어난다고 한다.<br>따라서 배열 등 크기가 큰 객체는 힙 영역에 동적으로 할당하는 것이 좋을것 같다.</b>
<br>
</details>
