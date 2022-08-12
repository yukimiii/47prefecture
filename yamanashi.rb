mount = [
"　　　　　＿＿　　　　　",
"　　　　／　　＼　　　　",
"　　　／　　　　＼　　　",
"　　／　　　　　　＼　　",
"　／　　　　　　　　＼　",
"／　　　　　　　　　　＼",
]
cloud = [
"　　　　",
"　　　　",
"　　雲雲",
"雲雲雲雲",
"雲雲　　",
"　　　　",
].map!{|s| s*3}

"42".reverse.to_i.times{
  print "\e[H\e[J"
  puts mount.zip(cloud).map{|m,c|
    m.chars.zip(c.chars).map{|m,c|
      c == "　" ? m : c
    }.join
  }
  cloud.map!{|s| s[1..-1]+s[0]}
  sleep 0.243
}
