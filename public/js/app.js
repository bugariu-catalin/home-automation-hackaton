
var App = new function() {
	var _Door_Open = false;
	var _Door_Bell = false;
	var _Door_Lock = false;

	var _Light_Open = false;
	var _Light_Error = false;
	
	var _Sound_On = true;
	
	$(document).ready(function () {	
		App.Door_Close(); //Show door closed after first load
		App.Light_Close(); //Show light closed after first load
		App.Sound_Off();
		//setInterval('flip()',1000);
		$('#sound').click(function(){
			if (App.getSound_On()) App.Sound_Off(); else App.Sound_On();
		});
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

	//Sound functions
	this.getSound_On = function() {
		return _Sound_On;
	}
	
	this.Sound_On = function() {
		_Sound_On = true;
		$('#sound').removeClass('SoundOff')
		           .addClass('SoundOn');
	}

	this.Sound_Off = function() {
		_Sound_On = false;
		$('#sound').removeClass('SoundOn')
		           .addClass('SoundOff');
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
	if (!App.getSound_On()) {
		App.Sound_On();
	} else {
		App.Sound_Off();
	}
}