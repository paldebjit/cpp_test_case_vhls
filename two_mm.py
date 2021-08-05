import heterocl as hcl
import os

def top_2mm(P=16, Q=22, R=18, S=24, alpha=0.1, beta=0.1, dtype=hcl.Int(), target=None):

    hcl.init(dtype)
    A = hcl.placeholder((P, Q), "A")
    B = hcl.placeholder((Q, R), "B")
    C = hcl.placeholder((R, S), "C")
    D = hcl.placeholder((P, S), "D")

    def kernel_2mm(A, B, C, D):
        
        r = hcl.reduce_axis(0, Q, "r")
        out_AB = hcl.compute((P, R), 
                         lambda x, y: hcl.sum(A[x, r] * B[r, y], 
                         axis=r, 
                         dtype=dtype
                         ), 
                         name="out_AB"
                         )

        k = hcl.reduce_axis(0, R, "k")
        out_ABC = hcl.compute((P, S), 
                         lambda x, y: hcl.sum(out_AB[x, k] * C[k, y], 
                         axis=k, 
                         dtype=dtype
                         ), 
                         name="out_ABC"
                         )
        hcl.update(D,
                   lambda x, y: (alpha * out_ABC[x, y] + beta * D[x, y]),
                   name="D"
                   )
        
    s = hcl.create_schedule([A, B, C, D], kernel_2mm)
    hcl.lower(s)
    return hcl.build(s, target=target)

f1 = top_2mm(target="vhls", dtype=hcl.Int(15))
f = open("2mm_Int.cc", "w")
f.write(f1)
f.close()

f1 = top_2mm(target="vhls", dtype=hcl.UInt(24))
f = open("2mm_UInt.cc", "w")
f.write(f1)
f.close()

f1 = top_2mm(target="vhls", dtype=hcl.Fixed(13, 5))
f = open("2mm_Fixed.cc", "w")
f.write(f1)
f.close()

f1 = top_2mm(target="vhls", dtype=hcl.UFixed(44, 30))
f = open("2mm_UFixed.cc", "w")
f.write(f1)
f.close()

f1 = top_2mm(target="vhls", dtype=hcl.Float(32))
f = open("2mm_Float_1.cc", "w")
f.write(f1)
f.close()

f1 = top_2mm(target="vhls", dtype=hcl.Float(64))
f = open("2mm_Float_2.cc", "w")
f.write(f1)
f.close()
