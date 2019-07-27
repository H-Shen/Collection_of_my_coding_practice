from HTMLParser import HTMLParser

def process(attrs):
    res = []
    for name,value in attrs:
        if value == None:
            res.append('-> ' + name + ' > ' + 'None')
        else:
            res.append('-> ' + name + ' > ' + value)
    return res

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print "Start :", tag

        if attrs != []:
            res = process(attrs)
            for i in res:
                print i

    def handle_endtag(self, tag):
        print "End   :", tag
    def handle_startendtag(self, tag, attrs):
        print "Empty :", tag

        if attrs != []:
            res = process(attrs)
            for i in res:
                print i

result = []

for i in xrange(input()):
	result.append(raw_input())

content = ''.join(result)
parser = MyHTMLParser()
parser.feed(content)
parser.close()

