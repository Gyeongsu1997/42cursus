![header](https://capsule-render.vercel.app/api?type=transparent&fontColor=703ee5&height=120&section=header&text=Born2beRoot&fontSize=70)

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#whatihavelearned">What i have learned</a>
</h3>

---

## 📘 About
<b>가상화의 세계로</b>

가상 머신에 리눅스 운영체제를 설치하여 리눅스 커널 보안 모듈인 AppArmor, LVM을 이용한 파티션, SSH 서비스, 방화벽(UFW), 비밀번호 정책 및 sudo 정책 등을 설정하고 cron을 사용하여 주기적으로 쉘 스크립트를 실행하도록 설정하는 과제이다. 보너스 파트에서는 lighttpd, MariaDB, PHP를 사용하는 WordPress 웹사이트를 설치하고 기타 유용하다고 생각하는 서비스를 선택하여 설정하도록 요구하였다. 리눅스 서버를 설치하는 것이 처음이고 과제에서 요구하는 내용이 많아 오래 걸렸지만 가상 머신, 포트 포워딩 등의 용어를 새롭게 알게 되었고 SSH, 포트 등 익숙한 용어지만 정확히 모르고 사용하던 개념들을 정리할 수 있는 계기가 되었다.

## 💡 What i have learned

<details>
<summary><b>가상 머신(virtual machine)</b></summary>
 
 - 가상 머신은 CPU, RAM, 하드디스트 등의 컴퓨팅 환경을 소프트웨어로 구현한 가상의 컴퓨터를 의미한다.
 - 일반 컴퓨터에서처럼 가상 머신 위에서 운영체제나 응용 프로그램을 설치하고 실행할 수 있다.
 - Oracle VM VirtualBox는 가상 머신을 구현하는 가상화 소프트웨어이다.
 - 하나의 서버 컴퓨터에서 가상 머신을 여러 개 만들어 여러 서비스를 운영하면 하드웨어 자원을 최대한 활용할 수 있다고 한다.
 > 참고: [가상화 기술(전가상화, 반가상화, 호스트기반 가상화)쉽게 설명!](https://mamu2830.blogspot.com/2020/04/blog-post.html)
<br>
</details>

<details>
<summary><b>ISO image</b></summary>

 - 데비안(Debian) 공식 홈페이지에 들어가 운영체제를 설치하려고 하니 여러 이미지들 중 하나를 다운로드하라고 한다. 내가 알고 있던 이미지는 그림 파일 밖에 없어서 여기서 말하는 이미지가 무엇인지 혼동이 왔다. 찾아보니 ISO 이미지(ISO image)라고 한다.
 - ISO 이미지는 광학 디스크(CD, DVD, BD 등)에 포함된 모든 파일 데이터를 담고 있는 파일이라고 한다.
 - ISO 이미지를 이용하면 소프트웨어를 물리적인 매체를 이용하지 않고 네트워크를 통해 전송할 수 있으며 ISO 이미지를 다시 광학 디스크로 구울 수도 있다고 한다.
 - 본 과제에서는 debian installer를 ISO 이미지 파일로 다운로드해서 가상 머신에서 가상 디스크를 마운트하여 운영체제를 설치하였다.
 > 참고: [ISO 이미지](https://ko.wikipedia.org/wiki/ISO_%EC%9D%B4%EB%AF%B8%EC%A7%80)
<br>
</details>

<details>
<summary><b>SSH</b></summary>

 - SSH란 Secure Shell의 약자로 원격지 호스트 컴퓨터에 접속하기 위해 사용되는 인터넷 프로토콜이다.
 - 암호화로 인해 기존의 유닉스 시스템 셸에 원격 접속하기 위해 사용하던 Telnet보다 보안성이 좋다고 한다.
 - SSH Key는 공개키(public key)와 개인키(private key)의 쌍으로 이루어져 있으며 공개키를 서버에 복사하여 저장한 후 클라이언트에서 서버에 접속 요청을 하면 서버에 저장된 공개키와 클라이언트가 가지고 있는 개인키를 비교하여 서로 한 쌍의 key임이 확인되면 데이터를 주고 받을 수 있게 된다.
 > <b>💡 힙 영역은 메모리의 낮은 주소에서 높은 주소 방향으로 할당이 이루어지지만 스택 영역은 메모리의 높은 주소에서 낮은 주소 방향으로 할당이 이루어진다고 한다.</b>
 - 대표적인 예시로 깃허브 원격 저장소에 소스코드를 push할 때 또는 AWS 인스턴스 서버에 접속하여 해당 머신을 원격으로 제어할 때 SSH를 통한 연결을 한다.
<br>
</details>
