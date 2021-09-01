import sys, requests, json

address = input() if len(sys.argv)==1 else " ".join(sys.argv[1:])
url = "http://api.geodosu.com/v2/geodosu2"
params = {"output":"json","address":address}
res = requests.get(url,params=params)
data = json.loads(res.text)
print(json.dumps(data,ensure_ascii=False,indent=2))
