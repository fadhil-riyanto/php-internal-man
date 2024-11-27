<?php

$input_data = file_get_contents("notepad");
$arr = explode("\n", $input_data);

$first = 1;
foreach($arr as $i) {
        if ($first == 1) {
                echo "\"" . $i . "\\n\" \\" . PHP_EOL;
        } else {
                echo "                        \"\\t" . $i . "\\n\" \\" . PHP_EOL;
        }
        

        $first = 0;
}