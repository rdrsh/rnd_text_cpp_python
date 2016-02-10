import re
import random

#~ text = file('warAndPeace.txt').read()
text = file('warAndPeace.truncated.txt').read()

regexp = re.compile(r'(\w)$\n\n', re.MULTILINE)
text = regexp.sub('\\1.\n\n', text)
text = re.sub(r'\s+', ' ', text)

matched = []
for match in re.finditer(r'(\w+)(\W+)', text):
    word, punctuation  = match.groups()
    matched.append((word, punctuation))

wordToId = {}
data = []
for i, (word, punctuation) in enumerate(matched):
    if not wordToId.has_key(word):
        id = len(wordToId)
        data.append([word, []])
        wordToId[word] = id

    try:
        nextWord = matched[i+1][0]
        id = wordToId[word]
        data[id][1].append((punctuation, nextWord))
    except:
        pass

for id, row in enumerate(data):
    #~ print id, row
    for i, (punctuation, nextWord) in enumerate(row[1]):
        nextId = wordToId[nextWord]
        data[id][1][i] = (punctuation, nextId)
        #~ print punctuation, nextWord


def printText(data):
    id = 0
    wordCount = 100
    for i in xrange(wordCount):
        word = data[id][0]
        (punctuation, nextId) =  random.choice(data[id][1])
        print word+punctuation,
        id = nextId

printText(data)

#~ print data
