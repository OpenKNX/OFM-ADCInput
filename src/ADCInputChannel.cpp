#include "ADCInputChannel.h"

ADCInputChannel::ADCInputChannel(uint8_t index)
{
    _channelIndex = index;
}

const std::string ADCInputChannel::name()
{
    return "ADCInput";
}

void ADCInputChannel::setup()
{
    if (ParamADC_CHSensorType == 0)
        return;

        
    //KoBI_ChannelOutput.valueNoSend(false, DPT_Switch);

    // Debug
    logTraceP("paramSensorTyp: %i", ParamADC_CHSensorType);
    logTraceP("paramSendCycle: %i", ParamADC_CHSendcycletime);
    logTraceP("paramSendABS: %i", ParamADC_CHSendenAbsolut);
    logTraceP("paramSendREL: %i", ParamADC_CHSendenRelativ);
    logTraceP("paramVoltKorr: %i", ParamADC_CHVoltageCorrection);
    
}
void ADCInputChannel::loop()
{
    if (ParamADC_CHSensorType == 0)
        return;

    processInput();
    processPeriodicSend();
}

/*
void ADCInputChannel::setHardwareState(bool state)
{
    if (!ParamBI_ChannelActive)
        return;

    if (state == _currentHardwareState)
        return;

    logTraceP("setHardwareState %i", state);
    _currentHardwareState = state;
}
*/

void ADCInputChannel::processInput()
{
    // no hw state available
    /*
    if (_currentHardwareState == -1)
        return;

    if (debounce())
        return;

    if (_currentHardwareState != _currentState)
    {

        _currentState = _currentHardwareState;
        sendState();
    }
    */
}


void ADCInputChannel::processPeriodicSend()
{
    
    uint32_t paramValue = ParamADC_CHSendcycletime;

    // no hw state available
    if (_currentState == -1)
        return;

    // periodic send is disabled
    if (paramValue == 0)
        return;

    // first run - skip
    if (_lastPeriodicSend == 0)
    {
        _lastPeriodicSend = millis();
        return;
    }

    if (delayCheck(_lastPeriodicSend, paramValue))
    {
        _lastPeriodicSend = millis();
        sendState();
    }
        
}

void ADCInputChannel::sendState()
{
    /*
    int8_t state = -1;
    if (_currentState && ParamBI_ChannelClose == 1) // Open - send 0
        state = false;

    if (_currentState && ParamBI_ChannelClose == 2) // Closed - send 1
        state = true;

    if (!_currentState && ParamBI_ChannelOpen == 1) // OPen - send 0
        state = false;

    if (!_currentState && ParamBI_ChannelOpen == 2) // Closed - send 1
        state = true;

    if (state == -1)
        return;

    logDebugP("sendState: %i", state);
    */
   float TEst = 2.7;
   KoADC_ChannelOutput.value(TEst2, getDPT(VAL_DPT_9));
    
}

bool ADCInputChannel::isActive()
{
    if(ParamADC_CHSensorType > 0)
    return true;
    else false;
}