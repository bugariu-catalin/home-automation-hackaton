
var App = new function() {
	var _Door_Open = false;
	var _Door_Bell = false;
	var _Door_Lock = false;

	var _Light_Open = false;
	var _Light_Error = false;
	
	$(document).ready(function () {	
		App.Door_Close(); //Show door closed after first load
		App.Light_Close(); //Show light closed after first load
		//setInterval('flip()',1000);
	});

	//Light functions
	this.getLight_Open = function() {
		return _Light_Open;
	}
	
	this.Light_Open = function() {
		_Light_Open = true;
		$('#light').removeClass('LightClose')
		           .removeClass('LightError')
				   .addClass('LightOpen');
	}
	
	this.Light_Close = function() {
		_Light_Open = false;
		$('#light').removeClass('LightOpen')
				   .removeClass('LightError')
		           .addClass('LightClose');
	}

	this.Light_Error = function() {
		$('#light').removeClass('LightOpen')
				   .removeClass('LightClose')
				   .addClass('LightError');
	}
	
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
	if (!App.getLight_Open()) {
		App.Light_Open();
	} else {
		App.Light_Close();
	}
}