import sys

n = int(input())


def query(x) :
    print(x)
    sys.stdout.flush()
    return input()


    l = 1
    r = n + 1
    while l < r:
mid = l + (r - l) // 2
if query(mid) == "<" :
    r = mid
else :
    l = mid + 1
    print(f"! {l - 1}")
