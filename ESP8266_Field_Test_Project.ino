#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "esp8266_OLED";
const char* passphrase = "12345678";
String st;
String content;
int statusCode;

void setup() {
	Serial.begin(9600);

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
			IPAddress ip = WiFi.softAPIP();
			String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
			content = "<!DOCTYPE HTML>\r\n<html>Hello from Field test tool at ";
			content += ipStr;
		
			
			content += "<fieldset>\r\n <legend> Set RF Parameter </legend>";
			content += "<form method='get' action='status'> ";
			content += "<label>Freq: </label><input name='freq' length=32>" ;
			content += "<label>SF = < / label><select name = 'sf' length = 32>" ;
			content += "<label>Mode= </label><input name ='mode' length = 32>" ;
			content += "<input type = 'submit'>< / form>";
			content += "</fieldset>";
			content += "</html>";

			server.send(200, "text/html", content);
		});
		server.on("/status", []() {
			String set_freq = server.arg("freq");
			String set_bw = server.arg("bw");
			String set_mode = server.arg("mode");
			if (set_freq.length() > 0 )
			{
				content = "{\"Success\":\"saved setting parameter...set_freq= ";
				content += set_freq;
				content += "<input type='button' onclick ='history.back()' value ='back'></input> ";
				statusCode = 200;
			}
			else {
				content = "{\"Error\":\"404 not found\"}";
				statusCode = 404;
				Serial.println("Sending 404");
			}
			server.send(statusCode, "text/html", content);
		});
	}

}

void loop() {
	server.handleClient();
}