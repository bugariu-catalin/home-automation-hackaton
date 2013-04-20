var updateInterval = 5000;
var App = new function() {
	var _Door_Open = false;
	var _Door_Bell = false;
	var _Door_Lock = false;

	var _Light_Open = false;
	var _Light_Error = false;
	
	var _Sound_On = true;
	var _Motion_On = true;
	
	$(document).ready(function () {	
		App.Door_Close(); //Show door closed after first load
		App.Light_Close(); //Show light closed after first load
		App.Sound_On();
		App.Motion_Off();
		//setInterval('flip()',1000);
		
		$('#sound').click(function(){
			if (App.getSound_On()) App.Sound_Off(); else App.Sound_On();
		});
		
		$('#VideoIcon').click(function(){
            $('#overlay').fadeIn('fast',function(){
				$('#box').animate({'top':'160px'},500);
            });
		});
        $('#boxclose, #boxclose2').click(function(){
            $('#box').animate({'top':'-1000px'},500,function(){
                $('#overlay').fadeOut('fast');
            });
        });
		setInterval('App.updateStatus()',updateInterval);
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
	
	//Notification functions
	this.Notify_Message = function(_type, title,message) {
		if (!(_type in {'alert':'','warning':'','success':'','info':''})) {
			console.log('Error unknown Notify_Message type');
			return;
		}
		
		$('#' + _type + ' > #msg').html('<h3>' + title + '</h3>' + message)
		$('#' + _type ).show();
	}
	
	//Mation functions
	this.getMotion_On = function() {
		return _Motion_On;
	}
	
	this.Motion_On = function() {
		_Motion_On = true;
		$('#MotionIcon').show();
	}
	
	this.Motion_Off = function() {
		_Motion_On = false;
		$('#MotionIcon').hide();
	}

	this.updateStatus = function() {
		$.post('api.php?get_status=1', function(data) {
		  console.log(data);
		  if (data._Light_Open) App.Light_Open(); else App.Light_Close(); 
		},'json');
	}
}
//Test function
//TODO: delete it
function flip() {
	if (!App.getMotion_On()) {
		App.Motion_On();
	} else {
		App.Motion_Off();
	}
}