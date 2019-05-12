from random import *
from faker import Faker
import time
import datetime


# some set up
def encrypt(string, length, count):
    return [int(x) for x in ' '.join(string[i:i+length] for i in range(0, len(string), length)).split(' ')][:count]


uid = encrypt('130171258299362364448460675736750757814890965', 3, 15)
qid = encrypt('1004103210351047125513981598160716601713194020772089221222202245235024742508252026222653268927622970304430463286343634683480351335813593368237483890394640334051413242684361438943924446451745934779480348814903508152255248528453405467552055465649571757505838591261796221626564256465646765006641664866996783683968507244726172727302732873727451748875397634790581078115821284088617893691189435985098579983',4, 50)
aid = encrypt('11196120371229713494135391361114126144071479915129156051565115765157771591518263193762004822005226112290924143247882484825438270872808428318284053216333046343613533437766389354063541223418094357944312445284541546166466524777548926490394914049819503755059751928520985279854879561415670457729587465954760611608146219263589666856716067306685697032470589707197137671600727457325475463757827780578463798018007181018812068127982350825878453585188855308907689187895068987790824918229362795592956109783399620', 5, 75)
cid = encrypt('100149105069109189128766134550138671150134153644157032157405162054173357174802176300177439183390191249202502213104224379228683238138238321242337252912287325303696324011327601330423330500333832348771361097371119377432382940396771399846402821411722418641438645451070468343483484504815505442505914514983518950539376545020545502545689552778582116586204590921590971599503608580624740633259652380684630691816709152723554742967779949787632793384805577809205813406820561828759831060834839835202837382851141855745856808863108878954890127904131919163929302939094952653959221960802964573976455981876996495997488', 6, 100)
# END

# making up sentences
nouns = ("programmer", "coder", "ide", "girl", "monkey")
verbs = ("crashes", "loops", "skips", "wont run", "lags") 
adv = ("crazily.", "dutifully.", "foolishly.", "merrily.", "occasionally.")
adj = ("python", "java", "html", "c++", "php")
l = [nouns, verbs, adj, adv]
#
first = ('one', 'another', 'some')
second = ('question', 'problem', 'issue')
witH = ('with',)
third = ('python', 'c++', 'c', 'java', 'css', 'html')
questions = [first, second, witH, third]
#
good = ("solution", "fix", "useful", "idea")
foR = ("for",)
bad = ("bad", "not useful", "horrible")
comments = [first, bad, good, second, third]  
answers = [first, good, foR, third]
# END


def random_date():
        fake = Faker()
        return str(fake.date_time_this_century(before_now=True, after_now=False, tzinfo=None)) + "." + str(choice(uid))   
        

def generateQuestions():
    for i in range(50):
        print("({}, '{}', '{}', '{}', {}, {}),".format(qid[i], ' '.join([choice(i) for i in questions]), ' '.join([choice(i) for i in l]), random_date() ,choice(uid), str(choice([1,2,3]))))


def generateAnswers():
    for i in range(75):
        print("({}, '{}', '{}', {}, {}),".format(aid[i], ' '.join([choice(i) for i in answers]), random_date(), choice(uid), choice(qid)))


def generateComments():
    for i in range(100):
        print("({}, '{}', '{}', {}, {}),".format(str(randint(100000, 999999)), ' '.join([choice(i) for i in comments]), random_date(), choice(aid), choice(uid)))

generateQuestions()