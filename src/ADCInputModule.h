#include "ADCInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"
#include "ADS1X15.h"


#define AS1115_MAX_CH 4


class ADCInputModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;

  private:
    void processHardwareInputs();
    void processInput();
  
    long adc_Value[AS1115_MAX_CH] = {1}; 
    uint32_t _lastPollingTime = 0;

    ADCInputChannel* _channels[AS1115_MAX_CH];
};

extern ADCInputModule openknxADCInputModule;

