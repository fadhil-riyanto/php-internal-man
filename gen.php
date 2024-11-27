<?php

$input_data = file_get_contents("notepad");
$arr = explode("\n", $input_data);
foreach($arr as $i) {
        echo "\"" . $i . "\\n\" \\" . PHP_EOL;
}