def Filter(s):
    result = list()
    for i in s:
        if i not in result:
            result.append(i)
    return ''.join(result)

def merge_the_tools(s, k):
    for j in range(0, len(s) // k):
        print(Filter(s[j * k : (j + 1) * k]))

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)