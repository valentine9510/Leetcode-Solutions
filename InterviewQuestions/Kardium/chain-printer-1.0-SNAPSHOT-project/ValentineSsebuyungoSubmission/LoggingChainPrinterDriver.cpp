#include "LoggingChainPrinterDriver.h"

void LoggingChainPrinterDriver::fire(int solenoidIndex) {
    std::cout << "Fire solenoid " << solenoidIndex << std::endl;
}

void LoggingChainPrinterDriver::step() {
    std::cout << "Step chain 1 mm" << std::endl;
}

void LoggingChainPrinterDriver::linefeed() {
    std::cout << "Linefeed" << std::endl;
}
