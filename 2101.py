#!/usr/bin/env python
from fractions import gcd

def __lcm(a, b):
    res = (a*b)/gcd(a,b)
    return res % mod

while True:
    a, b = map(int, raw_input().split())
    if a == 0 and b == 0:
        break
    print __lcm(a, b)
