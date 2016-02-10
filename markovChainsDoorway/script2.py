################################################################################
## config
################################################################################

fileName = 'warAndPeace.txt'
fileName = 'warAndPeace.truncated.txt'
fileName = 'GRRM.AStormofSwords.2.txt'

################################################################################
## imports
################################################################################

import sys, string, re, random, UserDict

################################################################################
## UIdDict
################################################################################

class UIdDict(UserDict.UserDict):
    id = 0

    def __getitem__(self, key):
        d = self.data
        if key not in d:
            d[key] = self.id
            self.id += 1
        return d[key]

################################################################################
## defs
################################################################################

def checkForEnd(p):
    return '.' in p or '!' in p or '?' in p

#~ for p in '.|,|!|!:|:'.split('|'):
    #~ print p, checkForEnd(p)

def dumpArr(a):
    for i, v in enumerate(a):
        print i, v

################################################################################
## start
################################################################################

text = file(fileName).read()

#~ regexp = re.compile(r'(\w)$\n\n', re.MULTILINE)
#~ text = regexp.sub('\\1.\n\n', text)
#~ text = re.sub(r'\s+', ' ', text)

matched = []
for match in re.finditer(r'''([\w'\-]+)([^\w'\-]+)''', text):
    word, punctuation = match.groups()
    matched.append((word, punctuation))

#~ if not checkForEnd(matched[-1][1]): # text last dot
    #~ matched[-1][1] = '.'

del text

################################################################################
## structure calculating
################################################################################

wordToId = {}
wordData = []
textData = []
startIds = []
endFlag = True

for i, (word, punctuation) in enumerate(matched):
    if not wordToId.has_key(word):
        wordToId[word] = len(wordData)

        nextTextIds = []
        for j, (word2, punctuation2) in enumerate(matched):
            if word == word2 and j+1 < len(matched):
                nextTextIds.append(j+1)

        wordData.append([word, nextTextIds])

    if endFlag:
        startIds.append(i)

    wordId = wordToId[word]
    punctuation = punctuation.strip()
    endFlag = checkForEnd(punctuation)
    textData.append((wordId, punctuation, endFlag))


#~ print wordToId
#~ dumpArr(wordData)
#~ dumpArr(textData)

del matched, wordToId

#~ sys.exit()

################################################################################
## render
################################################################################

def printOriginal(textData, wordData, startIds):
    for id, punctuation, endFlag in textData:
        print wordData[id][0]+punctuation,
        if endFlag:
            print

def printText(textData, wordData, startIds, wordCount, chainLen = 2):
    endFlag = True
    space = ''
    chainStep = random.randrange(chainLen)
    for i in xrange(wordCount):
        if endFlag:
            textId = random.choice(startIds)
            w = 'start'

        wordId, punctuation, endFlag = textData[textId]
        word, nextIds = wordData[wordId]
        if i == wordCount-1 and not checkForEnd(punctuation):
                punctuation = '.'
        print space+word+punctuation,
        #~ print space+w,
        space = ' '

        if (chainStep < chainLen-1 and textId < len(textData)-1):
            textId += 1
            w = 'next'
        elif not endFlag:
            textId = random.choice(nextIds)
            w = 'random'

        chainStep += 1
        if chainStep == chainLen:
            chainStep = 0


#~ printText(textData, wordData, startIds, 200, 5)
#~ printOriginal(textData, wordData, startIds)

################################################################################
## to cpp
################################################################################

def cppRepr(s):
    s = s.replace('\\', '\\\\')
    s = s.replace('"', '\\"')
    return '"'+s+'"'

def toCpp(textData, wordData, startIds):
    defsCode = '''
struct WordInfo {
    char* word;
    int nextIdsLen;
    int* nextIds;
};

struct TextInfo {
    WordInfo* wordInfo;
    char* punctuation;
    int endFlag;
};
'''.strip()

    nextIdsCode = ''
    wordInfoCode = ''
    textInfoCode = ''
    startIdsCode = ''

    for wordId, (word, nextIds) in enumerate(wordData):
        #~ print word, nextIds
        if (len(nextIds)):
            nextIdsCode += 'int nextIds%d[] = {%s};\n' % (wordId, string.join(map(str, nextIds), ', '))
            wordInfoCode += '    {%s, %d, nextIds%d},\n' % (cppRepr(word), len(nextIds), wordId)
        else:
            wordInfoCode += '    {%s, 0, 0},\n' % cppRepr(word)

    wordInfoCode = wordInfoCode[0:-2]
    wordInfoCode = 'WordInfo wordInfo[] = {\n'+wordInfoCode+'\n};\n'

    for id, (wordId, punctuation, endFlag) in enumerate(textData):
        textInfoCode += '    {wordInfo+%d, %s, %d},\n' % (wordId, cppRepr(punctuation), int(endFlag))

    textInfoCode = textInfoCode[0:-2]
    textInfoCode = 'TextInfo textInfo[] = {\n'+textInfoCode+'\n};\n'

    startIdsCode = string.join(map(str, startIds), ', ')
    startIdsCode = 'int startIds[] = {%s};\n' % startIdsCode

    print defsCode, '\n'
    print nextIdsCode
    print wordInfoCode
    print textInfoCode
    print startIdsCode

toCpp(textData, wordData, startIds)
