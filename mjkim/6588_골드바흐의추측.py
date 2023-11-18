from sys import stdin
input = stdin.readline

def get_primes_yn(max_n):
    arr = [True for i in range(max_n)]
    arr[0] = arr[1] = False
    for i in range(2, max_n):
        if not arr[i]: continue
        for j in range(i ** 2, max_n, i):
            arr[j] = False
    return arr
    

def find_answer(n, primes_yn):
    for i in range(3, n, 2):
        if primes_yn[i] and primes_yn[n - i]:
            return "{0} = {1} + {2}".format(n, i, n - i)

    return "Goldbach's conjecture is wrong."

primes_yn = get_primes_yn(1000000)

n = int(input())
while n > 0:
    print(find_answer(n, primes_yn))
    n = int(input())
