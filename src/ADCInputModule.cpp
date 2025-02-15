#include "ADCInputModule.h"



const std::string ADCInputModule::name()
{
    return "BasicADCInput";
}

const std::string ADCInputModule::version()
{
    return MODULE_ADCInput_Version;
}

void ADCInputModule::setup()
{
    /*
    if (_gpioPins == nullptr)
    {
        logErrorP("No GPIO pins defined, module inactive");
        return;
    }

    for (uint8_t i = 0; i < MIN(BI_ChannelCount, OPENKNX_BI_GPIO_COUNT); i++)
    {
#if OPENKNX_BI_ONLEVEL == LOW
        pinMode(_gpioPins[i], INPUT_PULLUP);
#else // OPENKNX_BI_ONLEVEL == HIGH
        pinMode(_gpioPins[i], INPUT_PULLDOWN);
#endif

#if defined(OPENKNX_BI_PULSE) && OPENKNX_BI_PULSE != -1
        pinMode(OPENKNX_BI_PULSE, OUTPUT);
#endif

        _channels[i] = new BinaryInputChannel(i);
        _channels[i]->setup();
    }
    */
}

void ADCInputModule::loop()
{
    /*
    if (_gpioPins == nullptr)
        return;
    */   
    processHardwareInputs();
    /*
    for (uint8_t i = 0; i < MIN(BI_ChannelCount, OPENKNX_BI_GPIO_COUNT); i++)
        _channels[i]->loop();
    */    
}

void ADCInputModule::processHardwareInputs()
{
    /*
    if (_gpioPins == nullptr)
        return;

#if defined(OPENKNX_BI_PULSE) && OPENKNX_BI_PULSE != -1
    if (!delayCheck(_lastHardwareQuery, OPENKNX_BI_PULSE_PAUSE_TIME))
        return;

    digitalWrite(OPENKNX_BI_PULSE, true);
    delayMicroseconds(OPENKNX_BI_PULSE_WAIT_TIME);
#endif

    for (uint8_t i = 0; i < MIN(BI_ChannelCount, OPENKNX_BI_GPIO_COUNT); i++)
    {
        if (_channels[i]->isActive())
            _channels[i]->setHardwareState(digitalRead(_gpioPins[i]) == OPENKNX_BI_ONLEVEL);
    }

#if defined(OPENKNX_BI_PULSE) && OPENKNX_BI_PULSE != -1
    digitalWrite(OPENKNX_BI_PULSE, false);
    _lastHardwareQuery = millis();
#endif
   */
}

ADCInputModule openknxADCInputModule;

