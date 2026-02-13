# GIVEN DATA
p = 4000.0        # 4 kN converted to N
l = 10.0          # m
E = 200e9         # Pa
A0 = 300e-6       # m^2
n_members = 9

sqrt2 = 1.414213562

# Member lengths
L = [
    l,
    l,
    l,
    sqrt2*l,
    l,
    sqrt2*l,
    sqrt2*l,
    l,
    l
]

# Virtual forces
n = [
    1/3,
    2/3,
    2/3,
    -2*sqrt2/3,
    -1/3,
    -sqrt2/3,
    -sqrt2/3,
    1,
    1/3
]

# Real forces
N = [
    p,
    p,
    p,
    -sqrt2*p,
    -p,
    -sqrt2*p,
    0,
    p,
    p
]

# DEFLECTION FUNCTION
def deflection(A):
    total = 0.0
    for i in range(n_members):
        total += (n[i] * N[i] * L[i]) / (A[i] * E)
    return total


# INITIAL SETUP
A = [A0] * n_members
lower = 0.95 * A0
upper = 1.05 * A0

# Total volume
V0 = 0.0
for i in range(n_members):
    V0 += A0 * L[i]

best_def = deflection(A)


step = 0.01 * A0

for i in range(n_members):
    for j in range(n_members):
        if i != j:

            A_new = A.copy()
            A_new[i] += step
            A_new[j] -= step * (L[i] / L[j])

            # Check bounds
            valid = True
            for k in range(n_members):
                if A_new[k] < lower or A_new[k] > upper:
                    valid = False
                    break

            # Check volume
            volume = 0.0
            for k in range(n_members):
                volume += A_new[k] * L[k]

            if valid and abs(volume - V0) < 1e-10:
                new_def = deflection(A_new)
                if new_def < best_def:
                    A = A_new
                    best_def = new_def


# RESULTS
print("Optimized Areas (mm^2):")
for i in range(n_members):
    print("Member", i+1, ":", A[i]*1e6)

print("\nMinimum Deflection at C (mm):")
print(best_def * 1000)



"""
FINAL OUTPUT for p = 4 :-

Optimized Areas (mm^2):
Member 1 : 285.5147186279999
Member 2 : 301.757359314
Member 3 : 300.51471862799997
Member 4 : 312.00000000000006
Member 5 : 288.5147186279999
Member 6 : 312.00000000000006
Member 7 : 286.3933982794035
Member 8 : 312.00000000000006
Member 9 : 296.99999999999994

Minimum Deflection at C (mm):
4.028691095980477

"""