
var App = new function() {
	var _Door_Open = false;
	var _Door_Bell = false;
	var _Door_Lock = false;
	
	$(document).ready(function () {	
		App.Door_Close(); //Show door closed after first load
		//setInterval('flip()',1000);
	});

	//Door functions
	this.getDoor_Open = function() {
		return _Door_Open;
	}

	this.Door_Open = function() {
		_Door_Open = true;
		$('#door').removeClass('DoorClose').addClass('DoorOpen');
	}

	this.Door_Close = function() {
		_Door_Open = false;
		$('#door').removeClass('DoorOpen').addClass('DoorClose');
	}
	
	this.Door_Bell = function() {
		if (_Door_Bell) {
			$('#DoorBell').show();	
		} else {
			$('#DoorBell').hide();
		}
	}
	
	this.Door_Lock = function() {
		if (_Door_Lock) {
			$('#DoorLock').show();	
		} else {
			$('#DoorLock').hide();
		}
	}
	
	

}
//Test function
//TODO: delete it
function flip() {
return;
	if (!App.getDoor_Open()) {
		App.Door_Open();
	} else {
		App.Door_Close();
	}
}