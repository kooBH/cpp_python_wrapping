from a import A
import numpy as np

f = A(5)
f.Print()
data = [1,2,3,4,5]
arr=np.array(data,dtype=np.float64)
print(type(arr))
f.Set(arr)
f.Print()
f.Op()
f.Get(arr)
print(arr)
