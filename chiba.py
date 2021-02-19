import random

d = {'pre': ['','西','東','本','新','京成',],
    'stem': '千葉',
    'post': ['','中央','公園','寺','みなと','ニュータウン中央',],}
f = random.choice(('pre','post'))
p = random.choice(d[f])
print(f"{p*(f=='pre')}{d['stem']}{p*(f=='post')}")
