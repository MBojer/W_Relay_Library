/*
W_Relay
*/


// --------------------------------------------- WBus ---------------------------------------------

#include "Arduino.h"
#include "W_Relay.h"


// --------------------------------------------- Setup ---------------------------------------------
W_Relay::W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5, int Replay_Pin_6) {

  _Relay_Pin_[0] = Replay_Pin_1;
  _Relay_Pin_[1] = Replay_Pin_2;
  _Relay_Pin_[2] = Replay_Pin_3;
  _Relay_Pin_[3] = Replay_Pin_4;
  _Relay_Pin_[4] = Replay_Pin_5;
  _Relay_Pin_[5] = Replay_Pin_6;

} // W_Relay()

W_Relay::W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4, int Replay_Pin_5) {
  W_Relay(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, Replay_Pin_4, Replay_Pin_5, -1);
} // Referance only

W_Relay::W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3, int Replay_Pin_4) {
  W_Relay(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, Replay_Pin_4, -1, -1);
} // Referance only

W_Relay::W_Relay(int Replay_Pin_1, int Replay_Pin_2, int Replay_Pin_3) {
  W_Relay(Replay_Pin_1, Replay_Pin_2, Replay_Pin_3, -1, -1, -1);
} // Referance only

W_Relay::W_Relay(int Replay_Pin_1, int Replay_Pin_2) {
  W_Relay(Replay_Pin_1, Replay_Pin_2, -1, -1, -1, -1);
} // Referance only

W_Relay::W_Relay(int Replay_Pin_1) {
  W_Relay(Replay_Pin_1, -1, -1, -1, -1, -1);
} // Referance only



// --------------------------------------------- W_Relay ---------------------------------------------




// void W_Relay::Push(String Push_String, bool Add_To_Front_Of_Queue) {
//
//   if (Queue_Is_Empthy == true) {
//     _Queue_String = Push_String + ";";
//     _Queue_Length = 1;
//     Queue_Is_Empthy = false;
//   }
//
//   else {
//     _Queue_String = _Queue_String + Push_String + ";";
//     _Queue_Length++;
//     Queue_Is_Empthy = false;
//   }
//
//   if (_Queue_Length >= _Max_Queue_Length) {
//     // CHANGE ME - Error reporting !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     _Queue_String = ";";
//     _Queue_Length = 0;
//     Queue_Is_Empthy = true;
//   }
//
// } // End Marker for Push
//
// void W_Relay::Push(String Push_String) { // Refferance only
//   Push(Push_String, false);
// }
