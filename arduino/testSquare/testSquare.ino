#include <fuzzy_table.h>
#include <PID_Beta6.h>

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

#include <MotorWheel.h>
#include <Omni3WD.h>

#include <SONAR.h>
#include <EEPROM.h>

// Motors

irqISR(irq1,isr1);
MotorWheel wheel1(9,8,6,7,&irq1);        // Pin9:PWM, Pin8:DIR, Pin6:PhaseA, Pin7:PhaseB

irqISR(irq2,isr2);
MotorWheel wheel2(10,11,14,15,&irq2);    // Pin10:PWM, Pin11:DIR, Pin14:PhaseA, Pin15:PhaseB

irqISR(irq3,isr3);
MotorWheel wheel3(3,2,4,5,&irq3);        // Pin3:PWM, Pin2:DIR, Pin4:PhaseA, Pin5:PhaseB

Omni3WD Omni(&wheel1,&wheel2,&wheel3);

void setup() {
  TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
  TCCR2B=TCCR2B&0xf8|0x01;    // Pin3,Pin11 PWM 31250Hz

  //
  Omni.PIDEnable(0.46,0.2,0,10);
  Serial.begin(9600);
  /*wheel3.runPWM(50, HIGH);
  wheel2.runPWM(50, LOW);*/
}

void loop() {

  Omni.setCarAdvance(300);
  Omni.delayMS(2000, false);
  Omni.setCarSlow2Stop(500);
  Omni.delayMS(500, false);
  
  Omni.setCarRotateLeft(300);
  Omni.delayMS(550, false);
  Omni.setCarSlow2Stop(200);
  Omni.delayMS(500, false);

}
