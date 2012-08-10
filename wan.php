<?php
for ($i = 1; $i < 10000; $i++){
	$str .= $i;	
}
$len = strlen($str);
for($i = 0; $i < $len; $i= $i+100){
	var_dump(substr($str, $i, 100));
}
$start = 1;
$s = 3;
$end = 1000;
$s_len = strlen($start);
$e_lent = strlen($end);
$number = 0;
for ($i = 1; $i < 5; $i++){
	var_dump('________');
	echo "<br/>";
	for ($j = 1; $j < 5; $j++){
		if ($j >=  $i){
			$diff = ($j - $i);
			if($diff == 0){
				$diff2 = $j - 1;
				$tmp = pow(10, $diff2);
			}else{
				$pow = pow(10 , $j - 1) ;
				$a = ceil($pow);
				$pow2 = pow(10 , $j - 2) ;
				$b = ceil($pow2);
				$tmp = $a - $b;
			}
			echo "<br/>";
			$number += $tmp;
		}
	}
}
var_dump(($number));
//$exp = explode('3', $str);
//var_dump(($str));
die;
