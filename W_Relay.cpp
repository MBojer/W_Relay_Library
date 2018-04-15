/*
W_Relay
*/


// --------------------------------------------- WBus ---------------------------------------------

#include "Arduino.h"
#include "W_Relay.h"



// --------------------------------------------- Setup ---------------------------------------------
W_Relay::W_Relay(bool Relay_On_State) {

  _Relay_On_State = Relay_On_State;

} // W_Relay()


// --------------------------------------------- Set_Pins ---------------------------------------------
void W_Relay::Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5, int Replay_Pin_6) {

  _Relay_Pin[0] = Replay_Pin_1;
  _Relay_Pin[1] = Replay_Pin_2;
  _Relay_Pin[2] = Replay_Pin_3;
  _Relay_Pin[3] = Replay_Pin_4;
  _Relay_Pin[4] = Replay_Pin_5;
  _Relay_Pin[5] = Replay_Pin_6;

  // ------------------------------ Configuring pins ------------------------------
  for (byte i = 0; i < _Relay_Number_Of_Init; i++) {

    if (_Relay_Pin[i] == -1) break;

    pinMode(_Relay_Pin[i], OUTPUT);
    digitalWrite(_Relay_Pin[i], !_Relay_On_State);
  }


} // W_Relay()

void W_Relay::Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5) {
  Set_Pins(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, Replay_Pin_4, Replay_Pin_5, -1);
} // Referance only
void W_Relay::Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4) {
  Set_Pins(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, Replay_Pin_4, -1, -1);
} // Referance only
void W_Relay::Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3) {
  Set_Pins(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, -1, -1, -1);
} // Referance only
void W_Relay::Set_Pins(int Replay_Pin_1, int Replay_Pin_2) {
  Set_Pins(Replay_Pin_1, Replay_Pin_2, -1, -1, -1, -1);
} // Referance only
void W_Relay::Set_Pins(int Replay_Pin_1) {
  Set_Pins(Replay_Pin_1, -1, -1, -1, -1, -1);
} // Referance only


// --------------------------------------------- Set_Topics() ---------------------------------------------
void W_Relay::Set_Topics(String _Relay_Topic_String_All, String _Relay_Topic_String) {

  _Relay_Topic = _Relay_Topic_String;
  _Relay_Topic_All = _Relay_Topic_String_All;

} // Set_Topics()


// --------------------------------------------- Set_Auto_OFF_Pins() ---------------------------------------------
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4, bool Auto_OFF_Relay_5, bool Auto_OFF_Relay_6) {

  _Relay_Auto_OFF_Relays[0] = Auto_OFF_Relay_1;
  _Relay_Auto_OFF_Relays[1] = Auto_OFF_Relay_2;
  _Relay_Auto_OFF_Relays[2] = Auto_OFF_Relay_3;
  _Relay_Auto_OFF_Relays[3] = Auto_OFF_Relay_4;
  _Relay_Auto_OFF_Relays[4] = Auto_OFF_Relay_5;
  _Relay_Auto_OFF_Relays[5] = Auto_OFF_Relay_6;

} // Set_Auto_OFF_Relays()
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4, bool Auto_OFF_Relay_5) {
  Set_Auto_OFF_Relays(Auto_OFF_Relay_1, Auto_OFF_Relay_2, Auto_OFF_Relay_3, Auto_OFF_Relay_4, Auto_OFF_Relay_5, false);
} // Referance only
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4) {
 Set_Auto_OFF_Relays(Auto_OFF_Relay_1, Auto_OFF_Relay_2, Auto_OFF_Relay_3, Auto_OFF_Relay_4, false, false);
} // Referance only
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3) {
 Set_Auto_OFF_Relays(Auto_OFF_Relay_1, Auto_OFF_Relay_2, Auto_OFF_Relay_3, false, false, false);
} // Referance only
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2) {
 Set_Auto_OFF_Relays(Auto_OFF_Relay_1, Auto_OFF_Relay_2, false, false, false, false);
} // Referance only
void W_Relay::Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1) {
 Set_Auto_OFF_Relays(Auto_OFF_Relay_1, false, false, false, false, false);
} // Referance only


// --------------------------------------------- Set_Auto_OFF_Delay() ---------------------------------------------
void W_Relay::Set_Auto_OFF_Delay(unsigned long Auto_OFF_Delay) {

  _Relay_Auto_OFF_Delay = Auto_OFF_Delay;

} // Set_Auto_OFF_Delay()

// --------------------------------------------- isValidNumber() ---------------------------------------------
bool W_Relay::isValidNumber(String str) {
  for(byte i=0;i<str.length();i++)
  {
    if(isDigit(str.charAt(i))) return true;
  }
  return false;
} // isValidNumber()


void W_Relay::_MQTT_Send_Topic_Add(String Add_String) {

  if (_MQTT_Send_Topic == ";") _MQTT_Send_Topic = Add_String + ";";

  else _MQTT_Send_Topic += Add_String + ";";

} // _MQTT_Send_Topic_Add()

void W_Relay::_MQTT_Send_Payload_Add(String Add_String) {

  if (_MQTT_Send_Payload == ";") _MQTT_Send_Payload = Add_String + ";";

  else _MQTT_Send_Payload += Add_String + ";";

} // _MQTT_Send_Payload_Add()


// --------------------------------------------- Relay_Auto_OFF ---------------------------------------------
void W_Relay::Auto_OFF() {

  for (byte i = 0; i < _Relay_Number_Of_Init; i++) {

    if (_Relay_Auto_OFF_Active[i] == false) continue;

    else if (_Relay_Auto_OFF_At[i] < millis()) {

      if (digitalRead(_Relay_Pin[i]) == _Relay_On_State) {
        digitalWrite(_Relay_Pin[i], !_Relay_On_State);
        Serial.println("Relay " + String(i + 1) + " Auto OFF");
        _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(i + 1) + "/State"));
        _MQTT_Send_Payload_Add(String(OFF));
      }

      _Relay_Auto_OFF_Active[i] = false;
    }
  }
} // Relay_Auto_OFF()


// --------------------------------------------- _Relay_Auto_OFF_Check ---------------------------------------------
void W_Relay::_Relay_Auto_OFF_Check(byte Selected_Relay) {

  if (_Relay_Auto_OFF_Relays[Selected_Relay - 1] == true) {
    _Relay_Auto_OFF_At[Selected_Relay - 1] = millis() + _Relay_Auto_OFF_Delay;
    _Relay_Auto_OFF_Active[Selected_Relay - 1] = true;
  }

} // _Relay_Auto_OFF_Check()


// --------------------------------------------- Relay_Auto_OFF ---------------------------------------------
void W_Relay::_Relay_Auto_OFF(int Relay_Number) {
  if (digitalRead(_Relay_Pin[Relay_Number - 1]) == _Relay_On_State) {
    digitalWrite(_Relay_Pin[Relay_Number - 1], !_Relay_On_State);
    _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(Relay_Number) + "/State"));
    _MQTT_Send_Payload_Add(String(OFF));
  }
} // _Relay_Auto_OFF()


// --------------------------------------------- MQTT_Send() ---------------------------------------------
String W_Relay::MQTT_Send_Topic(bool Remove_Entry) {

  if (_MQTT_Send_Topic == ";") return ";";

  else {
    String Return_String = _MQTT_Send_Topic.substring(0, _MQTT_Send_Topic.indexOf(";"));

    if (Remove_Entry == true) {
      _MQTT_Send_Topic = _MQTT_Send_Topic.substring(Return_String.length() + 1, _MQTT_Send_Topic.length());
      if (_MQTT_Send_Topic == "") _MQTT_Send_Topic = ";";
    }

    return Return_String;
  }

} // MQTT_Send_Topic()
String W_Relay::MQTT_Send_Topic() {
  return MQTT_Send_Topic(false);
} // MQTT_Send_Topic()


String W_Relay::MQTT_Send_Payload(bool Remove_Entry) {

  if (_MQTT_Send_Payload == ";") return ";";

  else {
    String Return_String = _MQTT_Send_Payload.substring(0, _MQTT_Send_Payload.indexOf(";"));

    if (Remove_Entry == true) {
      _MQTT_Send_Payload = _MQTT_Send_Payload.substring(Return_String.length() + 1, _MQTT_Send_Payload.length());
      if (_MQTT_Send_Payload == "") _MQTT_Send_Payload = ";";
    }

    return Return_String;
  }

} // MQTT_Send_Payload()
String W_Relay::MQTT_Send_Payload() {
  return MQTT_Send_Payload(false);
} // MQTT_Send_Payload()


// --------------------------------------------- Check ---------------------------------------------
void W_Relay::Check(String Topic, String Payload) {

  if (Payload.length() > 1) Payload = Payload.substring(0, 1); // Trim length to avoid some wird error

  // /Boat/ALL
  if (Topic == _Relay_Topic_All && _Relay_Topic != "") {
    if (Payload.indexOf("Relay-OFF") != -1) {
      Serial.println("Relay - All OFF");
      for (int i = 0; i < _Relay_Number_Of_Init; i++) {
        if (digitalRead(_Relay_Pin[i]) != !_Relay_On_State) {
          digitalWrite(_Relay_Pin[i], !_Relay_On_State);
          Serial.println("Relay " + String(i + 1) + " changed state to: OFF");
          _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(i + 1) + "/State"));
          _MQTT_Send_Payload_Add(String(OFF));
          return;
        }
      }
    }
  }

  else if (Topic.indexOf("/State") != -1)  {
    // Ignore state publish from localhost
    return;
  }

  else if (Topic.indexOf(_Relay_Topic) != -1 && _Relay_Topic != "") {

    String Relay_String = Topic;
    Relay_String.replace(_Relay_Topic + "/", "");

    byte Selected_Relay = Relay_String.toInt();

    // Ignore all requests thats larger then _Relay_Number_Of_Init
    if (Selected_Relay > _Relay_Number_Of_Init) {
      // ADD invalid relay statement
    }

    // State request
    else if (Payload == "?") {
      String State_String;
      if (digitalRead(_Relay_Pin[Selected_Relay - 1]) == _Relay_On_State) State_String += "1";
      else State_String += "0";
      _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(Selected_Relay) + "/State"));
      _MQTT_Send_Payload_Add(State_String);
      return;
    }

    else if(isValidNumber(Payload) == true) {
      byte State = Payload.toInt();

      bool State_Digital;
      if (State == ON) State_Digital = _Relay_On_State;
      else if (State == OFF) State_Digital = !_Relay_On_State;
      else if (State == FLIP) State_Digital = !digitalRead(_Relay_Pin[Selected_Relay - 1]);

      if (Selected_Relay <= _Relay_Number_Of_Init && digitalRead(_Relay_Pin[Selected_Relay - 1]) != State_Digital) {
        digitalWrite(_Relay_Pin[Selected_Relay - 1], State_Digital);
        Serial.print("Relay " + String(Selected_Relay) + " changed state to: ");
        if (State_Digital == _Relay_On_State) {
          _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(Selected_Relay) + "/State"));
          _MQTT_Send_Payload_Add(String(ON));
          Serial.println("ON");
          _Relay_Auto_OFF_Check(Selected_Relay);
        }
        else {
          Serial.println("OFF");
          _MQTT_Send_Topic_Add(String(_Relay_Topic + "/" + String(Selected_Relay) + "/State"));
          _MQTT_Send_Payload_Add(String(OFF));
        }
      }
    }
  }
} // Check()
