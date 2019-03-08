
#include <FRONT_END.h>

//此段為<< constructor建構>> 
FRONT_END:: FRONT_END (){
   
}
//此行為<<destructor解構>>
FRONT_END::~ FRONT_END (){ /*nothing to destruct*/ }

String FRONT_END::Home_page(){
	char htmlStr[700];
	IPAddress ip = WiFi.softAPIP();
	String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
	snprintf ( htmlStr, 700,
		"<!DOCTYPE HTML> <html>\
		  <head>\
		    <meta charset='utf-8'/>\
			<meta http-equiv='refresh' content='5'/>\
		    <title>Field Test Tool</title>\
		  </head>\
		  <body>\
		  <form method='get' action='status'>\
		    <h1>Blutech Field Test Tool </h1>\
			<h2>Select mode</h2>\
			<h3><input type='radio' name='mode' value='gw' checked='checked' /> Gateway <input type='radio' name='mode' value='node' /> Node <br/ >  </h3>\		  
		  <input type = 'submit'></form>\
		  </body>\
		
	);	
	return htmlStr ;
}

String FRONT_END::Gateway_mode(){
        digitalWrite(LED_PIN,LOW);
}

String FRONT_END::Node_mode(int time){
        on();                  
        delay(time/2);  
        off();                  
        delay(time/2);
}