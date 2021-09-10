import Foundation
let adj=[["Niigata",String("TOKYO enil amayiI".reversed())],["Gunma","Hokuriku"+"_via_Nagano"+" Shinkansen"],["Saitama","Mikuni-toge pass"],["Yamanashi","HIGH RAIL "+"Koumi line"],["Shizuoka","Iida line"],["Aichi","National road 153"],["Gifu","Chuo line"],["Toyama","Kanden trolley bus".replacingOccurrences(of:"trolley", with:"electric")]]
let d=adj.randomElement()!
print("Hello, Nagano")
print("you can go to \(d[0]) prefecture by \(d[1])")
