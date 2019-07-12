# https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d
import re
print(max(re.findall('\d+', input()), key = len))