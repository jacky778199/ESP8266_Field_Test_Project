
#include "FRONT_END.h"

//此段為<< constructor建構>> 
FRONT_END:: FRONT_END (){
   
}
//此行為<<destructor解構>>
FRONT_END::~ FRONT_END (){ /*nothing to destruct*/ }

char * FRONT_END::Home_page(){
	char htmlStr[700];
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
			<input type='button' name='buttom_gw' value='Gateway' onclick=\"location.href='/gateway'\">\
			<input type='button' name = 'buttom_node' value = 'Node' onclick =\"location.href='/node'\">\
		<!-- <h3><input type='radio' name='mode' value='gw' checked='checked' /> Gateway <input type='radio' name='mode' value='node' /> Node <br/ >  </h3>\  -->\
			<input type = 'submit'></form>\
		  </body>\
		</html> "
	);	
	return htmlStr ;
}

char * FRONT_END::Gateway_mode(){
    char htmlStr[700];
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
		</html> "
	);	
	return htmlStr ;
}

char * FRONT_END::Node_mode(){
    char htmlStr[700];
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
		</html> "
	);	
}