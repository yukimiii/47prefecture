from PIL import Image, ImageDraw, ImageFont

im = Image.new("RGBA", (2000,2000), (255,255,255))
draw = ImageDraw.Draw(im)
w, h, off, c = 60, 1000, 600, (100,64,64)
g = 1067
draw.rectangle((h+-g//2, h, h+-g//2-w, 0),    fill=c, width=20)
draw.rectangle((h+g//2,  h, h+g//2+w,  0),    fill=c, width=20)
g = 1435
draw.rectangle((h+-g//2, h, h+-g//2-w, 2000), fill=c, width=20)
draw.rectangle((h+g//2,  h, h+g//2+w,  2000), fill=c, width=20)
f = ImageFont.truetype('Arial', 100)
draw.multiline_text((off, 500),  "< narrow gauge >",   fill=(0,0,0), font=f)
draw.multiline_text((off, 1500), "< standard gauge >", fill=(0,0,0), font=f)
im.show()
