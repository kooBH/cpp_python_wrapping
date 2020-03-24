from a import A
import numpy as np

if __name__ == '__main__': 
    f = A(5)
    f.Print()
    data = np.arange(25).reshape((5, 5)) 
    arr=np.array(data,dtype=np.float64)
    print(type(arr))
    f.Set(arr)
    f.Print()
    f.Op()
    f.Get(arr)
    print(arr)
