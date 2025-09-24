#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

#define REMOTEXY_BLUETOOTH_NAME "Motor Marc"
#define REMOTEXY_ACCESS_PASSWORD "test2"

#include <RemoteXY.h>
#pragma pack(push, 1)

uint8_t RemoteXY_CONF[] = // 44 bytes
{
  255,2,0,0,0,37,0,18,0,0,0,31,1,106,200,1,1,2,0,4,
  45,1,20,159,48,2,26,2,38,174,44,22,0,2,26,31,31,79,78,0,
  79,70,70,0
};

struct {
  int8_t slider_01; // from -100 to 100
  uint8_t switch_01; // =1 if switch ON and =0 if OFF
  // other variable
  uint8_t connect_flag; // =1 if wire connected, else =0
} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
// END RemoteXY include //
/////////////////////////////////////////////
const int B_1 = 0;
const int A_1 = 1;

void setup()
{
  Serial.begin(9600);
  RemoteXY_Init();
  pinMode(B_1, OUTPUT);
  pinMode(A_1, OUTPUT);
}

void loop() {
  RemoteXY_Handler();
  int engine = RemoteXY.slider_01;
  int switch1 = RemoteXY.switch_01;
  int engineToFull = (engine) * 2.55;
  Serial.print("Engine: Abs ");
  Serial.print(abs(engineToFull));
  Serial.print(" Full ");
  Serial.print(engineToFull);
  Serial.print(" Switch: ");
  Serial.print(switch1);
  Serial.print("\n");
  
  if(engine == 0 || switch1 == 0) {
    digitalWrite(B_1, LOW);
    digitalWrite(A_1, LOW);
  } else if(engine > 0) {
    digitalWrite(B_1, abs(engineToFull));
    digitalWrite(A_1, LOW);
  } else if(engine < 0) {
    digitalWrite(B_1, LOW);
    digitalWrite(A_1, abs(engineToFull));
  }
}
