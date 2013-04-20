<?php

if ($_POST['get_status']) {
	echo file_get_contents('/home/pi/.all_status');
}
?>