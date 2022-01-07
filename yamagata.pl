sub mount { my ($b,$r) = @_; for (; $b > 0; $b >>= 1) { $r .= substr " $s",$b&1,1 } return $r."\n" }
sub shape { return @_[0]." ". $s x 2 ."\n"; }
$s = "*";
print mount 4;
print mount 21;
print mount 31;
print "\n";
print shape "--";
print shape "++";
print shape "/|";
