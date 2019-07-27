n = input()
l = list()
for i in range(int(n)):
    s = input().split()

    command = s[0]
    argument = s[1:]

    if command !="print":
        command += "("+ ",".join(argument) +")"
        eval("l." + command)
    else:
        print(l)
