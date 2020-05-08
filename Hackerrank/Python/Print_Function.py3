N = int(input())
string = ''
if N == 1:
    print(N)
else:
    for i in range(1,N + 1):
        string += str(i)
    print(int(string))
