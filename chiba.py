import random

d = {'千葉':[['',''],['西',''],['東',''],['本',''],['新',''],['京成',''],['','中央'],['','公園'],['','寺'],['','みなと'],['','ニュータウン中央']]
    }
stem = random.choice(list(d.keys()))
p = random.choice(d[f])
print(f"{p*(f=='pre')}{d['stem']}{p*(f=='post')}")
