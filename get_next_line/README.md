# get_next_line

파일 디스크립터(file descriptor)로부터 한 줄을 읽어들여 반환하는 함수를 구현하는 과제이다. 정적 변수라는 개념이 등장한다. 동적으로 할당한 메모리 관리의 어려움과 중요성을 느낄 수 있는 과제였다.

## 💡 공부한 것들

<details>
<summary><b>file descriptor</b></summary>
 
 - 리눅스에서의 파일  디스크립터는 프로세스에서 열린 파일의 목록을 관리하는 테이블의 인덱스로 파일 디스크립터를 이용해 해당 파일의 주소를 참조하여 접근할 수 있다.
 - 파일 디스크립터는 0 이상의 정수값을 가지며 0은 표준 입력, 1은 표준 출력, 2는 표준 에러로 기본적으로 할당된다. 따라서 프로세스에서 파일을 열면 3번부터 차례대로 할당받게 된다.
 - 참고: [get_next_line](https://80000coding.oopy.io/4d3eba5f-5d2d-4bec-b0a2-fa058d67c643#56d19da82b7847a89d0eca867a9a2484)
<br>
</details>

<details>
<summary><b>정적변수(static variable)</b></summary>

 - 정적변수는 전역변수처럼 프로그램이 시작될때 메모리에 생성되고 프로그램이 종료될때 소멸되는 변수이다. 이때 초기값이 있으면 Data 영역에 생성되고 초기값이 없으면 BSS 영역에 생성되어 초기값으로 0이 들어간다고 한다.
 - 정적변수는 다시 정적 지역변수와 정적 전역변수로 나뉘는데 정적 지역변수는 함수의 중괄호 안에서만 사용할 수 있고 정적 전역변수는 해당 소스파일 내부에서만 사용할 수 있다. 따라서 전역변수처럼 extern 키워드를 이용해 외부 파일에서 참조하는 것이 불가능하다.
 - 정적 변수는 초기화가 한번만 진행되므로 함수의 실행이 끝나고 다시 함수를 호출해도 기존에 가지고 있던 값을 그대로 가지고 있다.
 - 참고: [c언어 정적변수, 지역변수, 전역변수 비교 (static, local, global)](https://code4human.tistory.com/128)
 - 이번 과제에서는 위와 같은 정적변수의 특성을 이용해 포인터 변수를 정적변수로 선언하여 사용한다. 그런데 주의할 점이 있다. 아래와 같이 포인터 변수에 동적으로 할당받은 메모리 주소를 대입하면 함수를 다시 호출했을 때 포인터 변수에 주소값이 남아있고 문자열을 출력한 결과도 동일하다.
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
 - 그러나 아래와 같이 포인터 변수에 정적 배열의 주소를 대입하고 함수를 다시 호출하면 포인터 변수의 주소값은 그대로지만 문자열을 출력했을 때의 결과가 달라진 것을 확인할 수 있다.
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
 
<br>
</details>

<details>
<summary><b>스택 영역</b></summary>

 - 프로그램이 운영체제에 의해 할당받는 메모리 공간 중 스택 영역은 함수의 매개변수와 지역 변수가 저장되는 공간이다. 가변 인자 또한 함수의 매개변수로서 이 스택 영역에 위치한다.
 - 스택 영역과 자주 비교되는 힙 영역은 동적으로 할당 된 변수가 위치하는 공간이다. 힙 영역은 메모리의 낮은 주소에서 높은 주소 방향으로 할당이 이루어지지만 스택 영역은 메모리의 높은 주소에서 낮은 주소 방향으로 할당이 이루어진다고 한다.
 - 새롭게 안 사실이었고 이를 확인하기 위해 스택 영역에 위치한 변수들의 주소를 출력해 본 결과 실제로 높은 메모리 주소부터 할당이 되는 것을 확인하였다. 다만 배열의 경우에는 다른 변수들 보다 스택 영역에서 높은 주소에 위치하고 배열의 각 원소들은 인덱스가 작을수록 낮은 주소에 채워지도록 저장되는것 같다.
 ```c
 #include <stdio.h>

 void test(int n1)
 {
	 int n2;
	 int arr[3];
	 int n3;

	 printf("address of arr[2]: %p\n", &arr[2]);
	 printf("address of arr[1]: %p\n", &arr[1]);
	 printf("address of arr[0]: %p\n", &arr[0]);
	 printf("address of n1: %p\n", &n1);
	 printf("address of n2: %p\n", &n2);
	 printf("address of n3: %p\n", &n3);
 }

 int main(void)
 {
	 test(0);
	 return (0);
 }
 ```
 > 실행 결과
 <img width="491" alt="ft_printf_1" src="https://user-images.githubusercontent.com/97381683/230554949-1e791700-e572-4a13-b1d8-9f6b43f5d7fd.png">

<br>
</details>
