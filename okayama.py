import random

d = {
    '新幹線':[['のぞみ','東京','新神戸'],['みずほ','鹿児島中央','広島'],['さくら','鹿児島中央','福山'],['ひかり','東京','相生'],['こだま','博多','新倉敷'],],
    '山陽線':[['','姫路','西川原'],['','三原','北長瀬'],['快速サンライナー','福山','倉敷'],['特急いなば','鳥取','上郡'],['寝台特急サンライズ出雲・瀬戸','東京','姫路'],],
    '瀬戸大橋線':[['快速マリンライナー','高松',random.choice(['大元','妹尾','早島'])],['特急しおかぜ','松山','児島'],['特急南風','高知','児島'],['寝台特急サンライズ瀬戸','高松','児島'],['','児島','大元'],['快速','茶屋町','大元'],],
    '宇野みなと線':[['','宇野','大元'],],
    '伯備線':[['特急やくも','出雲市','倉敷'],['','新見','北長瀬'],['寝台特急サンライズ出雲','出雲市','倉敷'],],
    '赤穂線':[['','播州赤穂','西川原'],],
    '津山線':[['','津山','法界院'],['快速ことぶき','津山','法界院'],],
    '桃太郎線':[['','総社','備前三門'],],
    '岡山電気軌道':[['','東山','西川緑道公園'],['','清輝橋','西川緑道公園'],],
}
s = random.choice(list(d.keys()))
p = random.choice(d[s])
print(f"岡山から {s} {p[0]} {p[1]} 行きに乗った!  次は {p[2]} だ!")
