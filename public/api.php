<?php

if ($_REQUEST['get_status']==1) {
	$a = array();
	$f = file('/home/pi/.all_status');
	foreach ($f as $item) {
		$item = explode('=',$item);
		$a[$item[0]] = $item[1];
	}
	echo json_encode($a);
}
?>