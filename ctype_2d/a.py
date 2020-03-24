import ctypes
from numpy.ctypeslib import ndpointer
import numpy as np


#lib = ctypes.cdll.LoadLibrary('./build/libfoo.so')
lib = ctypes.cdll.LoadLibrary('./build/Release/foo.dll')
print(dir(lib))
_doublepp = ndpointer(dtype=np.uintp, ndim=1, flags='C')

class A(object):
    def __init__(self, val):
        lib.A_new.argtypes = [ctypes.c_int]
        lib.A_new.restype = ctypes.c_void_p

        lib.A_Set.argtypes = [ctypes.c_void_p,_doublepp ] 
        lib.A_Set.restype = ctypes.c_void_p

        lib.A_Op.argtypes = [ctypes.c_void_p]
        lib.A_Op.restype = ctypes.c_void_p

        lib.A_Get.argtypes = [ctypes.c_void_p,_doublepp] 
        lib.A_Get.restype = ctypes.c_void_p

        lib.A_Print.argtypes = [ctypes.c_void_p]
        lib.A_Print.restype = ctypes.c_void_p

        self.obj = lib.A_new(val)

    def Set(self,x):
        xpp = (x.__array_interface__['data'][0] + np.arange(x.shape[0])*x.strides[0]).astype(np.uintp) 
        lib.A_Set(self.obj,xpp)
    
    def Op(self):
        lib.A_Op(self.obj)

    def Get(self,x):
        xpp = (x.__array_interface__['data'][0] + np.arange(x.shape[0])*x.strides[0]).astype(np.uintp) 
        lib.A_Get(self.obj,xpp)
   
    def Print(self):
        lib.A_Print(self.obj)

    


