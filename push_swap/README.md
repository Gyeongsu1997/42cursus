![header](https://capsule-render.vercel.app/api?type=transparent&fontColor=703ee5&height=120&section=header&text=push_swap&fontSize=70)

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#what-i-have-learned">What i have learned</a>
</h3>

---

## About

스택 두 개를 사용하여 인자로 들어온 숫자들을 정렬하는 과제이다. 스택에 적용할 수 있는 연산은 아래와 같이 총 11개이다.

- sa (swap a): stack a의 상단 2개의 원소를 서로 바꾼다.
- sb (swap b): stack b의 상단 2개의 원소를 서로 바꾼다.
- ss: sa와 sb를 동시에 수행한다.
- pa (push a): stack b의 상단에 있는 원소를 꺼내어 stack a의 상단에 넣는다.
- pb (push b): stack a의 상단에 있는 원소를 꺼내어 stack b의 상단에 넣는다.
- ra (rotate a): stack a의 모든 원소를 한칸씩 위로 올린다. 연산 수행 후 가장 상단에 있던 원소가 가장 하단의 원소가 된다.
- rb (rotate b): stack b의 모든 원소를 한칸씩 위로 올린다. 연산 수행 후 가장 상단에 있던 원소가 가장 하단의 원소가 된다.
- rr: ra와 rb를 동시에 수행한다.
- rra (reverse rotate a): stack a의 모든 원소를 한칸씩 아래로 내린다. 연산 수행 후 가장 하단에 있던 원소가 가장 상단의 원소가 된다.
- rrb (reverse rotate b): stack b의 모든 원소를 한칸씩 아래로 내린다. 연산 수행 후 가장 하단에 있던 원소가 가장 상단의 원소가 된다.
- rrr: rra와 rrb를 동시에 수행한다.

위 명령어들을 최대한 적게 사용하여 정렬하는 것이 목표이다.

## Usage

1. ’make’ 또는 ‘make all’ 또는 ‘make push_swap’ 명령어를 입력하여 프로그램을 빌드한다.
2. 생성된 push_swap 파일을 실행하며 정렬할 수들을 프로그램 인수로 입력한다.
(입력한 수들은 stack a의 초기 상태를 의미하여 첫번째 인수가 stack a의 top에 해당한다. stack b는 처음에 비어있는 상태이다.)
3. 인자로 받은 수들을 정렬하기 위해 필요한 연산이 표준 출력으로 출력된다.

<img width="604" alt="push_swap_1" src="https://github.com/Gyeongsu1997/42cursus/assets/97381683/b64f61e0-e101-4d12-8e17-6e51b60091f3">
