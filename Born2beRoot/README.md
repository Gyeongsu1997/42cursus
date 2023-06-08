![header](https://capsule-render.vercel.app/api?type=transparent&fontColor=703ee5&height=120&section=header&text=ft_printf&fontSize=70)

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#whatihavelearned">What i have learned</a>
</h3>

---

## 📘 About
<b>printf에 반환값이 있었다니..!</b>

표준 라이브러리 함수인 printf를 구현하는 과제이다. 가변 인자라는 새로운 개념이 등장한다. 이와 관련해 스택 영역 등 몰랐던 용어들을 새롭게 알게 되었고 컴퓨터 구조 등 CS 공부의 필요성을 느낀 과제였다.

## 💡 What i have learned

<details>
<summary><b>default argument promotion</b></summary>
 
 - 가변 인자에 대해 공부하며 가장 의문이었던 부분은 ‘default argument promotion’이라는 것이다.
 - stdarg에 대한 man page를 보면 va_arg에 대한 설명 중 아래와 같은 문장이 있다.
 > If there is no next argument, or if type is not compatible with the type of the actual next argument (<b>as promoted according to the default argument promotions</b>), random errors will occur.
 - 또한 examples에 ‘char is promoted to int.’라는 문장이 주석으로 달려있다.
 - 이 ‘default argument promotion’은 대체 무엇일까?
 - 이에 따르면 가변 인자로 들어온 int보다 작은 정수형(char, short 등)은 int형으로 변환되고 float형은 double형으로 변환된다고 한다.
 - 이것은 C 표준으로 정의되어 있으며 이 또한 지난번 Libft 과제에서 배운 K&R 방식과의 호환을 위한 것이라고 한다.
<br>
</details>

<details>
<summary><b>가변 인자 처리</b></summary>

 - 가변 인자를 처리하기 위해서는 stdarg.h 헤더파일을 include하고 헤더파일에 정의되어 있는 va_list 타입의 변수(이하 ap)를 선언한다.
 - va_list는 가변 인자의 주소를 담기 위한 포인터 변수 또는 포인터 변수를 포함하는 구조체로 정의되어 있다.
 - 이후 va_start 매크로로 ap를 가변 인자의 시작 주소로 초기화 해주어야 한다.
 - va_start 매크로는 void va_start(va_list ap, last)와 같은 프로토타입을 가지며 last에는 가변 인자가 오기 전 타입을 알고 있는 마지막 매개변수명을 넣어준다.
 - 이 last에 대해 man page에 아래와 같은 부연 설명이 적혀있다.
 > Because the address of this parameter is used in the va_start() macro, it should not be declared as a register variable, or as a function or an array type.
 - 처음에는 문자열도 array type이니 last에 넣으면 안되는것 아닌가 하고 생각했지만 문자열은 ‘\0’로 끝난다고 약속되어 있으니 문자열의 끝을 알 수 있으므로 사용할 수 있는것 같다.
 - ap를 초기화하면 va_arg 매크로를 통해 가변 인자를 하나씩 꺼내올 수 있다.
 - va_arg 매크로는 type va_arg(va_list ap, type)와 같은 프로토타입을 가지며 type에는 미리 알고 있는 가변 인자의 type을 넣어주어 해당 byte만큼의 데이터를 type 형으로 반환한다.
 - va_arg 매크로를 호출하면 ap가 변형되어 다음번에 호출할 때는 다음 가변 인자를 꺼내올 수 있다.
 - 가변 인자의 사용이 끝나면 va_end 매크로를 호출해 ap의 사용을 종료한다.
 - 매크로 사용 예시는 아래와 같다.
 ```c
 #include <stdarg.h>
 #include <unistd.h>

 int ft_printf(const char *fmt, ...)
 {
	 va_list ap;
	 char c;

	 va_start(ap, fmt);
	 while (*fmt)
	 {
		 if (*fmt == '%')
		 {
			 if (*(++fmt) == 'c')
			 {
				 c = va_arg(ap, int);
				 write(1, &c, 1);
			 }
			 ...
		 }
		 else
			 write(1, fmt, 1);
		 ...
		 fmt++;
	 }
	 va_end(ap);
	 ...
 }
 ```
<br>
</details>

<details>
<summary><b>스택 영역</b></summary>

 - 프로그램이 운영체제에 의해 할당받는 메모리 공간 중 스택 영역은 함수의 매개변수와 지역 변수가 저장되는 공간이다.
 - 가변 인자 또한 함수의 매개변수로서 이 스택 영역에 위치한다.
 - 스택 영역과 자주 비교되는 힙 영역은 동적으로 할당 된 변수가 위치하는 공간이다.
 > <b>💡 힙 영역은 메모리의 낮은 주소에서 높은 주소 방향으로 할당이 이루어지지만 스택 영역은 메모리의 높은 주소에서 낮은 주소 방향으로 할당이 이루어진다고 한다.</b>
 - 새롭게 안 사실이었고 이를 확인하기 위해 스택 영역에 위치한 변수들의 주소를 출력해 본 결과 실제로 높은 메모리 주소부터 할당이 되는 것을 확인하였다.
 - 다만 배열의 경우에는 다른 변수들 보다 스택 영역에서 높은 주소에 위치하고 배열의 각 원소들은 인덱스가 작을수록 낮은 주소에 채워지도록 저장되는것 같다.
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
