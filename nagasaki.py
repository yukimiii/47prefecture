# pip install music21 pygame
"""
dona nobis pacem
author: traditional/unknown
"""

import music21

melo = [
""" tinynotation: 3/4
f8 c a2  g8 c b-2  a4 g f f e2  d'4 c'8 b- a g c'4. b-8 a4  a8 g f4 e f2.
c'2.     c'2.    c'4 b- a a g2  d'4 d'2        c'4 c'2    c'8 b- a4 g a2.
f2.      e  f4. g8 a b- c'4 c2  b-4 b-2        a4 a2       e8 g c'4 c f2.
""",
""" tinynotation: 3/4
f2.      e  f4. g8 a b- c'4 c2  b-4 b-2        a4 a2       e8 g c'4 c f2.
f8 c a2  g8 c b-2  a4 g f f e2  d'4 c'8 b- a g c'4. b-8 a4  a8 g f4 e f2.
c'2.     c'2.    c'4 b- a a g2  d'4 d'2        c'4 c'2    c'8 b- a4 g a2.
""",
""" tinynotation: 3/4
c'2.     c'2.    c'4 b- a a g2  d'4 d'2        c'4 c'2    c'8 b- a4 g a2.
f2.      e  f4. g8 a b- c'4 c2  b-4 b-2        a4 a2       e8 g c'4 c f2.
f8 c a2  g8 c b-2  a4 g f f e2  d'4 c'8 b- a g c'4. b-8 a4  a8 g f4 e f2.
""",
]

ins = [
        music21.instrument.Harp,
        music21.instrument.Viola,
        music21.instrument.Saxophone,
      ]
c = []
for m, p in zip(melo, ins):
    c.append(music21.converter.parse(m))
    c[-1].insert(p())

s = music21.stream.Score(c)
#s.show() # open in musescore etc.
sp = music21.midi.realtime.StreamPlayer(s)
sp.play()
