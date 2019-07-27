def split_and_join(a):
    return "-".join(a.split())

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)