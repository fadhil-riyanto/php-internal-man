<?php

$input_data = file_get_contents("notepad");
$arr = explode("\n", $input_data);

$first = 1;
foreach($arr as $i) {
        
        $replaced = addslashes($i);

        if ($first == 1) {
                echo "\"" . $replaced . "\\n\" \\" . PHP_EOL;
        } else {
                echo "                        \"\\t" . $replaced . "\\n\" \\" . PHP_EOL;
        }
        

        $first = 0;
}