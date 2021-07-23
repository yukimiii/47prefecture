from PIL import Image, ImageDraw

im = Image.new("RGB", (2020,1896), (255,255,255))
draw = ImageDraw.Draw(im)
draw.ellipse((420, 620, 780, 980), outline=(0,0,220))
draw.ellipse((620, 820, 980, 1180), outline=(220,220,0))
draw.ellipse((820, 620, 1180, 980), outline=(0,0,0))
draw.ellipse((1020, 820, 1380, 1180), outline=(0,220,0))
draw.ellipse((1220, 620, 1580, 980), outline=(220,0,0))
draw.arc((720, 1300, 1120, 1700), start=140,end=270, fill=(220,0,0))
draw.arc((800, 1300, 1220, 1700), start=80,end=210, fill=(0,0,220))
draw.arc((840, 1240, 1240, 1640), start=20,end=150, fill=(0,220,0))
im.show()
