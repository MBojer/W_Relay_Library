/*
W Relay
Version 0.1
*/

#ifndef W_Relay_h
  #define W_Relay_h

  #include "Arduino.h"

  class W_Relay {

    public:
      // --------------------------------------------- Setup ---------------------------------------------
      W_Relay(bool Relay_On_State);

      // --------------------------------------------- Set Commands ---------------------------------------------
      void Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5, int Replay_Pin_6);
      void Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5);
      void Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4);
      void Set_Pins(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3);
      void Set_Pins(int Replay_Pin_1, int Replay_Pin_2);
      void Set_Pins(int Replay_Pin_1);

      void Set_Topics(String Relay_Topic_String_All, String Relay_Topic_String);

      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4, bool Auto_OFF_Relay_5, bool Auto_OFF_Relay_6);
      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4, bool Auto_OFF_Relay_5);
      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3, bool Auto_OFF_Relay_4);
      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2, bool Auto_OFF_Relay_3);
      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1, bool Auto_OFF_Relay_2);
      void Set_Auto_OFF_Relays(bool Auto_OFF_Relay_1);

      void Set_Auto_OFF_Delay(unsigned long Auto_OFF_Delay);

      bool isValidNumber(String str);


      // --------------------------------------------- Relay Auto OFF ---------------------------------------------
      void Auto_OFF();


      // --------------------------------------------- Check ---------------------------------------------
      void Check(String Topic, String Payload);


      // --------------------------------------------- MQTT Send Queue ---------------------------------------------
      String MQTT_Send_Topic(bool Remove_Entry);
      String MQTT_Send_Topic();
      String MQTT_Send_Payload(bool Remove_Entry);
      String MQTT_Send_Payload();


    private:
      // --------------------------------------------- MQTT Send Queue ---------------------------------------------
      String _MQTT_Send_Topic = ";";
      String _MQTT_Send_Payload = ";";

      void _MQTT_Send_Topic_Add(String Add_String);
      void _MQTT_Send_Payload_Add(String Add_String);

      // --------------------------------------------- Relay Auto OFF ---------------------------------------------
      void _Relay_Auto_OFF(int Relay_Pin);
      void _Relay_Auto_OFF_Check(byte Selected_Relay);


      // --------------------------------------------- General ---------------------------------------------
      #define OFF 0
      #define ON 1
      #define FLIP 2

      // --------------------------------------------- Set Pins ---------------------------------------------
      #define _Relay_Number_Of_Init 6
      int _Relay_Pin[_Relay_Number_Of_Init];

      bool _Relay_On_State = HIGH;


      // --------------------------------------------- Set Topics ---------------------------------------------
      String _Relay_Topic;
      String _Relay_Topic_All;


      // --------------------------------------------- Set Auto OFF ---------------------------------------------
      bool _Relay_Auto_OFF_Relays[_Relay_Number_Of_Init] = {false, false, false, false, false, false};

      bool _Relay_Auto_OFF_Active[_Relay_Number_Of_Init] = {false, false, false, false, false, false};

      unsigned long _Relay_Auto_OFF_At[_Relay_Number_Of_Init] = {0, 0, 0, 0, 0, 0};
      unsigned long _Relay_Auto_OFF_Delay = 5000;



  };

#endif
