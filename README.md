home-automation-hackaton
========================

Home Automation Hackaton

Inteligent house project designed at hackaton.ro 2013
The purpose of the project is to show the how you can improve your
life with the help of the technology.

CONFIGURE SERVER
----------------

Install required software on raspberry pi:

    #you need to be superuser to install things
	sudo /bin/bash
	
	#prerequisites
	apt-get install git libi2c-dev
	
	#LAMP stack
	apt-get install apache2
	apt-get install mysql-server
	apt-get install php5
	apt-get install php5-mysql
	
	#espeak for speech
	apt-get install espeak

	#install WiringPi following the instructions on https://github.com/WiringPi/WiringPi/blob/master/INSTALL
	
INSTALL
-------
    
	git clone https://github.com/bugariu-catalin/home-automation-hackaton.git
    cd src/rpi
    gcc -o rpi rpi.c  -lwiringPi
	
Configure apache server to load the index from public/index.html

REFERENCES
==========
http://ro-duino.blogspot.ro/2012/06/apache-php-si-mysql-pe-raspberry-pi.html
http://www.penguintutor.com/linux/raspberrypi-webserver
http://robofun.ro/forum/viewtopic.php?f=22&t=262
http://visualgdb.com/tutorials/raspberry/LED/
http://hertaville.com/2012/11/18/introduction-to-accessing-the-raspberry-pis-gpio-in-c/
http://twitter.github.io/bootstrap/
http://jquery.com/
http://tympanus.net/codrops/2009/12/03/css-and-jquery-tutorial-overlay-with-slide-out-box/
http://raspberrypi.stackexchange.com/questions/1505/how-to-attach-an-arduino
https://github.com/WiringPi
