import requests, json

url = "http://api.geodosu.com/v2/geodosu2"
params = {"output":"json","address":input()}
res = requests.get(url,params=params)
data = json.loads(res.text)
print(json.dumps(data,ensure_ascii=False,indent=2))
