# **Minishell**

## ✅ **Parse**
### **Order**
***check quote → divide tokens(with pipe) → divide token (with space) → replace $ variables → delete quote***
- `‘ “`를 검사하면서 `pipe` 단위로 `while`문을 돌면서 tokens를 나누어 준다.
    - 1-1 `‘ “`를 발견할 때마다 짝수 인지 홀수 인지 flag를 걸어 준다.
    - 1-2 `pipe`를 만났을 때 flag가 홀수 이면 그 `pipe`는 넘어간다.
    - 1-3 들어온 문자열이 끝났을 때 flag가 홀수 이면 프롬프트 재시작.
- `‘ “`를 검사하면서 `space`와 `< > << >>`를 기준으로 token을 나눈다.
    - 2-1 `‘ “`를 발견할 때마다 짝수 인지 홀수 인지 flag를 걸어 준다.
    - 2-2 `space` 와 `< > << >>` 를 만났을 때 flag가 홀수 이면 넘어간다.
        - 2-2-1 들어온 문자열이 끝났을 때 flag가 홀수 이면 프롬프트 재시작.
    - 2-3 `< > << >>` 무조건 하나의 `token`에 들어간다
- 나눈 token들 I/O redirection 검사
    - 3-1 `‘ “` flag 검사하면서 redirection flag 추가.
- 토큰을 나눈 후 `$`로 시작하는 문자열을 **환경변수 목록과 비교하여 교체**
    - 4-1 `‘` 홀수이면 치환X `“` 홀수 이면 치환
    - 4-2 환경변수 이름이 잘못되면 치환X
    - 4-3 환경변수 이름이 숫자로 시작하면 $와 함께 숫자 삭제
- 치환한 token들 `‘ “` 빼주기.
    - 5-1 redirection들은 무조건 분리가 되어있기 때문에 앞글자만 확인하면 된다.
### $ name rules

- a to z, A to Z, 0 to 9 with ‘_’
- Can not start 0~9.

## ✅ **Execute**

### **<< Here_doc**

- tokens 다 돌면서 `<<` 찾기
    - 1-1 `<<` 찾으면 limiter 이름 + idx로 파일 생성하고 넣어주기
    - 1-2 limiter 나올 때까지 넣어주고 `<<` → `<`으로 그리고 limiter → 파일 이름으로 바꿔주기.
- 명령어들 실행 끝날 때 파일 이름 모아뒀다가 `unlink`.

### **Order**

***check pipe_num → one process or pipex → if (one) check builtin or not → else (pipex) exec pipex and check redir***

## **해야할 일**
1. here_doc limiter 고치기.
2. here_doc 중간 시그널 나오면 명령어 실행X -> NULL 값 반환 등으로 확인.
3. cat 실행 시 시그널 받고 자식에서는 prompt 출력 X
4. 시그널 전체적으로 고치기.
5. 환경변수 확장 후 토큰 나누기.
6. unset PATH -> 명령어 실행 후 $? 시, 127 나와야함.
7. 임의의 디렉토리 만들고 이동한 뒤, 삭제하면 seg error 떠선 안됨.
예시(안걸리면 장땡)  
minishell:0.9$ cd 1  
minishell:0.9$ ls  
minishell:0.9$ rm -r ../1  
minishell:0.9$ cd  
[1]    53600 segmentation fault  ./minishell  
8. <<a | <<b  

>a  
>b  
error message가 뜨면 안됨. 또 echo $?시 0 나와야함(적당 작동임)  
9. To check memory leaks
