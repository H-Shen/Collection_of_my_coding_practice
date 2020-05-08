for _ in range(int(input())):
    s = input()
    while ' && ' in s:
        s = s.replace(' && ', ' and ')
    while ' || ' in s:
        s = s.replace(' || ', ' or ')
    print(s)
