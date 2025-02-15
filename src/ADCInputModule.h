#include "ADCInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"


class ADCInputModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;

  private:
    void processHardwareInputs();

    uint32_t _lastHardwareQuery = 0;

    //const uint8_t _gpioPins[OPENKNX_BI_GPIO_COUNT] = {OPENKNX_BI_GPIO_PINS};

    //ADCInputChannel* _channels[OPENKNX_BI_GPIO_COUNT];
};

extern ADCInputModule openknxADCInputModule;

