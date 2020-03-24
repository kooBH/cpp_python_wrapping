import ctypes
from numpy.ctypeslib import ndpointer


lib = ctypes.cdll.LoadLibrary('./build/libfoo.so')

class A(object):
    def __init__(self, val):
        lib.A_new.argtypes = [ctypes.c_int]
        lib.A_new.restype = ctypes.c_void_p

        #lib.A_Set.argtypes = [ndpointer(ctypes.c_double,flags="C_CONTIGUOUS") ]
        lib.A_Set.argtypes = [ctypes.c_void_p,ndpointer(ctypes.c_double,flags="C_CONTIGUOUS") ] 
        lib.A_Set.restype = ctypes.c_void_p

        lib.A_Op.argtypes = [ctypes.c_void_p]
        lib.A_Op.restype = ctypes.c_void_p

        lib.A_Get.argtypes = [ctypes.c_void_p,ndpointer(ctypes.c_double,flags="C_CONTIGUOUS") ] 
        lib.A_Get.restype = ctypes.c_void_p

        lib.A_Print.argtypes = [ctypes.c_void_p]
        lib.A_Print.restype = ctypes.c_void_p

        self.obj = lib.A_new(val)

    def Set(self,val):
        lib.A_Set(self.obj,val)
    
    def Op(self):
        lib.A_Op(self.obj)

    def Get(self,val):
        lib.A_Get(self.obj,val)
   
    def Print(self):
        lib.A_Print(self.obj)

    


