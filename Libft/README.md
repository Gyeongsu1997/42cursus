![header](https://capsule-render.vercel.app/api?type=transparent&fontColor=703ee5&height=120&section=header&text=Libft&fontSize=70)

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#what-i-have-learned">What i have learned</a>
</h3>

---

## About
<b>나만의 라이브러리 만들기</b>

몇 개의 C 표준 라이브러리 함수들과 같은 프로토타입을 가지고 같은 동작을 하는 함수들을 구현하고 표준 라이브러리에 없는 함수나 라이브러리 함수와 다르게 동작하도록 스펙이 주어진 함수들을 구현하는 과제이다. 직접 구현한 함수들로 만든 라이브러리는 이후의 과제에서 사용된다고 한다.

## What i have learned

<details>
<summary><b>함수의 반환형 앞에 static 키워드를 붙이는 이유</b></summary>
 
 - 반환형 앞에 static 키워드를 붙이면 그 함수는 정적 함수가 되어 해당 소스파일 내부에서만 사용 가능한 함수가 된다.
 - 프로젝트를 여러명의 개발자가 나누어 개발하는 경우, 각자 작성한 소스파일에서 함수 이름이 중복되는 경우를 피하기 위해서 사용한다.
 - 함수 이름이 중복되는 경우 목적 파일을 만드는 것에는 문제가 없지만 만들어진 목적파일들을 링크하는 과정에서 오류가 발생한다.
<br>
</details>

<details>
<summary><b>포인터 변수에서 const 키워드의 위치에 따른 의미 차이</b></summary>

 - 변수 앞에 const 키워드를 붙이면 해당 변수는 상수로 취급한다.
 - 즉, 변수 선언시에만 초기값을 할당할 수 있고 그 후에는 값을 변경할 수 없게 된다. 
 - 이러한 const 키워드를 포인터 변수 앞에 붙일 때는 아래와 같이 그 위치에 따라 의미가 조금 다르다.
 ```c
 char c1 = 'a';
 char c2 = 'b';

 const char *p1 = &c1; //const char *는 char const *와 같은 의미이다.
 char *const p2 = &c1;
 const char *const p3 = &c1;

 p1 = &c2; //정상적으로 컴파일
 *p1 = 'c'; //컴파일 에러

 *p2 = 'c'; //정상적으로 컴파일
 p2 = &c2; //컴파일 에러

 p3 = &c2; //컴파일 에러
 *p3 = 'c'; //컴파일 에러
 ```
<br>
</details>

<details>
<summary><b>표준 라이브러리 함수에서 반환형이나 매개변수로 size_t 타입을 사용하는 이유</b></summary>

 - size_t는 부호없는 정수 자료형으로 32비트 운영체제에서는 4바이트, 64비트 운영체제에서는 8바이트의 크기를 갖는다.
 - 하지만 unsigned int는 운영체제가 32비트이던 64비트이던 4바이트의 크기를 갖는다.
 - 따라서 운영체제에 따라 가능한 가장 큰 범위의 부호없는 정수형을 사용하고 싶을 때는 size_t를 사용한다.
 > 참고: [데이터 형식 범위](https://learn.microsoft.com/ko-kr/cpp/cpp/data-type-ranges?view=msvc-170)
<br>
</details>

<details>
<summary><b>memset 함수에서 int형 매개변수를 받아 unsigned char로 형변환해서 사용하는 이유</b></summary>

 - C99 표준 이전인 K&R 방식에서는 함수를 정의할 때 리턴타입이나 매개변수의 타입을 명시하지 않고 모두 int로 인식하는 ‘implicit int rule’이 적용되었다.
 - 또한 int로 받은 매개변수를 다른 타입으로 변환하고 싶으면 함수의 중괄호 밖에서 자료형을 명시해 주었다.
 - 결론적으로 이 시절의 관습이 남아있는 함수라서 그렇다.
 > 참고: [80년대 C언어는 어땠을까?](https://80000coding.oopy.io/31f3b397-1483-4a75-9d88-c99284e7f3ca)
<br>
</details>
