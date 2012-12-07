<?php
function factorial_a($n) {
    if ($n == 0) {
        return 1;
    }
    return factorial_a($n - 1) * $n;
}
var_dump(factorial_a(100));



#b
function factorial($n, $accumulator = 1) {
    if ($n == 0) {
        return $accumulator;
    }
    return factorial($n - 1, $accumulator * $n);
}
var_dump(factorial(100));


#c
function factorial($n, $accumulator = 1) {
    if ($n == 0) {
        return $accumulator;
    }
    return function() use($n, $accumulator) {
        return factorial($n - 1, $accumulator * $n);
    };
}

function trampoline($callback, $params) {
    $result = call_user_func_array($callback, $params);
    while (is_callable($result)) {
        $result = $result();
    }
    return $result;
}

var_dump(trampoline('factorial', array(100)));

