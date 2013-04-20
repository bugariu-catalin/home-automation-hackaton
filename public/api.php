<?php

if ($_REQUEST['get_status']==1) {
	echo file_get_contents('/home/pi/.all_status');
}
?>