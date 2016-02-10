import random
import time
import rndText


#~ print dir(rndText)
#~ rndText.seed()
#~ rndText.printOriginal()
#~ rndText.printText(100)
#~ rndText.printText(1000, ['AAA', 'BBB', 'CCC'], isPunctuation=1, charCase=0, chainLen=3)
#~ rndText.renderText(1000, ['AAA', 'BBB', 'CCC'], isPunctuation=1, charCase=0, chainLen=3)

s = rndText.renderText(100)
#~ print len(s)
print s

#~ rndText.seed()
#~ rndText.printText(1000, ['AAA'])
#~ t1 = time.clock()
#~ for i in range(1):
    #~ print rndText.renderText(100)
    #~ rndText.printText(100)
#~ t2 = time.clock()
#~ print
#~ print t2-t1

