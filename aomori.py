import requests

url = "http://61.199.163.163/kikakuchousei/opendata/documents/16-kokuseicyousa-h22jinko-setai.csv"


response = requests.get(url)

data = response.content.decode("utf-8")

print(data)
