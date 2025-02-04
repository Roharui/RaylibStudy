# Cmake 보일러 플레이트

> Windows + MSYS2로 개발되었으므로 참고 바랍니다.

Cmake 설정을 하기 귀찮으신 분들을 위한 보일러 플레이트입니다.

## 환경 세팅

> [여기](https://chocolatey.org/install)서 choco를 먼저 설치해주세요.

```
choco install msys2
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-gtest
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-ninja
```

다음 명령어를 순서대로 입력합니다.

## 시작하기 전에

./CMakeLists.txt의 주석을 확인해주세요
