#include "ADCInputChannel.h"

ADCInputChannel::ADCInputChannel(uint8_t index) { _channelIndex = index; }

const std::string ADCInputChannel::name() { return "ADCInput"; }

void ADCInputChannel::setup() {
  if (ParamADC_CHSensorType == 0)
    return;

   // KoBI_ChannelOutput.valueNoSend(false, DPT_Switch);

  // Debug
  logTraceP("paramSensorTyp: %i", ParamADC_CHSensorType);
  logTraceP("paramSendCycle: %i", ParamADC_CHSendcycletime);
  logTraceP("paramSendABS: %i", ParamADC_CHSendenAbsolut);
  logTraceP("paramSendREL: %i", ParamADC_CHSendenRelativ);
  logTraceP("paramVoltKorr: %i", ParamADC_CHVoltageCorrection);
}
void ADCInputChannel::loop() {
  if (ParamADC_CHSensorType == 0)
    return;

  processPeriodicSend();
}


void ADCInputChannel::getADC_value(long value)
{
    _adcValue = value;

    // Hier muss senden bei Wertänderung drin sein !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}

void ADCInputChannel::processPeriodicSend() {

  uint32_t paramValue = ParamADC_CHSendcycletime;

  // no hw state available
  if (_currentState == -1)
    return;

  // periodic send is disabled
  if (paramValue == 0)
    return;

  // first run - skip
  if (_lastPeriodicSend == 0) {
    _lastPeriodicSend = millis();
    return;
  }

  if (delayCheck(_lastPeriodicSend, paramValue)) {
    _lastPeriodicSend = millis();
    sendState();
  }
}

void ADCInputChannel::sendState() {


  // HIER abfragen welche TYP: mV ; SMT50, 
  
  // und auch bei mV welche Einheit (V, ....)


  logDebugP("sendState: %i", _adcValue);
  
  float Test = _adcValue/ 10.0;
  KoADC_ChannelOutput.value(Test, DPT_Value_Volt);
}

bool ADCInputChannel::isActive() {
  if (ParamADC_CHSensorType > 0)
    return true;
  else
    return false;
}