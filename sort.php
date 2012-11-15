<?php
$str = "";

for ($i = 1;$i < 1000 ; $i++){
	$str[] = $i;
}

function tow($str, $number){
	$end = count($str) - 1;
	$start = 0;
	$count = 0;
	while ($start <= $end){
		$count++;
		$now = floor(($start + $end)/2);
		if ($str[$now] > $number){
			$end = $end - 1;
		}elseif ($str[$now] < $number){
			$start = $now + 1;
		}else{
			return $count;
		}
	}
	return false;
}
for ($i = 1;$i < 1000 ; $i++){
	var_dump(tow($str, $i));
}


$str = "";
for ($i = 1;$i < 30 ; $i++){
	$number = mt_rand(1, 10000000);
	$str[] = $number;
}
function bubble($str){
	for($i = 0 , $len = count($str); $i <= $len; $i ++){
		for ($j = $len - 1; $j > $i ; $j--){
			if ($str[$j] > $str[$j-1]){
				$tmp = $str[$j-1];
				$str[$j-1] = $str[$j];
				$str[$j] = $tmp;
				
			}
		}
	}
	return $str;
}
var_dump(bubble($str));



