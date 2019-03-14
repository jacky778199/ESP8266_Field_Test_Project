
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

char * FRONT_END::Gateway_mode() {
	char htmlStr[2500];
	snprintf(htmlStr, 2500,
		"<!DOCTYPE HTML> <html>\
		  <head>\
		    <meta charset='utf-8'/>\
			<meta http-equiv='refresh' content='50'/>\
		    <title>Field Test Tool-Gateway Mode</title>\
		  <script>\
			var obj_GW_Parameter = { \
				Freq : '868',\
				SF : '12',\
				BW : '250'\
			}; \
			function Set_GW_Parameter(){ \
			var form1 = document.getElementById('GW_SettingForm'); \
				obj_GW_Parameter.Freq = form1.GW_Freq.value ; \
				obj_GW_Parameter.SF = form1.GW_SF.value; \
				obj_GW_Parameter.BW = form1.GW_BW.value;\
				obj_GW_Parameter.Length = form1.GW_Length.value;\
			var xhr = new XMLHttpRequest();\
			var url = '/parse_data';\
			xhr.open('post', url);\
			xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');\
			xhr.send('GW_Freq='+obj_GW_Parameter.Freq+'&GW_SF='+obj_GW_Parameter.SF+'&GW_BW='+obj_GW_Parameter.BW+'&GW_Length='+obj_GW_Parameter.Length);\
			console.log('GW_Freq'+obj_GW_Parameter.Freq);\
			};\
		  </script>\
		</head>\
		  <body>\
		  <form name='GW_SettingForm' id='GW_SettingForm'>\
		    <h1>Blutech Field Test Tool </h1>\
			<h2>Gateway mode</h2>\
			<hr/>\
			<fieldset> <legend> Set RF Parameter </legend> \
			<label>Freq: </label> <input type='text' name='GW_Freq' size='5'> Mhz<br/ > \
			<label>SF= </label> <select name='GW_SF'> <option value='12' selected='selected'>SF12  <option value='11'>SF11 <option value='10'>SF10 <option value='9'>SF9 <option value='8'>SF8 <option value='7'>SF7 <option value='6'>SF6 </option> </select> <br/ > \
			<label>BW= </label> <select name='GW_BW'> <option value = '250' selected = 'selected'>250K  <option value = '500'>500K <option value = '125'>125K <option value = '62.5'>62.5K <option value = '41.66'>41.66K <option value = '31.25'>31.25K <option value = '20.83'>20.83K </option> </select> <br/> \
			<label>Data Length= </label> <select name='GW_Length'> <option value='100' selected = 'selected'>100 Bytes  <option value = '1'>1 Bytes <option value = '5'>5 Bytes <option value = '10'>10 Bytes <option value = '50'>50 Bytes <option value = '150'>150 Bytes <option value = '200'>200 Bytes <option value = '241'>241 Bytes </option> </select> <br/> \
			<input type='button' name='B1' onclick='Set_GW_Parameter()' value = '設定參數'>\
			</fieldset>  \
		  </form>\
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