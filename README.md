# cpp_python_wrapping

## NOTE
대상 파일을 ```.cpp``` 로 해야한다. 

---

```
python3 setup.py build
```

1. build 폴더안의 so 파일을 꺼내온다
2. 파이썬에서 import
(so 파일의 이름을 A.so 로 바꿨다 하고)
```
import A
B = A.PyA(0,0,5,5)
B.getArea()
25
```
