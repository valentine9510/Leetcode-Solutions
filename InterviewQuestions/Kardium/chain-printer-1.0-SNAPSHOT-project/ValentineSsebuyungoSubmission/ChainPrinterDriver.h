#ifndef CHAINPRINTERDRIVER_H
#define CHAINPRINTERDRIVER_H

#include <iostream>

/**
 * Hypothetical chain printer driver interface.
 */
class ChainPrinterDriver {
public:
    /**
     * Fires the specified solenoid, returning immediately.
     *
     * @param solenoidIndex The solenoid index (0-7).
     */
    virtual void fire(int solenoidIndex) = 0;

    /**
     * Waits for all solenoids to finish firing, then advances the chain one step (1 mm) to the left.
     * Returns after the chain has advanced.
     */
    virtual void step() = 0;

    /**
     * Advances the paper feed by one line, returning after the paper has advanced.
     */
    virtual void linefeed() = 0;

    virtual ~ChainPrinterDriver() = 0;
};



// Default implementations for ChainPrinterDriver methods
inline void ChainPrinterDriver::fire(int solenoidIndex) {
    std::cout << "fired solenoid - " << solenoidIndex << std::endl;
}

inline void ChainPrinterDriver::step() {
    std::cout << "Step\n";
}

inline void ChainPrinterDriver::linefeed() {
    std::cout << "LineFeed\n";
}

inline ChainPrinterDriver::~ChainPrinterDriver() {
    std::cout << "Destructor\n";
}

#endif // CHAINPRINTERDRIVER_H
