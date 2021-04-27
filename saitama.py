import random

d = {
  '浦和': {
    'pre': ['','西','東','北','南','中','武蔵',],
    'post': ['','美園',]},
  '大宮': {
    'pre': ['','西','東','北',],
    'post': ['','公園',]},
  '川越': {
    'pre': ['','西','本',],
    'post': ['','市',]},
}
fix = random.choice(('pre','post'))
stem = random.choice(list(d.keys()))
p = random.choice(d[stem][fix])
print(f"{p*(fix=='pre')}{stem}{p*(fix=='post')}")
