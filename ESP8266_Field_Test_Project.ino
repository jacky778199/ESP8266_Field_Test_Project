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
String set_node_freq, set_node_sf, set_node_mode, set_node_bw, set_node_length;
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
			server.send(200, "text/html", Front_end.Home_page() );
		});

		server.on("/parse_data", []() {
			set_gw_freq = server.arg("GW_Freq");
			set_gw_sf = server.arg("GW_SF");
			set_gw_bw = server.arg("GW_BW");
			set_gw_length = server.arg("GW_Length"); //Gateway ¨S¦³Length!!
			
			set_node_freq = server.arg("Node_Freq");
			set_node_sf = server.arg("Node_SF");
			set_node_bw = server.arg("Node_BW");
			set_node_length = server.arg("Data_Length");

			content = "Gateway Freq= ";
			content += set_gw_freq;
			server.send(200, "text/html", content);
		});

		server.on("/node", []() {
			
			server.send(200, "text/html", Front_end.Node_mode() );
		});
		server.on("/gateway", []() {

			server.send(200, "text/html", Front_end.Gateway_mode() );
		});

	}

}

void drawFontFaceDemo() 
{
	// Font Demo1
	// create more fonts at http://oleddisplay.squix.ch/
	if (set_gw_freq != 0 )
	{
		display.clear();
		display.setTextAlignment(TEXT_ALIGN_LEFT);
		display.setFont(ArialMT_Plain_16);
		display.drawString(0, 0, "BW=");	display.drawString(50, 0, set_gw_bw);
		//	display.setFont(ArialMT_Plain_10);
		display.drawString(0, 14, "Freq="); display.drawString(50, 14, set_gw_freq); display.drawString(90, 14, "Mhz");
		//	display.setFont(ArialMT_Plain_10);
		display.drawString(0, 28, "SF="); display.drawString(50, 28, set_gw_sf);
		display.drawString(0, 42, "<Gateway>"); display.drawString(90, 42, set_gw_length);

	}
	if (set_node_freq != 0)
	{
		display.clear();
		display.setTextAlignment(TEXT_ALIGN_LEFT);
		display.setFont(ArialMT_Plain_16);
		display.drawString(0, 0, "BW=");	display.drawString(50, 0, set_node_bw);
		//	display.setFont(ArialMT_Plain_10);
		display.drawString(0, 14, "Freq="); display.drawString(50, 14, set_node_freq); display.drawString(90, 14, "Mhz");
		//	display.setFont(ArialMT_Plain_10);
		display.drawString(0, 28, "SF="); display.drawString(50, 28, set_node_sf);
		display.drawString(0, 42, "Data length="); display.drawString(90, 42, set_node_length);

	}
	else
	{
		//display.drawString(0, 0, "Waiting...");
	}
}

void loop() {
	server.handleClient();

	display.clear();
	drawFontFaceDemo();
	display.display();
}

