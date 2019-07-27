table = {'CLISP', 'RUBY', 'DART', 'JAVA', 'ERLANG', 'BASH', 'JAVASCRIPT', 'PASCAL', 'BRAINFUCK', 'CPP', 'SCALA', 'CSHARP', 'LUA', 'R', 'PYTHON', 'C', 'PHP', 'PERL', 'CLOJURE', 'OBJECTIVEC', 'D', 'OCAML', 'GO', 'GROOVY', 'HASKELL', 'SBCL'}

for i in range(int(input())):
    print("VALID") if input().split()[1] in table else print("INVALID")
