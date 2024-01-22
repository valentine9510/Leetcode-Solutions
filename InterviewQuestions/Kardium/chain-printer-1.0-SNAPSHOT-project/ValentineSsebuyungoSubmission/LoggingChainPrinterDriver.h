#ifndef LOGGINGCHAINPRINTERDRIVER_H
#define LOGGINGCHAINPRINTERDRIVER_H

#include <iostream>
#include "ChainPrinterDriver.h"

class LoggingChainPrinterDriver : public ChainPrinterDriver {
public:
    void fire(int solenoidIndex) override;
    void step() override;
    void linefeed() override;
};

#endif // LOGGINGCHAINPRINTERDRIVER_H
