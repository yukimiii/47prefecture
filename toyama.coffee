# npm install coffeescript 

math = (x,y) -> Math.round Math.PI * x * x / y
sushi = "masu no sushi"
console.log "ramen + rice + #{sushi} #{math sushi.length,8}cm^2"
