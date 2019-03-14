#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>  
#include "SSD1306Wire.h"
#include "FRONT_END.h"  
SSD1306Wire  display(0x3c, 5, 4);

ESP8266WebServer server(80);
FRONT_END Front_end;

const char* ssid = "esp8266_OLED";
const char* passphrase = "12345678";
String st;
String content;
String data_length, set_gw_freq, set_gw_sf , set_gw_mode, set_gw_bw, set_gw_length;
String set_freq, set_sf, set_mode;
int statusCode;

void setup() {
	Serial.begin(9600);
	display.init();
	delay(10);
	Serial.println("Startup AP");

	setupAP();
}

void setupAP(void) {
	WiFi.disconnect();
	delay(100);
	WiFi.mode(WIFI_AP_STA);
	delay(100);
	boolean wifi_ap_result = WiFi.softAP(ssid);  //Start wifi AP (ssid & password)
	Serial.print("wifi_ap_result (1 is ok 0 is fail)= "); Serial.println(wifi_ap_result);
	launchWeb(1);   // =createWebServer(webtype=1);
	Serial.println("over");
}

void launchWeb(int webtype) {

	Serial.print("SoftAP IP: ");
	Serial.println(WiFi.softAPIP());
	Serial.print("Server MAC address: ");
	Serial.println(WiFi.softAPmacAddress());
	createWebServer(webtype);
	// Start the server
	server.begin();
	Serial.println("Server started");
}

void createWebServer(int webtype)
{
	if (webtype == 1) {
		server.on("/", []() {
			//IPAddress ip = WiFi.softAPIP();
			//String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
			//content = "<!DOCTYPE HTML>\r\n<html>Hello from Field test tool at ";
			//content += ipStr;
			//content += "<hr>";
			//content += "<fieldset> <legend> Set RF Parameter </legend> ";
			//content += "<form method='get' action='status'>   ";
			//content += "<label>Freq: </label> <input type=''text' name='freq' size='5'> Mhz<br/ > ";
			//content += "<label>SF= </label> <select name='sf'> <option value='12' selected='selected'>SF12  <option value='11'>SF11 <option value='10'>SF10 <option value='9'>SF9 <option value='8'>SF8 <option value='7'>SF7 <option value='6'>SF6 </option> </select> <br/ > ";
			//content += "<label>Mode= </label> <input type='radio' name='mode' value='gw' checked='checked' /> Gateway <input type='radio' name='mode' value='node' /> Node <br/ >  ";
			//content += "<input type = 'submit'></form>  ";
			//content += "</fieldset> </html>  ";
			
			server.send(200, "text/html", Front_end.Home_page() );
		});
		server.on("/status", []() {
			set_freq = server.arg("freq");
			set_sf = server.arg("sf");
			set_mode = server.arg("mode");
			if (set_mode=="gw" )
			{
				content = "<< Gateway Mode >> Parameter <hr> <br/> Freq= ";
				content += set_freq ;
				content += "Mhz <br/ > SF= ";
				content += set_sf ;
				content += "  Mode= ";
				content += set_mode ;
				content += "<br/ > <input type='button' onclick ='history.back()' value ='back'></input> ";
				statusCode = 200;
			}
			else if (set_mode == "node")
			{
				content = "<< Node Mode >> Parameter <hr> <br/> Freq= ";
				content += set_freq;
				content += "Mhz <br/ > SF= ";
				content += set_sf;
				content += "  Mode= ";
				content += set_mode;
				content += "<form method='get' action='Node-status'>   ";
				content += "<br/> <label>Data Length = </label> <select name = 'data_length'> <option value = '100' selected = 'selected'>100 Bytes  <option value = '1'>1 Bytes <option value = '5'>5 Bytes <option value = '10'>10 Bytes <option value = '50'>50 Bytes <option value = '150'>150 Bytes <option value = '200'>200 Bytes <option value = '241'>241 Bytes </option> </select> <br/> ";
				content += "<input type = 'submit'></form>  ";
				content += "<br/ > <a href='/'> Setup page </a> ";
				
				statusCode = 200;
			}
			else {
				content = "{\"Error\":\"404 not found\"}";
				statusCode = 404;
				Serial.println("Sending 404");
			}
			server.send(statusCode, "text/html", content);
		});

		server.on("/parse_data", []() {
			set_gw_freq = server.arg("GW_Freq");
			set_gw_sf = server.arg("GW_SF");
			set_gw_bw = server.arg("GW_BW");
			set_gw_length = server.arg("GW_Length");
			content = "Gateway Freq= ";
			content += set_gw_freq;
			server.send(200, "text/html", content);
		});

		server.on("/node", []() {
			
			content = "<< Node Mode >> Parameter <hr> <br/> Freq= ";
			content += set_freq;
			content += "Mhz <br/ > SF= ";
			content += set_sf;
			content += "  Mode= ";
			content += set_mode;
			content += "<form method='get' action='Node-status'>   ";
			content += "<br/> <label>Data Length = </label> <select name = 'data_length'> <option value = '100' selected = 'selected'>100 Bytes  <option value = '1'>1 Bytes <option value = '5'>5 Bytes <option value = '10'>10 Bytes <option value = '50'>50 Bytes <option value = '150'>150 Bytes <option value = '200'>200 Bytes <option value = '241'>241 Bytes </option> </select> <br/> ";
			content += "<input type = 'submit'></form>  ";
			content += "<br/ > <a href='/'> Setup page </a> ";
			server.send(200, "text/html", content);
		});
		server.on("/gateway", []() {

			server.send(200, "text/html", Front_end.Gateway_mode() );
		});

	}

}

void drawFontFaceDemo() {
	// Font Demo1
	// create more fonts at http://oleddisplay.squix.ch/
	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_16);
	display.drawString(0, 0, "BW=");	display.drawString(50, 0, set_gw_bw);
//	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 14, "Freq="); display.drawString(50, 14, set_gw_freq); display.drawString(90, 14, "Mhz");
//	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 28, "SF="); display.drawString(50, 28, set_gw_sf);
	display.drawString(0, 42, "Data length="); display.drawString(90, 42, set_gw_length);
}

void loop() {
	server.handleClient();

	display.clear();
	drawFontFaceDemo();
	display.display();
}

