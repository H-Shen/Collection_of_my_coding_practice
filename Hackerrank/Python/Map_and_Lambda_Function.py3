fib = lambda n:1 if n<=2 else fib(n-1) + fib(n-2)
N = int(input())
if N == 1:
    print([0])
elif N == 0:
    print([])
else:
    print([0] + [pow(fib(i), 3) for i in range(1,N)])