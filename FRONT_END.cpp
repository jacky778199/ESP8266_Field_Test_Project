
#include "FRONT_END.h"

//此段為<< constructor建構>> 
FRONT_END:: FRONT_END (){
   
}
//此行為<<destructor解構>>
FRONT_END::~ FRONT_END (){ /*nothing to destruct*/ }

char * FRONT_END::Home_page(){
	char htmlStr[1000];
	snprintf ( htmlStr, 1000,
		"<!DOCTYPE HTML> <html>\
		  <head>\
		    <meta charset='utf-8'/>\
			<meta http-equiv='refresh' content='15'/>\
		    <title>Field Test Tool</title>\
		  </head>\
		  <body>\
		  <form method='get' action='status'>\
		    <h1>Blutech Field Test Tool </h1>\
			<h2>Select mode</h2>\
			<input type='button' name='buttom_gw' value='Gateway' onclick=\"location.href='/gateway'\"  style='width:120px; height:40px; font-size:20px;' >\
			<input type='button' name = 'buttom_node' value = 'Node' onclick =\"location.href='/node'\"  style='width:120px; height:40px; font-size:20px;' >\
			</form>\
		  </body>\
		</html> "
	);	
	return htmlStr ;
}

char * FRONT_END::Gateway_mode() {
	char htmlStr[3500];
	snprintf(htmlStr, 3500,
		"<!DOCTYPE HTML> <html>\
		  <head>\
		    <meta charset='utf-8'/>\
		    <title>Field Test Tool-Gateway Mode</title>\
			<style>\
				h2{ font-size: 20pt; color: red; }\
		    </style>\
		  <script>\
			var obj_GW_Parameter = { \
				Freq : '868',\
				SF : '12',\
				BW : '250'\
			}; \
			function Set_GW_Parameter()\
			{ \
			var form1 = document.getElementById('GW_SettingForm'); \
				obj_GW_Parameter.Freq = form1.GW_Freq.value ; \
				obj_GW_Parameter.SF = form1.GW_SF.value; \
				obj_GW_Parameter.BW = form1.GW_BW.value;\
			var xhr = new XMLHttpRequest();\
			var url = '/parse_data';\
			xhr.open('post', url);\
			xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');\
			xhr.send('GW_Freq='+obj_GW_Parameter.Freq+'&GW_SF='+obj_GW_Parameter.SF+'&GW_BW='+obj_GW_Parameter.BW );\
			console.log('GW_Freq'+obj_GW_Parameter.Freq);\
			Display_parameter();\
			};\
			function Display_parameter()\
			{ \
			var NewFreqValue = document.getElementById('GW_Freq').value;\
			document.getElementById('GW_Freq_Now').innerHTML = NewFreqValue;\
			var NewSFValue = document.getElementById('GW_SF').value;\
			document.getElementById('GW_SF_Now').innerHTML = NewSFValue;\
			var NewBWValue = document.getElementById('GW_BW').value;\
			document.getElementById('GW_BW_Now').innerHTML = NewBWValue;\
			}\
		  </script>\
		</head>\
		  <body>\
		  <form name='GW_SettingForm' id='GW_SettingForm'>\
		    <h1>Blutech Field Test Tool </h1>\
			<h2>Gateway mode</h2>\
			<hr/>\
			<fieldset> <legend> Set RF Parameter </legend> \
			<label>Freq: </label> <input type='text' name='GW_Freq' id='GW_Freq' size='5'> Mhz<br/ > \
			<label>SF= </label> <select name='GW_SF' id='GW_SF'> <option value='12' selected='selected'>SF12  <option value='11'>SF11 <option value='10'>SF10 <option value='9'>SF9 <option value='8'>SF8 <option value='7'>SF7 <option value='6'>SF6 </option> </select> <br/ > \
			<label>BW= </label> <select name='GW_BW' id='GW_BW'> <option value = '250' selected = 'selected'>250K  <option value = '500'>500K <option value = '125'>125K <option value = '62.5'>62.5K <option value = '41.66'>41.66K <option value = '31.25'>31.25K <option value = '20.83'>20.83K </option> </select> <br/> \
			<input type='button' name='B1' onclick='Set_GW_Parameter()' value = '設定參數' style='width:120px; height:30px; font-size:18px;' >\
			</fieldset>  \
		  </form>\
		  <br/ >\
			Gateway Freq= <span id='GW_Freq_Now'>--- </span>　\
			 , SF= <span id='GW_SF_Now'>--- </span>　 \
			 , BW= <span id='GW_BW_Now'>--- </span>　\
		  </body>\
		</html> "

	);	
	return htmlStr ;
}

char * FRONT_END::Node_mode()
{
    char htmlStr[5000];
	snprintf(htmlStr, 5000,
		"<!DOCTYPE HTML> <html>\
		  <head>\
		    <meta charset='utf-8'/>\
		    <title>Field Test Tool-Node Mode</title>\
			<style>\
				h2{ font-size: 20pt; color: blue; }\
		    </style>\
		  <script>\
			var obj_Node_Parameter = { \
				Freq : '868',\
				SF : '12',\
				BW : '250'\
			}; \
			function Set_Node_Parameter(){ \
			var form1 = document.getElementById('Node_SettingForm'); \
				obj_Node_Parameter.Freq = form1.Node_Freq.value ; \
				obj_Node_Parameter.SF = form1.Node_SF.value; \
				obj_Node_Parameter.BW = form1.Node_BW.value;\
				obj_Node_Parameter.Length = form1.Data_Length.value;\
			var xhr = new XMLHttpRequest();\
			var url = '/parse_data';\
			xhr.open('post', url);\
			xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');\
			xhr.send('Node_Freq='+obj_Node_Parameter.Freq+'&Node_SF='+obj_Node_Parameter.SF+'&Node_BW='+obj_Node_Parameter.BW+'&Data_Length='+obj_Node_Parameter.Length);\
			console.log('Node_Freq'+obj_Node_Parameter.Freq);\
			Display_parameter()\
			};\
			function Display_parameter()\
			{ \
			var NewFreqValue = document.getElementById('Node_Freq').value;\
			document.getElementById('Node_Freq_Now').innerHTML = NewFreqValue;\
			var NewSFValue = document.getElementById('Node_SF').value;\
			document.getElementById('Node_SF_Now').innerHTML = NewSFValue;\
			var NewBWValue = document.getElementById('Node_BW').value;\
			document.getElementById('Node_BW_Now').innerHTML = NewBWValue;\
			var NewBWValue = document.getElementById('Data_Length').value;\
			document.getElementById('Data_Length_Now').innerHTML = NewBWValue;\
			}\
		  </script>\
		</head>\
		  <body>\
		  <form name='Node_SettingForm' id='Node_SettingForm'>\
		    <h1>Blutech Field Test Tool </h1>\
			<h2>Node mode</h2>\
			<hr/>\
			<fieldset> <legend> Set RF Parameter </legend> \
			<label>Freq: </label> <input type='text' name='Node_Freq' id='Node_Freq' size='5'> Mhz<br/ > \
			<label>SF= </label> <select name='Node_SF' id='Node_SF'> <option value='12' selected='selected'>SF12  <option value='11'>SF11 <option value='10'>SF10 <option value='9'>SF9 <option value='8'>SF8 <option value='7'>SF7 <option value='6'>SF6 </option> </select> <br/ > \
			<label>BW= </label> <select name='Node_BW' id='Node_BW'> <option value = '250' selected = 'selected'>250K  <option value = '500'>500K <option value = '125'>125K <option value = '62.5'>62.5K <option value = '41.66'>41.66K <option value = '31.25'>31.25K <option value = '20.83'>20.83K </option> </select> <br/> \
			<label>Data Length= </label> <select name='Data_Length' id='Data_Length' > <option value='100' selected = 'selected'>100 Bytes  <option value = '1'>1 Bytes <option value = '5'>5 Bytes <option value = '10'>10 Bytes <option value = '50'>50 Bytes <option value = '150'>150 Bytes <option value = '200'>200 Bytes <option value = '241'>241 Bytes </option> </select> <br/> \
			<input type='button' name='B1' onclick='Set_Node_Parameter()' value = '設定參數'>\
			</fieldset>  \
		  </form>\
		  <br/ >\
			Node Freq= <span id='Node_Freq_Now'>--- </span>　\
			 , SF= <span id='Node_SF_Now'>--- </span>　 \
			 , BW= <span id='Node_BW_Now'>--- </span>　<br/ >\
			 Data Length= <span id='Data_Length_Now'>--- </span>　\
		  </body>\
		</html> "
	);
	//Next step : Display current parameter!  , Button to switch OLED page functon
}