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
      W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5, int Replay_Pin_6);
      W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5);
      W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4);
      W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3);
      W_Relay(int Replay_Pin_1, int Replay_Pin_2);
      W_Relay(int Replay_Pin_1);


      // --------------------------------------------- Relay ---------------------------------------------



      // void Push(String Push_String, bool Add_To_Front_Of_Queue);
      // void Push(String Push_String);
      // String Pop();
      // String Peek();
      // String Peek_Queue();
      // int Length();
      // void Clear();
      // String Search_Peek(String Search_String);
      // String Search_Pop(String Search_String, bool Delete_All_Matches);
      //
      // bool Queue_Is_Empthy = true;


    private:
      // --------------------------------------------- Relay ---------------------------------------------
      #define OFF 0
      #define ON 1
      #define FLIP 2

      #define _Relay_Number_Of_Init 6
      int _Relay_Pin_[_Relay_Number_Of_Init];

      bool _Relay_On_State = HIGH;

      // Ticker Relay_Auto_OFF_Ticker;
      // unsigned long Relay_Auto_OFF_Timer = 20000;


  };

#endif
