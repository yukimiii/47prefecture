// node -v == 11.x
// npm install timbre

var T = require("timbre");
var arrive = "[l8 >a-<ce-a-<ce-dc >>b-<dfb-<dfed >ceg<cegfe <c>gfefg<c>b>]";
var depart = "[l8 >d<d>g<g>a<ad<d r>d0<ddged>ba gedr l32>gab<degab<deg2r4>]";
var gen = T("OscGen", {wave:"sin", env:{type:"adsr", d:100}, mul:0.25}).play();
T("mml", {mml:arrive+"r1"+depart+"r1"}, gen).on("ended", function() {
	gen.pause();
	this.stop();
}).start();
